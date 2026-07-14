# C - argc, argv

## Description

This project introduces command-line arguments in C. It focuses on understanding how a program receives information from the command line through the `main` function using `argc` and `argv`.

## Learning Objectives

At the end of this project, I am able to:

* Understand how command-line arguments are passed to a C program.
* Use the `argc` and `argv` parameters of the `main` function.
* Explain the difference between the two prototypes of `main`.
* Handle unused parameters using `(void)` or `__attribute__((unused))`.
* Compile programs with the required GCC options.

## Requirements

* Ubuntu 20.04 LTS
* GCC compiler
* Compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

* Betty coding style.
* No global variables.
* Maximum of 5 functions per file.

## Files

| File              | Description                                  |
| ----------------- | -------------------------------------------- |
| `main.h`          | Function prototypes and `_putchar` prototype |
| `0-whatsmyname.c` | Prints the program name                      |
| `1-args.c`        | Prints the number of arguments               |
| `2-args.c`        | Prints all arguments                         |
| `3-mul.c`         | Multiplies two numbers                       |
| `4-add.c`         | Adds positive numbers                        |

## Author

Thomas
