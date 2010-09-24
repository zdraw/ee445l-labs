#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
        

//---------------------OC_Init0---------------------
// arm output compare 0 for 4 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none    
void OC_Init0(void);