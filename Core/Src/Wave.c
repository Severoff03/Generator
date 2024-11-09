/*
 * Wave.c
 *
 *  Created on: Oct 24, 2024
 *      Author: User
 */
#include "Wave.h"


uint32_t DAC_Freq = 1000000;

int Sin_k = 300; //Подстройка числа отсчётов для подбора нужной частоты
float Squ_k = 1.7;
float Saw_k = 1;
float Tri_k = 1;


void Wave_Square(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/(freq*Squ_k);

	DAC_Output(amplitude);
	for (int i=0; i<Tics/2;i++){

	}
	DAC_Output(0);
	for (int i=0; i<Tics/2;i++){

	}
}

void Wave_Triangle(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/freq*(Tri_K);
	float step=2*amplitude/Tics;
	float tmp = 0;

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

	uint32_t Tics=DAC_Freq/(freq*Saw_k);
	float step=amplitude/Tics;
	float tmp = 0;

	for (int i=0; i<Tics||tmp <= amplitude;i++){
		DAC_Output(tmp);
		tmp= tmp+step;
	}
}

void Wave_Sin(uint16_t amplitude, uint32_t freq){

	uint32_t Tics=DAC_Freq/(freq*4*300);
	uint16_t zero = amplitude/2;

	for(float i=0; i<=M_PI/2 ;i=i+M_PI/(2*Tics)){  //上
		DAC_Output(zero+zero*sin(i));
	}
	for(float i=M_PI/2; i>=0 ;i=i-M_PI/(2*Tics)){    //下
		DAC_Output(amplitude-(zero-zero*sin(i)));
	}
	for(float i=0; i<M_PI/2 ;i=i+M_PI/(2*Tics)){   //ゼロ下
		DAC_Output(zero-zero*sin(i));
	}
	for(float i=M_PI/2; i>=0 ;i=i-M_PI/(2*Tics)){   //ゼロ下
		DAC_Output(zero-zero*sin(i));
	}
}

void Wave_Sin_Macked(uint16_t amplitude, uint32_t freq,uint16_t Mask){

	uint32_t Tics=DAC_Freq/(freq*4*Sin_k);
	uint16_t zero = amplitude/2;

	for(int i=0; i<=DAC_Freq/(freq*Sin_k*4) ;i++){  //上
		DAC_Output(zero+zero*Mask[i]);
	}
	for(int i=DAC_Freq/(freq*Sin_k*4); i>=0 ;i--){  //上
			DAC_Output(amplitude-zero*Mask[i]);
	}
	for(int i=0; i<=DAC_Freq/(freq*Sin_k*4) ;i++){  //上
		DAC_Output(zero-zero*Mask[i]);
	}
	for(int i=DAC_Freq/(freq*Sin_k*4); i>=0 ;i--){  //上
			DAC_Output(zero-zero*Mask[i]);
	}
}

void Wave_Noise(uint16_t amplitude){
	for (int i=0; i<50; i++){
		DAC_Output(rand()*amplitude);
	}

}

