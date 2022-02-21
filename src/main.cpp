#include <stm32f1xx.h>

void delay(uint32_t msec) 
{
    for(uint32_t i = 0; i < 2000UL*msec; ++i)
    {
        __NOP();
    }
}

int main() 
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    GPIOC->CRH |= GPIO_CRH_MODE13;

    while(1)
    {
        GPIOC->BSRR |= GPIO_BSRR_BS13;
        delay(100);

        GPIOC->BSRR |= GPIO_BSRR_BR13;
        delay(100);
    } 

    return 0;
}