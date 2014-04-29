//#include "fonts.h"
#include "kssm_table.h"
#include "pilgi16x16_kor.h"
#include "font8x16_ascii.h"

#include "hx8347_lcd.h"


//static sFONT *LCD_Currentfonts;

/* Global variables to set the written text color */
static  __IO uint16_t TextColor = RGB_BLACK, BackColor = RGB_WHITE;

extern const uint8_t Font8x16Ascii[128][16];

void GetFontBuffer(uint16_t code, uint8_t *FontBuffer);
uint16_t KsToKssm(uint16_t code);

//void LCD_Clear(uint16_t Color)
//{
//  uint32_t index = 0;
//
//  HX8347_AddrSet(0, 0, LCD_PIXEL_WIDTH-1, LCD_PIXEL_HEIGHT-1); 
//  for(index = 0; index < LCD_PIXEL_TOTAL; index++)	LCD->LCD_RAM = Color;
//}

void LCD_SetFontColor(uint16_t fgColor, uint16_t bgColor)
{
	TextColor = fgColor;
	BackColor = bgColor;
}

/*******************************************************************************
* Function Name : void TFT_PutStr(u16 xAxis,u16 yAxis,u8 *pStr,u16 color,u16 BgColor)
* Description   : 문자열 출력
* Parameters    : X좌표, Y좌표, 문자열, color
* Return        : none
*******************************************************************************/
void LCD_PutStr(uint16_t xAxis, uint16_t yAxis, uint8_t *pStr)
{    
    u8  EngChar;
    u16 KorChar;

    xAxis *= 8;
    yAxis *= 16;

	while(*pStr != '\0') {                
        
		if(*pStr<0x80) {
        	// 영문인 경우
            EngChar = *(pStr++);
            LCD_PutCharEng(xAxis,yAxis,EngChar);                       
            xAxis += 8;
        }else {
        	// 한글인 경우
            KorChar = *(pStr++)<<8;
            KorChar |= *(pStr++);

            LCD_PutCharKor(xAxis,yAxis,KsToKssm(KorChar));     
            xAxis += 16;
        }
    }    
}

/*******************************************************************************
* Function Name : void TFT_PutCharKor(u16 xStart,u16 yStart,u16 code,u16 color,u16 BgColor)
* Description   : 한글문자 출력
* Parameters    : X좌표, Y좌표, 완성형코드, color
* Return        : none
*******************************************************************************/
void LCD_PutCharKor(u16 xStart,u16 yStart,u16 code)
{
	s16 x,y;
    u8 FontBuffer[32];

    HX8347_AddrSet(xStart,yStart,xStart+15,yStart+15);
	GetFontBuffer(code,FontBuffer);

	for(y=0;y<32;y++)
	{
		for(x=7;x>=0;x--)
		{
            if(FontBuffer[y]&(1<<x)) LCD_WriteRam(TextColor);
            else LCD_WriteRam(BackColor);                         
		}
	}	
}

/*******************************************************************************
* Function Name : void TFT_PutCharEng(u16 xStart,u16 yStart,u8 ascii,u16 color,u16 BgColor)
* Description   : 아스키문자 출력
* Parameters    : X좌표, Y좌표, 아스키코드, color
* Return        : none
*******************************************************************************/
void LCD_PutCharEng(u16 xStart,u16 yStart,u8 ascii)
{
	s16 x,y;               

    HX8347_AddrSet(xStart,yStart,xStart+7,yStart+15);

    for(y=0;y<16;y++)
    {
        for(x=7;x>=0;x--)
        {
            if(Font8x16Ascii[ascii][y]&(1<<x)) LCD_WriteRam(TextColor);
            else LCD_WriteRam(BackColor);
        }
    }
}

