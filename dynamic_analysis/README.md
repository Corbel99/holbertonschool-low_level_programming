# Dynamic Analysis & Reverse Logic with GDB

## Description

This project is part of the Holberton School Low Level Programming curriculum.

The objective is to learn how to analyze the behavior of a C program at runtime using **GDB (GNU Debugger)** instead of relying only on source code inspection.

Throughout this project, the program must **not be modified**. All required information is obtained by observing the program while it executes.

## Learning Objectives

By completing this project, I will learn how to:

* Compile a program with debugging symbols.
* Launch and control a program with GDB.
* Set and manage breakpoints.
* Step through program execution.
* Inspect variables and function arguments.
* Understand the program's control flow.
* Infer an algorithm from runtime behavior.
* Use Visual Studio Code as a frontend for GDB.

## Technologies

* Language: C
* Compiler: GCC
* Debugger: GDB
* IDE: Visual Studio Code
* Operating System: Ubuntu / Linux

## Project Structure

```text
dynamic_analysis/
├── README.md
├── source.c
└── gdb_fundamentals.txt
```

## Compilation

Compile the program with debugging information:

```bash
gcc -g source.c -o source
```

## Running with GDB

Start the debugger:

```bash
gdb ./source
```

## Author

Thomas
