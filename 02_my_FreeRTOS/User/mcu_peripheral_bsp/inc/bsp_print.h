/**
  ******************************************************************************
  * @file    bsp_print.h
  * @author  NTUT Poan Chung
  * @brief   Header file of print function
  ******************************************************************************
  */

#ifndef BSP_PRINT_H
#define BPS_PRINT_H 

//#include "usb_device.h" //This is for STM32 USB middleawares
#include "usart.h" //This is for STM32 USB middleawares
#include <stdio.h>
#include <string.h>

extern uint8_t rx_data;
int _write(int file, char *ptr, int len);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif