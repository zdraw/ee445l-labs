#include "defs.h"

#include "PLL.h"
#include "LCDG.h"
#include "Timer.h"
#include "Game.h"
#include "switch.h"
#include "music.h"

void main(void) { 
  PLL_Init();
  LCD_Init();   // TCNT at 1.5 MHz
  Timer_Init();
  DDRP |= 0xA0; // heartbeats, PP7 every 3000, PP5 at sampling rate 
  Key_Init();
  DAC_Init();
  Music_InitOC7();
  asm cli
  Game_Init();
  
  //enableOC6(&whee, 60000, 25, 5);
  
  for(;;) {
  } 
}
