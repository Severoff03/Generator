/**
 ******************************************************************************
 * @file           : main.c
 * @author         : 私の子
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f1xx.h"
#include "DAC.h"
#include "Set.h"
#include "USART.h"
#include "Wave.h"

uint8_t form = 1;
uint16_t amp=1023;
uint32_t freq = 10;


int main(void)
{

	DAC_Init();
	//DAC_Output(1023);

	while(1){
	Wave_Sin(amp, freq);
	}
/*
	while(1){

		if (trigger){
			USART_Read();
		}

		switch (form){
		case '1':
		Wave_Square(amp, freq);
		break;
		case '2':
		Wave_Triangle(amp, freq);
		break;
		case '3':
		Wave_Sawtooth(amp, freq);
		break;
		case '4':
		Wave_Sin(amp, freq);
		break;
		case '5':
		Wave_Noise(amp);
		break;


		}

	}
*/
}





