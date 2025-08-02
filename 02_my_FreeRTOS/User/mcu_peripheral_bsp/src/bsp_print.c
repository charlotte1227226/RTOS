/**
  ******************************************************************************
  * @file    bsp_print.h
  * @author  NTUT Poan Chung
  * @brief   Header file of print function
  ******************************************************************************
  */

#include "bsp_print.h"
uint8_t rx_data;
int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, 50);
  return len;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart->Instance == USART1)
  {
    HAL_UART_Transmit(&huart1, &rx_data, 1, 1000);
    HAL_UART_Receive_IT(&huart1, &rx_data, 1);
  }
}