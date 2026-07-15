# Function Pointers

## Description

This project introduces **function pointers** in the C programming language.

The objective is to understand that functions, like variables, have an address in memory. A function pointer stores the address of a function and allows the program to call different functions dynamically.

Throughout this project, the following concepts are practiced:

* Declaring function pointers
* Passing function pointers as function parameters
* Calling a function through a function pointer
* Understanding the relationship between functions and memory addresses
* Building more flexible and reusable code

---

## Learning Objectives

At the end of this project, I am able to explain:

* What a function pointer is
* How to declare and use a function pointer
* What a function pointer stores
* Where a function pointer points in virtual memory
* Why function pointers are useful

---

## Requirements

* Ubuntu 20.04 LTS
* GCC compiler
* Compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

* Betty coding style
* No global variables
* Maximum of 5 functions per file
* Header file: `function_pointers.h`

---

## Allowed Functions

* `malloc`
* `free`
* `exit`
* `_putchar`

---

## Files

| File                  | Description                                         |
| --------------------- | --------------------------------------------------- |
| `function_pointers.h` | Function prototypes and header guards               |
| `0-print_name.c`      | Prints a name using a function pointer              |
| `1-array_iterator.c`  | Executes a function on each element of an array     |
| `2-int_index.c`       | Searches for an integer using a comparison function |
| `3-main.c`            | Entry point for the calculator program              |
| `3-op_functions.c`    | Arithmetic operation functions                      |
| `3-get_op_func.c`     | Returns the appropriate function pointer            |
| `3-calc.h`            | Prototypes and structures for the calculator        |

---

## Compilation Example

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o program
```

---

## Author

Thomas
