/**
******************************************************************************
* @file    bsp_i2c.c
* @author  NTUT Poan Chung
* @brief   I2C driver for MPU6050 / AT24C256
******************************************************************************
*/
#include "bsp_i2c.h"
extern I2C_HandleTypeDef hi2c1;
// extern I2C_HandleTypeDef hi2c2;
  
I2C_StatusTypeDef I2C_Init(uint8_t i2c_controller_num)
{
    switch (i2c_controller_num)
    {
        case I2C1_ID :
            MX_I2C1_Init();
            break;
        default:
            return I2C_ERROR;
    }
  
    return I2C_OK;
  }
  
  I2C_StatusTypeDef I2C_Write(I2C_Packet_Typedef *packet)
  {
    switch (packet->i2c_controller_num)
    {
        case I2C1_ID :
            if(HAL_I2C_Master_Transmit(&hi2c1, packet->dev_addr, packet->data, packet->data_size, I2C_TIMEOUT_MS) != HAL_OK)
            {
                return I2C_ERROR;
            }
            break;
        case I2C2_ID :
            // if(HAL_I2C_Master_Transmit(&hi2c2, dev_addr, tx_data, size+1, I2C_TIMEOUT_MS) != HAL_OK)
            // {
            //     return I2C_ERROR;
            // }
            break;
        default:
            return I2C_ERROR;
    }
  
    return I2C_OK;
  }
  
I2C_StatusTypeDef I2C_Read(I2C_Packet_Typedef *packet)
{
    switch (packet->i2c_controller_num)
    {
        case I2C1_ID :
            if(HAL_I2C_Master_Transmit(&hi2c1, packet->dev_addr, packet->reg_addr, packet->reg_addr_size, I2C_TIMEOUT_MS) != HAL_OK)
            {
                return I2C_ERROR;
            }
            if(HAL_I2C_Master_Receive(&hi2c1, packet->dev_addr, packet->data, packet->data_size, I2C_TIMEOUT_MS) != HAL_OK)
            {
                return I2C_ERROR;
            }
            printf("receive is HAL OK!! now continue\n");
            break;
        case I2C2_ID :
            // if(HAL_I2C_Master_Transmit(&hi2c2, dev_addr, &reg_addr, 1, I2C_TIMEOUT_MS) != HAL_OK)
            // {
            //     return I2C_ERROR;
            // }
            // if(HAL_I2C_Master_Receive(&hi2c2, dev_addr, data, size, I2C_TIMEOUT_MS) != HAL_OK)
            // {
            //     return I2C_ERROR;
            // }
            break;
        default:
            return I2C_ERROR;
    }
  
    return I2C_OK;
}