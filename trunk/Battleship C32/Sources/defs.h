#ifndef DEFS
#define DEFS

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

unsigned char reverseByte(unsigned char data);

#define SET_LCD_DDR1() (DDRT |= 0xC0)
#define SET_LCD_DDR2() (DDRP |= 0x0C)
  
#define E PTT_PTT6
#define DI PTT_PTT7
#define CS2 PTP_PTP3
#define CS1 PTP_PTP2
#define DATADR DDRB
#define DATA PORTB

#endif