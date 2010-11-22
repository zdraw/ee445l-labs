#include "derivative.h"      /* derivative-specific definitions */
#include "SCIb.h"
#include "XBee.h"
#include "Timer.h"
#include <string.h>

char FrameID;

int ok(void) {
  if(SCIb_InChar() != 'O') {
    return 0;  
  }
  if(SCIb_InChar() != 'K') {
    return 0;  
  }
  if(SCIb_InChar() != '\r') {
    return 0;  
  } 
  return 1;
}

void sendATCommand(char * command) {
  char * temp= command;
  do{
      while(*temp) {
        SCIb_OutChar(*temp);
        temp++;
      }
      Timer_Wait1ms(20);
    } while(!ok());
}

/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void) {
  FrameID = 1;
  
  PTP_PTP7 = 0;
  do{
   // SCIb_Clear();
    SCIb_OutString("X");
    Timer_Wait10ms(110);

    SCIb_OutString("+++");
    Timer_Wait10ms(110);
  
    sendATCommand("ATDL4E\r");
    sendATCommand("ATDH0\r");
    sendATCommand("ATMY4F\r");
    sendATCommand("ATAP1\r");
    sendATCommand("ATCN\r");
    } while(!ok());
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
  short i = 0;
  for(i = 0; i < length; i++)
  {
    checkSum += data[i];
  }
  checkSum += 0x01;
  checkSum += FrameID;
  checkSum = 0xFF - checkSum;
  frame.length = length;
  frame.data = data;
  frame.checkSum = checkSum;
  frame.frameID = FrameID++;
  if(FrameID > 255)
  {
    FrameID = 1;
  }
  return frame;
}

/*-----------------------XBee_SendTxFrameType-------------------
  Sends a frame to SCI Out
  Inputs: Data to be sent
  Outputs: frame structure */
void XBee_SendTxFrameType(FrameType data_frame)
{
  int i;
  SCIb_OutChar(0x7E);
  SCIb_OutChar((char)((data_frame.length & 0xFF00) >> 8));
  SCIb_OutChar((char)(data_frame.length & 0x00FF));
  SCIb_OutChar(0x01);
  SCIb_OutChar(data_frame.frameID);
  SCIb_OutChar(0x00);
  SCIb_OutChar(0x4E);
  SCIb_OutChar(0x00);
  for(i = 0; i < data_frame.length; i++)
  {
    SCIb_OutChar(data_frame.data[i]);  
  }
  SCIb_OutChar(data_frame.checkSum);
}

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void)
{
  short length, checkSum, data, i;
  if(SCIb_InChar() != 0x7E) {
    return 0;  
  } 
  else return 1;
  length = (SCIb_InChar()<<8) + SCIb_InChar();
  
  for(i = 0; i < length; i++){
    data = SCIb_InChar();
    checkSum += data;
  }
  if(checkSum == SCIb_InChar())
  {
    return data;
  } 
  
  return 0;
}
