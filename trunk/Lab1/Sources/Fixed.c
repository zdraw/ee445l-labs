#include <stdio.h>

//---------------------Fixed_uDecOut2---------------------
// Takes an unsigned 16-bit integer part of the 
// fixed-point number and outputs the fixedpoint
// value on the LCD
// Input: 16-bit unsigned integer
// Output: true if successful
unsigned short Fixed_uDecOut2(unsigned short integer) {
  if(integer > 65534) { // Out of range is an error
    printf("***.**");
    return 0;
  }
  else { // Splits into integer part and decimal part
    printf("%3d.%02d", integer/100, integer%100);
    return 1;
  }
}
  
  
unsigned short Fixed_sDecOut3(signed short integer) {
  if(integer < -9999 || integer > 9999) { // Out of range is an error
    printf(" *.***");
    return 0;
  }
  else { // Splits into integer part and decimal part
    if(integer < 0) { // Prints negative sign
      integer *= -1;
      printf("-%1d.%03d", integer/1000, integer%1000);
    } 
    else { // Does not print negative sign
      printf(" %1d.%03d", integer/1000, integer%1000);
    }
    return 1;
  }
}
   
   
unsigned short Fixed_uBinOut8(unsigned short integer) {
  if(integer > 65534) { // Out of range is an error
    printf("***.**");
    return 0;
  } 
  else {
    unsigned short newInt = (((unsigned long) integer)*100) >> 8; // Bit shifts to proper value
    printf("%3d.%02d", newInt/100, newInt%100); // Splits into integer part and decimal part
    return 1;
  }   
}