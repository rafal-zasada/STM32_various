
#include "GUI_msgs_UART.h"
#include "stm32l4xx.h"
#include "delay_ms.h"
#include "SPI.h"
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

	delay_ms(100);

	 ssd1306_Init();

	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Vp= 234.6V", Font_11x18, White);
	ssd1306_SetCursor(0, 18);
	ssd1306_WriteString("Vp= 234.6V", Font_11x18, White);
//	ssd1306_SetCursor(0, 18);
	//ssd1306_WriteString("zlote felgi? :)", Font_7x10, White);
	ssd1306_UpdateScreen();

	while(1);

	delay_ms(1000);
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();

	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("Vp= 245.5 V", Font_11x18, White);
	ssd1306_SetCursor(0, 17);
	ssd1306_WriteString("Vh= -6.26 V", Font_11x18, White);
	ssd1306_UpdateScreen();


	sprintf(GUI_buffer, "End of program\n");
	GUI_send_string(GUI_buffer);

	while(1);
	return 0;
}
