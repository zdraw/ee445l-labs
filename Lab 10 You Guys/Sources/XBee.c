#include "derivative.h"      /* derivative-specific definitions */
#include "SCIb.h"
#include "XBee.h"


FrameType frame;
char data[30];

/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void) {
  FrameID = 1;
  
  sendATCommand("X\r");
  sendATCommand("ATDL4F\r");
  sendATCommand("ATDH0\r");
  sendATCommand("ATMY4E\r");
  sendATCommand("ATAP1\r");
  sendATCommand("ATCN\r");
}

/*-----------------------XBee_CreateTxFrame-------------------
  Creates a frame of char data
  Inputs: Data to be sent
  Outputs: frame structure */
FrameType XBee_CreateTxFrame(char * data)
{
  short length = sizeof(data)/sizeof(char);
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

/*-----------------------XBee_SendTxFrame-------------------
  Sends a frame to SCI Out
  Inputs: Data to be sent
  Outputs: frame structure */
void XBee_SendTxFrame(FrameType data_frame)
{
  int i;
  SCIb_OutChar(0x7E);
  SCIb_OutChar((char)((data_frame.length & 0xFF00) >> 8));
  SCIb_OutChar((char)(data_frame.length & 0x00FF));
  SCIb_OutChar(0x01);
  SCIb_OutChar(data_frame.frameID);
  for(i = 0; i < data_frame.length; i++) 
  {
    SCIb_OutChar(data_frame.data[i]);  
  }
  SCIb_OutChar(data_frame.checkSum);
}

/*-----------------------XBee_RecieveTxFrame-------------------
  Receives a frame from data in
  Inputs: None
  Outputs: Input Frame */
FrameType XBee_RecieveTxFrame(void)
{
  short length, i;
  char frameID,checkSum;
  if(SCIb_InChar() != 0x7E)
  {
	  return;
  }
  
  length = SCIb_InChar();
  length = length << 8;
  length += SCIb_InChar();
  SCIb_InChar();
  for(i = 0; i < length; i++)
  {
	  data[i] = SCIb_InChar();
  }
  
  checkSum = SCIb_InChar();
  frame.length = length;
  frame.data = data;
  frame.checkSum = checkSum;
  frame.frameID = FrameID++;
  return frame;
}

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void)
{
  char OK[2]={'a','a'};
  SCIb_InString(OK,3);//Wait for response, should be OK<CR>
  if((OK[0]=='O')&&(OK[1]=='K')) 
  {
    return 1;
  }
  return 0;
} 

int ok(void) {
  if(SCIb_InChar() != 'O') {
    return 0;  
  }
  if(SCIb_InChar() != 'K') {
    return 0;  
  }
  if(SCIb_InChar() != 0x0D) {
    return 0;  
  }
  
  return 1;
}


void sendATCommand(char * command) {
  char * temp;
  do {
    temp = command;
    while(*temp != 0x0D) { 
      SCIb_OutChar(*temp); 
      temp++; 
    }
    SCIb_OutChar(0x0D);
    wait1ms(20);
  } while(!ok());
}