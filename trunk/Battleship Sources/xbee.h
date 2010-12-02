typedef struct
{
	short length; // Length of data
	char * data;
	char checkSum;
	short frameID;
} FrameType;



/*-----------------------XBee_Init----------------------------
  Initialize XBee
  Inputs: none
  Outputs: none */
void XBee_Init(void);

/*-----------------------XBee_RecieveTxFrame-------------------
  Receives a frame from data in
  Inputs: None
  Outputs: Input Frame */
int XBee_ReceiveTxFrame(FrameType * frame);

FrameType XBee_CreateTxFrameType(char * data);

void XBee_SendTxFrameType(FrameType data_frame);

/*-----------------------XBee_TxStatus------------------------
  Checks the status of XBee
  Inputs: none
  Outputs: 1 if Transmitter was successful, 0 if not */
short XBee_TxStatus(void);