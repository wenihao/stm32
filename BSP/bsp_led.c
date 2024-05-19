

/*1. 使能 GPIO 端口时钟；
  2. 初始化 GPIO 目标引脚为推挽输出模式；
  3. 编写简单测试程序，控制 GPIO 引脚输出高、低电平*/

#include "bsp_led.h"

static void LED_RCC_Config(void)
{
    RCC_APB2PeriphClockCmd(LED_RED_CLK | LED_GREEN_CLK | LED_BLUE_CLK, ENABLE);
}

static void LED_GPIO_Conffig(void)
{
    GPIO_InitTypeDef LED_GPIO_InitStruct;

    LED_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    LED_GPIO_InitStruct.GPIO_Pin = LED_RED_PIN | LED_GREEN_PIN | LED_BLUE_PIN;
    LED_GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_RED_PORT, &LED_GPIO_InitStruct);
    GPIO_Init(LED_GREEN_PORT, &LED_GPIO_InitStruct);
    GPIO_Init(LED_BLUE_PORT, &LED_GPIO_InitStruct);

    GPIO_SetBits(LED_RED_PORT, LED_RED_PIN);
    GPIO_SetBits(LED_GREEN_PORT, LED_GREEN_PIN);
    GPIO_SetBits(LED_BLUE_PORT, LED_BLUE_PIN);
}

void LED_SUM_Config(void)
{
    LED_RCC_Config();
    LED_GPIO_Conffig();
}
