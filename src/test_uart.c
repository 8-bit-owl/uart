#include <stdio.h>
#include "uart.h"
#include <string.h>
#include <assert.h>
#include "test_uart.h"



/*
volatile uint8_t test_case_1[UART_BUFF_LEN] = {0xa5,0x5a,0xdd,0xa5,0x5a,0x5a,
                          0xdd,0xaa,0xa5,0x5a,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};

*/

int main(void)
{
    printf("\n count: %d\n",sequence_count(test_case_1));
    return 0;
}

