/*
 * SPI.h
 *
 *  Created on: 28 Aug 2020
 *      Author: Raf
 */

#ifndef SPI_H_
#define SPI_H_

void SPI2_init(void);
void SPI2_send_byte(uint8_t byte);
void SPI_send_data(uint8_t *data, int data_size);

#endif /* SPI_H_ */
