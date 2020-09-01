/*
 * print_binary.c
 *
 *  Created on: 1 Sep 2020
 *      Author: Raf
 */

#include "GUI_msgs_UART.h"
#include "print_binary.h"

void print_binary(unsigned int number, unsigned int n_fields)
{
    int a[32];
    int i, j;
    int k;
    char binary_str[33] = {"00000000000000000000000000000000"};

    for(i = 0; number > 0; i++)
    {
        a[i] = number % 2;
        number = number / 2;
    } // decimal 0 and 1 values are now in the a[] in reversed order

    k = n_fields - i;
    if(k < 0)
    {
        // printf("String does not fit into defined space\n");
        GUI_send_string("String does not fit into defined space\n");
        return;
    }

    for(j = i - 1; j >= 0; j--) // convert decimal values to characters and reverse order
    {
        if(a[j] == 0)
            binary_str[k] = '0';
        else
            binary_str[k] = '1';
                k++;
    }
        binary_str[k] = 0;
        // printf("%s\n", binary_str);
        GUI_send_string(binary_str);
        GUI_send_string("\n");
}
