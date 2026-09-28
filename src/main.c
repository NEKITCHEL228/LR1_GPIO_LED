#include "stm32f1xx.h"

int main(void)
{
    // 1. Включение тактирования порта B
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // 2. Настройка вывода PA0 как выход push-pull, скорость 2 МГц
    // очистить биты для PA0
    GPIOA->CRL &= ~(0xF << (0 * 4));
    // MODE0 = 10 (выход 2 МГц), CNF0 = 00 (push-pull)
    GPIOA->CRL |= (0x2 << (0 * 4));
    // 3. Основной цикл
    while (1)
    {
        // Зажечь светодиод (активный высокий уровень)
        GPIOA->BSRR = (0x1UL << 1U);
        // программная задержка
        for (volatile uint32_t i = 0; i < 500000; i++)
            ;
        // Погасить светодиод
        GPIOA->BSRR = (0x1UL << 17U);
        // программная задержка
        for (volatile uint32_t i = 0; i < 500000; i++)
            ;
    }
}