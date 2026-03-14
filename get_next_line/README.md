*This project has been created as part of the 42 curriculum by horarivo.*

# Get Next Line

---

## Description
**Get Next Line** (GNL) is a project at 42 that tasks students with creating a function that returns a line read from a file descriptor. 

**Goal:**
The goal is to learn about static variables in C and deep-dive into file manipulation. The function must be able to read a full line from a file, a standard input, or even a redirection, without losing the "overflow" data from the previous read.

**Overview:**
The function `get_next_line` returns the next line of a text file (ending with `\n`) each time it is called. If it reaches the end of the file or an error occurs, it returns `NULL`. It is designed to be memory-efficient and handle different `BUFFER_SIZE` values.

---

## Instruction

### Compilation
The project includes a default `BUFFER_SIZE` of 42 in the header file. However, you can override this value at compilation time using the `-D` flag.

**Standard compilation (using default buffer):**
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
```

**Compilation with a custom buffer size:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Execution
Once compiled, run the executable:
```bash
./gnl [path_to_file]
```

---

## Algorithm: Explanation and Justification

### Selected Algorithm: Static Buffer Management

### Detailed Explanation
The core challenge of GNL is that a single `read()` call might fetch more data than needed for one line. The algorithm works as follows:
1. **Initial Read:** The function reads from the file descriptor into a temporary buffer using the size defined by `BUFFER_SIZE`.
2. **Persistence:** Because a line might end in the middle of a read, the "leftover" characters (everything after the first `\n`) are stored in a **static variable**.
3. **Accumulation:** A loop continues to read and join data until a newline character (`\n`) is found within the accumulated string or the end of the file is reached.
4. **Extraction:** Once a newline is detected, the function extracts the line to be returned and updates the static variable to keep only the remaining data for the next call.
5. **Memory Management:** Dynamic allocation is handled carefully (using `malloc` and `free`) to avoid leaks during string concatenation and extraction.

### Justification
* **Persistence:** The **static variable** is used to preserve the buffer's state across multiple function calls, which is mandatory since we cannot use global variables.
* **Flexibility:** This implementation remains robust regardless of the `BUFFER_SIZE` (from 1 to several millions).
* **Efficiency:** It minimizes system calls by buffering data and only reading from the file descriptor when the current static buffer no longer contains a newline.

---

## Resources

### Classic References
* **Man pages:** `read(2)`, `malloc(3)`, `free(3)`, ...
* **Static Variables:** Understanding the memory segments (Data/BSS) where static data is stored.
* **File Descriptors:** Managing open files.

### Use of AI
AI was utilized for the following tasks:
* **Logic Verification:** Confirming the behavior of static variables when handling multiple file descriptors simultaneously.
* **Debugging Assistance:** Identifying potential memory leaks using `valgrind` log interpretations.
* **Documentation:** Assisting in the vreation of this README.

---

## Testing Examples

Below are two examples of `main.c` files to test the project.

### 1. Basic Usage (Single File)
This test reads a single file line by line until the end.

```c
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc < 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### 2. Bonus Usage (Multiple File Descriptors)
This test demonstrates reading from three different files alternately to prove the static variable correctly manages multiple FDs.

```c
#include "get_next_line_bonus.h"
#include <stdio.h>

int main(void)
{
    int     fd1, fd2, fd3;
    char    *line;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);

    // Reading alternately from different FDs
    line = get_next_line(fd1);
    printf("FD 1: %s", line);
    free(line);

    line = get_next_line(fd2);
    printf("FD 2: %s", line);
    free(line);

    line = get_next_line(fd3);
    printf("FD 3: %s", line);
    free(line);

    line = get_next_line(fd1);
    printf("FD 1: %s", line);
    free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    
    return (0);
}
```