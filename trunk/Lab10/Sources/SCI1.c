// filename  ***************  SCI1.C ****************************** 
// Simple I/O routines to 9S12DP512 serial port   
// Jonathan W. Valvano 8/10/09

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//        Thompson, copyright (c) 2006,
//   "Introduction to Embedded Systems: Interfacing to the Freescale 9S12",
//        Cengage Publishing 2009, ISBN-10: 049541137X | ISBN-13: 9780495411376

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 
// Modified by EE345L students Charlie Gough && Matt Hawk
// Modified by EE345M students Agustinus Darmawan + Mingjie Qiu
 
#include <mc9s12dp512.h>     /* derivative information */
#include "SCI1.h"
#include "FIFO.h"
#define RDRF 0x20   // Receive Data Register Full Bit
#define TDRE 0x80   // Transmit Data Register Empty Bit

//-------------------------SCI1_Init------------------------
// Initialize Serial port SCI1
// Input: baudRate is tha baud rate in bits/sec
// Output: none
// assumes a module clock frequency of 24 MHz
void SCI1_Init(unsigned long baudRate){
unsigned long br;
  SCI1BDH = 0;   
  br=(1500000+baudRate/2)/baudRate; // MCLK/(16*baudRate) 
  SCI1BDL= (unsigned char) br; 
  SCI1CR1 = 0x00;
/* bit value meaning
    7   0    LOOPS, no looping, normal
    6   0    WOMS, normal high/low outputs
    5   0    RSRC, not appliable with LOOPS=0
    4   0    M, 1 start, 8 data, 1 stop
    3   0    WAKE, wake by idle (not applicable)
    2   0    ILT, short idle time (not applicable)
    1   0    PE, no parity
    0   0    PT, parity type (not applicable with PE=0) */ 
  SCI1CR2 = 0x2C; 
/* bit value meaning
    7   0    TIE, no transmit interrupts on TDRE
    6   0    TCIE, no transmit interrupts on TC
    5   1    RIE, receive interrupts on RDRF
    4   0    ILIE, interrupts on idle
    3   1    TE, enable transmitter
    2   1    RE, enable receiver
    1   0    RWU, no receiver wakeup
    0   0    SBK, no send break */ 
}

//-------------------------SCI0_OutChar------------------------
// Wait for buffer to be empty, output 8-bit to serial port
// busy-waiting synchronization
// Input: 8-bit data to be transferred
// Output: none
void SCI1_OutChar(char data) {
  while((SCI0SR1 & TDRE) == 0){};
  SCI0DRL = data;
}

//-------------------------SCI0_InChar------------------------
// Wait for new serial port input, busy-waiting synchronization
// The input is not echoed
// Input: none
// Output: ASCII code for key typed
unsigned char SCI1_InChar(void) {
  unsigned char data;
  while(!Fifo_Get(&data)){};
  return data;
}

interrupt 21 void SCI1Handler(void) {
  if(SCI1SR1 & RDRF){ 
    Fifo_Put(SCI1DRL); // clears RDRF
  }    
}



