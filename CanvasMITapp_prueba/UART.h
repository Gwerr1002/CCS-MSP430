/*
 * UART.h
 *
 *  Created on: 17 sep. 2021
 *      Author: gerard
 */

#ifndef UART_H_
#define UART_H_

#include <msp430g2553.h>

void initUART(void);
void serialprint(char *s);


#endif /* UART_H_ */
