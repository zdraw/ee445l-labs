#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "DAC.h"
#include "PLL.h"
#include "music.h"
#include "switch.h"


//---------------------initOC0---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC0(void){
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x07;   // divide by 128 TCNT prescale, TOI disarm, sets period to 5.33us
  PACTL = 0;      // timer prescale used for TCNT
  
  //TIOS |= 0x01;   // activate TC0 as output compare
  //TIE  |= 0x01;   // arm OC0
  //TC0   = TCNT+50;// first interrupt right away
}

//---------------------initOC1---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC1(void){
  //TIOS |= 0x02;   // activate TC0 as output compare
  //TIE  |= 0x02;   // arm OC0
  //TC1   = TCNT+50;// first interrupt right away
}

//---------------------initOC2---------------------
// arm output compare 2 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC2(void){
  //TIOS |= 0x04;   // activate TC0 as output compare
  //TIE  |= 0x04;   // arm OC0
  //TC2   = TCNT+50;// first interrupt right away
}

//---------------------initOC3---------------------
// arm output compare 3 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC3(void){  
  //TIOS |= 0x08;   // activate TC0 as output compare
  //TIE  |= 0x08;   // arm OC0
  //TC3   = TCNT+50;// first interrupt right away
}

void main(void) {
  PLL_Init(); 
  DAC_Init();
  Switch_Init();
  initOC0();
  initOC1();
  initOC2();
  initOC3();

  for(;;) {}
}
