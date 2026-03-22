#include "driver_uart.h"   // Include UART driver function declarations
#include "hw_uart.h"       // Include hardware register definitions

/* System Control Registers (for clock enable) */
#define SYSCTL_RCGC1 (*((volatile unsigned int *)0x400FE104)) // UART clock control register
#define SYSCTL_RCGC2 (*((volatile unsigned int *)0x400FE108)) // GPIO clock control register

void uart_init(void)
{
    /* Enable UART0 clock */
    SYSCTL_RCGC1 |= (1 << 0);   // Set bit 0 to enable UART0 peripheral clock

    /* Enable GPIOA clock (UART0 pins) */
    SYSCTL_RCGC2 |= (1 << 0);   // Enable clock for GPIO Port A (used by UART0 TX/RX pins)
}

void uart_send_char(char c)
{
    /* Wait until FIFO not full */
    while (UART0_FR & UART_FR_TXFF); // TXFF = Transmit FIFO Full → wait if full

    UART0_DR = c;   // Write character to Data Register → transmitted via UART
}

void uart_send_string(const char *str)
{
    while (*str)                 // Loop until null character '\0'
    {
        uart_send_char(*str++);  // Send current character and move pointer forward
    }
}

char uart_receive_char(void)
{
    /* Wait until data available */
    while (UART0_FR & UART_FR_RXFE); // RXFE = Receive FIFO Empty → wait if empty

    return (char)(UART0_DR & 0xFF);  // Read received data (lower 8 bits)
}