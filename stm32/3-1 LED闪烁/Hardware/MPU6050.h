#ifndef __MPU6050_H
#define __MPU6050_H

void MPU6050_Init( void );

void MPU6050_WriteReg(uint8_t RegAddress,uint8_t Data);

uint16_t MPU6050_ReadReg( uint8_t RegAddress );

uint8_t MPU6050_GetID(void);

void MPU6050_GetNum(int16_t *AccX, int16_t *AccY, int16_t *AccZ,
					int16_t *GyoX, int16_t *GyoY, int16_t *GyoZ);
#endif
