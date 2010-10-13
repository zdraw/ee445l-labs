#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

void ADC0_Init(void);
unsigned short ADC0_In(unsigned char channel);