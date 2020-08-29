/*
 * GUI_msgs.c
 *
 *  Created on: 25 Aug 2020
 *      Author: Raf
 */


// USART_2 will be used for messages sent to PC and displayed in Labview GUI
// pin PA2 - USART2_TX
// pin PA3 - USART2_RX

#include <GUI_msgs_UART.h>
#include "stm32l4xx.h"
#include <stdio.h>
#include <string.h>

void GUI_init(void)
{
	// enable clock for GPIOA
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

	// set PA2 to alternate function mode
	GPIOA->MODER |= GPIO_MODER_MODE2_1;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_0;

	// set PA2 function as USART2_TX (AF7, bits 0111)
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2;
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL2_3;

	// set PA3 to alternate function mode
	GPIOA->MODER |= GPIO_MODER_MODE3_1;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_0;

	// set PA3 function as USART2_RX (AF7, bits 0111)
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_0;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_1;
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL3_2;
	GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL3_3;

	// enable USART2 clock
	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;

	// set baud rate (default oversampling (by 16), baud rate = fck \ USARTDIV)
	SystemCoreClockUpdate();
	USART2->BRR = SystemCoreClock / 115200; // baud rate = 9600

	//enable USART2
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_TE;
}

void GUI_send_char(char ch)
{
	while(!(USART2->ISR & USART_ISR_TXE));
	USART2->TDR = ch;
}

void GUI_send_string(char *string)
{
	int i;
	int str_length = strlen(string);

	if(str_length > GUI_BUFFER_SIZE)
		str_length = GUI_BUFFER_SIZE;

	for(i = 0; i < str_length; i++)
		GUI_send_char(string[i]);
}




