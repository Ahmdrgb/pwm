/*
 * timer.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "4.LIB/hw_gpio.h"
#include "4.LIB/Bit_Math.h"

#include "4.LIB/Platform_Types.h"
#include "4.LIB/Std_Types.h"


void timer_Init(void);
void timerHandler(void);


#endif /* TIMER_H_ */
