#include "music.h"
#include "DAC.h"
#include "switch.h"
                           
unsigned char Buf_Read(unsigned char page, unsigned long addr) {
  unsigned char *pt;
  PPAGE = page;
  pt = (unsigned char *) (addr);
  return (*pt);  
}

unsigned static long i;

//---------------------Music_InitOC0---------------------
// arm output compare 0 for melody
// also enables timer to 43 ns period
// Input: none
// Output: none               
void Music_InitOC0(void){
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x00;   // divide by 1 TCNT prescale, TOI disarm, sets period to 42.67 ns
  PACTL = 0;      // timer prescale used for TCNT
  i = 0;
  DDRP |= 0x80;
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TC0   = TCNT+50;// first interrupt right away
}          

// OC handler for melody
interrupt 8 void TC0Handler() {
  TFLG1 = 0x01;
  
  DAC_Out(Buf_Read(0x20 + i/16000, 0x8000 + i%16000));  
  i++;
  
  TC0 += FREQ5;
}

//---------------------Music_Restart---------------------
// Restarts music
// Input: none
// Output: none               
void Music_Restart(void) {
  i = 0;
}

