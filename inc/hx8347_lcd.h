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
#include "fonts.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM3210E_EVAL
  * @{
  */
    
/** @addtogroup STM3210E_EVAL_LCD
  * @{
  */ 

/** @defgroup STM3210E_EVAL_LCD_Exported_Types
  * @{
  */
typedef struct 
{
  int16_t X;
  int16_t Y;
} Point, * pPoint;   
/**
  * @}
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

/** 
  * @brief  LCD color  
  */ 
#define LCD_COLOR_RED		        		0xF800
#define LCD_COLOR_CRIMSON		    		0xD8A7
#define LCD_COLOR_FIREBRICK	    			0xB104
#define LCD_COLORMAROON		    			0x8000
#define LCD_COLORDARKRED		    		0x8800
#define LCD_COLORBROWN		    			0xA145
#define LCD_COLORSIENNA		    			0xA285
#define LCD_COLORSADDLEBROWN				0x8A22
#define LCD_COLORINDIANRED					0xCAEB
#define LCD_COLORROSYBROWN					0xBC71
#define LCD_COLORLIGHTCORAL					0xF410
#define LCD_COLORSALMON		    			0xFC0E
#define LCD_COLORDARKSALMON					0xECAF
#define LCD_COLORCORAL		    			0xFBEA
#define LCD_COLORTOMATO		    			0xFB08
#define LCD_COLORSANDYBROWN					0xF52C
#define LCD_COLORLIGHTSALMON				0xFD0F
#define LCD_COLORPERU		    			0xCC27
#define LCD_COLORCHOCOLATE					0xD343
#define LCD_COLORORANGERED					0xFA20
#define LCD_COLORORANGE		    			0xFD20
#define LCD_COLORDARKORANGE					0xFC60
#define LCD_COLORTAN		        		0xD5B1
#define LCD_COLORPEACHPUFF					0xFED7
#define LCD_COLORBISQUE		    			0xFF38
#define LCD_COLORMOCCASIN					0xFF36
#define LCD_COLORNAVAJOWHITE				0xFEF5
#define LCD_COLORWHEAT		    			0xF6F6
#define LCD_COLORBURLYWOOD					0xDDD0
#define LCD_COLORDARKGOLDENROD				0xBC21
#define LCD_COLORGOLDENROD					0xDD24
#define LCD_COLORGOLD		    			0xFEA0
#define LCD_COLORYELLOW		    			0xFFE0
#define LCD_COLORLIGHTGOLDENRODYELLOW		0xFFDA
#define LCD_COLORPALEGOLDENROD				0xEF55
#define LCD_COLORKHAKI		    			0xF731
#define LCD_COLORDARKKHAKI					0xBDAD
#define LCD_COLORLAWNGREEN					0x7FE0
#define LCD_COLORGREENYELLOW				0xAFE5
#define LCD_COLORCHARTREUSE					0x7FE0
#define LCD_COLORLIME		    			0x07E0
#define LCD_COLORLIMEGREEN					0x3666
#define LCD_COLORYELLOWGREEN				0x9E66
#define LCD_COLOROLIVE		    			0x8400
#define LCD_COLOROLIVEDRAB					0x6C64
#define LCD_COLORDARKOLIVEGREEN				0x5345
#define LCD_COLORFORESTGREEN				0x2444
#define LCD_COLORDARKGREEN					0x0320
#define LCD_COLORGREEN		    			0x0400
#define LCD_COLORSEAGREEN					0x2C4A
#define LCD_COLORMEDIUMSEAGREEN				0x3D8E
#define LCD_COLORDARKSEAGREEN				0x8DF1
#define LCD_COLORLIGHTGREEN					0x9772
#define LCD_COLORPALEGREEN					0x9FD3
#define LCD_COLORSPRINGGREEN				0x07EF
#define LCD_COLORMEDIUMSPRINGGREEN			0x07D3
#define LCD_COLORTEAL		    			0x0410
#define LCD_COLORDARKCYAN					0x0451
#define LCD_COLORLIGHTSEAGREEN				0x2595
#define LCD_COLORMEDIUMAQUAMARINE	    	0x6675
#define LCD_COLORCADETBLUE					0x5CF4
#define LCD_COLORSTEELBLUE					0x4416
#define LCD_COLORAQUAMARINE					0x7FFA
#define LCD_COLORPOWDERBLUE					0xB71C
#define LCD_COLORPALETURQUOISE				0xAF7D
#define LCD_COLORLIGHTBLUE					0xAEDC
#define LCD_COLORLIGHTSTEELBLUE				0xB63B
#define LCD_COLORSKYBLUE		    		0x867D
#define LCD_COLORLIGHTSKYBLUE				0x867F
#define LCD_COLORMEDIUMTURQUOISE			0x4E99
#define LCD_COLORTURQUOISE					0x471A
#define LCD_COLORDARKTURQUOISE				0x067A
#define LCD_COLORAQUA		    			0x07FF
#define LCD_COLORCYAN		    			0x07FF
#define LCD_COLORDEEPSKYBLUE				0x05FF
#define LCD_COLORDODGERBLUE					0x1C9F
#define LCD_COLORCORNFLOWERBLUE				0x64BD
#define LCD_COLORROYALBLUE					0x435C
#define LCD_COLORBLUE		    			0x001F
#define LCD_COLORMEDIUMBLUE					0x0019
#define LCD_COLORNAVY		    			0x0010
#define LCD_COLORDARKBLUE					0x0011
#define LCD_COLORMIDNIGHTBLUE				0x18CE
#define LCD_COLORDARKSLATEBLUE				0x49F1
#define LCD_COLORSLATEBLUE					0x6AD9
#define LCD_COLORMEDIUMSLATEBLUE			0x7B5D
#define LCD_COLORMEDIUMPURPLE				0x939B
#define LCD_COLORDARKORCHID					0x9999
#define LCD_COLORDARKVIOLET					0x901A
#define LCD_COLORBLUEVIOLET					0x895C
#define LCD_COLORMEDIUMORCHID				0xBABA
#define LCD_COLORPLUM		    			0xDD1B
#define LCD_COLORLAVENDER					0xE73F
#define LCD_COLORTHISTLE		    		0xDDFB
#define LCD_COLORORCHID		    			0xDB9A
#define LCD_COLORVIOLET		    			0xEC1D
#define LCD_COLORINDIGO		    			0x4810
#define LCD_COLORDARKMAGENTA				0x8811
#define LCD_COLORPURPLE		    			0x8010
#define LCD_COLORMEDIUMVIOLETRED			0xC0B0
#define LCD_COLORDEEPPINK					0xF8B2
#define LCD_COLORFUCHSIA		    		0xF81F
#define LCD_COLORMAGENTA		    		0xF81F
#define LCD_COLORHOTPINK		    		0xFB56
#define LCD_COLORPALEVIOLETRED				0xDB92
#define LCD_COLORLIGHTPINK					0xFDB8
#define LCD_COLORPINK		    			0xFE19
#define LCD_COLORMISTYROSE					0xFF3C
#define LCD_COLORBLANCHEDALMOND				0xFF59
#define LCD_COLORLIGHTYELLOW				0xFFFC
#define LCD_COLORCORNSILK					0xFFDB
#define LCD_COLORANTIQUEWHITE				0xFF5A
#define LCD_COLORPAPAYAWHIP					0xFF7A
#define LCD_COLORLEMONCHIFFON				0xFFD9
#define LCD_COLORBEIGE		    			0xF7BB
#define LCD_COLORLINEN		    			0xFF9C
#define LCD_COLOROLDLACE		    		0xFFBC
#define LCD_COLORLIGHTCYAN					0xE7FF
#define LCD_COLORALICEBLUE					0xF7DF
#define LCD_COLORWHITESMOKE					0xF7BE
#define LCD_COLORLAVENDERBLUSH				0xFF9E
#define LCD_COLORFLORALWHITE				0xFFDE
#define LCD_COLORMINTCREAM					0xF7FF
#define LCD_COLORGHOSTWHITE					0xFFDF
#define LCD_COLORHONEYDEW					0xF7FE
#define LCD_COLORSEASHELL					0xFFBD
#define LCD_COLORIVORY		    			0xFFFE
#define LCD_COLORAZURE		    			0xF7FF
#define LCD_COLORSNOW		    			0xFFDF
#define LCD_COLORWHITE		    			0xFFFF
#define LCD_COLORGAINSBORO					0xDEFB
#define LCD_COLORLIGHTGREY					0xD69A
#define LCD_COLORSILVER		    			0xC618
#define LCD_COLORDARKGRAY					0xAD55
#define LCD_COLORLIGHTSLATEGRAY				0x7453
#define LCD_COLORSLATEGRAY					0x7412
#define LCD_COLORGRAY		    			0x8410
#define LCD_COLORDIMGRAY		    		0x6B4D
#define LCD_COLORDARKSLATEGRAY				0x2A69
#define LCD_COLORBLACK		    			0x0000


/** 
  * @brief  LCD Lines depending on the chosen fonts.  
  */
#define LCD_LINE_0               LINE(0)
#define LCD_LINE_1               LINE(1)
#define LCD_LINE_2               LINE(2)
#define LCD_LINE_3               LINE(3)
#define LCD_LINE_4               LINE(4)
#define LCD_LINE_5               LINE(5)
#define LCD_LINE_6               LINE(6)
#define LCD_LINE_7               LINE(7)
#define LCD_LINE_8               LINE(8)
#define LCD_LINE_9               LINE(9)
#define LCD_LINE_10              LINE(10)
#define LCD_LINE_11              LINE(11)
#define LCD_LINE_12              LINE(12)
#define LCD_LINE_13              LINE(13)
#define LCD_LINE_14              LINE(14)
#define LCD_LINE_15              LINE(15)
#define LCD_LINE_16              LINE(16)
#define LCD_LINE_17              LINE(17)
#define LCD_LINE_18              LINE(18)
#define LCD_LINE_19              LINE(19)
#define LCD_LINE_20              LINE(20)
#define LCD_LINE_21              LINE(21)
#define LCD_LINE_22              LINE(22)
#define LCD_LINE_23              LINE(23)
#define LCD_LINE_24              LINE(24)
#define LCD_LINE_25              LINE(25)
#define LCD_LINE_26              LINE(26)
#define LCD_LINE_27              LINE(27)
#define LCD_LINE_28              LINE(28)
#define LCD_LINE_29              LINE(29)

/** 
  * @brief LCD default font 
  */ 
#define LCD_DEFAULT_FONT         Font16x24

/** 
  * @brief  LCD Direction  
  */ 
#define LCD_DIR_HORIZONTAL       0x0000
#define LCD_DIR_VERTICAL         0x0001

/** 
  * @brief  LCD Size (Width and Height)  
  */ 
#define LCD_PIXEL_WIDTH          240
#define LCD_PIXEL_HEIGHT         320

/**
  * @}
  */ 

/** @defgroup STM3210E_EVAL_LCD_Exported_Macros
  * @{
  */ 
#define ASSEMBLE_RGB(R, G, B)    ((((R)& 0xF8) << 8) | (((G) & 0xFC) << 3) | (((B) & 0xF8) >> 3))  
/**
  * @}
  */ 

/** @defgroup STM3210E_EVAL_LCD_Exported_Functions
  * @{
  */ 
/** @defgroup  
  * @{
  */ 
void LCD_DeInit(void);  
void STM3210E_LCD_Init(void);
void LCD_LandscapeMode(void);
void LCD_YmirrLandscapeMode(void);
void LCD_XYmirrLandscapeMode(void);
void LCD_PortraitMode(void);
void LCD_XmirrPortraitMode(void);
void LCD_YmirrPortraitMode(void);
void LCD_XYmirrPortraitMode(void);
void HX8347_AddrSet(u16 xStart,u16 yStart,u16 xEnd,u16 yEnd);
void LCD_ImageDraw(u16 xStart,u16 yStart,u16 xSize,u16 ySize,const u16 *buffer);

void LCD_DisplayOff(void);


void LCD_SetColors(__IO uint16_t _TextColor, __IO uint16_t _BackColor); 
void LCD_GetColors(__IO uint16_t *_TextColor, __IO uint16_t *_BackColor);
void LCD_SetTextColor(__IO uint16_t Color);
void LCD_SetBackColor(__IO uint16_t Color);
void LCD_Clear(uint16_t Color);
void LCD_SetFont(sFONT *fonts);
sFONT *LCD_GetFont(void);

/**
  * @}
  */ 

/** @defgroup  
  * @{
  */ 
//void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
//uint16_t LCD_ReadReg(uint8_t LCD_Reg);
//void LCD_WriteRAM_Prepare(void);
//void LCD_WriteRAM(uint16_t RGB_Code);
//uint16_t LCD_ReadRAM(void);

void LCD_PowerOn(void);
void LCD_DisplayOn(void);
/**
  * @}
  */ 

/** @defgroup  
  * @{
  */ 
void LCD_CtrlLinesConfig(void);
void LCD_FSMCConfig(void);
/**
  * @}
  */

/**
  * @}
  */    
#ifdef __cplusplus
}
#endif

#endif /* __STM3210E_EVAL_LCD_H */
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
  
/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
