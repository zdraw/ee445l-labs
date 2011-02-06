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
#define WAITING_FOR_OPPONENT  1
#define PLACING_SHIPS         2
#define PLAYER_TURN_WAITING   3
#define PLAYER_TURN_DONE      4
#define COMPUTER_SCREEN       5
#define OPPONENT_TURN_WAITING 6
#define OPPONENT_TURN_DONE    7
#define WIN                   8
#define LOSE                  9

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