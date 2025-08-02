/**
  ******************************************************************************
  * @file    bsp_i2c.h
  * @author  NTUT MCA Lab Poan Chung
  * @brief   Header file of custom I2C driver (HAL-based)
  ******************************************************************************
  */

#ifndef __BSP_I2C_H__
#define __BSP_I2C_H__
  
#ifdef __cplusplus
extern "C" {
#endif
  
/* STM32 HAL headers */
#include "stm32f1xx_hal.h"
#include "i2c.h"
  
/* Return type for BSP I2C operations */
typedef enum
{
    I2C_OK = 0,
    I2C_ERROR,
    I2C_TIMEOUT
} I2C_StatusTypeDef;  
/* I2C Controller IDs */
#define I2C1_ID 1
#define I2C2_ID 2
#define I2C3_ID 3

/* Timeout setting */
#define I2C_TIMEOUT_MS 1000
  
typedef struct
{
    uint8_t i2c_controller_num; // I2C controller number (1, 2, or 3)
    uint8_t dev_addr;           // Device address
    uint8_t *reg_addr;           // Register address (optional, can be 0 if not needed)
    uint8_t reg_addr_size;      // Size of register address (1 or 2 bytes)
    uint8_t *data;              // Pointer to data buffer
    uint16_t data_size;              // Size of data to be transferred
    uint8_t is_read;           // 1 for read operation, 0 for write operation
} I2C_Packet_Typedef;

/* Function Prototypes */
I2C_StatusTypeDef I2C_Init(uint8_t i2c_controller_num);
I2C_StatusTypeDef I2C_Write(I2C_Packet_Typedef *packet);
I2C_StatusTypeDef I2C_Read(I2C_Packet_Typedef *packet);
#ifdef __cplusplus
}
#endif
  
#endif /* __BSP_I2C_H__ */
  