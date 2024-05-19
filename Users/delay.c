#include "delay.h"

void delay_ms(uint32_t ms)
{
    uint32_t i = 0,j = 0;
    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 18000; j++)
        {
        }
    }
}

void delay_us(uint32_t us)
{
    uint32_t i = 0,j = 0;
    for(i = 0; i < us; i++)
    {
        for(j = 0; j < 18; j++)
        {
        }
    }
}
