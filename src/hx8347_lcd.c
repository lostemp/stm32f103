/**
  ******************************************************************************
  * @file    stm3210e_eval_lcd.c
  * @author  MCD Application Team
  * @version V4.5.0
  * @date    07-March-2011
  * @brief   This file includes the LCD driver for AM-240320L8TNQW00H 
  *          (LCD_ILI9320) and AM-240320LDTNQW00H (LCD_SPFD5408B) Liquid Crystal
  *          Display Module of STM3210E-EVAL board.
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

/* Includes ------------------------------------------------------------------*/
#include "hx8347_lcd.h"

#ifndef USE_Delay
static void delay(vu32 nCount);
#endif /* USE_Delay*/

/**
  * @brief  Initializes the LCD.
  * @param  None
  * @retval None
  */
void HX8347_Init(void)
{ 
	_delay_(5); // delay 50 ms
	
	// Power ON RESET& Display OFF
	LCD_WriteReg(0x26, 0x0000); //DTE="0", D[1-0]="00", GON="0"
	LCD_WriteReg(0x1B, 0x0008); //PON="0", DK="1"
	LCD_WriteReg(0x43, 0x0000); //VCOMG="0"
	_delay_(1);	// delay 10 ms
		
	// For the setting before power supply startup
	LCD_WriteReg(0x20, 0x0050); //BT(0x0040)
	LCD_WriteReg(0x1F, 0x0008); //VRH(0x0006)
	LCD_WriteReg(0x44, 0x0054); //VCM(0x005A)
	LCD_WriteReg(0x45, 0x0010); //VDV(0x0011)
	LCD_WriteReg(0x1D, 0x0004); //VC1(0x0004)
	LCD_WriteReg(0x1E, 0x0001); //VC3(0x0000)

	LCD_WriteReg(0x19, 0x0049);
	LCD_WriteReg(0x93, 0x000A);   //OSC Control 3(125%, Internal oscillator frequency)
	
	//For power-supply setting(1)
	LCD_WriteReg(0x1C, 0x0004); //AP[2-0]="100"
	LCD_WriteReg(0x1B, 0x0010); //PON="1", DK="0"
	_delay_(4);	// delay 40 ms
	
	//For power-supply setting(2)
	LCD_WriteReg(0x43, 0x0080); //VCOMG="1"
	_delay_(6);	// delay 60 ms
	
	//Gamma setting 
	LCD_WriteReg(0x46, 0x0081);
	LCD_WriteReg(0x47, 0x0010); 
	LCD_WriteReg(0x48, 0x0001); 
	LCD_WriteReg(0x49, 0x0004); 
	LCD_WriteReg(0x4A, 0x0010); 
	LCD_WriteReg(0x4B, 0x0076); 
	LCD_WriteReg(0x4C, 0x0037); 
	LCD_WriteReg(0x4D, 0x0067); 
	LCD_WriteReg(0x4E, 0x0007); 
	LCD_WriteReg(0x4F, 0x0014); 
	LCD_WriteReg(0x50, 0x000A); 
	LCD_WriteReg(0x51, 0x000E);
	
	//Window Setting
	// Column address start, end
	LCD_WriteReg(0x02, 0x0000);	
	LCD_WriteReg(0x03, 0x0000);
	LCD_WriteReg(0x04, 0x0000);	
	LCD_WriteReg(0x05, 0x00EF);
	
	// Row address start, end
	LCD_WriteReg(0x06, 0x0000);	
	LCD_WriteReg(0x07, 0x0000);
	LCD_WriteReg(0x08, 0x0001);
	LCD_WriteReg(0x09, 0x003F);
	
	//Display Setting
	LCD_WriteReg(0x01, 0x0006);	 
	// MX=1,MY=1,MV=0
	// BGR=1 : RGB(Driver IC) -> BGR(LCD Pannel)
	LCD_WriteReg(0x16, 0x00C8); 

	// Timming setting
	LCD_WriteReg(0x23, 0x0095);	 
	LCD_WriteReg(0x24, 0x0095);	 
	LCD_WriteReg(0x25, 0x00FF);

	LCD_WriteReg(0x27, 0x0002);	 
	LCD_WriteReg(0x28, 0x0002);	 
	LCD_WriteReg(0x29, 0x0002);	 
	LCD_WriteReg(0x2A, 0x0002);	 
	LCD_WriteReg(0x2C, 0x0002);	 
	LCD_WriteReg(0x2D, 0x0002);	 

	LCD_WriteReg(0x3A, 0x0001);	 
	LCD_WriteReg(0x3B, 0x0001);	 
	LCD_WriteReg(0x3C, 0x00F0);	 
	LCD_WriteReg(0x3D, 0x0000);	 

	LCD_WriteReg(0x35, 0x0038);	 
	LCD_WriteReg(0x36, 0x0078);	 
	LCD_WriteReg(0x3E, 0x0038);	 
	LCD_WriteReg(0x40, 0x000F);	 
	LCD_WriteReg(0x41, 0x00F0);
	LCD_WriteReg(0x38, 0x0000); 
	
	// ** Display On Flow
	LCD_WriteReg(0x90, 0x007F); //SAP[7-0]
	
	// Display on
	LCD_WriteReg(0x26, 0x0004); //DTE="0", D[1-0]="01", GON="0"
	_delay_(4);	// delay 40 ms
	
	//Display on
	LCD_WriteReg(0x26, 0x0024); //DTE="0", D[1-0]="01", GON="1"
	
	//Display on
	LCD_WriteReg(0x26, 0x002C); //DTE="0", D[1-0]="11", GON="1"
	_delay_(4);	// delay 40 ms
	
	//Display on
	LCD_WriteReg(0x26, 0x003C); //DTE="1", D[1-0]="11", GON="1"
}

