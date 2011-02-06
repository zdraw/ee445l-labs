// filename ************* Fifo.h ********
// Header file for the receive FIFO (two versions)
// Jonathan W. Valvano 10/1/07

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//        Thompson, copyright (c) 2006,
//   "Introduction to Embedded Microcomputer Systems: 
//    Motorola 6811 and 6812 Simulation", Brooks-Cole, copyright (c) 2002

// Copyright 2006 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains  


/* Number of characters in the Fifo
     the FIFO is full when it has FifoSize-1 characters */
void Fifo_Init(void);

/*-----------------------Fifo_Put----------------------------
  Enter one character into the fifo
  Inputs: 8-bit data
  Outputs: true if data is properly saved,
           false if data not saved because it was previously full*/
int Fifo_Put(unsigned char data); 

/*-----------------------Fifo_Get----------------------------
  Remove one character from the fifo
  Inputs: pointer to place to return 8-bit data
  Outputs: true if data is valid, 
           false if fifo was empty at the time of the call*/
int Fifo_Get(unsigned char *datapt);

/*-----------------------Fifo_Status----------------------------
  Check the status of the fifo
  Inputs: none
  Outputs: true if there is any data in the fifo */
int Fifo_Status(void); 
