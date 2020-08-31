
#include "stm32l4xx.h"

// using general purpose TIM2

void delay_init(void)
{

	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;	// enable TIM2 clock
	TIM2->PSC = 0; 							// default prescaler
	SystemCoreClockUpdate();				// make sure SystemCoreClock is up to date
}

void delay_ms(unsigned int ms)
{
	TIM2->ARR = ms * (SystemCoreClock / 1000);
	TIM2->CNT = 0;
	TIM2->CR1 |= TIM_CR1_CEN;

	while(!(TIM2->SR & TIM_SR_UIF));

	TIM2->SR &= ~TIM_SR_UIF;
	TIM2->CR1 &= ~TIM_CR1_CEN;
}
