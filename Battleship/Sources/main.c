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
#include "Game.h"

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

  LCD_Clear(0);
  Game_UpdateShips();
  
  for(;;) {
      
  } 
}
