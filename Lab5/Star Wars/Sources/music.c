#include "music.h"
#include "DAC.h"
#include "switch.h"

// Note index for each part
unsigned static short note1 = 0;
unsigned static short note2 = 0;
unsigned static short note3 = 0;

// Output for each part
unsigned static short output1 = 0;
unsigned static short output2 = 0;
unsigned static short output3 = 0;

// Envelope multiplier for each part
unsigned static short envelope1 = 1;
unsigned static short envelope2 = 1;
unsigned static short envelope3 = 1;

// Number of envelope interrupts for each part
unsigned static short interrupts1 = 1;
unsigned static short interrupts2 = 1;
unsigned static short interrupts3 = 1;

// Stores sin wave
const unsigned short SinWave[SIN] = {
  683,
  944,
  1165,
  1313,
  1365,
  1313,
  1165,
  944,
  683,
  422,
  201,
  53,
  1,
  53,
  201,
  422
};

const NoteType melody[MELODY] = {
  {FREQUENCY/466,600},
  {0,100},
  {0,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,225},
  {FREQUENCY/415,75},
  {FREQUENCY/466,300},
  {0,100},
  {0,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,225},
  {FREQUENCY/415,75},
  {FREQUENCY/466,300},
  {0,100},
  {0,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,100},
  {FREQUENCY/466,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,150},
  {FREQUENCY/466,300},
  {FREQUENCY/349,525},
  {FREQUENCY/466,75},
  {FREQUENCY/466,75},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/622,75},
  {FREQUENCY/698,600},
  {0,150},
  {FREQUENCY/698,150},
  {FREQUENCY/698,100},
  {FREQUENCY/740,100},
  {FREQUENCY/831,100},
  {FREQUENCY/932,600},
  {0,100},
  {FREQUENCY/932,100},
  {FREQUENCY/932,100},
  {FREQUENCY/932,100},
  {FREQUENCY/831,100},
  {FREQUENCY/740,100},
  {FREQUENCY/831,225},
  {FREQUENCY/740,75},
  {FREQUENCY/698,600},
  {FREQUENCY/698,300},
  {FREQUENCY/622,150},
  {FREQUENCY/622,75},
  {FREQUENCY/698,75},
  {FREQUENCY/740,600},
  {FREQUENCY/698,150},
  {FREQUENCY/622,150},
  {FREQUENCY/554,150},
  {FREQUENCY/554,75},
  {FREQUENCY/622,75},
  {FREQUENCY/698,600},
  {FREQUENCY/622,150},
  {FREQUENCY/554,150},
  {FREQUENCY/523,150},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/659,600},
  {FREQUENCY/784,300},
  {FREQUENCY/698,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,150},
  {FREQUENCY/466,300},
  {FREQUENCY/349,525},
  {FREQUENCY/466,75},
  {FREQUENCY/466,75},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/622,75},
  {FREQUENCY/698,600},
  {0,150},
  {FREQUENCY/698,150},
  {FREQUENCY/698,100},
  {FREQUENCY/740,100},
  {FREQUENCY/831,100},
  {FREQUENCY/932,600},
  {0,300},
  {FREQUENCY/1109,300},
  {FREQUENCY/1047,300},
  {FREQUENCY/880,300},
  {0,300},
  {FREQUENCY/698,300},
  {FREQUENCY/740,600},
  {0,300},
  {FREQUENCY/932,300},
  {FREQUENCY/880,300},
  {FREQUENCY/698,300},
  {0,300},
  {FREQUENCY/698,300},
  {FREQUENCY/740,600},
  {0,300},
  {FREQUENCY/932,300},
  {FREQUENCY/880,300},
  {FREQUENCY/698,300},
  {0,300},
  {FREQUENCY/587,300},
  {FREQUENCY/622,600},
  {0,300},
  {FREQUENCY/740,300},
  {FREQUENCY/698,300},
  {FREQUENCY/554,300},
  {0,300},
  {FREQUENCY/466,300},
  {FREQUENCY/523,150},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/659,300},
  {0,300},
  {FREQUENCY/784,300},
  {FREQUENCY/698,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/349,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,150}
};

