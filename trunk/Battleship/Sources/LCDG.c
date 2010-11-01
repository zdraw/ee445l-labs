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
#define E PTP_PTP3
#define DI PTP_PTP2
#define CS2 PTP_PTP1
#define CS1 PTP_PTP0

// assuming TCNT is 1.5 MHz
#define T1usec 2
#define T4usec 6

// if 1, includes LCD test examples
// use 0 for more space efficient code
#define TEST 0

// digits are drawn at the top of the byte
const unsigned char TinyFont[10*3]={  // 3 wide by 5 tall
  14,17,14,   // 0
  18,31,16,   // 1
  25,21,23,   // 2
  17,21,31,   // 3
  7,4,31,     // 4
  23,21,9,    // 5
  31,21,28,   // 6
  1,1,31,     // 7
  31,21,31,   // 8
  7,21,31     // 9
};

// digits are drawn one pixel from the top 
const unsigned char TinyFont1[10*3]={  // 3 wide by 5 tall
  2*14,2*17,2*14,   // 0
  2*18,2*31,2*16,   // 1
  2*25,2*21,2*23,   // 2
  2*17,2*21,2*31,   // 3
  2*7,2*4,2*31,     // 4
  2*23,2*21,2*9,    // 5
  2*31,2*21,2*28,   // 6
  2*1,2*1,2*31,     // 7
  2*31,2*21,2*31,   // 8
  2*7,2*21,2*31     // 9
};
// two pixels from the top or one pixel from bottom 
const unsigned char TinyFont2[10*3]={  // 3 wide by 5 tall
  4*14,4*17,4*14,   // 0
  4*18,4*31,4*16,   // 1
  4*25,4*21,4*23,   // 2
  4*17,4*21,4*31,   // 3
  4*7,4*4,4*31,     // 4
  4*23,4*21,4*9,    // 5
  4*31,4*21,4*28,   // 6
  4*1,4*1,4*31,     // 7
  4*31,4*21,4*31,   // 8
  4*7,4*21,4*31     // 9
};
// three pixels from the top or at the bottom 
const unsigned char TinyFont3[10*3]={  // 3 wide by 5 tall
  8*14,8*17,8*14,   // 0
  8*18,8*31,8*16,   // 1
  8*25,8*21,8*23,   // 2
  8*17,8*21,8*31,   // 3
  8*7,8*4,8*31,     // 4
  8*23,8*21,8*9,    // 5
  8*31,8*21,8*28,   // 6
  8*1,8*1,8*31,     // 7
  8*31,8*21,8*31,   // 8
  8*7,8*21,8*31     // 9
};
// 5 wide by 7 tall font
const unsigned char Font[96*5]={   // no numbers with bit7=1
  0,0,0,0,0,           // 32  space
  0,0,95,0,0,          // 33  !
  0,7,0,7,0,           // 34  "
  20,127,20,127,20,    // 35  #
  36,42,127,42,18,     // 36  $
  35,19,8,100,98,      // 37  %
  54,73,85,34,80,      // 38  &
  0,5,3,0,0,           // 39  quote
  0,28,34,65,0,        // 40  (
  0,65,34,28,0,        // 41  )
  20,8,62,8,20,        // 42  *
  8,8,62,8,8,          // 43  plus
  0,80,48,0,0,         // 44  ,
  8,8,8,8,8,           // 45  minus
  0,112,112,112,0,     // 46  .
  32,16,8,4,2,         // 47  /
  62,81,73,69,62,      // 48  0
  0,66,127,64,0,       // 49  1
  66,97,81,73,70,      // 50  2
  33,65,69,75,49,      // 51  3
  24,20,18,127,16,     // 52  4
  39,69,69,69,57,      // 53  5
  60,74,73,73,48,      // 54  6
  3,1,113,9,7,         // 55  7
  54,73,73,73,54,      // 56  8
  6,73,73,41,30,       // 57  9
  0,54,54,0,0,         // 58  :
  0,86,54,0,0,         // 59  ;
  8,20,34,65,0,        // 60  <
  20,20,20,20,20,      // 61  equals
  65,34,20,8,0,        // 62  >
  2,1,81,9,6,          // 63  ?
  50,73,121,65,62,     // 64  @
  126,17,17,17,126,    // 65  A
  127,73,73,73,54,     // 66  B
  62,65,65,65,34,      // 67  C
  127,65,65,65,62,     // 68  D
  127,73,73,73,65,     // 69  E
  127,9,9,9,1,         // 70  F
  62,65,73,73,122,     // 71  G
  127,8,8,8,127,       // 72  H
  65,65,127,65,65,     // 73  I
  32,64,65,63,1,       // 74  J
  127,8,20,34,65,      // 75  K
  127,64,64,64,64,     // 76  L
  127,2,12,2,127,      // 77  M
  127,6,24,96,127,     // 78  N
  62,65,65,65,62,      // 79  O
  127,9,9,9,6,         // 80  P
  62,65,81,33,94,      // 81  Q
  127,9,25,41,70,      // 82  R
  70,73,73,73,49,      // 83  S
  1,1,127,1,1,         // 84  T
  63,64,64,64,63,      // 85  U
  31,32,64,32,31,      // 86  V
  63,64,56,64,63,      // 87  W
  99,20,8,20,99,       // 88  X
  7,8,112,8,7,         // 89  Y
  97,81,73,69,67,      // 90  Z
  0,127,65,65,0,       // 91  [
  2,4,8,16,32,         // 92  back slash
  0,65,65,127,0,       // 93  ]
  4,2,1,2,4,           // 94  ^
  64,64,64,64,64,      // 95  _
  0,1,2,4,0,           // 96  quote
  32,84,84,84,120,     // 97  a
  127,72,68,68,56,     // 98  b
  56,68,68,68,32,      // 99  c
  56,68,68,72,127,     // 100  d
  56,84,84,84,24,      // 101  e
  8,126,9,1,2,         // 102  f
  8,84,84,84,60,       // 103  g   
  127,8,4,4,120,       // 104  h
  0,72,125,64,0,       // 105  i
  32,64,68,61,0,       // 106  j  
  127,16,40,68,0,      // 107  k
  0,65,127,64,0,       // 108  l
  124,4,24,4,120,      // 109  m
  124,8,4,4,120,       // 110  n
  56,68,68,68,56,      // 111  o
  124,20,20,20,8,      // 112  p      
  12,18,18,20,126,     // 113  q   
  124,8,4,4,8,         // 114  r
  72,84,84,84,36,      // 115  s
  4,63,68,64,32,       // 116  t
  60,64,64,32,124,     // 117  u
  28,32,64,32,28,      // 118  v
  60,64,48,64,60,      // 119  w
  68,40,16,40,68,      // 120  x
  12,80,80,80,60,      // 121  y    
  68,100,84,76,68,     // 122  z
  0,65,54,8,0,         // 123  }
  0,0,127,0,0,         // 124  |
  0,8,54,65,0,         // 125  {
  8,4,8,16,8,          // 126  ~
  31,36,124,36,31      // 127  UT sign
};



