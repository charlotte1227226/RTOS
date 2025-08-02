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
#include "bsp_delay.h"


#define LED_GREEN LED_GREEN_PIN_Pin
#define LED_RED LED_RED_PIN_Pin

void Led_Init(void);
void Led_Control(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void Led_Test_Green(void);
void Led_Test_Red(void);