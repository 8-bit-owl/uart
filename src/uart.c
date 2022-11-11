#include "uart.h"
#define UART_BUFF_LEN 16


volatile uint8_t received_flag;
volatile uint8_t rx_buffer[UART_BUFF_LEN];

/*-------------------------------------*
Name: sequqnce_count

Description: incrments count if 0xa5 and 
0x5a are present sequentially.

Return: sequence count.
*-------------------------------------*/
uint8_t sequence_count(uint8_t *rx_buffer)
{
  uint8_t seq_count = 0;
  //returns the number of 0xa5, 0x5a in the sequence.
  for(int i = 1;i<UART_BUFF_LEN;i++)
  {
    if((rx_buffer[i-1] == 0xa5) && (rx_buffer[i] == 0x5a))
    {
      seq_count++;
    }
  }
  return seq_count;
}




/*-------------------------------------*
Name: uart_isr(void)

Description: when this isr is hit, it 
copies the data into the 16byte volatile 
buffer.

Returns: None
*-------------------------------------*/
void uart_isr(uint8_t *data)
{
  uint8_t rx_index = 0;
  while(rx_index<16)
  {
    rx_buffer[rx_index] = data[rx_index];
    rx_index++;
  }
  received_flag = 1;
}