#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

extern signed short volatile hours;
extern signed short volatile minutes;
extern signed short volatile seconds;  
extern int volatile alarmOn;

//---------------------OC_Init0---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none                
void OC_Init0(void); 

//---------------------OC_Init1---------------------
// arm output compare 0 for 800 Hz periodic interrupt
// Input: none
// Output: none 
void OC_Init1(void);