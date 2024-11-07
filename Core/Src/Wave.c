/*
 * Wave.c
 *
 *  Created on: Oct 24, 2024
 *      Author: User
 */
#include "Wave.h"


uint32_t DAC_Freq = 72000000;


void Wave_Square(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/freq;

	for (int i=0; i<Tics/2;i++){
	DAC_Output(amplitude);
	}

	for (int i=0; i<Tics/2;i++){
	DAC_Output(0);
	}
}

void Wave_Triangale(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/freq;
	uint16_t step=2*amplitude/Tics;
	uint16_t tmp = 0;

	for (int i=0; i<Tics/2||tmp <= amplitude;i++){
		DAC_Output(tmp);
		tmp= tmp+step;
	}
	for (int i=0; i<Tics/2||tmp >= 0;i++){
		DAC_Output(tmp);
		tmp= tmp-step;
	}
}

void Wave_Sawtooth(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/freq;
	uint16_t step=amplitude/Tics;
	uint16_t tmp = 0;

	for (int i=0; i<Tics||tmp <= amplitude;i++){
		DAC_Output(tmp);
		tmp= tmp+step;
	}
}

void Wave_Sin(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/(freq*4);
	uint16_t zero = amplitude/2;

	for(float i=0; i<=M_PI/2 ;i=i+M_PI/(2*Tics)){  //上
		DAC_Output(zero+zero*sin(i));
	}
	for(float i=M_PI; i>=0 ;i=i-M_PI/(2*Tics)){    //下
		DAC_Output(zero-zero*sin(i));
	}

	for(float i=0; i<M_PI/2 ;i=i+M_PI/(2*Tics)){   //ゼロ下
		DAC_Output(zero-zero*sin(i));
	}
	for(float i=M_PI; i>=0 ;i=i-M_PI/(2*Tics)){    //上
		DAC_Output(zero+zero*sin(i));
	}

}

void Wave_Noise(uint16_t amplitude){
	for (int i=0; i<50; i++){
		DAC_Output(rand()*amplitude);
	}

}

