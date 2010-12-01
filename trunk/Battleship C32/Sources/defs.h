#ifndef DEFS
#define DEFS

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define SET_LCD_DDR1() (DDRT |= 0xC0)
#define SET_LCD_DDR2() (DDRP |= 0x0C)
  
#define E PTT_PTT6
#define DI PTT_PTT7
#define CS2 PTP_PTP3
#define CS1 PTP_PTP2
#define DATADR DDRB
#define DATA PORTB

#define SW_PTP0 Game_DPad(LEFT)
#define SW_PTP1 Game_DPad(DOWN)
#define SW_PTP2 Game_DPad(UP)
#define SW_PTP3 Game_DPad(RIGHT)
#define SW_PTP4 Game_B()
#define SW_PTP5 Game_A()

#define LED_DDR0 DDRA_BIT0
#define LED_DDR1 DDRA_BIT1
#define LED_DDR2 DDRA_BIT2
#define LED_DDR3 DDRS_DDRS2
#define LED_DDR4 DDRS_DDRS3
#define LED_DDR5 DDRP_DDRP6

#define LED0 PORTA_BIT0
#define LED1 PORTA_BIT1
#define LED2 PORTA_BIT2
#define LED3 PTS_PTS2
#define LED4 PTS_PTS3
#define LED5 PTP_PTP6

#endif