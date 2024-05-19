/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-05-07 16:57:04
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-05-07 17:22:39
 * @FilePath: \undefinedc:\Users\19925\Desktop\stm32_learn_start\BSP\bsp_exti.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "config.h"

#define KEY1_INT_GPIO_PORT          GPIOA
#define KEY1_INT_GPIO_CLK           (RCC_APB2Periph_GPIOA\
                                     |RCC_APB2Periph_AFIO)

#define KEY1_INT_GPIO_PIN           GPIO_Pin_0

#define KEY1_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOA
#define KEY1_INT_EXTI_PINSOURCE     GPIO_PinSource0
#define KEY1_EXTI_IRQChannel        EXTI0_IRQn
#define KEY1_INT_EXTI_LINE          EXTI_Line0

#define KEY1_IRQHandler             EXTI0_IRQHandler

#define KEY2_INT_GPIO_PORT          GPIOC
#define KEY2_INT_GPIO_CLK           (RCC_APB2Periph_GPIOC\
                                     |RCC_APB2Periph_AFIO)

#define KEY2_INT_GPIO_PIN           GPIO_Pin_13

#define KEY2_INT_EXTI_PORTSOURCE    GPIO_PortSourceGPIOC
#define KEY2_INT_EXTI_PINSOURCE     GPIO_PinSource13
#define KEY2_EXTI_IRQChannel        EXTI15_10_IRQn
#define KEY2_INT_EXTI_LINE          EXTI_Line13

#define KEY2_IRQHandler             EXTI15_10_IRQHandler

static void NVIC_Configuration(void);
static void EXTI_GPIO_Config(void);
static void EXTI_KEY_Config(void);
void EXTI_SUM_Config(void);

enum INYERRUPT_PRIORITY // 优先级排序
{
    INYERRUPT_PRIORITY0 = 0,
    INYERRUPT_PRIORITY1,
    INYERRUPT_PRIORITY2,
    INYERRUPT_PRIORITY3,
    INYERRUPT_PRIORITY4,
    INYERRUPT_PRIORITY5,
    INYERRUPT_PRIORITY6,
    INYERRUPT_PRIORITY7,
    INYERRUPT_PRIORITY8,
    INYERRUPT_PRIORITY9,
    INYERRUPT_PRIORITY10,
    INYERRUPT_PRIORITY11,
    INYERRUPT_PRIORITY12,
    INYERRUPT_PRIORITY13,
    INYERRUPT_PRIORITY14,
    INYERRUPT_PRIORITY15,
};

#endif
