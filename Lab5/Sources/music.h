#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#define WHOLE   2400000 * 12 / 128
#define HALF    2400000 * 6  / 128
#define QUARTER 2400000 * 3  / 128 
#define EIGHTH  240000  * 15 / 128
#define TRIP8TH 2400000 * 1  / 128


typedef const struct Note{
  unsigned short frequency;            // Output to Port T
  unsigned long length;
  
} NoteType;


extern unsigned const char SinWave[256];
extern const NoteType melody[554];
extern const NoteType harmony[541];
extern const NoteType bass[571];