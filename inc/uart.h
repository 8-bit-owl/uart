#ifndef UART
#define UART

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef short int16_t;

#define UART_BUFF_LEN 16

/*static to this file*/
volatile uint8_t received_flag;
volatile uint8_t rx_buffer[UART_BUFF_LEN];

void uart_isr(uint8_t *data);

#endif