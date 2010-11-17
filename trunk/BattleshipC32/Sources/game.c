#include <mc9s12dp512.h>     /* derivative information */
#include "game.h"
#include "LCDG.h"
#include "switch.h"

#define DEBOUNCE_DELAY 30000

#define SINGLE       0
#define MULTI_XBEE   1
#define MULTI_SERIAL 2 

#define VERTICAL 0
#define HORIZONTAL 1

typedef struct {
  unsigned int x:4;
  unsigned int y:4;
  unsigned int orientation:1;
  unsigned int size:3;
} ShipType; 

typedef struct {
  unsigned int x:4;
  unsigned int y:4;
  unsigned int type:1;
} AttackType;

struct {
  unsigned int x:4;
  unsigned int y:4;  
} cursor;

static int mode;
static int state;

static int buttonFlag;

static ShipType ships[5] = {
  {0, 0, VERTICAL, 2},
  {0, 0, VERTICAL, 3},
  {0, 0, VERTICAL, 3},
  {0, 0, VERTICAL, 4},
  {0, 0, VERTICAL, 5}
};

static unsigned char field[10][10];

static int numShips;

static AttackType enemyAttacks[100];
static int numEnemyAttacks;     

static AttackType playerAttacks[100];
static int numPlayerAttacks;  

void incState(void) {
  switch(state) {
    case WELCOME:  
      state = PICKING_MODE;
      break;
    case PICKING_MODE:
      numShips = 1;
      state = PLACING_SHIPS;
      break;  
  }
  Game_Update();
}

void Game_Init(void) {
  state = WELCOME;  
  numShips = 0;
  numEnemyAttacks = 0;
  numPlayerAttacks = 0;
  cursor.x = 0;
  cursor.y =0;
  Game_Update();
}             

void Game_Update(void) { 
  int i, j;
  
  switch(state) {
    case WELCOME:
      LCD_Clear(0);
      LCD_GoTo(4, 1);
      LCD_OutString("Welcome to Battleship");
      
      enableOC6(&incState, 62500, 72, 1);
      break;
    case PICKING_MODE:
      LCD_Clear(0);
      LCD_GoTo(2, 3);
      LCD_OutString("Single Player");
      LCD_GoTo(4, 3);
      LCD_OutString("Multiplayer XBee");
      LCD_GoTo(6, 3);
      LCD_OutString("Multiplayer Wired");
      LCD_GoTo((cursor.x+1)*2,1);
      LCD_OutChar(127);
      break;
    case PLACING_SHIPS:
      LCD_Clear(0);
      
      for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
          field[i][j] = EMPTY;      
        }
      }
      
      for(i=0; i<numShips; i++) {
        ShipType ship = ships[i];
        if(ship.orientation == HORIZONTAL) {
          field[ship.x][ship.y] = SHIPEND_LEFT;
          for(j=1; j<ship.size-1; j++) {
            field[ship.x][ship.y+j] = SHIP_HORIZ;    
          }
          field[ship.x][ship.y+ship.size-1] = SHIPEND_RIGHT;
        }
        else {
          field[ship.x][ship.y] = SHIPEND_UP;
          for(j=1; j<ship.size-1; j++) {
            field[ship.x+j][ship.y] = SHIP_VERT;    
          }
          field[ship.x+ship.size-1][ship.y] = SHIPEND_DOWN;
        }
      }
      
      for(i=0; i<numEnemyAttacks; i++) {
        AttackType attack = enemyAttacks[i];
        field[attack.x][attack.y] = attack.type;  
      }
        
      LCD_DrawGrid(field);
      break;
  }
  
  /*
    
    else {
      for(i=0; i<numPlayerAttacks; i++) {
        AttackType attack = playerAttacks[i];
        field[attack.x][attack.y] = attack.type;  
      }
    }
  */
}

int shipInBounds(int index) {
  ShipType ship = ships[index];
  
  if(ship.x < 0 || ship.x > 9 || ship.y < 0 || ship.y > 9 ||
    (ship.orientation == VERTICAL && ship.x + ship.size > 10) ||
    (ship.orientation == HORIZONTAL && ship.y + ship.size > 10)) {
      return 0;
  } 
  
  return 1;
}

