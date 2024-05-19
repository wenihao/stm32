#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "config.h"

//RED
#define LED_RED_PORT    GPIOB
#define LED_RED_CLK     RCC_APB2Periph_GPIOB
#define LED_RED_PIN     GPIO_Pin_5

//GREEN
#define LED_GREEN_PORT  GPIOB
#define LED_GREEN_CLK   RCC_APB2Periph_GPIOB
#define LED_GREEN_PIN   GPIO_Pin_0

//BLUE
#define LED_BLUE_PORT   GPIOB
#define LED_BLUE_CLK    RCC_APB2Periph_GPIOB
#define LED_BLUE_PIN    GPIO_Pin_1

/* 直接操作寄存器的方法控制 IO */
#define digitalHi(p,i)       {p -> BSRR = i;}    //���Ϊ�ߵ�ƽ
#define digitalLo(p,i)       {p -> BRR  = i;}    //���Ϊ�͵�ƽ
#define digitalToggle(p,i)   {p -> ODR  ^= i;}   //�����ת��ƽ

/* 定义控制 IO 的宏 */
//RED
#define LED_RED_TOGGLE      digitalToggle(LED_RED_PORT,LED_RED_PIN)
#define LED_RED_ON          digitalHi(LED_RED_PORT,LED_RED_PIN)
#define LED_RED_OFF         digitalLo(LED_RED_PORT,LED_RED_PIN)

//GREEN
#define LED_GREEN_TOGGLE    digitalToggle(LED_GREEN_PORT,LED_GREEN_PIN)
#define LED_GREEN_ON        digitalHi(LED_GREEN_PORT,LED_GREEN_PIN)
#define LED_GREEN_OFF       digitalLo(LED_GREEN_PORT,LED_GREEN_PIN)

//BLUE
#define LED_BLUE_TOGGLE     digitalToggle(LED_BLUE_PORT,LED_BLUE_PIN)
#define LED_BLUE_ON        digitalHi(LED_BLUE_PORT,LED_BLUE_PIN)
#define LED_BLUE_OFF       digitalLo(LED_BLUE_PORT,LED_BLUE_PIN)

/* 基本混色，后面高级用法使用 PWM 可混出全彩颜色, 且效果更好 */
//RED
#define LED_RED \
LED_RED_ON;\
LED_GREEN_OFF\
LED_BLUE_OFF

//GREEN
#define LED_GREEN \
LED1_OFF;\
LED2_ON\
LED3_OFF

//BLUE
#define LED_BLUE \
LED1_OFF;\
LED2_OFF\
LED3_ON

//黄 (红 + 绿)
#define LED_YELLOW \
LED1_ON;\
LED2_ON\
LED3_OFF

//紫 (红 + 蓝)
#define LED_PURPLE \
LED1_ON;\
LED2_OFF\
LED3_ON

//青 (绿 + 蓝)
#define LED_CYAN \
LED1_OFF;\
LED2_ON\
LED3_ON

//白 (红 + 绿 + 蓝)
#define LED_WHITE \
LED1_ON;\
LED2_ON\
LED3_ON

//黑 (全部关闭)
#define LED_RGBOFF \
LED1_OFF;\
LED2_OFF\
LED3_OFF

static void LED_RCC_Config(void);
static void LED_GPIO_Conffig(void);
void LED_SUM_Config(void);

#endif
