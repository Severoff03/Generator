#include "DAC.h"

void DAC_Init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;


    GPIOA->CRL = 0x33333333; // PA0 - PA7, output, 10 MHz, push-pull
    GPIOA->CRH = 0x00000033; // PA8 - PA9, output, 10 MHz, push-pull
}

void DAC_Output(uint16_t value) {
	  value &= 0x03FF;


	    GPIOA->BSRR = (0x03FF << 16);  // Сбрасываем PA0 - PA9
	    GPIOA->BSRR = value;             // PA0 - PA9
}


