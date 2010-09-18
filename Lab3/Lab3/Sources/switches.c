#include "switches.h"

void switchInits(void) {
  DDRP &= ~0x7E;
  PIEP |= 0x7E;
  PPSP |= 0x7E;  
  PIFP = 0x7E;
}

interrupt 56 void switchHandler() {
  char on = PIFP;
  PIFP = 0x7E;
  if(alarmOn) {
    alarmOn = 0; 
  }
  else {
    if(on & 0x02) {
      alarmOn = 1;
      PTT ^= 0x04;
    } 
    if(on & 0x04) {
       PTT ^= 0x08;
    }
    if(on & 0x08) {
       PTT ^= 0x10;
    }
    if(on & 0x10) {
       PTT ^= 0x20;
    }
    if(on & 0x20) {
       PTT ^= 0x40;
    }
    if(on & 0x40) {
       PTT ^= 0x80;
    }
  }
  PTP ^= 0x80; 
}