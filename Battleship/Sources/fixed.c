// ****************fixed.c********
// Implementation of fixed point routines
// Jonathan W. Valvano 1/27/09

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//         Engineering, copyright (c) 2006,
//   "Introduction to Embedded Microcomputer Systems: 
//    Motorola 6811 and 6812 Simulation", Thomson, copyright (c) 2002

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 



//**********Sqrt**********
// sqrt for 16-bit integers
// input: 16-bit unsigned number
// output: sqrt(input)
// e.g., sqrt(1600) = 40
// no overflow error possible
unsigned short Sqrt(unsigned short s){ 
  unsigned t,oldt;
  unsigned short count=20;  
  t = 0;       // secant method
  if(s>0){
     t = 100;   // initial guess 100
     do{
       if((--count) == 0) return (unsigned short) t;
       oldt = t;  // from the last 
//       t = ((t*t+s)/t)/2;
  asm ldd  t
  asm tfr  d,y
  asm emul        //32-bit Y:D is t*t
  asm addd s
  asm exg d,y
  asm adcb #0
  asm adca #0    // carry from lsw
  asm exg d,y
  asm ldx t
  asm ediv
  asm tfr y,d
  asm lsrd
  asm std t
     } 
     while(t != oldt);
  }     
  return (unsigned short) t;
}

//**********Fixed_uMult2**********
// multiply for decimal fixed-point numbers with 0.01 resolution
// inputs: two integer parts of unsigned fixed-point numbers
// output: integer part of the product of the two inputs
//         result =(n1*n2)/100
// e.g., mult(16.00*2.50) = 40.00, 1600,250 -> 4000
// if overflow 65535 is returned 
unsigned short Fixed_uMult2(unsigned short n1, unsigned short n2){ 
unsigned short result;
  asm ldd  n1
  asm ldy  n2
  asm emul        //32-bit Y:D is n1*n2
  asm ldx #100
  asm ediv
  asm bvc *+5
  asm ldy #65535 // overflow
  asm sty result
  return result;
} 

//**********Fixed_uMult3**********
// multiply for decimal fixed-point numbers with 0.001 resolution
// inputs: two integer parts of unsigned fixed-point numbers
// output: integer part of the product of the two inputs
//         result =(n1*n2)/1000
// e.g., mult(16.000*2.500) = 40.000, 16000,2500 -> 40000
// if overflow 65535 is returned 
unsigned short Fixed_uMult3(unsigned short n1, unsigned short n2){ 
unsigned short result;
  asm ldd  n1
  asm ldy  n2
  asm emul        //32-bit Y:D is n1*n2
  asm ldx #1000
  asm ediv
  asm bvc *+5
  asm ldy #65535 // overflow
  asm sty result
  return result;
} 

//**********Fixed_sMult2**********
// multiply for decimal fixed-point numbers with 0.01 resolution
// inputs: two integer parts of signed fixed-point numbers
// output: integer part of the product of the two inputs
//         result =(n1*n2)/100
// e.g., mult(1.60*-2.50) = -4.00, 160,-250 -> -400
// if overflow -32768 is returned 
unsigned short Fixed_sMult2(short n1, short n2){ 
unsigned short result;
  asm ldd  n1
  asm ldy  n2
  asm emuls        //32-bit Y:D is n1*n2
  asm ldx #100
  asm edivs
  asm bvc *+5
  asm ldy #32768 // overflow
  asm sty result
  return result;
} 

//**********Fixed_sMult3**********
// multiply for decimal fixed-point numbers with 0.001 resolution
// inputs: two integer parts of signed fixed-point numbers
// output: integer part of the product of the two inputs
//         result =(n1*n2)/1000
// e.g., mult(1.600*-2.500) = -4.000, 1600,-2500 -> -4000
// if overflow -32768 is returned 
unsigned short Fixed_sMult3(short n1, short n2){ 
unsigned short result;
  asm ldd  n1
  asm ldy  n2
  asm emuls        //32-bit Y:D is n1*n2
  asm ldx #1000
  asm edivs
  asm bvc *+5
  asm ldy #32768 // overflow
  asm sty result
  return result;
} 
//**********Fixed_Sqrt2**********
// sqrt for decimal fixed-point numbers with 0.01 resolution
// input: integer part of an unsigned fixed-point number
// output: integer part of sqrt(input)
// e.g., sqrt(16.00) = 4.00, 1600 -> 400
// no overflow error possible
unsigned short Fixed_Sqrt2(unsigned short s){ 
unsigned short t,oldt,msw,lsw;
  unsigned short count=20;  
  t = 0;       // secant method
  if(s>0){
     t = 200;   // initial guess 2.0
     do{
       if((--count) == 0) return (unsigned short) t;
       oldt = t;  // from the last 
     //  t = ((t*t+100*s)/t)/2;
  asm ldd  s
  asm ldy  #100
  asm emul        //32-bit Y:D is 100*s
  asm sty msw
  asm std lsw
  asm ldd  t
  asm tfr  d,y
  asm emul        //32-bit Y:D is t*t
  asm addd lsw
  asm exg d,y
  asm adcb #0
  asm adca #0    // carry from lsw
  asm addd msw
  asm exg d,y
  asm ldx t
  asm ediv
  asm tfr y,d
  asm lsrd
  asm std t
     } 
     while(t!=oldt);
  }     
  return t;
} 
 
