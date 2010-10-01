#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "PLL.h"
#include "stepper.h"
#include "switch.h"

void main(void) {
  PLL_Init(); 
  switch_Init(); 
  OC_Init0();
  
  asm cli
  
  for(;;) {} // Everything important runs in background
}
