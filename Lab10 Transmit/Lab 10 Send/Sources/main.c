// filename ******** main.C ************** 
// Test of virtual SCI port   
// Technological Arts MC9S12DP512 board

// 9S12DP512 PT2 is RxD (input to 9S12DP512) 
// 9S12DP512 PT3 is TxD (output from 9S12DP512)
// 9S12DP512 channel 4 output compare interrupt used 
// baud rate can be from 1000 to 50000 bits/sec
// 1 start bit, 8 bit data, 1 stop
// Jonathan W. Valvano 10/25/09

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//        Thompson, copyright (c) 2006,
//   "Introduction to Embedded Systems: Interfacing to the Freescale 9S12",
//        Cengage Publishing 2009, ISBN-10: 049541137X | ISBN-13: 9780495411376

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "SCIb.H"
#include "PLL.H"
#include "lcd.h"
#include "Timer.H"
#include "XBee.h"
#include "SCI1.h"


unsigned short num;
unsigned char Letter;
void main(void) {
  PLL_Init();         // running at 24MHz
  SCIb_Init(9600);    // SCIb initialization
  SCI1_Init(115200);
  XBee_Init();
  DDRP_DDRP7 = 1;
  for(;;) {
    unsigned char buffer[95] = {0};
    FrameType frame;
    PTP_PTP7 = 1;
    SCI1_InString(buffer,95);
    do{
      //SCI1_OutString(frame.data);
    //  SCI1_OutString(buffer);
      frame=XBee_CreateTxFrameType(buffer);
      PTP_PTP7 ^= 1;
      XBee_SendTxFrameType(frame);
    }while(!XBee_TxStatus());
  }
 /*
  SCIb_OutString("Jonathan Valvano 10/25/09");
  for(;;) {
    SCIb_OutChar(CR);   SCIb_OutChar(LF); 
    SCIb_OutString("Decimal ");
    num = SCIb_InUDec();
    SCIb_OutUDec(num);
    SCIb_OutChar(CR);   SCIb_OutChar(LF); 
    SCIb_OutString("Hex ");
    num = SCIb_InUHex();
    SCIb_OutUHex(num);
  } 
  */
}
