/*
 * delay_ms.h
 *
 *  Created on: 26 Aug 2020
 *      Author: Raf
 */

#ifndef DELAY_MS_H_
#define DELAY_MS_H_

void delay_init(void);
void delay_ms(unsigned int ms); // maximum value of ms is about 50000 (for 80MHz clock. For lower clock speeds proportionally larger number is allowed)

#endif /* DELAY_MS_H_ */