int validShipPos(int index) {
  ShipType ship = ships[index];
  int i;
  
  for(i=0; i<numShips; i++) {
    if(i != index) {
      if(ship.orientation == HORIZONTAL) {
        if(ships[i].orientation == HORIZONTAL) {
          if(ship.x == ships[i].x) {
            if(ship.y + ship.size > ships[i].y ||
               ship.y < ships[i].y + ships[i].size) {
              return 0;  
            }
          }
        }
        else {
          if(ship.x >= ships[i].x && 
             ship.x < ships[i].x + ships[i].size &&
             ships[i].y >= ship.y &&
             ships[i].y < ship.y + ship.size) {
            return 0;  
          }
        }
      }
      else {
        if(ships[i].orientation == HORIZONTAL) {
          if(ship.y >= ships[i].y && 
             ship.y < ships[i].y + ships[i].size &&
             ships[i].x >= ship.x &&
             ships[i].x < ship.x + ship.size) {
            return 0;  
          }
        }
        else {
          if(ship.y == ships[i].y) {
            if(ship.x + ship.size > ships[i].x ||
               ship.x < ships[i].x + ships[i].size) {
              return 0;
            }
          }
        }
      }
    }
  }
  
  return 1;
}

void flag(void) {
  buttonFlag = 0;
}

void Game_DPad(unsigned char direction) {
  unsigned int tempX, tempY;
  if(!buttonFlag) {
    switch(state) {
      case PICKING_MODE:
        if(direction == UP) {
          cursor.x--;
        }
        else if (direction == DOWN) {
          cursor.x++;  
        }
        cursor.x %= 3;
        Game_Update();
        break;
      case PLACING_SHIPS:
        tempX = ships[numShips-1].x;
        tempY = ships[numShips-1].y;  
        
        do {
          switch(direction) {
            case UP:
              ships[numShips-1].x--;
              break;
            case DOWN:
              ships[numShips-1].x++;
              break;
            case LEFT:
              ships[numShips-1].y--;
              break;
            case RIGHT:
              ships[numShips-1].y++;
              break;
          }
        }while(!validShipPos(numShips-1) && shipInBounds(numShips-1));          
        
        if(validShipPos(numShips-1) && shipInBounds(numShips-1)) {
          Game_Update();            
        }
        else {
          ships[numShips-1].x = tempX;
          ships[numShips-1].y = tempY;
        }
        break;
    }
    
    buttonFlag = 1;  
    enableOC6(&flag, DEBOUNCE_DELAY, 8, 1);
  }
}

void Game_A(void) {
  if(!buttonFlag) {
    switch(state) {
      case PICKING_MODE:
        mode = cursor.x;
        incState();
        break;        
      case PLACING_SHIPS:
        if(numShips == 4) {
          incState();  
        }
        else {
          ShipType * ship = &ships[numShips];
          int shipFlag = 1;
          while(shipFlag && ship->orientation < 2) {
            while(shipFlag && ship->x < 10) {
              while(shipFlag && ship->y < 10) {
                if(validShipPos(numShips)) {
                  shipFlag = 0;  
                }
                if(shipFlag) {
                  ship->y++;
                }
              }               
              if(shipFlag) {
                ship->x++;
              }
            }                 
            if(shipFlag) {
              ship->orientation++;  
            }
          }
          numShips++;
          
          Game_Update();
        }
        break;
    }
    buttonFlag = 1;
    enableOC6(&flag, DEBOUNCE_DELAY, 8, 1);
  } 
  
}

void Game_B(void) {
  if(!buttonFlag) {
    switch(state) {
      case PLACING_SHIPS:
        ships[numShips-1].orientation ^= 1;
        if(validShipPos(numShips-1) && shipInBounds(numShips-1)) {
          Game_Update();          
        }
        else {
          ships[numShips-1].orientation ^= 1;
        }
        buttonFlag = 1;
        enableOC6(&flag, DEBOUNCE_DELAY, 8, 1);
        break;
    }
  } 
}