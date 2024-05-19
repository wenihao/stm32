/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-03-13 15:22:51
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-07 16:55:04
 * @FilePath: \Projectc:\Users\19925\Desktop\stm32_learn_start\Users\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

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
#include "config.h"
#include "task_key.h"
#include "bsp_led.h"
#include "bsp_exti.h"
#include "SysTick.h"
 
int main(void)
{

    uint32_t start = 0;
    uint32_t end = 0;
    uint32_t diff = 0;
    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    EXTI_SUM_Config();
    LED_SUM_Config();
    while (1)
    {
        start = SysTick->VAL;
        LED_RED_OFF;
        SysTick_Delay_ms(1000);
        LED_RED_ON;
        SysTick_Delay_ms(1000);
        end = SysTick->VAL;
        if(end < start)
        {
            diff = ((end - start) /72);
        }
        //task_key();
    }
}
