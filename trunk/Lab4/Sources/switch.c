#include "switch.h"

void switch_Init() {
  DDRP &= ~0x70; 
}