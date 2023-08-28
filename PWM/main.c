

#include "timer.h"

#include "1.MCAL/GPIO/INC/GPIO_Interface.h"

#include "4.LIB/Delay.h"

extern volatile u8 Pressed;
int main(void)
{

    const GPIO_Config_t Config ={GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_PIN_ALTFUNC,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC7};

    GPIO_Init(&Config, 1);
    timer_Init();
    u32 iterator =0;
    while(1)
    {

        while(TIMER1_TAMATCHR_R < 60000)
        {
            TIMER1_TAMATCHR_R+=100;
            delay_ms(10);
        }

        while(TIMER1_TAMATCHR_R > 60000)
        {
            TIMER1_TAMATCHR_R-=100;
            delay_ms(10);
        }
    }
    return 0;
}
