#include "OC.h"

unsigned short frequency;
void (*function)(void);

interrupt 8 void TOC0handler(void){ // executes at 100 Hz 
  TFLG1 = 0x01;         // acknowledge OC0 
  PTP |= 0x80;
  (*function)();
  TC0 += 187500/frequency; 
}

//---------------------OC_Init0---------------------
// arm output compare 0 for 100Hz periodic interrupt
// Input: none
// Output: none 
void OC0_Init(unsigned short freq, void (*func)(void)) {
  frequency = freq;
  function = func;
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x07;   // divide by 64 TCNT prescale, TOI disarm
  PACTL = 0;      // timer prescale used for TCNT
  TC0   = TCNT + 50; // first interrupt right away
}