/*
 * Wave.h
 *
 *  Created on: Oct 24, 2024
 *      Author: User
 */

#ifndef WAVE_H_
#define WAVE_H_

#include <stdint.h>
#include <math.h>
#include "DAC.h"

void Wave_Square(uint16_t amplitude, uint32_t freq);
void Wave_Triangale(uint16_t amplitude, uint32_t freq);
void Wave_Sawtooth(uint16_t amplitude, uint32_t freq);
void Wave_Sin(uint16_t amplitude, uint32_t freq);
void Wave_Noise(uint16_t amplitude);


#endif /* WAVE_H_ */
