/**
  ******************************************************************************
  * @file    stm3210e_eval_lcd.h
  * @author  MCD Application Team
  * @version V4.5.0
  * @date    07-March-2011
  * @brief   This file contains all the functions prototypes for the stm3210e_eval_lcd
  *          firmware driver.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************  
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HX8347_LCD_H
#define __HX8347_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

typedef struct
{
  __IO uint16_t LCD_REG;
  __IO uint16_t LCD_RAM;
} LCD_TypeDef;

/* @}
  */ 

/** @defgroup STM3210E_EVAL_LCD_Exported_Constants
  * @{
  */ 

/**
 * @brief Uncomment the line below if you want to use user defined Delay function
 *        (for precise timing), otherwise default _delay_ function defined within
 *         this driver is used (less precise timing).  
 */

#define USE_Delay

#ifdef USE_Delay
#include "main.h" 
  #define _delay_     Delay  /* !< User can provide more timing precise _delay_ function
                                   (with 10ms time base), using SysTick for example */
#else
  #define _delay_     delay      /* !< Default _delay_ function with less precise timing */
#endif
 
/** 
  * @brief  LCD Registers  
  */ 
#define LCD_REG_0             0x00
#define LCD_REG_1             0x01
#define LCD_REG_2             0x02
#define LCD_REG_3             0x03
#define LCD_REG_4             0x04
#define LCD_REG_5             0x05
#define LCD_REG_6             0x06
#define LCD_REG_7             0x07
#define LCD_REG_8             0x08
#define LCD_REG_9             0x09
#define LCD_REG_10            0x0A
#define LCD_REG_12            0x0C
#define LCD_REG_13            0x0D
#define LCD_REG_14            0x0E
#define LCD_REG_15            0x0F
#define LCD_REG_16            0x10
#define LCD_REG_17            0x11
#define LCD_REG_18            0x12
#define LCD_REG_19            0x13
#define LCD_REG_20            0x14
#define LCD_REG_21            0x15
#define LCD_REG_22            0x16
#define LCD_REG_23            0x17
#define LCD_REG_24            0x18
#define LCD_REG_25            0x19
#define LCD_REG_26            0x1A
#define LCD_REG_27            0x1B
#define LCD_REG_28            0x1C
#define LCD_REG_29            0x1D
#define LCD_REG_30            0x1E
#define LCD_REG_31            0x1F
#define LCD_REG_32            0x20
#define LCD_REG_33            0x21
#define LCD_REG_34            0x22
#define LCD_REG_36            0x24
#define LCD_REG_37            0x25
#define LCD_REG_40            0x28
#define LCD_REG_41            0x29
#define LCD_REG_43            0x2B
#define LCD_REG_45            0x2D
#define LCD_REG_48            0x30
#define LCD_REG_49            0x31
#define LCD_REG_50            0x32
#define LCD_REG_51            0x33
#define LCD_REG_52            0x34
#define LCD_REG_53            0x35
#define LCD_REG_54            0x36
#define LCD_REG_55            0x37
#define LCD_REG_56            0x38
#define LCD_REG_57            0x39
#define LCD_REG_58            0x3A
#define LCD_REG_59            0x3B
#define LCD_REG_60            0x3C
#define LCD_REG_61            0x3D
#define LCD_REG_62            0x3E
#define LCD_REG_63            0x3F
#define LCD_REG_64            0x40
#define LCD_REG_65            0x41
#define LCD_REG_66            0x42
#define LCD_REG_67            0x43
#define LCD_REG_68            0x44
#define LCD_REG_69            0x45
#define LCD_REG_70            0x46
#define LCD_REG_71            0x47
#define LCD_REG_72            0x48
#define LCD_REG_73            0x49
#define LCD_REG_74            0x4A
#define LCD_REG_75            0x4B
#define LCD_REG_76            0x4C
#define LCD_REG_77            0x4D
#define LCD_REG_78            0x4E
#define LCD_REG_79            0x4F
#define LCD_REG_80            0x50
#define LCD_REG_81            0x51
#define LCD_REG_82            0x52
#define LCD_REG_83            0x53
#define LCD_REG_96            0x60
#define LCD_REG_97            0x61
#define LCD_REG_106           0x6A
#define LCD_REG_118           0x76
#define LCD_REG_128           0x80
#define LCD_REG_129           0x81
#define LCD_REG_130           0x82
#define LCD_REG_131           0x83
#define LCD_REG_132           0x84
#define LCD_REG_133           0x85
#define LCD_REG_134           0x86
#define LCD_REG_135           0x87
#define LCD_REG_136           0x88
#define LCD_REG_137           0x89
#define LCD_REG_139           0x8B
#define LCD_REG_140           0x8C
#define LCD_REG_141           0x8D
#define LCD_REG_143           0x8F
#define LCD_REG_144           0x90
#define LCD_REG_145           0x91
#define LCD_REG_146           0x92
#define LCD_REG_147           0x93
#define LCD_REG_148           0x94
#define LCD_REG_149           0x95
#define LCD_REG_150           0x96
#define LCD_REG_151           0x97
#define LCD_REG_152           0x98
#define LCD_REG_153           0x99
#define LCD_REG_154           0x9A
#define LCD_REG_157           0x9D
#define LCD_REG_192           0xC0
#define LCD_REG_193           0xC1
#define LCD_REG_229           0xE5

#define LCD_PIXEL_WIDTH				240
#define LCD_PIXEL_HEIGHT			320
#define LCD_PIXEL_TOTAL				76800

/* Note: LCD /CS is CE4 - Bank 4 of NOR/SRAM Bank 1~4 */
#define LCD_BASE           ((uint32_t)(0x60000000 | 0x0C000000))
#define LCD                ((LCD_TypeDef *) LCD_BASE)

#define LCD_WriteReg(reg, cmd)  LCD->LCD_REG = reg; LCD->LCD_RAM = cmd;
#define LCD_WriteRamPre(reg)    LCD->LCD_REG = reg
#define LCD_WriteRam(data)      LCD->LCD_RAM = data

void HX8347_Init(void);
void HX8347_LandscapeMode(void);
void HX8347_XmirrLandscapeMode(void);
void HX8347_YmirrLandscapeMode(void);
void HX8347_XYmirrLandscapeMode(void);
void HX8347_PortraitMode(void);
void HX8347_XmirrPortraitMode(void);
void HX8347_YmirrPortraitMode(void);
void HX8347_XYmirrPortraitMode(void);
void HX8347_DisplayOn(void);
void HX8347_DisplayOff(void);
void HX8347_PowerOn(void);
void HX8347_AddrSet(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t End);

#ifdef __cplusplus
}
#endif

#endif 
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
