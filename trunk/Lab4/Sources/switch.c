#include "switch.h"

void switch_Init() {
  DDRP &= ~0x70; 
}

unsigned short switch_getInput() {
  if(PTP&0x40) {
    if(PTP&0x20) {
      return 1; 
    }
    else {
      return 2; 
    }
  }
  else if(PTP&0x20) {
    return 3;
  }
  else if(PTP&0x10) {
    return 4;
  } 
  else {
    return 0; 
  }
}