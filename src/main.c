
#include <GUI_msgs_UART.h>
#include "stm32l4xx.h"
#include "delay_ms.h"
#include "SPI.h"
#include "ssd1306_interface.h"
#include "ssd1306_tests.h"
#include "ssd1306.h"
#include "I2C.h"

#include <stdio.h>

int main(void)
{
	char GUI_buffer[GUI_BUFFER_SIZE] = {0}; // to be used with sprintf function for formatted strings.


	I2C3_init();
	SPI2_init();
	GUI_init();
	delay_init();

	sprintf(GUI_buffer, "System clock = %lu\n", SystemCoreClock);
	GUI_send_string(GUI_buffer);

	//ssd1306_TestAll();

//	uint8_t byte[] = {0b00111100};

//	I2C3_transmit(0x3C, byte, 1);

//	ssd1306_interface_init_SPI();

	delay_ms(100);

	ssd1306_TestAll();
	/// ssd1306_Init();
	//ssd1306_TestFonts();

	while(1)
	{
		delay_ms(100);

		sprintf(GUI_buffer, "CNT value= %lu\n", TIM2->CNT);
		GUI_send_string(GUI_buffer);

	//	SPI2_send_byte(0b11001100);
	}

	return 0;
}
