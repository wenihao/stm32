#include "bsp_exti.h"

static void NVIC_Configuration(void)
{
    /*按键1外部中断优先级配置*/
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = KEY1_EXTI_IRQChannel;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = INYERRUPT_PRIORITY0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    /*按键2外部中断优先级配置*/
    NVIC_InitStructure.NVIC_IRQChannel = KEY2_EXTI_IRQChannel;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = INYERRUPT_PRIORITY15;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void EXTI_GPIO_Config(void)
{
    GPIO_InitTypeDef EXTI_GPIO_InitStruct;

    /*开启GPIO时钟*/
    RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK | KEY2_INT_GPIO_CLK,ENABLE);

    /*配置GPIO*/
    EXTI_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    EXTI_GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN | KEY2_INT_GPIO_PIN;
    EXTI_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_Init(KEY1_INT_GPIO_PORT,&EXTI_GPIO_InitStruct);
    GPIO_Init(KEY2_INT_GPIO_PORT,&EXTI_GPIO_InitStruct);

    /*选择用作EXTI线的GPIO引脚*/
    GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE,KEY1_INT_EXTI_PINSOURCE);
    GPIO_EXTILineConfig(KEY2_INT_EXTI_PORTSOURCE,KEY2_INT_EXTI_PINSOURCE);
}

static void EXTI_KEY_Config(void)
{
    /*外部中断配置*/
    EXTI_InitTypeDef EXTI_InitStructKey;
    EXTI_InitStructKey.EXTI_Line = KEY1_INT_EXTI_LINE | KEY2_INT_EXTI_LINE;
    EXTI_InitStructKey.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructKey.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructKey.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructKey);
}

void EXTI_SUM_Config(void)
{
    NVIC_Configuration();
    EXTI_GPIO_Config();
    EXTI_KEY_Config();
}

