// filename ******** Main.C ************** 
// LCD Display (HD44780) on Port H for the 9S12DP512   
// Jonathan W. Valvano 9/18/09
// TCNT runs at 667ns,

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//        Thompson, copyright (c) 2006,
//   "Introduction to Embedded Systems: Interfacing to the Freescale 9S12",
//        Cengage Publishing 2009, ISBN-10: 049541137X | ISBN-13: 9780495411376

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 
// Purpose: test program for 4-bit LCD.C driver

/*   
  size is 1*16 
  if do not need to read busy, then you can tie R/W=ground 
  ground = pin 1    Vss
  power  = pin 2    Vdd   +5V
  ground = pin 3    Vlc   grounded for highest contrast
  PH4    = pin 4    RS    (1 for data, 0 for control/status)
  PH5    = pin 5    R/W   (1 for read, 0 for write)
  PH6    = pin 6    E     (enable)
  PH3    = pin 14   DB7   (4-bit data)
  PH2    = pin 13   DB6
  PH1    = pin 12   DB5
  PH0    = pin 11   DB4
16 characters are configured as 2 rows of 8
addr  00 01 02 03 04 05 06 07 40 41 42 43 44 45 46 47
*/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "LCD.H"
#include <stdio.h>
#include "PLL.H"

//---------------------mwait---------------------
// wait specified number of msec
// Input: number of msec to wait
// Output: none
// assumes TCNT timer is running at 667ns
void mwait(unsigned short msec){ 
unsigned short startTime;
  for(; msec>0; msec--){
    startTime = TCNT;
    while((TCNT-startTime) <= 63){} 
  }
}

unsigned short static volatile seconds;
interrupt 8 void TOC0handler(void){ // executes at 100 Hz 
  TFLG1 = 0x01;         // acknowledge OC0
  seconds++;
  TC0 = TC0+62500;      // 1 s
  PTP ^= 0x80;          // debugging monitor
}

//---------------------OC_Init0---------------------
// arm output compare 0 for 100Hz periodic interrupt
// Input: none
// Output: none 
void OC_Init0(){
  seconds = 0;     // debugging monitor
  DDRP |= 0x80;   // debugging monitor
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x07;   // divide by 8 TCNT prescale, TOI disarm
  PACTL = 0;      // timer prescale used for TCNT
/* Bottom three bits of TSCR2 (PR2,PR1,PR0) set TCNT period
    divide  FastMode(24MHz)    Slow Mode (8MHz)
000   1     42ns  TOF  2.73ms  125ns TOF  8.192ms
001   2     84ns  TOF  5.46ms  250ns TOF 16.384ms 
010   4    167ns  TOF  10.9ms  500ns TOF 32.768ms     
011   8    333ns  TOF  21.8ms    1us TOF 65.536ms
100  16    667ns  TOF  43.7ms    2us TOF 131.072ms
101  32   1.33us  TOF  87.4ms    4us TOF 262.144ms
110  64   2.67us  TOF 174.8ms    8us TOF 524.288ms
111 128   5.33us  TOF 349.5ms   16us TOF 1.048576s*/
  TC0   = TCNT+50; // first interrupt right away
}

#define PROCEDURE 2

#if PROCEDURE == 1
void main(void) {  
  char buffer[10];
  unsigned short totalsecs, hrs, mins, secs, initsecs = 32390,error;
  //PLL_Init();       // set E clock to 24 MHz
  //TimerInit();      // enable timer0     
  OC_Init0();           
  //OC_Init3();
  LCD_Open();
  LCD_Clear();
  asm cli   // allows debugger to run
  for(;;) {
    error = LCD_ErrorCheck();
    LCD_Clear();  
    totalsecs = seconds + initsecs;
    hrs = totalsecs / 3600;
    mins = (totalsecs - hrs*3600)/60;
    secs = totalsecs - hrs*3600 - mins*60;
    sprintf(buffer, "%02d:%02d:%02d", hrs,mins,secs);
    //LCD_GoTo(0,0);
    LCD_OutString(buffer); 
    while(totalsecs - initsecs == seconds) {};
  } 
}
#endif

#if PROCEDURE == 2

void main(void) {  
  unsigned short error; 
  OC_Init0(); 
  LCD_Open();
  LCD_Clear();
  asm cli   // allows debugger to run
  for(;;) {   
    error = LCD_ErrorCheck();
    LCD_OutString("ABCDEFGH"); 
    LCD_GoTo(1,0);
    LCD_OutString("IJKLMNOP");
    mwait(2000);  
    LCD_Clear();
    LCD_OutString("01234567");
    LCD_GoTo(1,0);
    LCD_OutString("890,./<>");
    mwait(2000);   
    LCD_Clear();
    LCD_OutString("abcdefgh");
    LCD_GoTo(1,0);
    LCD_OutString("ijklmnop");
    mwait(2000);  
    LCD_Clear();
    LCD_OutString("!@#$%^&*");
    LCD_GoTo(1,0);
    LCD_OutString("()_+-=[]");
    mwait(2000);  
    LCD_Clear();
  } 
}
#endif