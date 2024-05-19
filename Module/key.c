#include "key.h"
#include "bsp_key.h"

uint8_t key_scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON)
    {
        while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);
        return KEY_ON;
    }
    else
    {
        return KEY_OFF;
    }
}