static unsigned short OpenFlag=0;
unsigned char Column1; // column position
unsigned char bLeft1;  // to be placed into CS1, in LCD_OutChar
unsigned char bRight1; // to be placed into CS2, in LCD_OutChar
unsigned char Page;
unsigned char bDown;    // true if want font shifted down
unsigned char TinyDown; // 0 no shift, 1,2,3 shift down 
unsigned char Xcolumn;  // byte number 56-7F on left, 40-79 on right
unsigned char bRightx;  // to be placed into CS2
unsigned char bLeftx;   // to be placed into CS1
unsigned char PlotPixel; 
// number of data points drawn into the same X-axis pixel
// 4 means it takes 400 calls to LCD_Plot to draw one sweep
unsigned short SubCount; // goes PlotPixel down to 1
 
unsigned short XaxisResolution;
// X axis numbers are  0 to 999
// resolution>3 means no numbers are displayed
// number->       0    9    99   999
// 0  shown as   0.    9.   99.  999.
// 1  shown as  0.0   0.9   9.9  99.9
// 2  shown as 0.00  0.09  0.99  9.99
// 3  shown as .000  .009  .099  .999

unsigned short YaxisResolution;
// Y axis numbers are  -99 to 99
// any other value means no numbers are displayed
// 0  shown as -99     -1    0   1   99
// 1  shown as -9.9  -0.1  0.0 0.1  9.9
// 2  shown as -.99  -.01  .00 .01  .99
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
  PTH = instruction;
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
  PTH = data;
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
  Column1 = 0x41;  // column position
  bLeft1 = 1;
  bRight1 = 0;
  Page = 0xB8;
  bDown = 0;    // true if want font shifted down
  TinyDown = 0; // 0 no shift, 1,2,3 shift down 
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


