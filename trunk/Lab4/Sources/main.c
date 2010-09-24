#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "stepper.h"
#include "switch.h"

void main(void) {  
  switch_Init(); 
  OC_Init0();
  
  asm cli
  
  for(;;) {}
}
