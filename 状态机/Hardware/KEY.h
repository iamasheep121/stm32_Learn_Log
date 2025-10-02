#ifndef __KEY_H
#define __KET_H
void Key_Init(void);
uint8_t Key_GetNumber(void);
void Key_Turn(void);
void EXTI15_10_IRQHandler(void);

#endif
