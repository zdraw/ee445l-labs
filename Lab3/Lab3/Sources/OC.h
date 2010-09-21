#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

extern signed short volatile hours;
extern signed short volatile minutes;
extern signed short volatile seconds;  
extern int volatile alarmOn;

void OC_Init0(void);
void OC_Init1(void);