/*******************************************************************************
* Function Name : void LCD_LandscapeMode(void)  
* Description   : Landscape Mode(320*240)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_LandscapeMode(void)
{
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=1, MX=0, MV=1
    LCD_WriteReg(0x16, 0x00A8);
}

/*******************************************************************************
* Function Name : void LCD_XmirrLandscapeMode(void)
* Description   : X-Mirror Landscape Mode(320*240)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_XmirrLandscapeMode(void)
{          
	// MY : Page Address Order
	// MX : Colume Address Order
	// MV : Page/Colume Selection
    // MY=1, MX=1, MV=1 
    LCD_WriteReg(0x16, 0x00E8);
}

/*******************************************************************************
* Function Name : void LCD_YmirrLandscapeMode(void)
* Description   : Y-Mirror Landscape Mode(320*240)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_YmirrLandscapeMode(void)
{          
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=0, MX=0, MV=1 
    LCD_WriteReg(0x16, 0x0028);
}

/*******************************************************************************
* Function Name : void LCD_XYmirrLandscapeMode(void)
* Description   : XY-Mirror Landscape Mode(320*240)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_XYmirrLandscapeMode(void)
{          
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=0, MX=1, MV=1 
    LCD_WriteReg(0x16, 0x0068);
}

/*******************************************************************************
* Function Name : void LCD_PortraitMode(void) 
* Description   : Portrait Mode(240*320)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_PortraitMode(void)
{
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=1, MX=1, MV=0
    LCD_WriteReg(0x16, 0x00C8);
}

/*******************************************************************************
* Function Name : void LCD_XmirrPortraitMode(void) 
* Description   : X-Mirror Portrait Mode(240*320)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_XmirrPortraitMode(void)
{
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=1, MX=0, MV=0
    LCD_WriteReg(0x16, 0x0088);
}

/*******************************************************************************
* Function Name : void LCD_YmirrPortraitMode(void) 
* Description   : Y-Mirror Portrait Mode(240*320)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_YmirrPortraitMode(void)
{
	// MY : Page Address Order
	// MX : Colume Address Order	
	// MV : Page/Colume Selection
    // MY=0, MX=1, MV=0
    LCD_WriteReg(0x16, 0x0048);
}

/*******************************************************************************
* Function Name : void LCD_XYmirrPortraitMode(void) 
* Description   : Y-Mirror Portrait Mode(240*320)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_XYmirrPortraitMode(void)
{
	// MY : Page Address Order
	// MX : Colume Address Order
	// MV : Page/Colume Selection
    // MY=0, MX=0, MV=0
    LCD_WriteReg(0x16, 0x0008);
}

/**
  * @brief  Enables the Display.
  * @param  None
  * @retval None
  */
