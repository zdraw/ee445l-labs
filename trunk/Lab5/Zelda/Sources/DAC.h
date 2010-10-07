#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

//---------------------DAC_Init---------------------
// initializes DAC
// Input: none
// Output: none 
void DAC_Init(void);

//---------------------DAC_Out---------------------
// outputs 12 bits to DAC
// Input: none
// Output: none
void DAC_Out(unsigned short data);
