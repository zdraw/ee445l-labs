#include "defs.h"

#include "PLL.h"
#include "LCDG.h"
#include "Timer.h"
#include "Game.h"
#include "switch.h"

void main(void) {  
  PLL_Init();
  LCD_Init();   // TCNT at 1.5 MHz
  DDRP |= 0xA0; // heartbeats, PP7 every 3000, PP5 at sampling rate
  PTP |= 0x80;
  EnableInterrupts; 
  Key_Init();
  Game_Init();
  
  
  //enableOC6(&whee, 60000, 25, 5);
  
  for(;;) {
      
  } 
}
