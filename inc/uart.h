#ifndef UART
#define UART

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef short int16_t;

#define UART_BUFF_LEN 16

/*declared extern as they are shared*/
extern uint8_t received_flag;
extern uint8_t rx_buffer[UART_BUFF_LEN];

void uart_isr(uint8_t *data);
uint8_t sequence_count(uint8_t *test_case);
#endif