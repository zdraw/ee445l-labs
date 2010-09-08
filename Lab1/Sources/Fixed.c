#include <stdio.h>

unsigned short Fixed_uDecOut2(unsigned short integer) {
  if(integer > 65534) {
    printf("***.**");
    return 0;
  }
  else {
    printf("%3d.%02d", integer/100, integer%100);
    return 1;
  }
}
  
  
unsigned short Fixed_sDecOut3(signed short integer) {
  if(integer < -9999 || integer > 9999) {
    printf(" *.***");
    return 0;
  }
  else {
    if(integer < 0) {
      integer *= -1;
      printf("-%1d.%03d", integer/1000, integer%1000);
    } 
    else {
      printf(" %1d.%03d", integer/1000, integer%1000);
    }
    return 1;
  }
}
   
   
unsigned short Fixed_uBinOut8(unsigned short integer) {
  if(integer > 65534) {
    printf("***.**");
    return 0;
  } 
  else {
    unsigned short newInt = (((unsigned long) integer)*100)/256;
    printf("%3d.%02d", newInt/100, newInt%100);
    return 1;
  }   
}

unsigned short Fixed_uBinOut8s(unsigned short integer, char* buffer) {
  if(integer > 65534) {
    sprintf(buffer,"***.**");
    return 0;
  } 
  else {
    unsigned short newInt = (((unsigned long) integer)*100)/256;
    sprintf(buffer,"%3d.%02d", newInt/100, newInt%100);
    return 1;
  }   
}