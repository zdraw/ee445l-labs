#include "OC.h"

interrupt 8 void TOC0handler(void){ // executes at 100 Hz 
  TFLG1 = 0x01;         // acknowledge OC0
  seconds++;
  TC0 = TC0+62500;      // 1 s
  //PTP ^= 0x80;          // debugging monitor
}

//---------------------OC_Init0---------------------
// arm output compare 0 for 100Hz periodic interrupt
// Input: none
// Output: none 
void OC_Init0(){
  seconds = 0;     // debugging monitor
  DDRP |= 0x80;   // debugging monitor
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x07;   // divide by 8 TCNT prescale, TOI disarm
  PACTL = 0;      // timer prescale used for TCNT
/* Bottom three bits of TSCR2 (PR2,PR1,PR0) set TCNT period
    divide  FastMode(24MHz)    Slow Mode (8MHz)
000   1     42ns  TOF  2.73ms  125ns TOF  8.192ms
001   2     84ns  TOF  5.46ms  250ns TOF 16.384ms 
010   4    167ns  TOF  10.9ms  500ns TOF 32.768ms     
011   8    333ns  TOF  21.8ms    1us TOF 65.536ms
100  16    667ns  TOF  43.7ms    2us TOF 131.072ms
101  32   1.33us  TOF  87.4ms    4us TOF 262.144ms
110  64   2.67us  TOF 174.8ms    8us TOF 524.288ms
111 128   5.33us  TOF 349.5ms   16us TOF 1.048576s*/
  TC0   = TCNT+50; // first interrupt right away
}  

void OC_Init1() {
  alarmOn = 0;
  DDRP |= 0x01;
  DDRT |= 0xFC;
  TIOS |= 0x02;
  TIE |= 0x02;
  TC1 = TCNT+50;   
}

interrupt 9 void TOC1handler(void) {
  static short thingies = 0;
  TFLG1 = 0x02;
  if(alarmOn) {
    thingies++;
    PTP ^= 0x01;
    if(thingies >= 400) {
      PTT ^= 0xFC;
      thingies = 0;
    }
  }
  TC1 = TCNT + 39;
}