# C - Doubly Linked Lists

## Description

This project is part of the Holberton School low-level programming curriculum.

The objective is to understand and manipulate doubly linked lists in C. Unlike singly linked lists, each node contains a pointer to both the previous and the next node, allowing traversal in both directions.

## Learning Objectives

At the end of this project, I am able to explain:

- What a doubly linked list is.
- How to traverse a doubly linked list forward and backward.
- How to insert and delete nodes in a doubly linked list.
- How to update `prev` and `next` pointers correctly.
- When to use a doubly linked list instead of a singly linked list.

## Requirements

- Ubuntu 20.04 LTS
- GCC
- Compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

- Betty style
- No global variables
- No more than 5 functions per file
- Allowed standard library functions:
  - `malloc`
  - `free`
  - `printf`
  - `exit`

## Data Structure

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Files

| File | Description |
|------|-------------|
| `lists.h` | Structure definition and function prototypes |
| `*.c` | Doubly linked list function implementations |
| `README.md` | Project documentation |

## Concepts Covered

- Doubly linked lists
- Dynamic memory allocation
- Structures
- Pointers
- Pointer manipulation
- Memory management
- List traversal
- Node insertion
- Node deletion

## Author

Thomas Corbel  
Holberton School
