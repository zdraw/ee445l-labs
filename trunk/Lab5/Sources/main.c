#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "DAC.h"
#include "PLL.h"
#include "music.h"
#include "switch.h"

void main(void) {
  PLL_Init(); 
  DAC_Init();
  Switch_Init();
  OC0_Init();

  for(;;) {}
}
