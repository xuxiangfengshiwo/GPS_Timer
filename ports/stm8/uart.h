
#include "atom.h"
#include "stm8s_uart2.h"


#define RX_MAX_BUF_LEN (128)
typedef enum
{
    E_OK,
    E_NOK
}Uart_Read_Status_T;


/*
 * Perform UART startup initialization.
 */
int	uart_init(uint32_t baudrate);

Uart_Read_Status_T uart_ReadBuf(uint8_t * buf, uint8_t* length);
