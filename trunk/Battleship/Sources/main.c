/* ************************ Main.c *****************************
 * AGM1264 example
 * ************************************************************ */
 
// 9S12DP512
// Jonathan W. Valvano 11/20/09 

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 

// Input on PAD4, from slide pot connected to to +5 and ground
// heartbeats, PP7 every 3000, PP5 at sampling rate

// AGM1264 graphics interface
// gnd    =  1- AGM1264F ground
// +5V    =  2- AGM1264F Vcc (with 0.1uF cap to ground)
// pot    =  3- AGM1264F Vo (center pin of 10k pot)
// PP2    =  4- AGM1264F D/I (0 for command, 1 for data)
// gnd    =  5- AGM1264F R/W (blind cycle synchronization)
// PP3    =  6- AGM1264F E   (1 to latch in data/command)
// PH0    =  7- AGM1264F DB0
// PH1    =  8- AGM1264F DB1
// PH2    =  9- AGM1264F DB2
// PH3    = 10- AGM1264F DB3
// PH4    = 11- AGM1264F DB4
// PH5    = 12- AGM1264F DB5
// PH6    = 13- AGM1264F DB6
// PH7    = 14- AGM1264F DB7
// PP0    = 15- AGM1264F CS1 (controls left half of LCD)
// PP1    = 16- AGM1264F CS2 (controls right half of LCD)
// +5V    = 17- AGM1264F RES (reset)
// pot    = 18- ADM1264F Vee (-10V)
// 10k pot from pin 18 to ground, with center to pin 3
// references   http://www.azdisplays.com/prod/g1264f.php
// sample code  http://www.azdisplays.com/PDF/agm1264f_code.pdf
// data sheet   http://www.azdisplays.com/PDF/agm1264f.pdf


// TCNT will become 1.5 MHz, calling LCD_Init, which calls Timer_Init

#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "PLL.h"
#include "adc.h"
#include "LCDG.h"
#include "Timer.h"

unsigned short ADCsample;	// ADC sample, 0 to 1023
unsigned short Voltage;   // 0.01 volts, 0 to 500
unsigned short ADCcount;  // 0 to 2999
unsigned short StartTime; // in seconds
void main(void) {  
  PLL_Init();
  LCD_Init();   // TCNT at 1.5 MHz
  ADC_Init();   // Activate ADC 
  DDRP |= 0xA0; // heartbeats, PP7 every 3000, PP5 at sampling rate
  EnableInterrupts;

  LCD_Test();  // to run this, set TEST=1 inside LCDG.c, single step through
  LCD_Clear(0);

  LCD_OutString("Jonathan Valvano"); 
  LCD_PlotYaxis(0, 25, 50, 1, "Voltage");
  LCD_PlotClear(0, 500, 30); //30*100=3000 points/sweep
  StartTime = 0; ADCcount = 0;
  LCD_PlotXaxis(StartTime, StartTime+3, 0, "Time (sec)");
  LCD_GoTo(8,1);
  LCD_OutFix2(0);
  LCD_OutString(" volts"); 
  for(;;) {
    Timer_Wait1ms(1);          // very inaccurate time, should use interrupts
    ADCsample = ADC_In(0x84);	 // right justified channel 4
    PTP ^= 0x20;               // heartbeat
  asm ldd  ADCsample
  asm ldy  #500
  asm emul        // 32-bit Y:D is 500*ADCsample
  asm ldx  #1023
  asm ediv        // 16-bit Y is (500*ADCsample)/1023
  asm sty  Voltage
    LCD_Plot(Voltage);
    ADCcount++;             // 0 to 2999
    if(ADCcount == 3000){   // end of sweep??
      PTP ^= 0x80;          // heartbeat after 3000 samples
      StartTime = StartTime+3;
      if(StartTime>900) StartTime=0;
      LCD_PlotXaxis(StartTime, StartTime+3, 0, "Time (sec)");
      LCD_GoTo(8,1);
      LCD_OutFix2(Voltage);
      ADCcount = 0;
    }
  } 
}
