#include "defs.h"

#include "PLL.h"
#include "LCDG.h"
#include "Timer.h"
#include "Game.h"
#include "switch.h"
#include "music.h"
#include "SCI.h"
#include "Xbee.h"
#include "Fifo.h"

void main(void) {
  LED_DDR0 = 1;
  LED_DDR1 = 1;
  LED_DDR2 = 1;
  LED_DDR3 = 1;
  LED_DDR4 = 1;
  LED_DDR5 = 1;
  
  LED0 = 1;
  LED1 = 1;
  LED2 = 1;
  LED3 = 1;
  LED4 = 1;
  LED5 = 1;  
  PLL_Init();
  //LCD_Init();   // TCNT at 1.5 MHz
  Timer_Init();
  DDRP |= 0xA0; // heartbeats, PP7 every 3000, PP5 at sampling rate 
  //Key_Init();
  //DAC_Init();
  //Music_InitOC7();
  Fifo_Init();
  SCI_Init(9600*8);
  SCI_OutChar('U');
  asm cli
  //XBee_Init();
  //Game_Init();
  
  //enableOC6(&whee, 60000, 25, 5);
  
  for(;;) {
    //Game_Update();
  } 
}
