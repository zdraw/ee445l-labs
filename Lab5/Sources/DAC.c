#include "DAC.h"

// 9S12DP512 SPI0 interface to Max539
// PS6 (out) SCLK synchronous clock
// PS5 (out) MOSI serial data output
// PS7 (out) CS used to latch data into Max539
// PS4 (in) is associated with SPI0, but not used
                  
void DAC_Init(void) {
  DDRS |=  0xE0;  // 1) make PS7, PS6, PS5 outputs, PS4 input
  DDRS &= ~0x10;  // DDRS
  SPI0CR1 = 0x50; // 2) enable SPI, no interrupts, master, CPOL, CPHA
                  // SPI0CR1 = 01010000
  SPI0CR2 = 0x00; // 3) set up PS7 as a regular output
                  // SSOE=0, MODFEN=0 SPI0CR1, SPI0CR2
  SPI0BR = 0x00;  // 4) set the baud rate, SPI0BR
  PTIS |= 0x80;   // 5) make PS7=CS high
} 

void transmitByte(unsigned char data) {
  while(!(SPI0SR&0x20)) {}  // 1) wait for SPTEF to be 1, SPI0SR
  SPI0DR = data;            // 2) write 8-bit data to SPI0DR
  while(!(SPI0SR&0x80)) {}  // 3) wait for SPIF to be 1, SPI0SR
  data = SPI0DR;            // 4) clear the SPIF flag by reading the data
                            // dummy = SPI0DR;
}

void DAC_Out(unsigned short data) {
  PTIS &= ~0x80;                    // 1) set PS7=CS low
  transmitByte((data&0x3F00) >> 8); // 2) transmit most significant 8-bit data to the DAC
  transmitByte(data&0x00FF);        // 3) transmit least significant 8-bit data to the DAC
  PTIS |=  0x80;                    // 4) set PS7=CS high
}