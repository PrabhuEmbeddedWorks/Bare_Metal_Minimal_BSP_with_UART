/* Entry point */
ENTRY(Reset_Handler)    /* Program starts from Reset_Handler */

/* Memory regions */
MEMORY
{
    FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K   /* Flash memory */
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 64K    /* SRAM */
}

/* Sections */
SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))   /* Keep vector table */
        *(.text*)              /* Code */
        *(.rodata*)            /* Read-only data */
    } > FLASH

    .data :
    {
        _sdata = .;            /* Start of data */
        *(.data*)              /* Initialized variables */
        _edata = .;            /* End of data */
    } > RAM AT > FLASH

    _sidata = LOADADDR(.data); /* Flash copy address */

    .bss :
    {
        _sbss = .;             /* Start of BSS */
        *(.bss*)
        *(COMMON)
        _ebss = .;             /* End of BSS */
    } > RAM

    _estack = ORIGIN(RAM) + LENGTH(RAM); /* Stack top */
}