/*
 * SPI.c
 *
 *  Created on: 28 Aug 2020
 *      Author: Raf
 */
#include "stm32l4xx.h"

// using SPI2
// pin PC2 - SPI2_MISO
// pin PC3 - SPI2_MOSI
// pin PB10 - SPI2_SCK
// pin PB12 - SPI2_NSS (not used for now)

void SPI2_init(void)
{
	// enable clocks for GPIOB, GPIOC and SPI2
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	RCC->APB1ENR1 |= RCC_APB1ENR1_SPI2EN;

	// set pin PC2 to alternate function mode
	GPIOC->MODER &= ~GPIO_MODER_MODER2_0;
	GPIOC->MODER |= GPIO_MODER_MODER2_1;

	// set pin PC3 to alternate function mode
	GPIOC->MODER &= ~GPIO_MODER_MODER3_0;
	GPIOC->MODER |= GPIO_MODER_MODER3_1;

	// set pin PB10 to alternate function mode
	GPIOB->MODER &= ~GPIO_MODER_MODER10_0;
	GPIOB->MODER |= GPIO_MODER_MODER10_1;

	// set pin PB12 to alternate function mode
	GPIOB->MODER &= ~GPIO_MODER_MODER12_0;
	GPIOB->MODER |= GPIO_MODER_MODER12_1;

	// select SPI2_MISO (AF5) for pin PC2
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL2_0;
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFSEL2_1;
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL2_2;
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFSEL2_3;

	// select SPI2_MOSI (AF5) for pin PC3
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL3_0;
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFSEL3_1;
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL3_2;
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFSEL3_3;

	// select SPI2_SCK (AF5) for pin PB10
	GPIOB->AFR[1] |= GPIO_AFRH_AFSEL10_0;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFSEL10_1;
	GPIOB->AFR[1] |= GPIO_AFRH_AFSEL10_2;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFSEL10_3;

	// select SPI2_NSS (AF5) for pin PB12
	GPIOB->AFR[1] |= GPIO_AFRH_AFSEL12_0;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFSEL12_1;
	GPIOB->AFR[1] |= GPIO_AFRH_AFSEL12_2;
	GPIOB->AFR[1] &= ~GPIO_AFRH_AFSEL12_3;

	// set master configuration
	 SPI2->CR1 |= SPI_CR1_MSTR;

	// set baud rate        default was 000 --> fPCLK/2
	SPI2->CR1 |= (SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0);

	// To enable master internally set following 2 bits:
	SPI2->CR1 |= SPI_CR1_SSM;
	SPI2->CR1 |= SPI_CR1_SSI;
	// Otherwise use pin PB12 - SPI2_NSS as input if multi-master mode is required (see manual for other details)

	// enable SPI2
	SPI2->CR1 |= SPI_CR1_SPE;
}

void SPI2_send(uint8_t byte)
{
	if(SPI2->SR & SPI_SR_TXE)
		*(uint8_t*)(&SPI2->DR) = byte;
}


