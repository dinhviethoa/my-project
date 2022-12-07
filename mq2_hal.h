/*
 * mq2_hal.h
 *
 * Created: 12/6/2022 2:52:37 PM
 *  Author: Dinh Viet Hoa
 */ 


#ifndef MQ2_HAL_H_
#define MQ2_HAL_H_


#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RL_VALUE (10)
#define RO_CLEAR_AIR_FACTOR (9.83)
#define LPG (0)
#define SMOKE (1)
float resistancetanCalculation(int raw_adc);
float SensorCalibration(int tem);
float ReadSensor(int tem);
int GetGasPercentage(float rs_ro_ratio, int gas_id);
int GetPercentage(float rs_ro_ratio, float *curve);

#endif /* MQ2_HAL_H_ */
