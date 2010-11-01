//*****************LCDG.c***************************************
// implementation of the driver for the AGM1264F MODULE
// Jonathan W. Valvano 11/20/09 

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//         Engineering, copyright (c) 2006,
//   "Introduction to Embedded Microcomputer Systems: 
//    Motorola 6811 and 6812 Simulation", Thomson, copyright (c) 2002

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 

// Hardware:
// gnd    =  1- AGM1264F ground
// +5V    =  2- AGM1264F Vcc (with 0.1uF cap to ground)
// pot    =  3- AGM1264F Vo  (center pin of 10k pot)
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

// BUG NOTICE 11/11/09 -Valvano
// When changing from right to left or from left to right
//   the first write with data=0 goes to two places
// One can reduce the effect of this bug by
// 1) Changing sides less often
// 2) Ignore autoincrement, and set column and page address each time
// 3) Blanking the screen then write 1's to the screen
// GoTo bug fixed on 11/20/09

//******************************************************************
#include <mc9s12dp512.h>     /* derivative information */
#include "Timer.h"
#include "game.h"

#define E PTP_PTP3
#define DI PTP_PTP2
#define CS2 PTP_PTP1
#define CS1 PTP_PTP0
#define DATA PTH

// assuming TCNT is 1.5 MHz
#define T1usec 2
#define T4usec 6

static unsigned short OpenFlag=0;
short MinY,RangeY;        // used to scale input data

// ********* lcdCmd***********
// Output command to AGM1264F 128-bit by 64-bit graphics display
// Inputs: 8-bit instruction
// Outputs: none
void lcdCmd(unsigned char instruction){
  // R/W=0, write mode  default, R/W=0 always
  // normally D/I will be left at D/I=1 for data
  DI = 0;        // D/I=0, COMMAND WRITE
  Timer_Wait(T1usec);
  E = 1;         // E pulse width > 450ns
  DATA = instruction;
  Timer_Wait(T1usec);
  E = 0;         // falling edge latch, setup time 200ns
  DI = 1;        // D/I=1 default state is data
  Timer_Wait(T4usec);
} 

// ********* lcdData***********
// Output data to AGM1264F 128-bit by 64-bit graphics display
// Inputs: 8-bit data
// Outputs: none
void lcdData(unsigned char data){
  // R/W=0, write mode  default, R/W=0 always
  // normally D/I will be left at D/I=1 for data
  E = 1;         // E pulse width > 450ns
  DATA = data;
  Timer_Wait(T1usec);
  E = 0;         // falling edge latch, setup time 200ns
  Timer_Wait(T4usec);
}    

// ********* LCD_Init***********
// Initialize AGM1264F 128-bit by 64-bit graphics display
// activates TCNT at 1.5 MHz, assumes PLL active
// Input: none                                      
// Output: none
// does not clear the display
void LCD_Init(void){
  Timer_Init();   // TCNT at 1.5 MHz
  DDRH = 0xFF;    // PH7-PH0 outputs to DB7-DB0, PT3=E
  DDRP |= 0x0F;   // PP3-PP0 outputs to E,DI,CS1,CS2
  CS2 = 1;         // talk to both LCD controllers
  CS1 = 1;
  DI = 1;          // default mode is data 
  E = 0;           // inactive
  Timer_Wait1ms(100); // let it warm up
  lcdCmd(0x3F);    // display=ON
  lcdCmd(0xB8);    // Page address (0 to 7) is 0
  lcdCmd(0x40);    // Column address (0 to 63) is 0
  lcdCmd(0xC0);    // Y=0 is at top
  OpenFlag = 1;    // device open
}


