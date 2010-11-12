//---------------------wait---------------------
// time delay
// Input: time in 0.667usec
// Output: none
void static wait(unsigned short delay){ 
unsigned short startTime;
  startTime = TCNT;
  while((TCNT-startTime) <= delay){}  
}

//---------------------1mswait---------------------
// time delay
// Input: time in msec
// Output: none
void static wait1ms(unsigned short msec){ 
  for(;msec;msec--){
    wait(188);    // 1ms wait
  }
}

void sendATCommand(char * command) {
  unsigned char loop = 1;
  while(loop) {
    while(*command) {
      SCI1_OutChar(*command);  
    }
    SCI1_OutChar(0x0D);
    wait1ms(20);
    loop = 0;
    if(SCI1_InChar != 'O') {
      loop = 1;  
    }
    if(SCI1_InChar != 'K') {
      loop = 1;  
    }
    if(SCI1_InChar != 0x0D) {
      loop = 1;  
    }
  }
}

void XBee_Init(void) {
  sendATCommand("X");
  sendATCommand("ATDL4F");
  sendATCommand("ATDH0");
  sendATCommand("ATMY4E");
  sendATCommand("ATAP1");
  sendATCommand("ATCN");
}