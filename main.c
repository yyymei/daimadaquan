#include "stm32f10x.h"

// ??????
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 7200; j++);
}

int main(void)
{
    // 1. ?? GPIOA?GPIOB?GPIOC ???
    RCC->APB2ENR |= (1 << 2) | (1 << 3) | (1 << 4);

    // 2. ?? PA0?PB5 ?????,50MHz
    GPIOA->CRL &= ~(0xF << 0);
    GPIOA->CRL |=  (0x3 << 0);
    GPIOB->CRL &= ~(0xF << 20);
    GPIOB->CRL |=  (0x3 << 20);

    // 3. ?? PC13 ?????,50MHz (CRH??8-15??)
    GPIOC->CRH &= ~(0xF << 20);
    GPIOC->CRH |=  (0x3 << 20);

    // 4. ????:????(???)
    GPIOA->BSRR = (1 << 0);
    GPIOB->BSRR = (1 << 5);
    GPIOC->BSRR = (1 << 13);

    // 5. ???:???
    while (1)
    {
        // ?? PA0 (??LED1)
        GPIOA->BRR  = (1 << 0);
        GPIOB->BSRR = (1 << 5);
        GPIOC->BSRR = (1 << 13);
        delay_ms(1000);

        // ?? PB5 (??LED2)
        GPIOA->BSRR = (1 << 0);
        GPIOB->BRR  = (1 << 5);
        GPIOC->BSRR = (1 << 13);
        delay_ms(1000);

        // ?? PC13 (??LED3)
        GPIOA->BSRR = (1 << 0);
        GPIOB->BSRR = (1 << 5);
        GPIOC->BRR  = (1 << 13);
        delay_ms(1000);
    }
}