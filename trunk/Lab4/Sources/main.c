#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "stepper.h"
#include "switch.h"

void main(void) {
  OC_Init0();
  switch_Init(); 
  
  asm cli
  
  for(;;) {
  
  }
}
