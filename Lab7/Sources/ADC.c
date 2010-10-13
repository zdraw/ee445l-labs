#include "ADC.h"


void ADC0_Init(void) {
  ATD0CTL2 = 0x80;
  ATD0CTL3 = 0x08;
  ATD0CTL4 = 0x85; 
}

unsigned short ADC0_In(unsigned char channel) {
  unsigned short data;
  ATD0CTL5 = channel;
  while(!(ATD0STAT1&0x01)) {}
  data = ATD0DR0;
  return data;
}