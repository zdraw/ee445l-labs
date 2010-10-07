#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
                              
#define SIN 16
#define FREQUENCY 24000000/SIN

#define MREPEAT 36
#define HREPEAT 34
#define BREPEAT 29

#define MELODY  146
#define HARMONY  181
#define BASS  163


typedef const struct Note{
  unsigned short frequency;
  unsigned long length;
  
} NoteType;

//---------------------Music_InitOC0---------------------
// arm output compare 0 for melody
// also enables timer to 43 ns period
// Input: none
// Output: none               
void Music_InitOC0(void);

//---------------------Music_InitOC1---------------------
// arm output compare 1 for harmony
// Input: none
// Output: none               
void Music_InitOC1(void);

//---------------------Music_InitOC2---------------------
// arm output compare 2 for bass
// Input: none
// Output: none             
void Music_InitOC2(void);

//---------------------Music_InitOC3---------------------
// arm output compare 3 for envelopes at 750 Hz
// Input: none
// Output: none               
void Music_InitOC3(void);

//---------------------Music_Restart---------------------
// arm output compare 3 for envelopes at 750 Hz
// Input: none
// Output: none               
void Music_Restart(void);