#include "uart.h"

/*-------------------------------------*
shared buffers between the test app and 
the UART driver.
---------------------------------------*/
uint8_t received_flag;
uint8_t rx_buffer[UART_BUFF_LEN];


/*-------------------------------------*
Name: sequqnce_count

Description: increments count if 0xa5 and 
0x5a are present consecutively.

Return: sequence count.
*-------------------------------------*/
uint8_t sequence_count(uint8_t *rx_buffer)
{
  uint8_t seq_count = 0;
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

Description:  when this isr is hit, it 
copies the data into the 16byte shared 
buffer.

Returns: None
*-------------------------------------*/
void uart_isr(uint8_t *data)
{
  received_flag = 1;
  uint8_t rx_index = 0;
  while(rx_index<UART_BUFF_LEN)
  {
     rx_buffer[rx_index]=data[rx_index];
    rx_index++;
  }
}