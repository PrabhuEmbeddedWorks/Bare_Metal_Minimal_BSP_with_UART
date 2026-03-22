#include <stdint.h>   // Standard integer definitions

/* External linker symbols */
extern uint32_t _estack;  // End of stack (top of stack)
extern uint32_t _sidata;  // Start of initialized data in flash
extern uint32_t _sdata;   // Start of data section in RAM
extern uint32_t _edata;   // End of data section in RAM
extern uint32_t _sbss;    // Start of BSS section
extern uint32_t _ebss;    // End of BSS section

extern int main(void);    // Main function

/* Reset Handler */
void Reset_Handler(void)
{
    uint32_t *src = &_sidata;  // Source pointer (flash)
    uint32_t *dest = &_sdata;  // Destination pointer (RAM)

    /* Copy initialized data */
    while (dest < &_edata)     // Until end of data section
    {
        *dest++ = *src++;      // Copy data from flash to RAM
    }

    /* Zero BSS */
    dest = &_sbss;             // Point to BSS start
    while (dest < &_ebss)      // Until end of BSS
    {
        *dest++ = 0;           // Initialize with zero
    }

    /* Call main */
    main();                    // Jump to main application

    while (1);                 // Infinite loop if main returns
}

/* Vector Table */
__attribute__((section(".isr_vector")))   // Place in vector section
void (* const vector_table[])(void) =
{
    (void (*)(void))(&_estack), // Initial Stack Pointer
    Reset_Handler               // Reset handler entry point
};