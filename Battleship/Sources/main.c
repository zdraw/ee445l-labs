#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "PLL.h"
#include "adc.h"
#include "LCDG.h"
#include "Timer.h"
#include "Game.h"
#include "switch.h"

unsigned short ADCsample;	// ADC sample, 0 to 1023
unsigned short Voltage;   // 0.01 volts, 0 to 500
unsigned short ADCcount;  // 0 to 2999
unsigned short StartTime; // in seconds
void main(void) {  
  PLL_Init();
  LCD_Init();   // TCNT at 1.5 MHz
  ADC_Init();   // Activate ADC 
  DDRP |= 0xA0; // heartbeats, PP7 every 3000, PP5 at sampling rate
  PTP |= 0x80;
  EnableInterrupts; 
  Key_Init();
  Game_Init();
  
  
  //enableOC6(&whee, 60000, 25, 5);
  
  for(;;) {
      
  } 
}
