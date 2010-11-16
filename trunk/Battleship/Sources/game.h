#ifndef GAME_H
#define GAME_H

#define EMPTY         0
#define SHIPEND_UP    1
#define SHIPEND_DOWN  2
#define SHIPEND_LEFT  3
#define SHIPEND_RIGHT 4
#define SHIP_VERT     5
#define SHIP_HORIZ    6
#define HIT           7
#define MISS          8

#define WELCOME       0
#define PICKING_MODE  1
#define PLACING_SHIPS 2

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

void Game_Init(void);
void Game_Update(void);


void Game_DPad(unsigned char direction);
void Game_A(void);
void Game_B(void);

#endif