//-----------------------LCD_GoTo-----------------------
// Move cursor
// Input: line number is 1 to 8, column from 1 to 21 
// Output: none
// errors: it will ignore legal addresses
void LCD_GoTo(int line, int column){
  if(OpenFlag==0){
    return;  // not open
  }
  if((line<1) || (line>8)) return;
  if((column<1) || (column>21)) return;
  if(line<5){
    bDown = 0;             // normal position on lines 1,2,3,4
  } else{
    bDown = 0xFF;          // shifted down on lines 5,6,7,8
  }
  Page = 0xB8+line-1;      // 0xB8 to 0xBF
  if(column<12){
    Column1 = 59+6*column; // 0x41+6*(column-1);
    bLeft1 = 1;  
    bRight1 = 0;           // on left side
  } else{
    Column1 = 6*column-5;  // 0x43+6*(column-12);
    bLeft1 = 0;  
    bRight1 = 1;           // on right side
  }
}


#define EMPTY         0
#define SHIPEND_UP    1
#define SHIPEND_DOWN  2
#define SHIPEND_LEFT  3
#define SHIPEND_RIGHT 4
#define SHIP_VERT     5
#define SHIP_HORIZ    6
#define HIT           7
#define MISS          8

unsigned volatile int field[10][10]; 
unsigned static char grid[8][61]; 



void setGridPixel(int row, int col, int x, int y) {
  grid[((row*6)+x)/8][(col*6)+y] |= 1 << (((row*6)+x)%8);    
}

void LCD_DrawGrid(void) { 
  int i, j;
  
  for(i=0; i<10; i++) {
    for(j=0; j<10; j++) {
      field[i][j] = EMPTY;      
    }
  }
  
  field[0][0] = SHIPEND_LEFT;
  field[0][1] = SHIP_HORIZ;
  field[0][2] = SHIP_HORIZ;  
  field[0][3] = SHIPEND_RIGHT;
  
  field[5][0] = SHIPEND_UP;
  field[6][0] = SHIP_VERT;
  field[7][0] = SHIP_VERT;
  field[8][0] = SHIP_VERT;
  field[9][0] = SHIPEND_DOWN;
  
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
            
      /*for(k=0; k < 6; k++) {
        grid[((i*6)+k)/8][j*6] |= 1 << (((i*6)+k)%8);
        grid[(i*6)/8][(j*6)+k] |= 1 << ((i*6)%8);
        
      }*/
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
        case MISS:
          setGridPixel(i, j, 1, 3);
          setGridPixel(i, j, 2, 2);
          setGridPixel(i, j, 2, 3);
          setGridPixel(i, j, 2, 4);
          setGridPixel(i, j, 3, 1);
          setGridPixel(i, j, 3, 2);
          setGridPixel(i, j, 3, 3);
          setGridPixel(i, j, 3, 4);
          setGridPixel(i, j, 3, 5);
          setGridPixel(i, j, 4, 2);
          setGridPixel(i, j, 4, 3);
          setGridPixel(i, j, 4, 4);
          setGridPixel(i, j, 5, 3);
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