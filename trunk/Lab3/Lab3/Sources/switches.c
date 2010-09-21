#include "switches.h"

#define BOUNCE_DELAY 3125
                  
unsigned int alarmSet;                 
signed short setHours;
signed short setMinutes;
signed short alarmHours;
signed short alarmMinutes;

void switchInit(void) {
  alarmSet = 0; 
  setHours = 0;
  setMinutes = 0;
  alarmHours = 0;
  alarmMinutes = 0;
  DDRP &= ~0x7E;
  PIEP |= 0x7E;
  //PPSP |= 0x7E;  
  PPSP &= ~0x7E;
  PIFP = 0x7E;
}

interrupt 56 void switchHandler() {
  unsigned static long startTime = 0;
  if(TCNT - startTime > BOUNCE_DELAY) {
    if(alarmOn) {
      alarmOn = 0;
      alarmSet = 0;
      PIFP = 0x7E;
    }
    else {
      if(PIFP & 0x02) {
        alarmSet = ~alarmSet;
        PIFP = 0x02;
      } 
      if(PIFP & 0x04) {  
        if(PTP & 0x40) {
          alarmMinutes++;
        }
        else {
          seconds = 0; 
          minutes++;
        }
        PIFP = 0x04;
      }
      if(PIFP & 0x08) {      
        if(PTP & 0x40) {
          alarmMinutes--;
        }
        else {          
          seconds = 0; 
          minutes--;
        }
        PIFP = 0x08;
      }
      if(PIFP & 0x10) {       
        if(PTP & 0x40) {
          alarmHours++;
        }
        else {     
          seconds = 0;
          hours++;
        }
        PIFP = 0x10;
      }
      if(PIFP & 0x20) {      
        if(PTP & 0x40) {
          alarmHours--;
        }
        else {    
          seconds = 0; 
          hours--;
        }
        PIFP = 0x20;
      }
      if(PIFP & 0x40) {
        PIFP = 0x40;
      }
      
      /*if(setHours >= 24) {
        setHours = 0;
      }
      if(setHours < 0) {
        setHours = 23;
      }
      
      if(setMinutes >= 60) {
        setMinutes = 0;
      }
      if(setMinutes < 0) {
        setMinutes = 59;
      }          */
      
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
      
      if(alarmHours >= 24) {
        alarmHours = 0;
      }
      if(alarmHours < 0) {
        alarmHours = 23;
      }
      if(alarmMinutes >= 60) {
        alarmMinutes = 0;
      }
      if(alarmMinutes < 0) {
        alarmMinutes = 59;
      }     
    }
    startTime = TCNT; 
  }
  else {
    PIFP = 0x7E; 
  }
}