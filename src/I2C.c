/*
 * I2C.c
 *
 *  Created on: 30 Aug 2020
 *      Author: Raf
 */

#include "stm32l4xx.h"
#include "I2C.h"
#include <stdio.h>
#include "GUI_msgs_UART.h"
#include "delay_ms.h"


// using I2C3
// PC0 - I2C3_SCL
// PC1 - I2C3_SDA

char GUI_buffer[GUI_BUFFER_SIZE];

void I2C3_init(void)
{
	// enable port C clock
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

	// enable I2C2 clock
	RCC->APB1ENR1 |= RCC_APB1ENR1_I2C3EN;

	// set pins PC0 and PC1 to alternate functions
	GPIOC->MODER &= ~GPIO_MODER_MODER0_0;
	GPIOC->MODER |= GPIO_MODER_MODER0_1;
	GPIOC->MODER &= ~GPIO_MODER_MODER1_0;
	GPIOC->MODER |= GPIO_MODER_MODER1_1;

	// select alternate function AF4 for pin PC0
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFRL0;
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL0_2;

	// select alternate function AF4 for pin PC1
	GPIOC->AFR[0] &= ~GPIO_AFRL_AFRL1;
	GPIOC->AFR[0] |= GPIO_AFRL_AFSEL1_2;

	// set AUTOEND when all bytes has been sent
	I2C3->CR2 |= I2C_CR2_AUTOEND;

	//set speed (CubeMX used for calculation)
	I2C3->TIMINGR = 0x00000E14;

	//enable I2C2
	I2C3->CR1 |= I2C_CR1_PE;
}

// standard I2C transmission
void I2C3_transmit(unsigned int address, uint8_t *send_buffer, int n_bytes)
{
	//set slave address
	if(address > 127)	// makes sure address is max 7 bit
		while(1);
	I2C3->CR2 &= ~I2C_CR2_SADD;
	I2C3->CR2 |= (address << 1u);

	I2C3->CR2 &= ~I2C_CR2_RD_WRN;

	I2C3->CR2 &= ~I2C_CR2_NBYTES;
	I2C3->CR2 |= (n_bytes << 16);
	I2C3->CR2 |= I2C_CR2_START;

	//just one byte for now
	while(!(I2C3->ISR & I2C_ISR_TXE));
	I2C3->TXDR = *(send_buffer);
}

//HAL_I2C_Mem_Write(&SSD1306_I2C_PORT, SSD1306_I2C_ADDR, 0x40, 1, buffer, buff_size, HAL_MAX_DELAY);
void I2C3_memory_write(unsigned int ssd1306_address, uint8_t memory_address, uint8_t *send_buffer, int n_bytes)
{
	//set slave address
	if(ssd1306_address > 127)	// makes sure address is max 7 bit
		while(1);
	I2C3->CR2 &= ~I2C_CR2_SADD;
	I2C3->CR2 |= (ssd1306_address << 1u);

	I2C3->CR2 &= ~I2C_CR2_RD_WRN;

	I2C3->CR2 &= ~I2C_CR2_NBYTES;
	I2C3->CR2 |= ((n_bytes + 1) << 16); // + 1 for memory address
	I2C3->CR2 |= I2C_CR2_START;

	// send memory address
	while(!(I2C3->ISR & I2C_ISR_TXE));
	I2C3->TXDR = memory_address;

	int i;
	for(i = 0; i < n_bytes; i++)
	{
		while(!(I2C3->ISR & I2C_ISR_TXE));
			I2C3->TXDR = send_buffer[i];
	}
}




