/*
 * mq2_hal.c
 *
 * Created: 12/6/2022 2:52:53 PM
 *  Author: Dinh Viet Hoa
 */ 
#include "mq2_hal.h"

float LPGCurve[3] = {2.3,0.20,-0.45};

float SmokeCurve[3] = {2.3,0.53,-0.43};
	
float resistancetanCalculation(int raw_adc){
	return (((float)RL_VALUE*(1023-raw_adc)/raw_adc));
}

float SensorCalibration(int tem){
	int i;
	float val = 0;
	for (i = 0; i < 50; i++){
		val += resistancetanCalculation(tem);
		_delay_ms(500);
	}
	val = val/(50*RO_CLEAR_AIR_FACTOR) ; 
	
	
	return val;
}

float ReadSensor(int tem){
	int i;
	float rs = 0;
	
	for (i = 0; i < 5;i++){
		rs += resistancetanCalculation(tem);
		_delay_ms(50);
	}
	rs = rs/5;
	return rs;
}

int GetGasPercentage(float rs_ro_ratio, int gas_id){
	if ( gas_id == LPG ){
		return GetPercentage(rs_ro_ratio, LPGCurve);
	}
	if ( gas_id == SMOKE){
		return GetPercentage(rs_ro_ratio, SmokeCurve);
	}
}

int GetPercentage(float rs_ro_ratio, float *curve){
	return (pow(10,(((log(rs_ro_ratio)-curve[1])/curve[2]) + curve[0])));
}

