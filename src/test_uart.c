#include <stdio.h>
#include "uart.h"
#include <string.h>
#include <assert.h>
#include "test_uart.h"

#define DEBUG 1

void print_testcase(uint8_t *test_case);
uint8_t test_case_1[UART_BUFF_LEN] = {0xa5,0x5a,0xdd,0xa5,0x5a,0x5a,
                          0xdd,0x9a,0xa5,0x5a,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};

uint8_t test_case_2[UART_BUFF_LEN] = {0xa5,0x5a,0xdd,0xaa,0xff,0x5a,
                          0xdd,0xaa,0x55,0xaa,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};
uint8_t test_case_3[UART_BUFF_LEN] = {0x00,0x11,0xdd,0x99,0x9a,0x5a,
                          0xdd,0xaa,0x55,0xaa,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};
uint8_t test_case_4[UART_BUFF_LEN] = {0x00,0x24,0xdd,0x99,0x9a,0xff,
                          0xdd,0xaa,0x55,0xaa,0xdd,0xdd,
                          0xa5,0x5a,0xa5,0x5a};
uint8_t test_case_5[UART_BUFF_LEN] = {0xa5,0x5a,0xa5,0x5a,0xa5,0x5a,
                          0xa5,0x5a,0xa5,0x5a,0xa5,0x5a,
                          0xa5,0x5a,0xa5,0x5a};
uint8_t test_case_6[UART_BUFF_LEN] = {0x00,0xa5,0x5a,0xa5,0x5a,0xa5,
                          0x5a,0xa5,0x5a,0xa5,0x5a,0xa5,
                          0x5a,0xa5,0x5a,0xa5};


/*-----------------------------------
Name: main.c

Description: Runs the tests on
uart_isr and sequence_count function
with the test_case buffers.

Returns: None
-------------------------------------*/
void main(void)
{
    uint8_t seq_count = 0;
#if DEBUG
    print_testcase(test_case_1);
#endif
    /*call uart isr*/
    uart_isr(test_case_1);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*set the shared flag*/
    received_flag = 0;
    printf("\nsequence count: %d\n",seq_count);
    
#if DEBUG
    print_testcase(test_case_2);
#endif
    /*call uart isr*/
    uart_isr(test_case_2);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*set the shared flag*/
    received_flag = 1;
    printf("\nsequence count: %d\n",seq_count);

#if DEBUG
    print_testcase(test_case_3);
#endif
    /*call uart isr*/
    uart_isr(test_case_3);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*set the shared flag*/
    received_flag = 1;
    printf("\nsequence count: %d\n",seq_count);

#if DEBUG
    print_testcase(test_case_4);
#endif
    /*call uart isr*/
    uart_isr(test_case_4);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*set the shared flag*/
    received_flag = 0;
    printf("\nsequence count: %d\n",seq_count);
#if DEBUG
    print_testcase(test_case_5);
#endif
    /*call uart isr*/
    uart_isr(test_case_5);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*reset the shared flag*/
    received_flag = 0;
    printf("\nsequence count: %d\n",seq_count);   
    
#if DEBUG
    print_testcase(test_case_6);
#endif
    /*call uart isr*/
    uart_isr(test_case_6);
    /*check sequence count*/
    seq_count = sequence_count(rx_buffer);
    /*cleared the shared buffer*/
    memset(rx_buffer,0,UART_BUFF_LEN);
    /*reset the shared flag*/
    received_flag = 0;
    printf("\nsequence count: %d\n",seq_count);
}

/*-----------------------------*
Name: print_testcase

Description: Prints the 16bytes 
starting from the uint8_t pointer
(*test_case).

Return: None
-------------------------------*/
void print_testcase(uint8_t *test_case)
{
    printf("Test case = [");
    for(uint8_t i = 0;i<UART_BUFF_LEN;i++)
    {
        printf("%x ",test_case[i]);
    }
    printf("]");
}