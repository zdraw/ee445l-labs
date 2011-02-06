#ifndef DEFS
#define DEFS

#include <hidef.h>         /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"

#define DEBOUNCE_DELAY 30000

#define SET_LCD_DDR1() (DDRP |= 0x0F)
#define SET_LCD_DDR2()

#define E PTP_PTP3
#define DI PTP_PTP2
#define CS2 PTP_PTP1
#define CS1 PTP_PTP0
#define DATADR DDRH
#define SET_DATA(x) ((PTH) = (x))

#define SW_PTP0 Game_B()
#define SW_PTP1 Game_A()
#define SW_PTP2 Game_DPad(RIGHT)
#define SW_PTP3 Game_DPad(DOWN)
#define SW_PTP4 Game_DPad(LEFT)
#define SW_PTP5 Game_DPad(UP)

#define LED_DDR0 DDRP_DDRP4
#define LED_DDR1 DDRP_DDRP5
#define LED_DDR2 DDRP_DDRP6
#define LED_DDR3 DDRP_DDRP7
#define LED_DDR4 DDRT_DDRT6
#define LED_DDR5 DDRT_DDRT7
                    
#define LED0 PTP_PTP4
#define LED1 PTP_PTP5
#define LED2 PTP_PTP6
#define LED3 PTP_PTP7
#define LED4 PTT_PTT6
#define LED5 PTT_PTT7

#define SPISR SPI0SR
#define SPIDR SPI0DR

#define SS_DDR DDRS_DDRS7
#define MOSI_DDR DDRS_DDRS5
#define SCK_DDR DDRS_DDRS6

#define SPICR1 SPI0CR1
#define SPICR2 SPI0CR2
#define SPIBR SPI0BR

#define SS PTS_PTS7

#define TX_DDR DDRS_DDRS3
#define RX_DDR DDRS_DDRS2

#define SCICR1 SCI1CR1
#define SCICR2 SCI1CR2
#define SCIBDL SCI1BDL
#define SCIBDH SCI1BDH
#define SCISR1 SCI1SR1
#define SCIDRL SCI1DRL

#define SCI_INTERRUPT 21

#endif