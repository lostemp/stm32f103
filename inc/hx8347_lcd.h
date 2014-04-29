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
/* #define USE_Delay */

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

// 16bit Color Table
#define RGB_RED		        0xF800
#define RGB_CRIMSON		    0xD8A7
#define RGB_FIREBRICK	    0xB104
#define RGB_MAROON		    0x8000
#define RGB_DARKRED		    0x8800
#define RGB_BROWN		    0xA145
#define RGB_SIENNA		    0xA285
#define RGB_SADDLEBROWN		0x8A22
#define RGB_INDIANRED		0xCAEB
#define RGB_ROSYBROWN		0xBC71
#define RGB_LIGHTCORAL		0xF410
#define RGB_SALMON		    0xFC0E
#define RGB_DARKSALMON		0xECAF
#define RGB_CORAL		    0xFBEA
#define RGB_TOMATO		    0xFB08
#define RGB_SANDYBROWN		0xF52C
#define RGB_LIGHTSALMON		0xFD0F
#define RGB_PERU		    0xCC27
#define RGB_CHOCOLATE		0xD343
#define RGB_ORANGERED		0xFA20
#define RGB_ORANGE		    0xFD20
#define RGB_DARKORANGE		0xFC60
#define RGB_TAN		        0xD5B1
#define RGB_PEACHPUFF		0xFED7
#define RGB_BISQUE		    0xFF38
#define RGB_MOCCASIN		0xFF36
#define RGB_NAVAJOWHITE		0xFEF5
#define RGB_WHEAT		    0xF6F6
#define RGB_BURLYWOOD		0xDDD0
#define RGB_DARKGOLDENROD	0xBC21
#define RGB_GOLDENROD		0xDD24
#define RGB_GOLD		    0xFEA0
#define RGB_YELLOW		    0xFFE0
#define RGB_LIGHTGOLDENRODYELLOW		0xFFDA
#define RGB_PALEGOLDENROD	0xEF55
#define RGB_KHAKI		    0xF731
#define RGB_DARKKHAKI		0xBDAD
#define RGB_LAWNGREEN		0x7FE0
#define RGB_GREENYELLOW		0xAFE5
#define RGB_CHARTREUSE		0x7FE0
#define RGB_LIME		    0x07E0
#define RGB_LIMEGREEN		0x3666
#define RGB_YELLOWGREEN		0x9E66
#define RGB_OLIVE		    0x8400
#define RGB_OLIVEDRAB		0x6C64
#define RGB_DARKOLIVEGREEN	0x5345
#define RGB_FORESTGREEN		0x2444
#define RGB_DARKGREEN		0x0320
#define RGB_GREEN		    0x0400
#define RGB_SEAGREEN		0x2C4A
#define RGB_MEDIUMSEAGREEN	0x3D8E
#define RGB_DARKSEAGREEN	0x8DF1
#define RGB_LIGHTGREEN		0x9772
#define RGB_PALEGREEN		0x9FD3
#define RGB_SPRINGGREEN		0x07EF
#define RGB_MEDIUMSPRINGGREEN		0x07D3
#define RGB_TEAL		    0x0410
#define RGB_DARKCYAN		0x0451
#define RGB_LIGHTSEAGREEN	0x2595
#define RGB_MEDIUMAQUAMARINE	    0x6675
#define RGB_CADETBLUE		0x5CF4
#define RGB_STEELBLUE		0x4416
#define RGB_AQUAMARINE		0x7FFA
#define RGB_POWDERBLUE		0xB71C
#define RGB_PALETURQUOISE	0xAF7D
#define RGB_LIGHTBLUE		0xAEDC
#define RGB_LIGHTSTEELBLUE	0xB63B
#define RGB_SKYBLUE		    0x867D
#define RGB_LIGHTSKYBLUE	0x867F
#define RGB_MEDIUMTURQUOISE	0x4E99
#define RGB_TURQUOISE		0x471A
#define RGB_DARKTURQUOISE	0x067A
#define RGB_AQUA		    0x07FF
#define RGB_CYAN		    0x07FF
#define RGB_DEEPSKYBLUE		0x05FF
#define RGB_DODGERBLUE		0x1C9F
#define RGB_CORNFLOWERBLUE	0x64BD
#define RGB_ROYALBLUE		0x435C
#define RGB_BLUE		    0x001F
#define RGB_MEDIUMBLUE		0x0019
#define RGB_NAVY		    0x0010
#define RGB_DARKBLUE		0x0011
#define RGB_MIDNIGHTBLUE	0x18CE
#define RGB_DARKSLATEBLUE	0x49F1
#define RGB_SLATEBLUE		0x6AD9
#define RGB_MEDIUMSLATEBLUE	0x7B5D
#define RGB_MEDIUMPURPLE	0x939B
#define RGB_DARKORCHID		0x9999
#define RGB_DARKVIOLET		0x901A
#define RGB_BLUEVIOLET		0x895C
#define RGB_MEDIUMORCHID	0xBABA
#define RGB_PLUM		    0xDD1B
#define RGB_LAVENDER		0xE73F
#define RGB_THISTLE		    0xDDFB
#define RGB_ORCHID		    0xDB9A
#define RGB_VIOLET		    0xEC1D
#define RGB_INDIGO		    0x4810
#define RGB_DARKMAGENTA		0x8811
#define RGB_PURPLE		    0x8010
#define RGB_MEDIUMVIOLETRED	0xC0B0
#define RGB_DEEPPINK		0xF8B2
#define RGB_FUCHSIA		    0xF81F
#define RGB_MAGENTA		    0xF81F
#define RGB_HOTPINK		    0xFB56
#define RGB_PALEVIOLETRED	0xDB92
#define RGB_LIGHTPINK		0xFDB8
#define RGB_PINK		    0xFE19
#define RGB_MISTYROSE		0xFF3C
#define RGB_BLANCHEDALMOND	0xFF59
#define RGB_LIGHTYELLOW		0xFFFC
#define RGB_CORNSILK		0xFFDB
#define RGB_ANTIQUEWHITE	0xFF5A
#define RGB_PAPAYAWHIP		0xFF7A
#define RGB_LEMONCHIFFON	0xFFD9
#define RGB_BEIGE		    0xF7BB
#define RGB_LINEN		    0xFF9C
#define RGB_OLDLACE		    0xFFBC
#define RGB_LIGHTCYAN		0xE7FF
#define RGB_ALICEBLUE		0xF7DF
#define RGB_WHITESMOKE		0xF7BE
#define RGB_LAVENDERBLUSH	0xFF9E
#define RGB_FLORALWHITE		0xFFDE
#define RGB_MINTCREAM		0xF7FF
#define RGB_GHOSTWHITE		0xFFDF
#define RGB_HONEYDEW		0xF7FE
#define RGB_SEASHELL		0xFFBD
#define RGB_IVORY		    0xFFFE
#define RGB_AZURE		    0xF7FF
#define RGB_SNOW		    0xFFDF
#define RGB_WHITE		    0xFFFF
#define RGB_GAINSBORO		0xDEFB
#define RGB_LIGHTGREY		0xD69A
#define RGB_SILVER		    0xC618
#define RGB_DARKGRAY		0xAD55
#define RGB_LIGHTSLATEGRAY	0x7453
#define RGB_SLATEGRAY		0x7412
#define RGB_GRAY		    0x8410
#define RGB_DIMGRAY		    0x6B4D
#define RGB_DARKSLATEGRAY	0x2A69
#define RGB_BLACK		    0x0000	


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
void HX8347_AddrSet(u16 xStart, u16 yStart, u16 xEnd, u16 End);

#ifdef __cplusplus
}
#endif

#endif 
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