void HX8347_DisplayOn(void)
{
	/* Display On */
	LCD_WriteReg(LCD_REG_7, 0x0173); /* 262K color and display ON */
}

/*******************************************************************************
* Function Name : void LCD_DisplayOff(void) 
* Description   : Y-Mirror Portrait Mode(240*320)
* Parameters    : None
* Return        : None
*******************************************************************************/
void HX8347_DisplayOff(void)
{
	//Display off
	LCD_WriteReg(0x26, 0x0038);	//GON = "1", DTE = "1", D[1-0] = "10"
	_delay_(4); // delay 40 ms
	
	LCD_WriteReg(0x26, 0x0028);	//GON = "1", DTE = "0", D1-0 = "10"
	_delay_(4); // delay 40 ms

	LCD_WriteReg(0x26, 0x0000);	//GON = "0", DTE = "0", D1-0 = "00"

	//Power OFF Setting
	LCD_WriteReg(0x90, 0x0000);	//SAP[7-0] = "00000000"		
	LCD_WriteReg(0x1C, 0x0000); //AP[2-0]="000"
	LCD_WriteReg(0x1B, 0x0008); //PON="0", DK="1"	
	LCD_WriteReg(0x43, 0x0000); //VCOMG="1"
}

/**
  * @brief  Power on the LCD.
  * @param  None
  * @retval None
  */
void HX8347_PowerOn(void)
{
	/* Power On sequence ---------------------------------------------------------*/
	LCD_WriteReg(LCD_REG_16, 0x0000); /* SAP, BT[3:0], AP, DSTB, SLP, STB */
	LCD_WriteReg(LCD_REG_17, 0x0000); /* DC1[2:0], DC0[2:0], VC[2:0] */
	LCD_WriteReg(LCD_REG_18, 0x0000); /* VREG1OUT voltage */
	LCD_WriteReg(LCD_REG_19, 0x0000); /* VDV[4:0] for VCOM amplitude*/
	_delay_(20);                 /* Dis-charge capacitor power voltage (200ms) */
	LCD_WriteReg(LCD_REG_16, 0x17B0); /* SAP, BT[3:0], AP, DSTB, SLP, STB */
	LCD_WriteReg(LCD_REG_17, 0x0137); /* DC1[2:0], DC0[2:0], VC[2:0] */
	_delay_(5);                  /* Delay 50 ms */
	LCD_WriteReg(LCD_REG_18, 0x0139); /* VREG1OUT voltage */
	_delay_(5);                  /* Delay 50 ms */
	LCD_WriteReg(LCD_REG_19, 0x1d00); /* VDV[4:0] for VCOM amplitude */
	LCD_WriteReg(LCD_REG_41, 0x0013); /* VCM[4:0] for VCOMH */
	_delay_(5);                  /* Delay 50 ms */
	LCD_WriteReg(LCD_REG_7, 0x0173);  /* 262K color and display ON */
}

/*******************************************************************************
* Function Name : void HX8347_AddrSet(u16 xStart,u16 yStart,u16 xEnd,u16 yEnd)
* Description   : TFT LCD position setting
* Parameters    : X좌표,Y좌표
* Return        : None
*******************************************************************************/
void HX8347_AddrSet(uint16_t xStart,uint16_t yStart,uint16_t xEnd,uint16_t yEnd)
{
	// 시작 위치 설정
    LCD_WriteReg(0x02,xStart>>8);
    LCD_WriteReg(0x03,xStart&0x00FF);
    LCD_WriteReg(0x06,yStart>>8);
    LCD_WriteReg(0x07,yStart&0x00FF);

	// 끝 위치 설정
    LCD_WriteReg(0x04,xEnd>>8);  	
    LCD_WriteReg(0x05,xEnd&0x00FF);   	
    LCD_WriteReg(0x08,yEnd>>8);  	
    LCD_WriteReg(0x09,yEnd&0x00FF);
    
    // Write data to GRAM
    LCD_WriteRamPre(LCD_REG_34);
}

#ifndef USE_Delay
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
static void delay(vu32 nCount)
{
  vu32 index = 0; 
  for(index = (100000 * nCount); index != 0; index--)
  {
  }
}
#endif /* USE_Delay*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
