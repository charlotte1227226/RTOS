/**
******************************************************************************
* @file    bsp_delay.c
* @author  NTUT Poan Chung
* @brief   delay
******************************************************************************
*/
#include "bsp_delay.h"

void delay_ms(short int ms)
{
    HAL_Delay(ms);
}