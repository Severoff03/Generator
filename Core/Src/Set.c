
#include "Set.h"

int Sin_k = 200;
int DAC_Freq = 10000000;

int Sin_mack(uint32_t freq){
	uint16_t Mast[DAC_Freq/(freq*Sin_k*4)];
	int phantom_Pi = 0;

	for (int i=0; i<DAC_Freq/(freq*Sin_k*4); i++){
		Mask[i]=sin(phantom_Pi);
		phantom_Pi=phantom_Pi*3.14/(DAC_Freq/(freq*Sin_k*4));
	}
}
