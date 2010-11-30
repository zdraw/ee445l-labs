unsigned char reverseByte(unsigned char data) {
  int i;
  unsigned char reversed = 0;
  
  for(i=0; i<8; i++) {
    if(data&(1<<i)) {
      reversed |= 1<<(7-i);  
    }
  }
  
  return reversed;
}