#include "driver_uart.h"   // Include UART driver APIs

int main(void)
{
    uart_init();   // Initialize UART peripheral

    /* DEBUG: Confirm code is running */
    uart_send_string("STARTED\n");  // Print startup message

    uart_send_string("\r\n=============================\r\n");  // Formatting line
    uart_send_string("Minimal BSP Boot Successful!\r\n");    // Boot confirmation
    uart_send_string("=============================\r\n");

    uart_send_string("\r\n=== UART RX DEBUG MODE ===\r\n"); // Debug mode message
    uart_send_string("Type something:\r\n> ");              // Prompt user
    uart_send_string("> ");                                // Extra prompt (duplicate)

    while (1)
    {
        char c = uart_receive_char();   // Wait and read one character

        /* Ignore Enter keys */
        if (c == '\r' || c == '\n')     // If Enter key pressed
        {
            uart_send_string("\r\n> "); // Print new prompt
            continue;                  // Skip rest of loop
        }

        /* Print each character in new line */
        uart_send_string("\r\n[RX]: "); // Print label
        uart_send_char(c);              // Print received character
    }

    return 0;   // Never reached (infinite loop)
}