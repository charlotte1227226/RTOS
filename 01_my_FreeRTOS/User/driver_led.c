/**
******************************************************************************
* @file    driver_led.c
* @author  NTUT Chung Po An
* @brief   led driver  
******************************************************************************
*/

#include "driver_led.h"

void Led_Init(void){
    MX_GPIO_Init();
}

void Led_Control(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
    HAL_GPIO_WritePin(GPIOx,GPIO_Pin, PinState);
}

void mdelay(short int ms){
    HAL_Delay(ms);
}

void Led_Test(){
    Led_Init();
    while (1)
    {
        Led_Control(GPIOC, LED_GREEN, 1);
        mdelay(500);
        Led_Control(GPIOC, LED_GREEN, 0);
        mdelay(500);
    }
    
}