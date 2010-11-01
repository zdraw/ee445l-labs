#include "game.h"
#include "LCDG.h"

#define SINGLE_PLAYER 0
#define MULTI_PLAYER 1    

#define PLAYER_SCREEN 0
#define ENEMY_SCREEN 1 

#define VERTICAL 0
#define HORIZONTAL 1

typedef struct {
  int x;
  int y;
  int orientation;
  int size;
} ShipType; 

typedef struct {
  int x;
  int y;
  int type;
} AttackType;

static int screen;

static ShipType ships[5];
static int numShips;

static AttackType enemyAttacks[100];
static int numEnemyAttacks;     

static AttackType playerAttacks[100];
static int numPlayerAttacks;

void Game_Init(void) {
  screen = PLAYER_SCREEN;  
  numShips = 0;
  numEnemyAttacks = 0;
  numPlayerAttacks = 0;
}

void Game_UpdateShips(void) { 
  int i, j;
  static int field[10][10];
  
  for(i=0; i<10; i++) {
    for(j=0; j<10; j++) {
      field[i][j] = EMPTY;      
    }
  }
  
  if(screen == PLAYER_SCREEN) {
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
  }
  else {
    for(i=0; i<numPlayerAttacks; i++) {
      AttackType attack = playerAttacks[i];
      field[attack.x][attack.y] = attack.type;  
    }
  }
  

  LCD_DrawGrid(field);
}