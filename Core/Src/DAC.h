/*
 * DAC.h
 *
 *  Created on: Oct 24, 2024
 *      Author: User
 */

#ifndef DAC_H_
#define DAC_H_

#include "stm32f1xx.h"

void DAC_Init(void);
void DAC_Output(uint16_t value);

#endif /* DAC_H_ */