// ********* LCD_Clear***********
// Clear the entire 1024 byte (8192 bit) image on the
//    AGM1264F 128-bit by 64-bit graphics display
// Input: value to write into all bytes of display RAM
// Output: none
// e.g., LCD_Clear(0);  // makes all pixels off
void LCD_Clear(unsigned char data){
unsigned char page;
  int i;
  if(OpenFlag == 0) return;
  for(page = 0xB8; page< 0xB8+8; page++){ // pages 0 to 7
    CS2 = 1;          // right enable
    CS1 = 0;         
    lcdCmd(page);    // Page address (0 to 7) 
    lcdCmd(0x40);    // Column = 0
    for(i=64; i>0; i--){
      lcdData(data);   // copy one byte to right side
    }
    CS2 = 0;          
    CS1 = 1;         // left enable
    lcdCmd(page);    // Page address (0 to 7) 
    lcdCmd(0x40);    // Column = 0
    for(i=64; i>0; i--){
      lcdData(data);   // copy one byte to left side
    }
  }
}

// page   is 0xB8 to 0xBF for pages 0 to 7
// column is 0x40 to 0x7F for columns 0 to 63
void OutByte(unsigned char page, unsigned char column,unsigned char data){
  lcdCmd(page);    // Page address (0 to 7) 
  lcdCmd(column);  // Column = 0 to 63
  lcdData(data);   // data
}

unsigned static char grid[8][61];  

void setGridPixel(int row, int col, int x, int y) {
  grid[((row*6)+x)/8][(col*6)+y] |= 1 << (((row*6)+x)%8);    
}

void LCD_DrawGrid(int field[10][10]) { 
  int i, j;
  
  //PTP |= 0x80;
  
        
  for(j=0; j<61; j++) {
    grid[0][j] = 0x41;
    grid[1][j] = 0x10;
    grid[2][j] = 0x04;
    grid[3][j] = 0x41;
    grid[4][j] = 0x10;
    grid[5][j] = 0x04;
    grid[6][j] = 0x41;
    grid[7][j] = 0x10;
    
    if(!(j%6)) {
      for(i=0; i<7; i++) {
        grid[i][j] = 0xFF;
      }
      grid[7][j] = 0x1F;
    }
  }
  
  for(i=0; i<10; i++) {
    for(j=0; j<10; j++) {
      switch(field[i][j]) {
        case SHIPEND_UP:
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 5, 2);
          setGridPixel(i, j, 5, 3);
          setGridPixel(i, j, 5, 4);
          break;
        case SHIPEND_DOWN: 
          setGridPixel(i, j, 1, 2);
          setGridPixel(i, j, 1, 3);
          setGridPixel(i, j, 1, 4);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 4, 3);
          break;
        case SHIPEND_LEFT: 
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 2, 5);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 3, 5);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 4, 5);
          break;
        case SHIPEND_RIGHT:
          setGridPixel(i, j, 2, 1);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 3, 1);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 4, 1);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          break;
        case SHIP_VERT:
          setGridPixel(i, j, 1, 2);
          setGridPixel(i, j, 1, 3);
          setGridPixel(i, j, 1, 4);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 5, 2);
          setGridPixel(i, j, 5, 3);
          setGridPixel(i, j, 5, 4);
          break;
        case SHIP_HORIZ: 
          setGridPixel(i, j, 2, 1);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 2, 5);
          setGridPixel(i, j, 3, 1);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 3, 5);
          setGridPixel(i, j, 4, 1);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 4, 5);
          break;
        case HIT:  
          setGridPixel(i, j, 1, 3);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 3, 1);
          setGridPixel(i, j, 3, 2);      
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 3, 5);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 5, 3);
          break;
        case MISS:
          setGridPixel(i, j, 1, 1);
          setGridPixel(i, j, 1, 5);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 5, 1);
          setGridPixel(i, j, 5, 5);
          break;
        default:
          PTP |= 0x80;
          break;
      }
    }
  }
  
  CS1 = 0;
  CS2 = 1;  
  
  for(i=0; i<8; i++) {
    for(j=0; j<61; j++) {
      OutByte(i+0xB8, j+0x40, grid[i][j]);
    }
  }
  
}