#include <hidef.h>      /* common defines and macros */
#include <mc9s12dp512.h>     /* derivative information */
#pragma LINK_INFO DERIVATIVE "mc9s12dp512"
              
#include "PLL.h"
#include "DAC.h"
#include "music.h"
#include "switch.h"

unsigned static short note = 0;
unsigned static short note2 = 0;
unsigned static short note3 = 0;
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
unsigned static short envelope1 = 1;
unsigned static short envelope2 = 1;
unsigned static short envelope3 = 1;          
void initOC2(void){
  TIOS |= 0x04;   // activate TC0 as output compare
  TIE  |= 0x04;   // arm OC0
  TC2   = TCNT+50;// first interrupt right away
  //PTP |= 0x80;
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
  
  if(melody[note].frequency) {
    DAC_Out((SinWave[i%SIN] * envelope1) + output1 + output2);
    output0 = SinWave[i%SIN] * envelope1; 
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
  unsigned static short interrupts3 = 0;
  
  TFLG1 = 0x02; 
  interrupts++;
  interrupts2++;
  interrupts3++;
  
                                
  if(interrupts >= melody[note].length) {
      if(PTP&0x01) {
        note--;
      }
      else {
        note++;
        if(note >= MELODY) {
          note = MREPEAT;  
        }
      }
      interrupts = 0;
      envelope1 = 1;
  }
  else if(interrupts >= (melody[note].length*2)/3) {
    envelope1 = 0;  
  }
  
  if(interrupts2 >= bass1[note2].length) {
      if(PTP&0x01) {
        note2--;
      }
      else {
        note2++;
        if(note2 >= BASS1) {
          note2 = B1REPEAT;  
        }      
      }
      interrupts2 = 0;
      envelope2 = 1;
  }
  else if(interrupts2 >= (bass1[note2].length*2)/3) {
    envelope2 = 0;  
  }
  
  if(interrupts3 >= bass2[note3].length) {
      if(PTP&0x01) {
        note3--;
      }
      else {
        note3++; 
        if(note3 >= BASS2) {
          note3 = B2REPEAT;  
        }      
      }
      interrupts3 = 0;
      envelope3 = 1;
  }
  else if(interrupts3 >= (bass2[note3].length*2)/3) {
    envelope3 = 0;  
  }
  
  TC1 = TC1 + 32000;
      
}

/*interrupt 8 void TC0Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x01;
  
  DAC_Out(SinWave[i%SIN]);
  i++;
  
  TC0 = TC0 + 677;   
}   
               
interrupt 9 void TC1Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x02;
  
  DAC_Out(SinWave[i%SIN]);
  i++;
  
  TC1 = TC1 + 1138;
      
} */

interrupt 10 void TC2Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x04;
  
  
  if(bass1[note2].frequency) {
    DAC_Out((SinWave[i%SIN] * envelope2) + output0 + output2);
    output1 = SinWave[i%SIN] * envelope2;   
    i++;
    TC2 = TC2 + bass1[note2].frequency;
  }
  else {
    output1 = 0;
    TC2 = TC2 + 480;  
  }
} 

interrupt 11 void TC3Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x08;
  
  
  if(note3 < BASS2 && bass2[note3].frequency) {
    DAC_Out((SinWave[i%SIN] * envelope3) + output0 + output1);
    output2 = SinWave[i%SIN] * envelope3;   
    i++;
    TC3 = TC3 + bass2[note3].frequency;
  }
  else {
    output2 = 0;
    TC3 = TC3 + 480;  
  }
}  

void main(void) {
  PLL_Init(); 
  DAC_Init();
  Switch_Init();
  initOC0();
  initOC1();
  initOC2();
  initOC3();
  
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