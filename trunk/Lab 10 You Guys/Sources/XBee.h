#ifndef XBEE_H
#define XBEE_H

struct Frame
{
	short length; // Length of data
	char *data;
	char checkSum;
	short frameID;
};

typedef struct Frame FrameType;
short FrameID;

/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void);

/*-----------------------XBee_CreateTxFrame-------------------
  Creates a frame of char data
  Inputs: Data to be sent
  Outputs: frame structure */
FrameType XBee_CreateTxFrame(char * data);

/*-----------------------XBee_SendTxFrame-------------------
  Sends a frame to SCI Out
  Inputs: Data to be sent
  Outputs: frame structure */
void XBee_SendTxFrame(FrameType data_frame);

/*-----------------------XBee_RecieveTxFrame-------------------
  Receives a frame from data in
  Inputs: None
  Outputs: Input Frame */
FrameType XBee_RecieveTxFrame(void);

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void);

#endif