const NoteType harmony[HARMONY] = {
  {FREQUENCY/294,600},
  {0,100},
  {0,100},
  {FREQUENCY/294,100},
  {FREQUENCY/294,100},
  {FREQUENCY/294,100},
  {FREQUENCY/294,100},
  {FREQUENCY/262,225},
  {FREQUENCY/262,75},
  {FREQUENCY/262,300},
  {0,300},
  {FREQUENCY/262,100},
  {FREQUENCY/262,100},
  {FREQUENCY/262,100},
  {FREQUENCY/277,225},
  {FREQUENCY/277,75},
  {FREQUENCY/277,300},
  {0,100},
  {0,100},
  {FREQUENCY/277,100},
  {FREQUENCY/277,100},
  {FREQUENCY/277,100},
  {FREQUENCY/277,100},
  {FREQUENCY/277,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,150},
  {FREQUENCY/294,300},
  {FREQUENCY/294,100},
  {FREQUENCY/294,100},
  {FREQUENCY/262,100},
  {FREQUENCY/294,225},
  {FREQUENCY/294,75},
  {FREQUENCY/294,75},
  {FREQUENCY/311,75},
  {FREQUENCY/349,75},
  {FREQUENCY/392,75},
  {FREQUENCY/415,225},
  {FREQUENCY/466,75},
  {FREQUENCY/466,75},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/622,75},
  {FREQUENCY/698,300},
  {FREQUENCY/415,100},
  {FREQUENCY/466,100},
  {FREQUENCY/523,100},
  {FREQUENCY/554,225},
  {FREQUENCY/370,75},
  {FREQUENCY/370,75},
  {FREQUENCY/415,75},
  {FREQUENCY/466,75},
  {FREQUENCY/523,75},
  {FREQUENCY/554,200},
  {FREQUENCY/554,100},
  {FREQUENCY/554,100},
  {FREQUENCY/523,100},
  {FREQUENCY/466,100},
  {FREQUENCY/554,225},
  {FREQUENCY/415,75},
  {FREQUENCY/415,100},
  {FREQUENCY/415,100},
  {FREQUENCY/370,100},
  {FREQUENCY/415,225},
  {FREQUENCY/415,75},
  {FREQUENCY/415,100},
  {FREQUENCY/370,100},
  {FREQUENCY/415,100},
  {FREQUENCY/370,150},
  {FREQUENCY/370,75},
  {FREQUENCY/349,75},
  {FREQUENCY/370,150},
  {FREQUENCY/370,75},
  {FREQUENCY/415,75},
  {FREQUENCY/466,300},
  {FREQUENCY/415,150},
  {FREQUENCY/370,150},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/311,75},
  {FREQUENCY/349,150},
  {FREQUENCY/349,75},
  {FREQUENCY/370,75},
  {FREQUENCY/415,300},
  {FREQUENCY/370,150},
  {FREQUENCY/349,150},
  {FREQUENCY/330,300},
  {FREQUENCY/330,150},
  {FREQUENCY/330,75},
  {FREQUENCY/349,75},
  {FREQUENCY/392,150},
  {FREQUENCY/392,75},
  {FREQUENCY/440,75},
  {FREQUENCY/466,150},
  {FREQUENCY/523,150},
  {FREQUENCY/440,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,150},
  {FREQUENCY/294,300},
  {FREQUENCY/294,100},
  {FREQUENCY/294,100},
  {FREQUENCY/262,100},
  {FREQUENCY/294,225},
  {FREQUENCY/294,75},
  {FREQUENCY/294,75},
  {FREQUENCY/311,75},
  {FREQUENCY/349,75},
  {FREQUENCY/392,75},
  {FREQUENCY/415,225},
  {FREQUENCY/466,75},
  {FREQUENCY/466,75},
  {FREQUENCY/523,75},
  {FREQUENCY/587,75},
  {FREQUENCY/622,75},
  {FREQUENCY/698,300},
  {FREQUENCY/415,100},
  {FREQUENCY/466,100},
  {FREQUENCY/523,100},
  {FREQUENCY/554,600},
  {0,300},
  {FREQUENCY/659,300},
  {FREQUENCY/622,300},
  {FREQUENCY/523,300},
  {0,300},
  {FREQUENCY/440,300},
  {FREQUENCY/494,600},
  {0,300},
  {FREQUENCY/554,300},
  {FREQUENCY/523,300},
  {FREQUENCY/440,300},
  {0,300},
  {FREQUENCY/440,300},
  {FREQUENCY/494,600},
  {0,300},
  {FREQUENCY/554,300},
  {FREQUENCY/523,300},
  {FREQUENCY/440,300},
  {0,300},
  {FREQUENCY/440,300},
  {FREQUENCY/370,600},
  {0,300},
  {FREQUENCY/494,300},
  {FREQUENCY/466,300},
  {FREQUENCY/349,300},
  {0,300},
  {FREQUENCY/277,300},
  {FREQUENCY/330,300},
  {FREQUENCY/330,150},
  {FREQUENCY/330,75},
  {FREQUENCY/349,75},
  {FREQUENCY/392,150},
  {FREQUENCY/392,75},
  {FREQUENCY/440,75},
  {FREQUENCY/466,150},
  {FREQUENCY/523,150},
  {FREQUENCY/440,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,75},
  {FREQUENCY/220,75},
  {FREQUENCY/220,150},
  {FREQUENCY/220,150}
};

