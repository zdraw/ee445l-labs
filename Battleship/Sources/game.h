

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
#define PLACING_SHIPS 1

void Game_Init(void);
void Game_Update(void);


void Game_Up(void);
void Game_Down(void);
void Game_Left(void);
void Game_Right(void);
void Game_A(void);
void Game_B(void);