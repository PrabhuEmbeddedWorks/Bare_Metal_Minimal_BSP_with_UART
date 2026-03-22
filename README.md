# Bare Metal Minimal BSP with UART on ARM Cortex-M3 using QEMU

## Project Structure

```
minimal_bsp/
├── driver_uart.c
├── driver_uart.h
├── hw_uart.h
├── linker.ld
├── main.c
├── startup.c
```

---

## 1. System Requirements

### Update Package List

```bash
sudo apt update
```

### Install Required Packages

```bash
sudo apt install -y gcc-arm-none-eabi qemu-system-arm build-essential
```

## 2. Create Project Directory

```bash
mkdir minimal_bsp
cd minimal_bsp
```

---

## 3. Place Source Files

Copy all the following files into the directory:

```
driver_uart.c
driver_uart.h
hw_uart.h
linker.ld
main.c
startup.c
```

Verify:

```bash
ls
```

Expected:

```
driver_uart.c  driver_uart.h  hw_uart.h  linker.ld  main.c  startup.c
```

---

## 4. Compile the Firmware

### Command

```bash
arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -nostartfiles \
-T linker.ld startup.c driver_uart.c main.c \
-o firmware.elf
```

### Explanation

* `-mcpu=cortex-m3` → Target CPU
* `-mthumb` → Thumb instruction set
* `-nostartfiles` → No standard startup (we provide our own)
* `-T linker.ld` → Custom linker script
* Output → `firmware.elf`

---

## 5. Verify Build Output

```bash
ls
```

Expected:

```
driver_uart.c  driver_uart.h  firmware.elf  hw_uart.h  linker.ld  main.c  startup.c
```

---

## 6. Run on QEMU

### Command

```bash
qemu-system-arm -machine lm3s6965evb -nographic -kernel firmware.elf
```

### Explanation

* `-machine lm3s6965evb` → Cortex-M3 board
* `-nographic` → Terminal UART output
* `-kernel` → Load ELF directly

---

## 7. Expected Output

```
Timer with period zero, disabling
STARTED

=============================
Minimal BSP Boot Successful!
=============================

=== UART RX DEBUG MODE ===
Type something:
> >
```

---

## 8. UART RX Testing

### Input

Type characters manually in terminal:

```
HELLO
```

### Expected Output

```
[RX]: H
[RX]: E
[RX]: L
[RX]: L
[RX]: O
```

### Behavior Explanation

* Each character is received via UART
* Printed on a new line
* Enter key resets prompt
---

### Learning Outcomes

* Understanding of Bare-Metal Boot Flow
* Writing Startup Code
* Linker Script Usage
* Memory-Mapped I/O
* UART Driver Implementation
* Running Embedded Firmware on QEMU

---

