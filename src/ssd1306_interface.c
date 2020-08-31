/*
 * ssd1306_interface.c
 *
 *  Created on: 29 Aug 2020
 *      Author: Raf
 */

#include "ssd1306_interface.h"
#include "SPI.h"

// This file contains only functions for additional pins when ssd1306 is used in SPI mode. SPI has to be initialised separately and associated with ssd1306 library.

void ssd1306_interface_init_SPI(void)
{
	// ssd1306_CS_port - pin PA3
	// ssd1306_RES_port - pin PA8
	// ssd1306_DC_port - PA2

	// enable clock for port A
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	// set PA3 as output
	GPIOA->MODER |= GPIO_MODER_MODE3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_1;

	// set PA8 as output
	GPIOA->MODER |= GPIO_MODER_MODE8_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE8_1;

	// set PA2 as output
	GPIOA->MODER |= GPIO_MODER_MODE2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_1;

	SPI2_init(); // for pinout refer to SPI.c
}

void ssd1306_SPI_CS_port(int state)
{
	if(state == SET)
		GPIOA->ODR |= GPIO_ODR_OD3;
	if(state == RESET)
		GPIOA->ODR &= ~GPIO_ODR_OD3;
}

void ssd1306_SPI_RES_port(int state)
{
	if(state == SET)
		GPIOA->ODR |= GPIO_ODR_OD8;
	if(state == RESET)
		GPIOA->ODR &= ~GPIO_ODR_OD8;
}

void ssd1306_SPI_DC_port(int state)
{
	if(state == SET)
		GPIOA->ODR |= GPIO_ODR_OD2;
	if(state == RESET)
		GPIOA->ODR &= ~GPIO_ODR_OD2;
}
