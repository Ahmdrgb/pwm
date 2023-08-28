/*
 * timer.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Ahmed
 */


#include "timer.h"

volatile u8 LED_TOGLLE=0;


void timer_Init(void)
{
    SET_BIT(SYSCTL_RCGCTIMER_R,1);

    //SET_BIT(NVIC_EN0_R,21);

    ///////////////// 1 ///////////////////
    CLR_BIT(TIMER1_CTL_R,0);
    ///////////////// 2 ///////////////////
    TIMER1_CFG_R = 4;
    ///////////////// 3 ///////////////////
    INSERT_VALUE(TIMER1_TAMR_R,0,4,0xA);
    ///////////////// 4 ///////////////////
    SET_BIT(TIMER1_CTL_R,6);
    ///////////////// 5 ///////////////////
    TIMER1_TAILR_R =60000;

    /////////Interrupt/////////////////////
    ///////////////////6////////////////////
    //INSERT_VALUE(TIMER1_CTL_R,2,2,0x1);

    //SET_BIT(TIMER1_CTL_R,2);
    ///////////////////////7///////////////
    //SET_BIT(TIMER1_TAMR_R,9);

    TIMER1_TAMATCHR_R = 100;

    //SET_BIT(TIMER1_IMR_R,1);

    SET_BIT(TIMER1_CTL_R,0);

}

void timerHandler(void)
{
    TIMER1_TAMATCHR_R+=3;
    SET_BIT(TIMER1_ICR_R,1);

}

