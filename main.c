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
  �����жϹ��ܣ�����ʲô�ͷ���ʲô����Ƭ������CPU���͵����ݣ�Ȼ����ͨ�����ڷ��ͳ�ȥ�������յ�����ʱ�����жϣ���ת���жϣ����ж��к����н����յ������ݷ��ͳ�ȥ
  �ڶ�ʱ����ʵ�ֵ�1s�ķ�ת
  ��while��ʵ�ִ��ڷ�������
  */
void main(void)
{
	/*ʱ������*/
	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); //ʱ���ٶ�Ϊ�ڲ�16M��һ��Ƶ

  /* ����IO���������� */
	GPIO_Configuration();//LED

  /*��ʱ��2��ʼ������*/
  TIMER_Initializes();

  /*����1��ʼ������*/
  UART_Initializes(9600);

  rim();//�������ж�

  while (1)
  {
    /* Toggles LEDs */
    //GPIO_WriteReverse(LED_GPIO_PORT, LED_GPIO_PINS);
    //Delay(1000);

    UART1_Printf((uint8_t*)"Hello��");           //���ڴ�ӡ(���)����
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
