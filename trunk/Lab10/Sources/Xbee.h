typedef struct
{
	short length; // Length of data
	char *data;
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
FrameType XBee_RecieveTxFrame(void);