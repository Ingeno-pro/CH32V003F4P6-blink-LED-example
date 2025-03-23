 
 
 /* @brief   Initializes GPIOD.0
 *
 * @return  none
 */
#include "debug.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate(); // Configure MCU Clock HSI
    Delay_Init(); // 6mSec delay to allow clock to stabilize

    //GPIO Init
    GPIO_InitTypeDef gpreg = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    gpreg.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_4;
    gpreg.GPIO_Mode = GPIO_Mode_Out_PP;
    gpreg.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpreg);

    //UART INIT
    USART_Printf_Init(115200);
    printf("start");

    while(1)
    {
        Delay_Ms(500);
        GPIO_WriteBit(GPIOC, GPIO_Pin_2, SET);
        GPIO_WriteBit(GPIOC, GPIO_Pin_4, RESET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOC, GPIO_Pin_4, SET);
        GPIO_WriteBit(GPIOC, GPIO_Pin_2, RESET);
        
    }
}