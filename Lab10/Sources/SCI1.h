// filename  ******************* SCI1.H **************************
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
 
// standard ASCII symbols 
#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20       
#define DEL  0x7F
 
//-------------------------SCI1_Init------------------------
// Initialize Serial port SCI
// Input: baudRate is tha baud rate in bits/sec
// Output: none
// assumes a module clock frequency of 24 MHz
void SCI1_Init(unsigned long baudRate);

void SCI1_OutChar(char data);

unsigned char SCI1_InChar(void);

void SCI1_OutString(char *pt);