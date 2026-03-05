*This project has been created as part of the 42 curriculum by horarivo.*

# Milestone 1

## Description
The **Milestone 1** at 42 marks the transition from basic C syntax to complex logic and resource management. This repository contains three foundational projects: **ft_printf** (variadic functions), **get_next_line** (static variables and file descriptors), and **push_swap** (algorithm optimization and stack manipulation).

---

## 🖋️ ft_printf

### Description
The **ft_printf** project consists of recreating the famous `printf` function from the C standard library. The primary goal is to learn how to handle a variable number of arguments using **variadic functions** (`va_start`, `va_arg`, etc.).

### Function Overview
| Format | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (standard C convention). |
| `%p` | Prints a `void *` pointer in hexadecimal format. |
| `%d` / `%i` | Prints a decimal (base 10) number. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` / `%X` | Prints a number in hexadecimal (base 16) lowercase/uppercase. |
| `%%` | Prints a percent sign. |

---

## 📜 get_next_line

### Description
The **get_next_line** project is a function that returns a line read from a file descriptor. It is a crucial tool for any future C project requiring file parsing or reading from the standard input.

### Algorithm & Data Structures
* **Static Variables**: The core of the function uses a `static char *` to persist data between function calls. This allows the program to "remember" the leftover characters read from the buffer that belong to the next line.
* **Buffer Management**: Data is read in chunks defined by a `BUFFER_SIZE`. The function continuously concatenates these chunks until a newline character (`\n`) or the end of the file (`EOF`) is detected.
* **Memory Efficiency**: Careful use of `malloc` and `free` ensures that only the necessary amount of memory is allocated for each line, preventing memory leaks during long read operations.

---

## 🔄 push_swap

### Description
The **push_swap** project is an algorithm challenge where a stack of integers must be sorted using a second stack and a limited set of operations. The goal is to achieve the smallest number of operations possible.

### Operations Overview
| Command | Description |
| :--- | :--- |
| `sa` / `sb` | Swap the first 2 elements at the top of stack A or B. |
| `pa` / `pb` | Push the top element from one stack to the other. |
| `ra` / `rb` | Shift up all elements of a stack by 1 (the first becomes the last). |
| `rra` / `rrb` | Shift down all elements of a stack by 1 (the last becomes the first). |

### Algorithm & Strategy
* **The Turk Algorithm / Mechanical Turk**: My implementation uses a cost-based optimization strategy. It calculates the most "efficient" element to move by checking how many rotations are needed for both stacks simultaneously (`rr` or `rrr`).
* **Pre-sorting & Positioning**: Before moving an element, the algorithm identifies its target position in the destination stack to maintain a specific order (ascending or descending), minimizing the final adjustment steps.
* **Complexity**: Designed to handle 100 integers in fewer than 700 moves and 500 integers in fewer than 5500 moves, reaching the highest efficiency scores.

---

## Instructions

### Compilation
Each project folder contains its own **Makefile** to automate the build process.

* `make`: Compiles the project and generates the executable or library.
* `make clean`: Removes object files (`.o`).
* `make fclean`: Removes object files and the final binary.
* `make re`: Forces a full recompilation.

### Usage
For **push_swap**:
```bash
./push_swap 4 67 3 1 9
```

For **ft_printf** and **get_next_line**:
Integrate the source files or the `.a` library into your project and include the respective headers.

## Resources

### References

* **42 Norm**: Strict coding standard to ensure code readability and maintainability.
* **Man Pages**: Primary documentation for Unix system calls and C standard library functions (e.g., `man 3 printf`, `man 2 read`).
* **Sorting Algorithms**: Theoretical research on algorithm complexity (Big O) and implementation of the Turk algorithm for stack sorting.
* **Static Variables**: Documentation on memory persistence within the stack/heap and the use of static pointers for buffer management.
* **Variadic Functions**: Official C documentation for `stdarg.h` to handle undefined numbers of function arguments.
* **AI usage** : Artificial Intelligence tools were utilized for code optimization and debugging.
