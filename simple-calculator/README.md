# Simple Calculator

## Description

This project is a terminal-based calculator written in C.

The calculator allows the user to choose an arithmetic operation from a menu, enter two numbers, and display the result.

The program uses standard C libraries only and is designed to compile without warnings using strict compiler flags.

## Compilation

Compile the program with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Run

After compiling, run the program with:

```bash
./calculator
```

## Supported Operations

* Addition (`+`)
* Subtraction (`-`)
* Multiplication (`*`)
* Division (`/`)
* Quit the program

## Numeric Behavior

The calculator uses standard C numeric types.

Depending on the implementation, calculations may use:

* Integer arithmetic
* Decimal (floating-point) arithmetic

## Known Limitations

For the mandatory part of this project:

* Only integer menu choices are validated.
* The menu option must be within the valid range.
* Non-numeric input (for example: `abc`, `hello`, or `1abc`) is **not** handled and may cause unexpected behavior.
* Division by zero is handled by displaying an error message.
