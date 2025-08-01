/**
******************************************************************************
* @file    driver_led.h
* @author  NTUT Chung Po An
* @brief   Header file of led driver  
******************************************************************************
*/
#include "main.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "stm32f1xx_hal.h"

#define LED_GREEN LED_PIN_Pin


void Led_Init(void);
void Led_Control(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void mdelay(short int ms);
void Led_Test(void);