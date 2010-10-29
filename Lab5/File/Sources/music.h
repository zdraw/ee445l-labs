#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#define FREQ44 544 // 24000000/4000
#define FREQ22 1088 // 24000000/4000
#define FREQ11 2177 // 24000000/4000
#define FREQ5  4354 // 24000000/4000
#define FREQ2  8707 // 24000000/4000

//---------------------Music_InitOC0---------------------
// arm output compare 0 for melody
// also enables timer to 43 ns period
// Input: none
// Output: none               
void Music_InitOC0(void);

//---------------------Music_Restart---------------------
// arm output compare 3 for envelopes at 750 Hz
// Input: none
// Output: none               
void Music_Restart(void);