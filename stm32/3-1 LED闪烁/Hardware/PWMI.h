#ifndef __PWMI_H
#define __PWMI_H
void PWMI_Init(void);

void PWMI_Set_Prescaler(uint16_t Prescaler);

uint16_t GetFrequence( void );

uint16_t PWM_GetCapture( uint16_t CCR);

uint16_t PWM_Get_CCR( void );

uint16_t PWM_Get_duty(void);



#endif
