#include "switch.h"

void Switch_Init(void) {
  DDRP &= ~0x07; 
}

unsigned char Switch_Data(void) {
  return (PTP&0x07);
}