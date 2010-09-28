#include "music.h"

//---------------------OC0_Init---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void OC0_Init(void){
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x07;   // divide by 128 TCNT prescale, TOI disarm, sets period to 5.33us
  PACTL = 0;      // timer prescale used for TCNT
  
  //TIOS |= 0x01;   // activate TC0 as output compare
  //TIE  |= 0x01;   // arm OC0
  //TC0   = TCNT+50;// first interrupt right away
}