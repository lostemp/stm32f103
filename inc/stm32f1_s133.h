/**
  ******************************************************************************
  * @file    stm32f1_s133.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   This file contains definitions for STM32F429I-DISCO Kit Leds, push-
  *          buttons hardware resources.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1_S133_H
#define __STM32F1_S133_H

#ifdef __cplusplus
 extern "C" {
#endif
                                              
/* Includes ------------------------------------------------------------------*/
 #include "stm32f10x.h"
   
/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32F1
  * @{
  */
   
/** @addtogroup STM32F1
  * @{
  */
   
/** @addtogroup STM32F1_LOW_LEVEL
  * @{
  */ 

/** @defgroup STM32F1_LOW_LEVEL_Exported_Types
  * @{
  */
typedef enum 
{
  LED1 = 0,
  LED2 = 1
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;     

typedef enum
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;


/**
  * @}
  */ 

/** @defgroup STM32F1_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief  Define for STM32F1 board  
  */ 
#if !defined (USE_STM32F1_S133)
 #define USE_STM32F1_S133
#endif


/** @addtogroup STM32F1_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             2
  
#define LED1_PIN                         GPIO_Pin_0
#define LED1_GPIO_PORT                   GPIOA
#define LED1_GPIO_CLK                    RCC_APB2Periph_GPIOA

#define LED2_PIN                         GPIO_Pin_1
#define LED2_GPIO_PORT                   GPIOA
#define LED2_GPIO_CLK                    RCC_APB2Periph_GPIOA

#define COMn                             2

/**
 *  * @brief Definition for COM port1, connected to USART1
 *   */
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1
#define EVAL_COM1_TX_PIN                 GPIO_Pin_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM1_RX_PIN                 GPIO_Pin_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM1_IRQn                   USART1_IRQn

/**
 *  * @brief Definition for COM port2, connected to USART2
 *   */
#define EVAL_COM2                        USART2
#define EVAL_COM2_CLK                    RCC_APB1Periph_USART2
#define EVAL_COM2_TX_PIN                 GPIO_Pin_2
#define EVAL_COM2_TX_GPIO_PORT           GPIOA
#define EVAL_COM2_TX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM2_RX_PIN                 GPIO_Pin_3
#define EVAL_COM2_RX_GPIO_PORT           GPIOA
#define EVAL_COM2_RX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM2_IRQn                   USART2_IRQn

/**
  * @}
  */ 
  
/** @addtogroup STM32F1_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                          1  

/**
 * @brief Wakeup push-button
 */
#define USER_BUTTON_PIN                GPIO_Pin_14
#define USER_BUTTON_GPIO_PORT          GPIOB
#define USER_BUTTON_GPIO_CLK           RCC_APB2Periph_GPIOB
#define USER_BUTTON_EXTI_LINE          EXTI_Line14
#define USER_BUTTON_EXTI_PORT_SOURCE   GPIO_PortSourceGPIOB
#define USER_BUTTON_EXTI_PIN_SOURCE    GPIO_PinSource14
#define USER_BUTTON_EXTI_IRQn          EXTI0_IRQn 
/**
  * @}
  */

///** @addtogroup STM32F1_LOW_LEVEL_I2C_EE
//  * @{
//  */
///**
//  * @brief  I2C EEPROM Interface pins
//  */  
//#define sEE_I2C                          I2C3
//#define sEE_I2C_CLK                      RCC_APB1Periph_I2C3
//#define sEE_I2C_SCL_PIN                  GPIO_Pin_8                  /* PA.08 */
//#define sEE_I2C_SCL_GPIO_PORT            GPIOA                       /* GPIOA */
//#define sEE_I2C_SCL_GPIO_CLK             RCC_AHB1Periph_GPIOA
//#define sEE_I2C_SCL_SOURCE               GPIO_PinSource8
//#define sEE_I2C_SCL_AF                   GPIO_AF_I2C3
//#define sEE_I2C_SDA_PIN                  GPIO_Pin_9                  /* PC.09 */
//#define sEE_I2C_SDA_GPIO_PORT            GPIOC                       /* GPIOC */
//#define sEE_I2C_SDA_GPIO_CLK             RCC_AHB1Periph_GPIOC
//#define sEE_I2C_SDA_SOURCE               GPIO_PinSource9
//#define sEE_I2C_SDA_AF                   GPIO_AF_I2C3
//#define sEE_M24C64_32
//
//#define sEE_I2C_DMA                      DMA1   
//#define sEE_I2C_DMA_CHANNEL              DMA_Channel_3
//#define sEE_I2C_DMA_STREAM_TX            DMA1_Stream4
//#define sEE_I2C_DMA_STREAM_RX            DMA1_Stream2   
//#define sEE_I2C_DMA_CLK                  RCC_AHB1Periph_DMA1
//#define sEE_I2C_DR_Address               ((uint32_t)0x40005C10)
//#define sEE_USE_DMA
//   
//#define sEE_I2C_DMA_TX_IRQn              DMA1_Stream4_IRQn
//#define sEE_I2C_DMA_RX_IRQn              DMA1_Stream2_IRQn
//#define sEE_I2C_DMA_TX_IRQHandler        DMA1_Stream4_IRQHandler
//#define sEE_I2C_DMA_RX_IRQHandler        DMA1_Stream2_IRQHandler   
//#define sEE_I2C_DMA_PREPRIO              0
//#define sEE_I2C_DMA_SUBPRIO              0   
//   
//#define sEE_TX_DMA_FLAG_FEIF             DMA_FLAG_FEIF4
//#define sEE_TX_DMA_FLAG_DMEIF            DMA_FLAG_DMEIF4
//#define sEE_TX_DMA_FLAG_TEIF             DMA_FLAG_TEIF4
//#define sEE_TX_DMA_FLAG_HTIF             DMA_FLAG_HTIF4
//#define sEE_TX_DMA_FLAG_TCIF             DMA_FLAG_TCIF4
//#define sEE_RX_DMA_FLAG_FEIF             DMA_FLAG_FEIF2
//#define sEE_RX_DMA_FLAG_DMEIF            DMA_FLAG_DMEIF2
//#define sEE_RX_DMA_FLAG_TEIF             DMA_FLAG_TEIF2
//#define sEE_RX_DMA_FLAG_HTIF             DMA_FLAG_HTIF2
//#define sEE_RX_DMA_FLAG_TCIF             DMA_FLAG_TCIF2
//   
//#define sEE_DIRECTION_TX                 0
//#define sEE_DIRECTION_RX                 1  
//
//
//

/**
 *   * @brief  SD FLASH SDIO Interface
 *     */

#define SD_DETECT_PIN                    GPIO_Pin_11                 /* PF.11 */
#define SD_DETECT_GPIO_PORT              GPIOF                       /* GPIOF */
#define SD_DETECT_GPIO_CLK               RCC_APB2Periph_GPIOF

#define SDIO_FIFO_ADDRESS                ((uint32_t)0x40018080)
/**
 *   * @brief  SDIO Intialization Frequency (400KHz max)
 *     */
#define SDIO_INIT_CLK_DIV                ((uint8_t)0xB2)
/**
 *   * @brief  SDIO Data Transfer Frequency (25MHz max)
 *     */
#define SDIO_TRANSFER_CLK_DIV            ((uint8_t)0x01)
//#define SDIO_TRANSFER_CLK_DIV            ((uint8_t)0x00)


///* Time constant for the delay caclulation allowing to have a millisecond 
//   incrementing counter. This value should be equal to (System Clock / 1000).
//   ie. if system clock = 168MHz then sEE_TIME_CONST should be 168. */
//#define sEE_TIME_CONST                   168 
///**
//  * @}
//  */  

/** @defgroup STM32F1_LOW_LEVEL_Exported_Macros
  * @{
  */  
/**
  * @}
  */ 


/** @defgroup STM32F1_LOW_LEVEL_Exported_Functions
  * @{
  */
void STM_LEDInit(Led_TypeDef Led);
void STM_LEDOn(Led_TypeDef Led);
void STM_LEDOff(Led_TypeDef Led);
void STM_LEDToggle(Led_TypeDef Led);
void STM__PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM_PBGetState(Button_TypeDef Button);
void STM_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
//void sEE_LowLevel_DeInit(void);
//void sEE_LowLevel_Init(void);
//void sEE_LowLevel_DMAConfig(uint32_t pBuffer, uint32_t BufferSize, uint32_t Direction);

void SD_LowLevel_DeInit(void);
void SD_LowLevel_Init(void);
void SD_LowLevel_DMA_TxConfig(uint32_t *BufferSRC, uint32_t BufferSize);
void SD_LowLevel_DMA_RxConfig(uint32_t *BufferDST, uint32_t BufferSize);
uint32_t SD_DMAEndOfTransferStatus(void);



/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM32F1_H */
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
