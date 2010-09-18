#include "switches.h"
                  
unsigned int alarmSet;                 
unsigned short hours;
unsigned short minutes;
unsigned short alarmHours;
unsigned short alarmMinutes;

void switchInit(void) {
  alarmSet = 0; 
  hours = 0;
  minutes = 0;
  alarmHours = 0;
  alarmMinutes = 0;
  DDRP &= ~0x7E;
  PIEP |= 0x7E;
  PPSP |= 0x7E;  
  PIFP = 0x7E;
}

interrupt 56 void switchHandler() {
  if(alarmOn) {
    alarmOn = 0; 
  }
  else {
    if(PIFP & 0x02) {
      PIFP = 0x02;
      PTT ^= 0x04;
    } 
    if(PIFP & 0x04) {
      seconds -= seconds%60;   
      if(PTP & 0x40) {
        alarmMinutes--;
      }
      else {
        minutes--;
      }
      PIFP = 0x04;
      PTT ^= 0x08;
    }
    if(PIFP & 0x08) {      
      seconds -= seconds%60; 
      if(PTP & 0x40) {
        alarmMinutes++;
      }
      else {
        minutes++;
      }
      PIFP = 0x08;
      PTT ^= 0x10;
    }
    if(PIFP & 0x10) {      
      seconds -= seconds%60; 
      if(PTP & 0x40) {
        alarmHours--;
      }
      else {
        hours--;
      }
      PIFP = 0x10;
      PTT ^= 0x20;
    }
    if(PIFP & 0x20) {      
      seconds -= seconds%60; 
      if(PTP & 0x40) {
        alarmHours++;
      }
      else {
        hours++;
      }
      PIFP = 0x20;
      PTT ^= 0x40;
    }
    if(PIFP & 0x40) {
      PIFP = 0x40;
      PTT ^= 0x80;
    }
    if(hours >= 24) {
      hours = 0;
    }
    if(hours < 0) {
      hours = 23;
    }
    if(minutes >= 60) {
      minutes = 0;
    }
    if(minutes < 0) {
      minutes = 59;
    }      
  }
}