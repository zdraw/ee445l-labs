// filename***************  LCD.H ************************* 
// LCD Display (HD44780) on Port H for the 9S12DP512   
// Jonathan W. Valvano 9/18/09

//  This example accompanies the books
//   "Embedded Microcomputer Systems: Real Time Interfacing",
//        Thompson, copyright (c) 2006,
//   "Introduction to Embedded Systems: Interfacing to the Freescale 9S12",
//        Cengage Publishing 2009, ISBN-10: 049541137X | ISBN-13: 9780495411376

// Copyright 2009 by Jonathan W. Valvano, valvano@mail.utexas.edu 
//    You may use, edit, run or distribute this file 
//    as long as the above copyright notice remains 

/*   
  size is 1*16 
  if do not need to read busy, then you can tie R/W=ground 
  ground = pin 1    Vss
  power  = pin 2    Vdd   +5V
  ground = pin 3    Vlc   grounded for highest contrast
  PH4    = pin 4    RS    (1 for data, 0 for control/status)
  PH5    = pin 5    R/W   (1 for read, 0 for write)
  PH6    = pin 6    E     (enable)
  PH3    = pin 14   DB7   (4-bit data)
  PH2    = pin 13   DB6
  PH1    = pin 12   DB5
  PH0    = pin 11   DB4
16 characters are configured as 2 rows of 8
addr  00 01 02 03 04 05 06 07 40 41 42 43 44 45 46 47
*/

//---------------------LCD_Open---------------------
// Initialize the LCD display, called once at beginning
// Input: None
// Output: Sets internal flag if Open succeeds
// Returns: None
void LCD_Open(void);

//---------------------LCD_Clear---------------------
// Clear the LCD display, send cursor to home
// Input: None
// Output: Sets internal flag if LCD is not open or LCD is busy.
// Returns: None
void LCD_Clear(void);


//---------------------LCD_OutChar---------------------
// Sends one ASCII to the LCD display
// Input: Letter is ASCII code
// Output: Sets internal error flag if failure occurs
// Returns: None
void LCD_OutChar(unsigned char letter);


//---------------------LCD_OutString--------------
// Display String
// Input: Pointer to NULL-terminationed ASCII string 
// Output: Set internal error code if failure occurs
// Returns: None
void LCD_OutString(char *pt); 

//---------------------LCD_GoTo--------------
// Move the cursor to a particular row and column
// Input: Parameters (row, column)   First row and and column is 0
// Output: Sets internal error code if failure occurs
// Returns: None
void LCD_GoTo(unsigned char row, unsigned char col);

//---------------------LCD_ErrorCheck--------------
// LCD_ErrorCheck Check to see if the LCD driver has had any errors
// Returns an error code if LCD has had any errors 
//   since initialization or since the last call to ErrorCheck
// Input Parameter(none)
// Output Parameter(error code)
// Typical calling sequence
// Err = ErrorCheck();
// if(Err) Handle(Err);
short LCD_ErrorCheck(void);

    
     



