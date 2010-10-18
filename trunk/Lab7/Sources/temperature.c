unsigned short const ADCdata[53]={0,60,72,85,97,110,122,135,148,161,174,
     187,201,214,227,241,255,268,282,296,310,
     324,338,352,366,381,395,409,424,438,453,
     468,482,497,512,527,541,556,571,586,601,
     616,631,646,662,677,692,707,722,737,752,767,1024};


unsigned short const Tdata[53]={4000,4000,3960,3920,3880,3840,3800,3760,3720,3680,3640,
     3600,3560,3520,3480,3440,3400,3360,3320,3280,3240,
     3200,3160,3120,3080,3040,3000,2960,2920,2880,2840,
     2800,2760,2720,2680,2640,2600,2560,2520,2480,2440,
     2400,2360,2320,2280,2240,2200,2160,2120,2080,2040,2000,2000};


unsigned short Temp_Data(unsigned short adc) {
  unsigned short temp;
  
  asm ldd adc
  asm Lookup: ldx  #ADCdata  // first find x1<=xL<x2
  asm ldy  #Tdata  
  asm lookx1: cpd  2,x      // check xL<x2
  asm blo  found    // stops when X points to x1
  asm leax 2,x
  asm leay 2,y
  asm bra  lookx1
  asm found:   subd 0,x      // xL-x1
  asm pshd
  asm ldd  2,x      // x2
  asm subd 0,x      // D=x2-x1
  asm tfr  D,X      // X=x2-x1
  asm puld          // D=(xL-x1) 
  asm fdiv          // X=(65536*(xL-x1))/(x2-x1)
  asm tfr  X,D
  asm tfr  A,B      
  // B=(256*(xL-x1))/(x2-x1)
  // Y=>y1,y2
  asm etbl 0,y
  asm std temp        
   
   return temp;
}