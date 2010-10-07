#include "switch.h"
 
//---------------------Switch_Init---------------------
// sets DDRP for switches
// Input: none
// Output: none  
void Switch_Init(void) {
  DDRP &= ~0x07; 
}
  
//---------------------Switch_Data---------------------
// Input: none
// Output: Switch data  
unsigned char Switch_Data(void) {
  return (PTP&0x07);
}