#ifndef __TGUI_H
#define __TGUI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"

void LCD_SetFontColor(uint16_t fgColor, uint16_t bgColor);
void LCD_PutStr(uint16_t xAxis, uint16_t yAxis, uint8_t *pStr);
void LCD_PutCharKor(uint16_t xStart, uint16_t yStart, uint16_t code);
void LCD_PutCharEng(uint16_t xStart, uint16_t yStart, uint8_t ascii);

#ifdef __cplusplus
}
#endif

#endif
