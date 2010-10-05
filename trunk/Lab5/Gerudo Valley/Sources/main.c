#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
              
#include "PLL.h"
#include "DAC.h"
#include "music.h"
#include "switch.h"

unsigned static short note = 0;
unsigned static short note2 = 0;
//---------------------initOC0---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC0(void){
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x00;   // divide by 128 TCNT prescale, TOI disarm, sets period to 5.33us
  PACTL = 0;      // timer prescale used for TCNT
  DDRP |= 0x80;
  
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TC0   = TCNT+50;// first interrupt right away
}

//---------------------initOC1---------------------
// arm output compare 0 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC1(void){
  TIOS |= 0x02;   // activate TC0 as output compare
  TIE  |= 0x02;   // arm OC0
  TC1   = TCNT+50;// first interrupt right away
}

//---------------------initOC2---------------------
// arm output compare 2 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none    
unsigned static short envelope1;
unsigned static short envelope2;           
void initOC2(void){
  TIOS |= 0x04;   // activate TC0 as output compare
  TIE  |= 0x04;   // arm OC0
  TC2   = TCNT+50;// first interrupt right away
  PTP |= 0x80;
}

//---------------------initOC3---------------------
// arm output compare 3 for 1 Hz periodic interrupt
// also enables timer to 16 us period
// Input: none
// Output: none               
void initOC3(void){  
  TIOS |= 0x08;   // activate TC0 as output compare
  TIE  |= 0x08;   // arm OC0
  TC3   = TCNT+50;// first interrupt right away
}         

unsigned static short output0, output1, output2;

interrupt 8 void TC0Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x01;
  
  if(note < MELODY && melody[note].frequency) {
    DAC_Out((SinWave[i%PROCEDURE] * envelope1) + output1 + output2);
    output0 = SinWave[i%PROCEDURE] * envelope1; 
    i++;
    TC0 = TC0 + melody[note].frequency;
  }
  else {
    output0 = 0;
    TC0 = TC0 + 480;  
  }      
}   
               
interrupt 9 void TC1Handler() {
  unsigned static short interrupts = 0;
  unsigned static short interrupts2 = 0;
  
  TFLG1 = 0x02; 
  interrupts++;
  interrupts2++;
  
  envelope1 = (interrupts <= 50 ? 1 : 0);
  envelope2 = (interrupts2 <= 50 ? 1 : 0);
  
  
  if(interrupts >= melody[note].length) {
      if(PTP&0x01) {
        note--;
      }
      else {
        note++;      
      }
      interrupts = 0;
      envelope1 = 1;
  }
  if(interrupts2 >= bass[note2].length) {
      if(PTP&0x01) {
        note2--;
      }
      else {
        note2++;      
      }
      interrupts2 = 0;
      envelope2 = 1;
  }
  
  TC1 = TC1 + 60000;
      
} 

interrupt 10 void TC2Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x04;
  
  
  if(note < HARMONY && harmony[note].frequency) {
    DAC_Out((SinWave[i%32] * envelope1) + output0 + output2);
    output1 = SinWave[i%32] * envelope1;   
    i++;
    TC2 = TC2 + harmony[note].frequency;
  }
  else {
    output1 = 0;
    TC2 = TC2 + 480;  
  }
} 
 

interrupt 11 void TC3Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x08;
  
  if(note2 < BASS && bass[note2].frequency) {
    DAC_Out((SinWave[i%32] * envelope2) + output0 + output1);
    output2 = SinWave[i%32] * envelope2; 
    i++;
    TC3 = TC3 + bass[note2].frequency;
  }
  else {
    output2 = 0;
    TC3 = TC3 + 480;  
  }      
}  

void main(void) {
unsigned char i = 0;
  PLL_Init(); 
  DAC_Init();
  Switch_Init();
  initOC0();
  initOC1();
  #if PROCEDURE == 32
    initOC2();
    initOC3();
  #endif
  
  asm sei
      
  for(;;) {
    if(PTP&0x08) {
      asm cli  
    }
    if(PTP&0x04) {
      asm sei 
    }
    if(PTP&0x02) {
      note = 0;
      note2 = 0;
    }
  }
}