#ifndef __KEY_H
#define __KEY_H
#include "config.h"

//enum
//{
//    KEY_OFF = 0,
//    KEY_ON,
//};
#define KEY_ON 1
#define KEY_OFF 0
uint8_t key_scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif
