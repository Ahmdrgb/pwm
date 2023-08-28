/*
 * Timer.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ahmed ragab , ahmed abdulazeem
 */
#include "../../4.LIB/Bit_Math.h"
#include "../../4.LIB/Platform_Types.h"
#include "../../4.LIB/Std_Types.h"
#include "../../4.LIB/TM4C123xx.h"
#include "../../4.LIB/hw_gpio.h"
#include "../../4.LIB/delay.h"
#include "Timer.h"
/**
 * Mode of the timer.
 */
typedef enum timMode
{
    oneshot, periodic, edgeTime, PWM
}timerMode;

/**
 * Which timer block to use.
 */
typedef enum timBlock
{
    Timer0, Timer1, Timer2, Timer3, Timer4, Timer5,
    wTimer0, wTimer1, wTimer2, wTimer3, wTimer4, wTimer5
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
typedef enum timesuse
{
    timerA, timerB, concatenated
}timerstate;
typedef enum
{
    positive, nigative, none
}edge;
void timer_Init(timerBlock timer,timerMode mode ,countDirection direction,timerstate block,u32 loadregister,edge edge_state){

    switch(timer){
    case Timer0:
        switch(mode){
        case oneshot:
            switch(block){
            case timerA:
                SET_BIT(SYSCTL_RCGCTIMER_R,0);

                SET_BIT(NVIC_EN0_R,19);

                CLR_BIT(TIMER0_CTL_R,0);

                TIMER0_CFG_R = 0x04;

                SET_BIT(TIMER0_TAMR_R,0);

                TIMER0_TAILR_R =loadregister;

                SET_BIT(TIMER0_IMR_R,0);

                SET_BIT(TIMER0_CTL_R,0);
                break;
            case timerB:
                break;
            case concatenated:
                SET_BIT(SYSCTL_RCGCTIMER_R,0);

                SET_BIT(NVIC_EN0_R,19);

                CLR_BIT(TIMER0_CTL_R,0);

                TIMER0_CFG_R = 0;

                SET_BIT(TIMER0_TAMR_R,0);

                TIMER0_TAILR_R =loadregister;

                SET_BIT(TIMER0_IMR_R,0);

                SET_BIT(TIMER0_CTL_R,0);
                break;


            }

            break;
            case periodic:
                switch(block){
                case timerA:
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);

                    SET_BIT(NVIC_EN0_R,19);

                    CLR_BIT(TIMER0_CTL_R,0);

                    TIMER0_CFG_R = 0x04;

                    SET_BIT(TIMER0_TAMR_R,1);

                    TIMER0_TAILR_R =loadregister;

                    SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;
                case timerB:
                    break;
                case concatenated:
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);

                    SET_BIT(NVIC_EN0_R,19);

                    CLR_BIT(TIMER0_CTL_R,0);

                    TIMER0_CFG_R = 0;

                    SET_BIT(TIMER0_TAMR_R,1);

                    TIMER0_TAILR_R =loadregister;

                    SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;


                }
                break;
                case edgeTime:

                    break;
                case PWM:
                    /**/
                    break;
        }

        break;
        case Timer1:
            /**/
            break;
        case Timer2:
            /**/
            break;
        case Timer3:
            /**/
            break;
        case Timer4:
            /**/
            break;
        case Timer5:
            /**/
            break;
        case wTimer0:
            /**/
            break;
        case wTimer1:
            /**/
            break;
        case wTimer2:
            /**/
            switch(mode){
            case oneshot:
                switch(block){
                case timerA:
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);

                    SET_BIT(NVIC_EN0_R,19);

                    CLR_BIT(TIMER0_CTL_R,0);

                    TIMER0_CFG_R = 0x04;

                    SET_BIT(TIMER0_TAMR_R,0);

                    TIMER0_TAILR_R =loadregister;

                    SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;
                case timerB:
                    break;
                case concatenated:
                    SET_BIT(SYSCTL_RCGCTIMER_R,0);

                    SET_BIT(NVIC_EN0_R,19);

                    CLR_BIT(TIMER0_CTL_R,0);

                    TIMER0_CFG_R = 0;

                    SET_BIT(TIMER0_TAMR_R,0);

                    TIMER0_TAILR_R =loadregister;

                    SET_BIT(TIMER0_IMR_R,0);

                    SET_BIT(TIMER0_CTL_R,0);
                    break;


                }

                break;
                case periodic:
                    switch(block){
                    case timerA:
                        SET_BIT(SYSCTL_RCGCTIMER_R,0);

                        SET_BIT(NVIC_EN0_R,19);

                        CLR_BIT(TIMER0_CTL_R,0);

                        TIMER0_CFG_R = 0x04;

                        SET_BIT(TIMER0_TAMR_R,1);

                        TIMER0_TAILR_R =loadregister;

                        SET_BIT(TIMER0_IMR_R,0);

                        SET_BIT(TIMER0_CTL_R,0);
                        break;
                    case timerB:
                        break;
                    case concatenated:
                        SET_BIT(SYSCTL_RCGCTIMER_R,0);

                        SET_BIT(NVIC_EN0_R,19);

                        CLR_BIT(TIMER0_CTL_R,0);

                        TIMER0_CFG_R = 0;

                        SET_BIT(TIMER0_TAMR_R,1);

                        TIMER0_TAILR_R =loadregister;

                        SET_BIT(TIMER0_IMR_R,0);

                        SET_BIT(TIMER0_CTL_R,0);
                        break;


                    }
                    break;
                    case edgeTime:
                        switch(block){
                        case timerA:
                            /*Enable Timer Clock  */
                            SET_BIT(SYSCTL_RCGCWTIMER_R,2);

                            /*Enable NVIC   */
                            SET_BIT(NVIC_EN3_R,2);

                            CLR_BIT(WTIMER2_CTL_R,0);

                            WTIMER2_CFG_R = 4;

                            INSERT_VALUE(WTIMER2_TAMR_R,0,5,0x17);

                            /*Configure Edge Falling*/

                            INSERT_VALUE(WTIMER2_CTL_R,2,2,edge_state);


                            WTIMER2_TAILR_R =loadregister;

                            /*ALLOW Interrupt*/
                            SET_BIT(WTIMER2_IMR_R,2);

                            SET_BIT(WTIMER2_CTL_R,0);
                            break;
                        case timerB:
                            break;
                        }

                        break;
                        case PWM:
                            switch(block){
                            case timerA:
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
                                break;
                            case timerB:
                                break;
                            }
                            /**/
                            break;
            }
            break;
            case wTimer3:

                /**/
                break;
            case wTimer4:
                /**/
                break;
            case wTimer5:
                /**/
                break;
    }
}
void Timer0_timeout_Handler(void){}
void wTimer2_edgetime_Handler(void){}

