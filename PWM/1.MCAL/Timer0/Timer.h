/*
 * Timer.h
 *
 *  Created on: Aug 25, 2023
 *      Author: ahmed ragab,ahmed abdulazeem
 */

#ifndef  1_MCAL_TIMER0_TIMER0_H_
#define  1_MCAL_TIMER0_TIMER0_H_

/**
 * Mode of the timer.
 */
typedef enum timMode
{
    oneShot, periodic, edgeCount, edgeTime, PWM
}timerMode;

/**
 * Which timer block to use.
 */
typedef enum timBlock
{
    shortTimer0, shortTimer1, shortTimer2, shortTimer3, shortTimer4, shortTimer5,
    wideTimer0, wideTimer1, wideTimer2, wideTimer3, wideTimer4, wideTimer5
}timerBlock;

/**
 * Count direction of the timer.
 */
typedef enum countDirec
{
    up, down
}countDirection;

/**
 * Which subtimer to use or both in concatenated mode.
 */
typedef enum timestate
{
    timerA, timerB, concatenated
}timerUse;

void timer_Init(timerBlock timer,timerMode mode ,countDirection direction,timerUse block);

#endif /* 1_MCAL_TIMER0_TIMER0_H_ */
