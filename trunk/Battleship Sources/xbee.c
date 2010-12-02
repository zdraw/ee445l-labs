#include "defs.h"      /* derivative-specific definitions */
#include "xbee.h"
#include "SCI.h"
#include "Timer.h"
#include <string.h>

#ifdef FIRST
#define SOURCE 0x4E
#define DESTINATION 0x4F
#define SOURCE_CMD "ATMY4E"
#define DESTINATION_CMD "ATDL4F"

#else
#define SOURCE 0x4F
#define DESTINATION 0x4E
#define SOURCE_CMD "ATMY4F"
#define DESTINATION_CMD "ATDL4E"

#endif

char FrameID;

int ok(void) {
  if(SCI_InChar() != 'O') {
    return 0;  
  }
  if(SCI_InChar() != 'K') {
    return 0;  
  }
  if(SCI_InChar() != 0x0D) {
    return 0;  
  }
  
  return 1;
}


void sendATCommand(char * command) {
  char * temp;
  do {
    temp = command;
    while(*temp) { 
      SCI_OutChar(*temp); 
      temp++; 
    }
    SCI_OutChar(0x0D);
    Timer_Wait1ms(20);
  } while(!ok());
}

/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void) {
    SCI_OutChar('X');
    Timer_Wait10ms(110);
    
    SCI_OutString("+++"); 
    Timer_Wait10ms(110);   
    
    sendATCommand(SOURCE_CMD);
    sendATCommand("ATDH0");
    sendATCommand(DESTINATION_CMD);
    sendATCommand("ATAP1");
    sendATCommand("ATCN");
    PTP ^= 0x80; 
}

/*-----------------------XBee_RecieveTxFrame-------------------
  Receives a frame from data in
  Inputs: None
  Outputs: Input Frame */
int XBee_ReceiveTxFrame(FrameType * frame)
{
  short i;
  static short FrameID = 1;
       
  if(SCI_InChar() != 0x7E)
  {
	  return 0;
  }  
  
  frame->length = SCI_InChar();
  frame->length <<= 8;
  frame->length += SCI_InChar();
  
  for(i = 0; i < frame->length; i++)
  {
	  frame->data[i] = SCI_InChar();
  }
  
  frame->checkSum = SCI_InChar();
  frame->frameID = FrameID++;
  return 1;
}

/*-----------------------XBee_CreateTxFrameType-------------------
  Creates a frame of char data
  Inputs: Data to be sent
  Outputs: frame structure */
FrameType XBee_CreateTxFrameType(char * data)
{ 
  FrameType frame;
  short length = strlen(data) + 5;
  unsigned char checkSum = 0;
  int i;     
  
  frame.length = length; 
  frame.frameID = FrameID++;
  if(FrameID > 255)
  {
    FrameID = 1;
  }
  for(i = 0; i < length; i++)
  {       
    frame.data[i] = data[i];
    checkSum += data[i];
  }
  checkSum += 0x01;
  checkSum += FrameID;
  checkSum = 0xFF - checkSum;
  frame.checkSum = checkSum;
  return frame;
}

/*-----------------------XBee_SendTxFrameType-------------------
  Sends a frame to SCI Out
  Inputs: Data to be sent
  Outputs: frame structure */
void XBee_SendTxFrameType(FrameType data_frame)
{
  int i;
  do {
    SCI_OutChar(0x7E);
    SCI_OutChar((char)((data_frame.length & 0xFF00) >> 8));
    SCI_OutChar((char)(data_frame.length & 0x00FF));
    SCI_OutChar(0x01);
    SCI_OutChar(data_frame.frameID);
    SCI_OutChar(0x00);
    SCI_OutChar(0x4E);
    SCI_OutChar(0x00);
    for(i = 0; i < data_frame.length; i++)
    {
      SCI_OutChar(data_frame.data[i]);  
    }
    SCI_OutChar(data_frame.checkSum);
  } while(!XBee_TxStatus());
}

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void)
{
  unsigned short length;
  unsigned char api, id, data, checkSum;
  
  if(SCI_InChar() != 0x7E) {
    return 0;  
  } 
  
  length = (SCI_InChar()<<8);
  length += SCI_InChar();
  
  if(length != 3) {
    return 0;  
  }
  
  api = SCI_InChar();
  
  if(api != 0x89) {
    return 0;
  }
  
  id = SCI_InChar();
  
  data = SCI_InChar();
  
  if(data != 0x00) {
    return 0;
  }
  
  checkSum = SCI_InChar();
  
  if(checkSum != 0xB5)
  {
    return 0;
  } 
  
  return 1;
}