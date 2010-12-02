#ifndef GAME_H
#define GAME_H

#define HIT           0
#define MISS          1
#define SHIPEND_UP    2
#define SHIPEND_DOWN  3
#define SHIPEND_LEFT  4
#define SHIPEND_RIGHT 5
#define SHIP_VERT     6
#define SHIP_HORIZ    7
#define EMPTY         8

#define WELCOME               0
#define PICKING_MODE          1
#define WAITING_FOR_OPPONENT  2
#define OPPONENT_SHIPS        3
#define PLACING_SHIPS         4
#define PLAYER_TURN_WAITING   5
#define PLAYER_TURN_DONE      6
#define COMPUTER_SCREEN       7
#define OPPONENT_TURN_WAITING 8
#define OPPONENT_TURN_DONE    9
#define WIN                  10
#define LOSE                 11

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

typedef struct {
  unsigned int x:4;
  unsigned int y:4;  
} CursorType;

void Game_Init(void);
void Game_Update(void);

void Game_DPad(unsigned char direction);
void Game_A(void);
void Game_B(void);

CursorType Game_GetCursor(void);
int Game_GetState(void);

#endif