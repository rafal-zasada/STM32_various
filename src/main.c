
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

	//ssd1306_TestAll();
	 ssd1306_Init();
//	ssd1306_TestFonts();

//    ssd1306_Fill(Black);
//    ssd1306_SetCursor(2, 10);
//    ssd1306_WriteString("Font 16x26", Font_16x26, White);
//    ssd1306_UpdateScreen();
//    delay_ms(1500);

//    ssd1306_Fill(Black);
 //   ssd1306_SetCursor(2, 10);
 //   ssd1306_WriteString("Font 11x18", Font_11x18, White);
  //  ssd1306_WriteChar('P', Font_11x18, White);
   // ssd1306_UpdateScreen();
   // delay_ms(500);

    int d = 0;
    while(1)
    {
		ssd1306_Fill(Black);
		ssd1306_SetCursor(0, d);
	//	ssd1306_WriteString("Font 7x10", Font_7x10, White);



	    ssd1306_WriteChar('O', Font_7x10, White);

//		ssd1306_DrawPixel(3, 7, 1);
//		ssd1306_DrawPixel(3, 8, 1);
///		ssd1306_DrawPixel(3, 9, 1);
//		ssd1306_DrawPixel(3, 10, 1);

		ssd1306_UpdateScreen();
		d++;
		if(d == 20)
			d = 0;
		delay_ms(500);

		while(1);

    }


    extern uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];  // temporary added extern (and removed static from source file where it is defined)

    int n = 0;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 1;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 2;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 3;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);

    n = 0 + 128;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 1 + 128;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 2 + 128;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);
    n = 3 + 128;
    sprintf(GUI_buffer, "Buffer[%d] value = %d\n", n, SSD1306_Buffer[n]);
    GUI_send_string(GUI_buffer);

//    SSD1306_Buffer[n] = 0b10101010; // works

    ssd1306_UpdateScreen();

    while(1);

	int i, j;
	char string1[30];
	char string2[30];
	int x, y, buff_pos, buff_val;


	delay_ms(500);
    ssd1306_Fill(Black);
    ssd1306_UpdateScreen();


    for(i = 0; i < 128; i++)
    {
    	for(j = 0; j < 31; j++)
    	{
    	    x = i;
    	    y = j;

   // 		sprintf(GUI_buffer, "x = %d  y = %d \n", x, y);
   // 		GUI_send_string(GUI_buffer);

    	    ssd1306_DrawPixel(x, y, 1);
    	    ssd1306_UpdateScreen();
    	    ssd1306_Fill(Black);
    	  //  delay_ms(500);
    	}
    }





	while(1)
	{
		delay_ms(500);

		sprintf(GUI_buffer, "End of loop\n");
		GUI_send_string(GUI_buffer);

	//	SPI2_send_byte(0b11001100);
	}

	return 0;
}
