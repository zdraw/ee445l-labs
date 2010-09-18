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

#include "LCD.h"
#include <stdio.h>
#include "PLL.h"
#include "OC.h"
#include "switches.h"

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

#define PROCEDURE 1

#if PROCEDURE == 1
void main(void) {  
  char buffer[10];
  unsigned long totalsecs;
  unsigned short hrs, mins, secs,error;
  //PLL_Init();       // set E clock to 8 MHz
  //TimerInit();      // enable timer0     
  OC_Init0();           
  OC_Init1();
  switchInit(); 
  LCD_Open();
  LCD_Clear();
  asm cli   // allows debugger to run
  for(;;) {
    error = LCD_ErrorCheck();
    LCD_Clear();  
    totalsecs = seconds;
    hrs = (unsigned short) (totalsecs/3600) + hours;
    mins = (unsigned short) ((totalsecs%3600)/60) + minutes;
    secs = (unsigned short) (totalsecs%60);
    if(sprintf(buffer, "%02d:%02d:%02d", hrs,mins,secs)) {
      LCD_OutString(buffer);
      if((alarmSet || PTP & 0x40) && 
        sprintf(buffer, "   %02d:%02d", alarmHours, alarmMinutes))
        LCD_GoTo(1,0);
        LCD_OutString(buffer);
    }
    //LCD_GoTo(0,0); 
    while(totalsecs == seconds) {};
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