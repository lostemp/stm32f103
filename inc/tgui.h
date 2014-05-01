#ifndef __TGUI_H
#define __TGUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"

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

void LCD_SetFontColor(uint16_t fgColor, uint16_t bgColor);
void LCD_PutStr(uint16_t xAxis, uint16_t yAxis, uint8_t *pStr);
void LCD_PutCharKor(uint16_t xStart, uint16_t yStart, uint16_t code);
void LCD_PutCharEng(uint16_t xStart, uint16_t yStart, uint8_t ascii);
void LCD_ImageDraw(uint16_t xStart,uint16_t yStart,uint16_t xSize,uint16_t ySize,const uint16_t *buffer);
void LCD_Full8Color(uint16_t xSize,uint16_t ySize,uint16_t msec);
void LCD_Color(uint16_t xStart,uint16_t yStart,uint16_t xSize,uint16_t ySize,uint16_t color);

#ifdef __cplusplus
}
#endif

#endif