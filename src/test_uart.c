#include <stdio.h>
#include "uart.h"
#include <string.h>
#include <assert.h>
#include "test_uart.h"


#define DEBUG 1
void print_testcase(uint8_t *test_case);
uint8_t test_case_1[UART_BUFF_LEN] = {0xa5,0x5a,0xdd,0xa5,0x5a,0x5a,
                          0xdd,0xaa,0xa5,0x5a,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};

uint8_t test_case_2[UART_BUFF_LEN] = {0xa5,0x5a,0xdd,0xaa,0xff,0x5a,
                          0xdd,0xaa,0x55,0xaa,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};
uint8_t test_case_3[UART_BUFF_LEN] = {0x00,0x11,0xdd,0x99,0x9a,0x5a,
                          0xdd,0xaa,0x55,0xaa,0xdd,0xdd,
                          0xaa,0x55,0x55,0x01};
int main(void)
{
    if (TEST_UART_BUFF_LEN != UART_BUFF_LEN)
    {
        printf("Buffer length mismatch\n ");
        return 0;
    }
#if DEBUG
    print_testcase(test_case_1);
#endif
    printf("\ntest_case_1 sequence count: %d\n",sequence_count(test_case_1));
#if DEBUG
    print_testcase(test_case_2);
#endif
    printf("\ntest_case_2 sequence count: %d\n",sequence_count(test_case_2));
#if DEBUG
    print_testcase(test_case_3);
#endif
    printf("\ntest_case_3 sequence count: %d\n",sequence_count(test_case_3));  
    return 0;
}

void print_testcase(uint8_t *test_case)
{
    printf("Test case = [");
    for(uint8_t i = 0;i<UART_BUFF_LEN;i++)
    {
        printf("%x ",test_case[i]);
    }
    printf("]");
}