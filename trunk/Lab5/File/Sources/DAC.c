#include "DAC.h"

// 9S12DP512 SPI1 interface to Max539
// PS6 (out) SCLK synchronous clock
// PS5 (out) MOSI serial data output
// PS7 (out) CS used to latch data into Max539
// PS4 (in) is associated with SPI1, but not used

//---------------------DAC_Init---------------------
// initializes DAC
// Input: none
// Output: none             
void DAC_Init(void) {
  DDRS |=  0xE0;  // 1) make PS5, PS6, PS7 outputs, PS4 input
  DDRS &= ~0x10;  // DDRS                  
  SPI0CR1 = 0x58; // 2) enable SPI, no interrupts, master, CPOL=1, CPHA=0
                  // SPI0CR1 = 0101 1000
  SPI0CR2 = 0x00; // 3) set up PS7 as a regular output
                  // SSOE=0, MODFEN=0 SPI0CR1, SPI0CR2
  SPI0BR = 0x00;  // 4) set the baud rate, SPI0BR
  PTS  |= 0x80;   // 5) make PS7=CS high
}

//---------------------transmitByte---------------------
// outputs byte to DAC
// Input: none
// Output: none
void transmitByte(unsigned char data) {
  unsigned char dummy;
  while(!(SPI0SR&0x20)) {}  // 1) wait for SPTEF to be 1, SPI0SR
  SPI0DR = data;            // 2) write 8-bit data to SPI0DR
  while(!(SPI0SR&0x80)) {}  // 3) wait for SPIF to be 1, SPI0SR
  dummy = SPI0DR;            // 4) clear the SPIF flag by reading the data
                            // dummy = SPI0DR;
}

//---------------------DAC_Out---------------------
// outputs 12 bits to DAC
// Input: none
// Output: none 
void DAC_Out(unsigned char data) {       
  PTS &= ~0x80;                    // 1) set PS7=CS low
  //transmitByte((data&0x3F00) >> 8); // 2) transmit most significant 8-bit data to the DAC
  transmitByte(0);
  transmitByte(data);        // 3) transmit least significant 8-bit data to the DAC
  PTS |=  0x80;                    // 4) set PS7=CS high
}