const NoteType bass[BASS] = {
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/104,300},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/104,300},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/92,300},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/92,300},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/98,150},
  {FREQUENCY/110,150},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/104,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,300},
  {FREQUENCY/104,300},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/92,100},
  {FREQUENCY/104,300},
  {FREQUENCY/104,300},
  {FREQUENCY/92,300},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/82,100},
  {FREQUENCY/92,300},
  {FREQUENCY/92,300},
  {FREQUENCY/139,300},
  {FREQUENCY/139,100},
  {FREQUENCY/139,100},
  {FREQUENCY/131,100},
  {FREQUENCY/139,300},
  {FREQUENCY/139,300},
  {FREQUENCY/123,300},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/117,100},
  {FREQUENCY/123,300},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/104,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/131,300},
  {FREQUENCY/131,100},
  {FREQUENCY/131,100},
  {FREQUENCY/123,100},
  {FREQUENCY/131,300},
  {FREQUENCY/131,100},
  {FREQUENCY/131,100},
  {FREQUENCY/131,100},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/98,150},
  {FREQUENCY/110,150},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/104,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,300},
  {FREQUENCY/104,300},
  {FREQUENCY/104,100},
  {FREQUENCY/104,100},
  {FREQUENCY/92,100},
  {FREQUENCY/104,300},
  {FREQUENCY/104,300},
  {FREQUENCY/92,300},
  {FREQUENCY/92,100},
  {FREQUENCY/92,100},
  {FREQUENCY/82,100},
  {FREQUENCY/92,300},
  {FREQUENCY/92,300},
  {FREQUENCY/87,300},
  {FREQUENCY/87,100},
  {FREQUENCY/87,100},
  {FREQUENCY/82,100},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/82,100},
  {FREQUENCY/117,100},
  {FREQUENCY/139,100},
  {FREQUENCY/165,100},
  {FREQUENCY/233,100},
  {FREQUENCY/277,100},
  {FREQUENCY/330,300},
  {0,300},
  {FREQUENCY/349,300},
  {FREQUENCY/87,100},
  {FREQUENCY/87,100},
  {FREQUENCY/87,100},
  {FREQUENCY/87,300},
  {0,300},
  {FREQUENCY/82,100},
  {FREQUENCY/117,100},
  {FREQUENCY/139,100},
  {FREQUENCY/165,100},
  {FREQUENCY/233,100},
  {FREQUENCY/277,100},
  {FREQUENCY/330,300},
  {0,300},
  {FREQUENCY/349,300},
  {FREQUENCY/87,100},
  {FREQUENCY/87,100},
  {FREQUENCY/87,100},
  {FREQUENCY/87,300},
  {0,300},
  {FREQUENCY/123,300},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/117,100},
  {FREQUENCY/123,300},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/123,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/104,100},
  {FREQUENCY/117,300},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/117,100},
  {FREQUENCY/131,300},
  {FREQUENCY/131,100},
  {FREQUENCY/131,100},
  {FREQUENCY/123,100},
  {FREQUENCY/65,300},
  {FREQUENCY/65,100},
  {FREQUENCY/65,100},
  {FREQUENCY/65,100},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/87,300},
  {FREQUENCY/98,150},
  {FREQUENCY/110,150}
};

//---------------------Music_InitOC0---------------------
// arm output compare 0 for melody
// also enables timer to 43 ns period
// Input: none
// Output: none               
void Music_InitOC0(void){
  TSCR1 = 0x80;   // Enable TCNT, 24MHz boot mode, 8MHz in run mode
  TSCR2 = 0x00;   // divide by 1 TCNT prescale, TOI disarm, sets period to 42.67 ns
  PACTL = 0;      // timer prescale used for TCNT
  
  TIOS |= 0x01;   // activate TC0 as output compare
  TIE  |= 0x01;   // arm OC0
  TC0   = TCNT+50;// first interrupt right away
}

//---------------------Music_InitOC1---------------------
// arm output compare 1 for harmony
// Input: none
// Output: none               
void Music_InitOC1(void){
  TIOS |= 0x02;   // activate TC1 as output compare
  TIE  |= 0x02;   // arm OC1
  TC1   = TCNT+50;// first interrupt right away
}

//---------------------Music_InitOC2---------------------
// arm output compare 2 for bass
// Input: none
// Output: none             
void Music_InitOC2(void){
  TIOS |= 0x04;   // activate TC1 as output compare
  TIE  |= 0x04;   // arm OC1
  TC2   = TCNT+50;// first interrupt right away
}

//---------------------Music_InitOC3---------------------
// arm output compare 3 for envelopes at 750 Hz
// Input: none
// Output: none               
void Music_InitOC3(void){  
  TIOS |= 0x08;   // activate TC1 as output compare
  TIE  |= 0x08;   // arm OC1
  TC3   = TCNT+50;// first interrupt right away
}          

