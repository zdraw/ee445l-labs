#ifndef XBEE_H
#define XBEE_H

typedef struct 
{
        short length; // Length of data
        char *data;
        char checkSum;
        char frameID;
} FrameType;


/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void);

/*-----------------------XBee_CreateTxFrame-------------------
  Creates a frame of char data
  Inputs: Data to be sent
  Outputs: frame structure */
FrameType XBee_CreateTxFrameType(char * data);

/*-----------------------XBee_SendTxFrame-------------------
  Sends a frame to SCI Out
  Inputs: Data to be sent
  Outputs: frame structure */
void XBee_SendTxFrameType(FrameType data_frame);

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void);

#endif