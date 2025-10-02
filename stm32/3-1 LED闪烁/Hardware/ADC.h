#ifndef __ADC_H
#define __ADC_H
void AD_Init( void );
uint16_t AD_GetValue( void );

uint16_t AD_GetValue_Nbr( uint8_t ADC_Channe_x );

#endif
