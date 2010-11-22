typedef struct
{
	short length; // Length of data
	char data[30];
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
int XBee_RecieveTxFrame(FrameType * frame);