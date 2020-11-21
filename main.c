/**
  ******************************************************************************
  * @file    GPIO_Toggle\main.c
  * @author  MCD Application Team
  * @version V2.0.4
  * @date    26-April-2018
  * @brief   This file contains the main function for GPIO Toggle example.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
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

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "common_cfd.h"
#include "initial.h"
#include "stm8s_clk.h"

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  串口中断功能：接收什么就发送什么（单片机接收CPU发送的数据，然后再通过串口发送出去），接收到数据时产生中断，跳转到中断，在中断中函数中将接收到的数据发送出去
  在定时器中实现灯1s的反转
  在while中实现串口发送数据
  */
void main(void)
{
	/*时钟配置*/
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); //时钟速度为内部16M，一分频

  /* 基本IO口引脚配置 */
	GPIO_Configuration();//LED

  /*定时器2初始化配置*/
  TIMER_Initializes();

  /*串口1初始化配置*/
  UART_Initializes(9600);

  rim();//开启总中断

  while (1)
  {
    /* Toggles LEDs */
    //GPIO_WriteReverse(LED_GPIO_PORT, LED_GPIO_PINS);
    //Delay(1000);

    UART1_Printf((uint8_t*)"Hello！");           //串口打印(输出)数据
    Delay(1000);
  }

}



#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
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


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
