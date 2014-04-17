/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
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
#include "main.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MESSAGE1   " STM32 High Density " 
#define MESSAGE2   " Device running on  " 
#define MESSAGE3   "   STM3210E-EVAL    " 

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USART_InitTypeDef USART_InitStructure;
static __IO uint32_t TimingDelay;
SD_Error Status = SD_OK;
FATFS FatFs;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);
void NVIC_Configuration(void);
DWORD get_fattime (void);


#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f10x_xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f10x.c file
     */     
	
//	FIL fp;
//	char line[82];
//	int len;
//	FRESULT	fr;
//	UINT br, bw;

	/* USARTx configured as follow:
	- BaudRate = 115200 baud  
	- Word Length = 8 Bits
	- One Stop Bit
	- No parity
	- Hardware flow control disabled (RTS and CTS signals)
	- Receive and transmit enabled
	*/
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	STM_COMInit(COM1, &USART_InitStructure);

	STM_LEDInit(LED1);
	STM_LEDInit(LED2);

	/* Interrupt Config */
	NVIC_Configuration();

	/* Retarget the C library printf function to the USARTx, can be USART1 or USART2
	*      depending on the EVAL board you are using ********************************/
	printf("\n\r %s", MESSAGE1);
	printf(" %s", MESSAGE2);
	printf(" %s\n\r", MESSAGE3);


	/* Add your application code here */
	if (SysTick_Config(SystemCoreClock / 1000))
	{
		/* Capture error */
		while (1);
	}

	/* Initialize the LCD */
	STM3210E_LCD_Init();
	LCD_Clear(LCD_COLORBLACK);

	// Set landscape mode
	LCD_LandscapeMode();

	// Set the LCD Text Color                                                    
	LCD_SetTextColor(LCD_COLORWHITE);                                           
	//LCD_ImageDraw(0,0,96,120,TaeYeonIcon);
	//LCD_DisplayStringLine(LCD_LINE_0, (uint8_t *)MESSAGE1);                      
	//LCD_DisplayStringLine(LCD_LINE_1, (uint8_t *)MESSAGE2);                      
	//LCD_DisplayStringLine(LCD_LINE_2, (uint8_t *)MESSAGE3);


	if((Status = SD_Init()) != SD_OK) {
		printf("SD_Init() Fail\r\n");
	}else
		printf("SD_Init() OK!\r\n");

//	f_mount(&FatFs, "", 0);
//	fr = f_open(&fp, "hello.txt", FA_CREATE_ALWAYS | FA_WRITE);
//	if (fr) return (int)fr;
//
//	//while (f_gets(line, sizeof(line), &fil))
//	//	printf("%s\r", line);
//
//	sprintf(line, "FatFS Write\r\n");
//	len = strlen(line);
//	fr = f_write(&fp, line, len, &bw); 
//	f_close(&fp);
//
//	f_mount(NULL, "", 0);

  /* Infinite loop */
  while (1)
  {
	  STM_LEDOn(LED1);
	  STM_LEDOff(LED2);
	  Delay(50);
	  STM_LEDOff(LED1);
	  STM_LEDOn(LED2);
	  Delay(50);
  }
}

/**
 *   * @brief  Configures SDIO IRQ channel.
 *     * @param  None
 *       * @retval None
 *         */
void NVIC_Configuration(void)
{
	  NVIC_InitTypeDef NVIC_InitStructure;

		/* Configure the NVIC Preemption Priority Bits */
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

		NVIC_InitStructure.NVIC_IRQChannel = SDIO_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
}

void Delay(__IO uint32_t nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

/**
	* @brief  Decrements the TimingDelay variable.
	* @param  None
	* @retval None
	*/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

DWORD get_fattime (void)
{
	  DWORD res;

		  res = 0;

			  return res;
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
