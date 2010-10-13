#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
              
#include "PLL.h"
#include "DAC.h"
#include "music.h"
#include "switch.h"


void main(void) {
  // Initialize needed modules
  PLL_Init(); 
  DAC_Init();
  Switch_Init();
  Music_InitOC0();
  Music_InitOC1();
  //Music_InitOC2();
  //Music_InitOC3();
  
  // Start off paused
  asm cli
      
  for(;;) {
    // Play button
    if(Switch_Data()&0x08) {
      asm cli  
    }
    // Pause button
    if(Switch_Data()&0x04) {
      asm sei 
    }
    // Restart button
    if(Switch_Data()&0x02) {
      Music_Restart();
    }
  }
}