//**********Fixed_Sqrt3**********
// sqrt for decimal fixed-point numbers with 0.001 resolution
// input: integer part of an unsigned fixed-point number
// output: integer part of sqrt(input)
// e.g., sqrt(16.000) = 4.000, 16000 -> 4000
// no overflow error possible
unsigned short Fixed_Sqrt3(unsigned short s){ 
unsigned short t,oldt,msw,lsw;
  unsigned short count=20;  
  t = 0;       // secant method
  if(s>0){
     t = 2000;   // initial guess 2.0
     do{
       if((--count) == 0) return (unsigned short) t;
       oldt = t;  // from the last 
     //  t = ((t*t+1000*s)/t)/2;
  asm ldd  s
  asm ldy  #1000
  asm emul        //32-bit Y:D is 1000*s
  asm sty msw
  asm std lsw
  asm ldd  t
  asm tfr  d,y
  asm emul        //32-bit Y:D is t*t
  asm addd lsw
  asm exg d,y
  asm adcb #0
  asm adca #0    // carry from lsw
  asm addd msw
  asm exg d,y
  asm ldx t
  asm ediv
  asm tfr y,d
  asm lsrd
  asm std t
     } 
     while(t!=oldt);
  }     
  return t;
} 

/*
void doesItCrash(void){
unsigned short i,ans;
for(i=0; i<65535; i++){
  ans = Sqrt(i);
  ans = Fixed_Sqrt3(i);
}
asm stop
}


unsigned short results[20];
void sqrttest(void){
unsigned short i,ans,last;
last = 0;
for(i=0;i<65535;i++){
  ans = Fixed_Sqrt2(i);
  if(ans<last) asm stop
  last = ans;
}
last = 0;
for(i=0; i<65535; i++){
  ans = Sqrt(i);
  if(ans<last) asm stop     // should be monotonic
  last = ans;
}
last = 0;
for(i=0;i<65535;i++){
  ans = Fixed_Sqrt3(i);
  if(ans<last) asm stop
  last = ans;
}
  results[0] = Fixed_Sqrt2(0);
  results[1] = Fixed_Sqrt2(1);
  results[2] = Fixed_Sqrt2(25);
  results[3] = Fixed_Sqrt2(100);
  results[4] = Fixed_Sqrt2(200);
  results[5] = Fixed_Sqrt2(1600);
  results[6] = Fixed_Sqrt2(2500);
  results[7] = Fixed_Sqrt2(4900);
  results[8] = Fixed_Sqrt2(6395);
  results[9] = Fixed_Sqrt2(6399);
  results[10] = Fixed_Sqrt2(6400);
  results[11] = Fixed_Sqrt2(6401);
  results[12] = Fixed_Sqrt2(6405);
  results[13] = Fixed_Sqrt2(14400);
  results[14] = Fixed_Sqrt2(25600);
  results[15] = Fixed_Sqrt2(40000);
  results[16] = Fixed_Sqrt2(62500);
  results[17] = Fixed_Sqrt2(62501);
  results[18] = Fixed_Sqrt2(62502);
  results[19] = Fixed_Sqrt2(65535);
  asm bra *

  results[0] = Sqrt(0);
  results[1] = Sqrt(1);
  results[2] = Sqrt(40);
  results[3] = Sqrt(250);
  results[4] = Sqrt(500);
  results[5] = Sqrt(1000);
  results[6] = Sqrt(2000);
  results[7] = Sqrt(4000);
  results[8] = Sqrt(8995);
  results[9] = Sqrt(8999);
  results[10] = Sqrt(9000);
  results[11] = Sqrt(9001);
  results[12] = Sqrt(9005);
  results[13] = Sqrt(16000);
  results[14] = Sqrt(25000);
  results[15] = Sqrt(49000);
  results[16] = Sqrt(64000);
  results[17] = Sqrt(64001);
  results[18] = Sqrt(64002);
  results[19] = Sqrt(65535);
 // asm bra *
  results[0] = Fixed_Sqrt3(0);
  results[1] = Fixed_Sqrt3(1);
  results[2] = Fixed_Sqrt3(40);
  results[3] = Fixed_Sqrt3(250);
  results[4] = Fixed_Sqrt3(500);
  results[5] = Fixed_Sqrt3(1000);
  results[6] = Fixed_Sqrt3(2000);
  results[7] = Fixed_Sqrt3(4000);
  results[8] = Fixed_Sqrt3(8995);
  results[9] = Fixed_Sqrt3(8999);
  results[10] = Fixed_Sqrt3(9000);
  results[11] = Fixed_Sqrt3(9001);
  results[12] = Fixed_Sqrt3(9005);
  results[13] = Fixed_Sqrt3(16000);
  results[14] = Fixed_Sqrt3(25000);
  results[15] = Fixed_Sqrt3(49000);
  results[16] = Fixed_Sqrt3(64000);
  results[17] = Fixed_Sqrt3(64001);
  results[18] = Fixed_Sqrt3(64002);
  results[19] = Fixed_Sqrt3(65535);
  asm bra *
  }
  */