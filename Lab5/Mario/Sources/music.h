#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
                                      
#define PROCEDURE 32
#define FREQUENCY 24000000/PROCEDURE
#define EIGHTH  240000  * 15 / 60000
#define TRIP8TH 2400000 * 1  / 60000
#define MELODY  618
#define HARMONY 618
#define BASS    606 


typedef const struct Note{
  unsigned short frequency;            // Output to Port T
  unsigned long length;
  
} NoteType;


extern unsigned const short SinWave[];
extern const NoteType melody[];
extern const NoteType harmony[];
extern const NoteType bass[];