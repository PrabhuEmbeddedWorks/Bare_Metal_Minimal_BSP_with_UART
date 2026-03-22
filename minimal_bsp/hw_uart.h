#ifndef HW_UART_H           // Prevent multiple inclusion
#define HW_UART_H

#include <stdint.h>         // Standard integer types

/* UART Base Address */
#define UART0_BASE 0x4000C000   // Base memory address of UART0 peripheral

/* Registers */
#define UART0_DR (*((volatile uint32_t *)(UART0_BASE + 0x000))) // Data Register (TX/RX)
#define UART0_FR (*((volatile uint32_t *)(UART0_BASE + 0x018))) // Flag Register (status)

/* Flags */
#define UART_FR_TXFF (1 << 5)   // Transmit FIFO Full flag
#define UART_FR_RXFE (1 << 4)   // Receive FIFO Empty flag

#endif  // End of include guard