// OC handler for melody
interrupt 8 void TC0Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x01;
  
  // Checks if the note is a rest
  if(melody[note1].frequency) {
    // Outputs the proper sin value plus the other two lines' outputs to the DAC
    DAC_Out((SinWave[i%SIN] * envelope1) + output2 + output3);
    // Sets output1 to the proper sin value
    output1 = SinWave[i%SIN] * envelope1; 
    i++;
    // Sets the next interrupt according to the frequency    
    TC0 = TC0 + melody[note1].frequency;
  }
  else {
    // Sets output to zero
    output1 = 0;
    // Arbitrary next interrupt to check if note changed
    TC0 = TC0 + 480;  
  }      
}   
    
// OC handler for harmony
interrupt 9 void TC1Handler() { 
  unsigned static char i = 0;
  
  TFLG1 = 0x02;
  
  if(harmony[note2].frequency) {   
    // Outputs the proper sin value plus the other two lines' outputs to the DAC
    DAC_Out((SinWave[i%SIN] * envelope2) + output1 + output3);   
    // Sets output1 to the proper sin value
    output2 = SinWave[i%SIN] * envelope2;   
    i++;                             
    // Sets the next interrupt according to the frequency 
    TC1 = TC1 + harmony[note2].frequency;
  }
  else {  
    // Sets output to zero
    output2 = 0;       
    // Arbitrary next interrupt to check if note changed
    TC1 = TC1 + 480;  
  }  
  
}

interrupt 10 void TC2Handler() {
  unsigned static char i = 0;
  
  TFLG1 = 0x04;     
                                  
  if(note3 < BASS && bass[note3].frequency) {     
    // Outputs the proper sin value plus the other two lines' outputs to the DAC
    DAC_Out((SinWave[i%SIN] * envelope3) + output1 + output2);        
    // Sets output1 to the proper sin value
    output3 = SinWave[i%SIN] * envelope3;   
    i++;                                    
    // Sets the next interrupt according to the frequency 
    TC2 = TC2 + bass[note3].frequency;
  }
  else {                  
    // Sets output to zero
    output3 = 0;     
    // Arbitrary next interrupt to check if note changed
    TC2 = TC2 + 480;  
  }
} 

interrupt 11 void TC3Handler() {   
  TFLG1 = 0x08;
  
  // Counts number of interrupts triggered for each note
  interrupts1++;
  interrupts2++;
  interrupts3++;
  
  // Checks if note is finished                              
  if(interrupts1 >= melody[note1].length) {
      // If reverse button is pushed, decrement note
      if(Switch_Data()&0x01) {
        note1--;
      }
      // Otherwise, increment note
      else {
        note1++;
        // If note is past the end of the song, repeat
        if(note1 >= MELODY) {
          note1 = MREPEAT;  
        }
      }
      // Reset counter and envelope for next note
      interrupts1 = 0;
      envelope1 = 1;
  }
  // Set envelope for only 2/3 of note length
  else if(interrupts1 >= (melody[note1].length*2)/3) {
    envelope1 = 0;  
  }
  
  // Checks if note is finished     
  if(interrupts2 >= harmony[note2].length) {         
      // If reverse button is pushed, decrement note
      if(Switch_Data()&0x01) {
        note2--;
      }                    
      // Otherwise, increment note
      else {
        note2++;     
        // If note is past the end of the song, repeat
        if(note2 >= HARMONY) {
          note2 = HREPEAT;  
        }      
      }        
      // Reset counter and envelope for next note
      interrupts2 = 0;
      envelope2 = 1;
  }  
  // Set envelope for only 2/3 of note length
  else if(interrupts2 >= (harmony[note2].length*2)/3) {
    envelope2 = 0;  
  }
  
  // Checks if note is finished     
  if(interrupts3 >= bass[note3].length) {
      if(Switch_Data()&0x01) {       
      // If reverse button is pushed, decrement note
        note3--;
      }                       
      // Otherwise, increment note
      else {
        note3++;   
        // If note is past the end of the song, repeat
        if(note3 >= BASS) {
          note3 = BREPEAT;  
        }      
      }    
      // Reset counter and envelope for next note
      interrupts3 = 0;
      envelope3 = 1;
  }        
  // Set envelope for only 2/3 of note length
  else if(interrupts3 >= (bass[note3].length*2)/3) {
    envelope3 = 0;  
  }
  
  TC3 = TC3 + 32000;
}

//---------------------Music_Restart---------------------
// Restarts music
// Input: none
// Output: none               
void Music_Restart(void) {
  note1 = 0;
  note2 = 0;
  note3 = 0;
  
  interrupts1 = 0;
  interrupts2 = 0;
  interrupts3 = 0;
  
  envelope1 = 1;
  envelope2 = 1;
  envelope3 = 1;
}

