/*
  Initiating ADC Conversion:
    1. Writing to ATD0CTL5
    2. Edge on external trigger
    3. Level on external trigger
  
  Completed Conversion
    1. Reading ATD0STAT1
    2. Interrupt when complete
*/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
              
#include "PLL.h"
#include "lcd.h"
#include "Timer.h"
#include <stdio.h>

#include "SCI1.h"
#include "Fifo.h"
#include "Xbee.h"

volatile char whee;

void main(void) {
  int i;
  DDRP |= 0x80;
  PLL_Init(); // 24 MHz 
  Timer_Init();
  LCD_Open();
  Fifo_Init();
  SCI1_Init(9600); // SCI output to PC
     
  asm cli;
  
    LCD_Clear();
  
  XBee_Init();
  Timer_Wait10ms(100);
  for(;;) {
    long blah;
    FrameType frame;
    Fifo_Init();
    while(!XBee_RecieveTxFrame(&frame));
    
    LCD_Clear();
    for(i=5; i<frame.length; i++) {
      LCD_OutChar(frame.data[i]);    
    }
    Fifo_Init();
    PTP ^= 0x80;
  }
}