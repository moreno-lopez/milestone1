*This project has been created as part of the 42 curriculum by horarivo.*

# ft_printf

## Description
The **ft_printf** project consists of recreating the famous `printf` function from the C standard library. The primary goal is to learn how to handle a variable number of arguments using **variadic functions** (`va_start`, `va_arg`, etc.) and to gain a deep understanding of data formatting as well as different numerical bases (decimal, hexadecimal).

## Function Overview
My function handles the following conversions, in accordance with the subject requirements:

| Format | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (standard C convention). |
| `%p` | Prints a `void *` pointer in hexadecimal format (preceded by `0x`). |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Detailed Explanation
Unlike a standard function, `ft_printf` relies on the use of the `<stdarg.h>` library.

## Algorithm & Data Structures
* **Parsing & Dispatching**: The function processes the format string character by character in a single pass. A centralized dispatcher routes each format specifier to its specific function using `if/else if` statements to strictly comply with the 42 Norm (replacing `switch-case`).
* **Recursive Decomposition**: Numerical conversions (decimal, unsigned, hexadecimal) are handled using recursion. The function divides the number by its base to isolate and print the most significant digit as the call stack unwinds. This justifies avoiding `malloc` and temporary arrays, keeping memory usage minimal and preventing leaks.
* **Data Structures**: The core of the function relies on the va_list structure to manage variable arguments. Each character is written directly to the standard output as soon as it is processed, meaning the program doesn't need to store the final string in memory before displaying it.

1.  **Parsing**: The function traverses the character string. As soon as a `%` is detected, it analyzes the following character to determine the conversion type.
2.  **Argument Management**: Using the `va_start` and `va_arg` macros, the function dynamically extracts arguments from the stack based on the requested format (e.g., `int` for `%d`, `char *` for `%s`).
3.  **Bases and Recursion**: For numerical conversions (`%u`, `%x`, `%X`, `%p`), I implemented recursive functions capable of dividing the number by its respective base to display digits in the correct order while keeping track of the number of characters written.
4.  **The Static Library (.a)**: The project compiles into a `libftprintf.a` file. This is a **static library** (an archive of object files). Using a `.a` file allows all the individual functions (hexadecimal handlers, character printers, etc.) to be bundled into a single package. This makes it easier to link the entire "printf" toolset to other C projects with a single compilation flag.

## Instructions

### Compilation
The project includes a **Makefile** to automate the build process and generate the static library.

* `make`: Compiles the `libftprintf.a` library.
* `make clean`: Removes object files (`.o`).
* `make fclean`: Removes object files and the `.a` archive.
* `make re`: Forces a full recompilation.

### Usage
To integrate this library into your own project:
1.  Include the header: `#include "ft_printf.h"`
2.  Compile your project by linking the library: `cc main.c libftprintf.a`

## Resources

### References
* **``man 3 printf``**
* **stdarg.h Documentation**
* **42 Norm**
* **Youtube**