#ifndef DEFS
#define DEFS

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

unsigned char reverseByte(unsigned char data);

#define FIRST

#define DEBOUNCE_DELAY 15000

#define SET_LCD_DDR1() (DDRT |= 0xC0)
#define SET_LCD_DDR2() (DDRP |= 0x0C)
  
#define E PTT_PTT6
#define DI PTT_PTT7
#define CS2 PTP_PTP3
#define CS1 PTP_PTP2
#define DATADR DDRB
#define SET_DATA(x) (PORTB = reverseByte(x))

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

#define SS_DDR DDRM_DDRM3
#define MOSI_DDR DDRM_DDRM4
#define SCK_DDR DDRM_DDRM5

#define SS PTM_PTM3
#define MOSI PTM_PTM4
#define SCK PTM_PTM5

#define RX_DDR DDRS_DDRS0
#define TX_DDR DDRS_DDRS1

#define SCI_INTERRUPT 20

#endif