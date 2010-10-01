#include "switch.h"

//---------------------switch_Init---------------------
// Set PP6-4 as inputs
// Input: none
// Output: none   
void switch_Init() {
  DDRP &= ~0x70; 
}