#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
                              
#define SIN 16
#define FREQUENCY 24000000/SIN

#define MREPEAT 36
#define B1REPEAT 34
#define B2REPEAT 29

#define MELODY  146
#define BASS1  181
#define BASS2  163


typedef const struct Note{
  unsigned short frequency;            // Output to Port T
  unsigned long length;
  
} NoteType;


extern unsigned const short SinWave[];
extern const NoteType melody[];
extern const NoteType bass1[];
extern const NoteType bass2[];