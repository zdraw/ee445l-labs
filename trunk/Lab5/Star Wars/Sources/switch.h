#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

//---------------------Switch_Init---------------------
// sets DDRP for switches
// Input: none
// Output: none  
void Switch_Init(void);
  
//---------------------Switch_Data---------------------
// Input: none
// Output: Switch data  
unsigned char Switch_Data(void);