/*******************************************************************************
* Function Name : void GetFontBuffer(u16 code, u8 *FontBuffer)
* Description   : 조합형폰트 버퍼에 가져오기
* Parameters    : 조합형코드, 폰트버퍼
* Return        : None
*******************************************************************************/
void GetFontBuffer(uint16_t code, uint8_t *FontBuffer)
{
	unsigned char i;
	unsigned char cho_5bit, joong_5bit, jong_5bit;
	unsigned char cho_bul, joong_bul, jong_bul=0, jong_flag;
	unsigned short ch;

	cho_5bit = table_cho[(code >> 10) & 0x001F];		// 초성: 14-10 5bit를 추출
	joong_5bit = table_joong[(code >> 5) & 0x001F];	    // 중성: 09-05 5bit를 추출
	jong_5bit = table_jong[code & 0x001F];				// 종성: 04-00 5bit를 추출

	if(jong_5bit == 0) {
		// 종성이 없으면
		jong_flag = 0;
		cho_bul = bul_cho1[joong_5bit];
		if((cho_5bit == 1) || (cho_5bit == 16))			// 1: Fill Code, 16: ㅊ
			joong_bul = 0;
		else
			joong_bul = 1;
    }else { 
		// 종성이 있으면
		jong_flag = 1;
		cho_bul = bul_cho2[joong_5bit];
		if((cho_5bit == 1) || (cho_5bit == 16))
			joong_bul = 2;
		else
			joong_bul = 3;

		jong_bul = bul_jong[joong_5bit];
	}

	//----------------------- 폰트를 버퍼로 복사---------------------------
	ch = cho_bul*20 + cho_5bit;			        // 초성 폰트 복사 
	for(i = 0; i < 32; i++)
	    FontBuffer[i] = Font16x16Kor[ch][i];

	ch = 8*20 + joong_bul*22 + joong_5bit;	    // 중성 폰트를 OR
	for(i = 0; i < 32; i++)
	    FontBuffer[i] |= Font16x16Kor[ch][i];

	if(jong_flag) {
        // 종성이 존재하면 OR
		ch = 8*20 + 4*22 + jong_bul*28 + jong_5bit;
		for(i = 0; i < 32; i++)
			FontBuffer[i] |= Font16x16Kor[ch][i];
    }
}

/*******************************************************************************
* Function Name : u16 KsToKssm(u16 code)
* Description   : 완성형코드를 조합형코드로 변환
* Parameters    : 완성형코드
* Return        : 조합형코드
*******************************************************************************/
uint16_t KsToKssm(uint16_t code)
{
	u8  high,low;
	u16 index;

    high = code>>8;
    low = code;
	index = ((u16)high - 0xB0) * 94 + low - 0xA1;

	return KSTable[index][0] * 256 + KSTable[index][1];
}

/*******************************************************************************
* Function Name : u16 KsToKssm(u16 code)
* Description   : 유니코드를 조합형코드로 변환
* Parameters    : 유니코드
* Return        : 조합형코드
*******************************************************************************/
u16 UniToKssm(u16 unicode)
{
    u8 cho, jung, jong;               // 초성, 중성(joong은 jong과 혼동 방지를 위해 jung으로 표기), 종성  
    u16 uni_value;
    u16 kssm;                                 // 조합형 한글 저장소

    uni_value = unicode - 0xAC00;                // 유니코드 '가'에 해당하는 값을 뺀다.

    /* 초성, 중성, 종성 분리  */
    jong = uni_value % 28;
    jung = ((uni_value - jong) / 28 ) % 21;
    cho = ((uni_value - jong) / 28 ) / 21;

    /* 초성 중성 종성 조합형 자모 값으로 변환  */
    cho += 2;                            // 초성은 조합형의 경우 유니코드보다 오프셋이 2정도 크다.

    // 중성의 경우 해당 오프셋이 중간마다 띄어져 있으므로 위의 표를 참고하여 오프셋을 달리 더해준다.
    if(jung < 5) jung += 3;
    else if(jung < 11) jung += 5;
    else if(jung < 17) jung += 7;
    else jung += 9;

    // 종성의 경우 또한 중성처럼 표를 참고하여 오프셋을 달리 더해 준다.
    if(jong < 17) jong++;
    else jong += 2;

    /* 조합형 한글로 변환 */
    // MSB가 1일 경우 한글이므로 0x8000
    kssm = 0x8000 | (cho << 10) | ( jung<<5) | jong;

    return kssm;
}
