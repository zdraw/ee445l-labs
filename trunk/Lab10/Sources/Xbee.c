#include "derivative.h"      /* derivative-specific definitions */
#include "SCI1.h"
#include "Timer.h"
#include "XBee.h"

int ok(void) {
  if(SCI1_InChar() != 'O') {
    return 0;  
  }
  if(SCI1_InChar() != 'K') {
    return 0;  
  }
  if(SCI1_InChar() != 0x0D) {
    return 0;  
  }
  
  return 1;
}


void sendATCommand(char * command) {
  char * temp;
  //do {
    temp = command;
    while(!(*temp)) { 
      SCI1_OutChar(*temp); 
      temp++; 
    }
    SCI1_OutChar(0x0D);
    Timer_Wait1ms(20);
  //} while(!ok());
}

/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void) {
  do {
    SCI1_OutChar('X');
    Timer_Wait10ms(110);
    
    
    SCI1_OutString("+++"); 
    Timer_Wait10ms(110);   
    
    sendATCommand("ATDL4F");
    sendATCommand("ATDH0");
    sendATCommand("ATMY4E");
    sendATCommand("ATAP1");
    sendATCommand("ATCN");
    PTP ^= 0x80; 
  } while(!ok());
}

/*-----------------------XBee_RecieveTxFrame-------------------
  Receives a frame from data in
  Inputs: None
  Outputs: Input Frame */
FrameType XBee_RecieveTxFrame(void)
{
  short i;  
  FrameType frame;
  static short FrameID = 1;
  
  if(SCI1_InChar() != 0x7E)
  {
	  return;
  }
  
  frame.length = SCI1_InChar();
  frame.length <<= 8;
  frame.length += SCI1_InChar();
  
  for(i = 0; i < frame.length; i++)
  {
	  frame.data[i] = SCI1_InChar();
  }
  
  frame.checkSum = SCI1_InChar();
  frame.frameID = FrameID++;
  return frame;
}