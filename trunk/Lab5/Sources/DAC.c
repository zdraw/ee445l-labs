#include "DAC.h"

// 9S12DP512 SPI1 interface to Max539
// PH2 (out) SCLK synchronous clock
// PH1 (out) MOSI serial data output
// PH3 (out) CS used to latch data into Max539
// PH0 (in) is associated with SPI1, but not used
                  
void DAC_Init(void) {
  DDRH |=  0x0E;  // 1) make PH1, PH2, PH3 outputs, PH0 input
  DDRH &= ~0x01;  // DDRH
  SPI1CR1 = 0x50; // 2) enable SPI, no interrupts, master, CPOL, CPHA
                  // SPI0CR1 = 01010000
  SPI1CR2 = 0x00; // 3) set up PH7 as a regular output
                  // SSOE=0, MODFEN=0 SPI0CR1, SPI0CR2
  SPI1BR = 0x00;  // 4) set the baud rate, SPI0BR
  PTH |= 0x08;   // 5) make PH3=CS high
} 

void transmitByte(unsigned char data) {
  while(!(SPI1SR&0x20)) {}  // 1) wait for SPTEF to be 1, SPI0SR
  SPI1DR = data;            // 2) write 8-bit data to SPI0DR
  while(!(SPI1SR&0x80)) {}  // 3) wait for SPIF to be 1, SPI0SR
  data = SPI1DR;            // 4) clear the SPIF flag by reading the data
                            // dummy = SPI0DR;
}
/*
void DAC_Out(unsigned char data) {
  PTP ^= 0x80;
  PTH &= ~0x08;                    // 1) set PS7=CS low
  transmitByte(0x09); // 2) transmit most significant 8-bit data to the DAC
  transmitByte(data);        // 3) transmit least significant 8-bit data to the DAC
  PTH |=  0x08;                    // 4) set PS7=CS high
} 
*/
/* TLV chip bits 15-12 are control. x spd pwr x, spd=1=fast pwr=1=off spd=0=slow pwr=0=normal*/
void DAC_Out(unsigned short data) {
  PTH &= ~0x08;                    // 1) set PS7=CS low
  transmitByte(0x40+((data&0x3F00) >> 8)); // 2) transmit most significant 8-bit data to the DAC
  transmitByte(data&0x00FF);        // 3) transmit least significant 8-bit data to the DAC
  PTH |=  0x08;                    // 4) set PS7=CS high
}