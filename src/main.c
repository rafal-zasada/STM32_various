
#include "stm32l4xx.h"
#include "GUI_msgs.h"
#include "delay_ms.h"
#include <stdio.h>

int main(void)
{
	char GUI_buffer[GUI_BUFFER_SIZE] = {0}; // to be used with sprintf function for formatted strings.

	GUI_init();
	delay_init();

	sprintf(GUI_buffer, "System clock = %lu\n", SystemCoreClock);
	GUI_send_string(GUI_buffer);

	while(1)
	{

		delay_ms(500);


		sprintf(GUI_buffer, "CNT value= %lu\n", TIM2->CNT);
		GUI_send_string(GUI_buffer);
	}

	return 0;
}
