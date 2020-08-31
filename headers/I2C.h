/*
 * I2C.h
 *
 *  Created on: 30 Aug 2020
 *      Author: Raf
 */

#ifndef I2C_H_
#define I2C_H_

void I2C3_init(void);
void I2C3_transmit(unsigned int address, uint8_t *send_buffer, int n_bytes);
void I2C3_memory_write(unsigned int ssd1306_address, uint8_t memory_address, uint8_t *send_buffer, int n_bytes);

#endif /* I2C_H_ */
