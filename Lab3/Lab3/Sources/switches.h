#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#include "OC.h"

extern unsigned int alarmSet;
extern signed short setHours;
extern signed short setMinutes;
extern signed short alarmHours;
extern signed short alarmMinutes;

void switchInit(void);