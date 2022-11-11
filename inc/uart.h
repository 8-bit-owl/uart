#ifndef UART
#define UART

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef short int16_t;

#define UART_BUFF_LEN 16



void uart_isr(volatile uint8_t *data);

#endif