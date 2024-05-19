#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "config.h"

#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_CLK RCC_APB2Periph_GPIOA
#define KEY1_GPIO_PIN GPIO_Pin_0

#define KEY2_GPIO_PORT GPIOC
#define KEY2_GPIO_CLK RCC_APB2Periph_GPIOC
#define KEY2_GPIO_PIN GPIO_Pin_13

static void KEY_RCC_Config(void);
static void KEY_GPIO_Config(void);
void KEY_SUM_Config(void);

#endif
