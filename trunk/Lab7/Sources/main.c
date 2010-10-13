/*
  Initiating ADC Conversion:
    1. Writing to ATD0CTL5
    2. Edge on external trigger
    3. Level on external trigger
  
  Completed Conversion
    1. Reading ATD0STAT1
    2. Interrupt when complete
*/

#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
              
#define PROCEDURE 1
#include "PLL.h"
#include "ADC.h"
#include "OC.h"

#if PROCEDURE == 1
#include "SCI0.h"

unsigned short DataBuffer[100];
unsigned short Count=0;
void back(void) {
  unsigned short data;
  if(Count<100) {
    data = ADC0_In(0x85); // your program that samples channel 5
    DataBuffer[Count++] = data;
  }
}
void main(void){unsigned short i;
  PLL_Init(); // 24 MHz
  ADC0_Init(); // your module
  SCI0_Init(115200); // SCI output to PC
  OC0_Init(1000,&back); // your module sampling at 1000 Hz
  while(Count<100) {}; // copy ADC to buffer in background
  for(i=0; i<100; i++) {
    SCI0_OutUDec(DataBuffer[i]); SCI0_OutChar(10);SCI0_OutChar(13);
  }
  for(;;){};
}

#else
#include "FIFO.h"

void getData(void) {
  unsigned short data;
  data = ADC0_In(0x80);
  while(!Fifo_Put(data)) {}    
}

void main(void) {
  // Initialize needed modules
  PLL_Init();
  Fifo_Init();
  ADC0_Init();
  LCD_Open();
  OC0_Init(10, &getData);
  
  LCD_Clear();
  LCD_OutString("    %cC");
  
  for(;;) {
    unsigned short data;
    unsigned char temperature;
    unsigned char *buffer = "";
    while(!Fifo_Get(&data)) {}
    
    temperature = ADCTable[data];
    sprintf(buffer, "%2d.%01d", temperature/10, temperature%10);
    LCD_GoTo(0,0);
    LCD_OutString(buffer);
                                 
  }
}
#endif