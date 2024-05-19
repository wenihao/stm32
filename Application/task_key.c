#include "task_key.h"
#include "key.h"
#include "bsp_key.h"
#include "bsp_led.h"

void task_key(void)
{
    KEY_SUM_Config();
    LED_SUM_Config();
    while(1)
    {
        if(key_scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)  
        {
            LED_RED_TOGGLE;
        }
        if(key_scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON)
        {
            LED_GREEN_TOGGLE;
        }
    }
}
