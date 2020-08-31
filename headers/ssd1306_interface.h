/*
 * ssd1306_interface.h
 *
 *  Created on: 29 Aug 2020
 *      Author: Raf
 */

#include "stm32l4xx.h"

#ifndef SSD1306_INTERFACE_H_
#define SSD1306_INTERFACE_H_

#define SET 1
#define RESET 0

void ssd1306_SPI_interface_init_SPI(void);
void ssd1306_SPI_CS_port(int state);
void ssd1306_SPI_RES_port(int state);
void ssd1306_SPI_DC_port(int state);


#endif /* SSD1306_INTERFACE_H_ */
