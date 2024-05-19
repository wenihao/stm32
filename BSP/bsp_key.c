#include "bsp_key.h"

static void KEY_RCC_Config(void)
{
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK | KEY2_GPIO_CLK, ENABLE);
}

static void KEY_GPIO_Config(void)
{
    GPIO_InitTypeDef KEY_GPIO_InitStruct;
    KEY_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    KEY_GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN;
    GPIO_Init(KEY1_GPIO_PORT, &KEY_GPIO_InitStruct);

    KEY_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    KEY_GPIO_InitStruct.GPIO_Pin = KEY2_GPIO_PIN;
    GPIO_Init(KEY2_GPIO_PORT, &KEY_GPIO_InitStruct);
}

void KEY_SUM_Config(void)
{
    KEY_RCC_Config();
    KEY_GPIO_Config();
}
