#ifndef DRIVER_UART_H      // Prevent multiple inclusion
#define DRIVER_UART_H

void uart_init(void);                      // Initialize UART hardware
void uart_send_char(char c);               // Send single character
void uart_send_string(const char *str);    // Send string
char uart_receive_char(void);              // Receive one character

#endif  // End of include guard