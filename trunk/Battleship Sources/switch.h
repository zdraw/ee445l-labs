#ifndef SWITCH_H
#define SWITCH_H

void Key_Init(void);

void enableOC6(void (*function) (void), unsigned short delay, unsigned short delayCount, unsigned short count);
void disableOC6(void);
#endif