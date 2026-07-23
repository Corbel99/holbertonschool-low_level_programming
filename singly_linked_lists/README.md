# C - Singly Linked Lists

## Description

This project introduces singly linked lists in C.

The objective is to understand how linked lists work, how to create, traverse, modify and free them using dynamic memory allocation.

Throughout the project, we implement several functions to manipulate a `list_t` linked list.

---

## Learning Objectives

At the end of this project, we should be able to explain:

- What a singly linked list is
- How linked lists differ from arrays
- How to create and manipulate linked lists
- How to dynamically allocate and free memory
- How to use structures and pointers together
- How to use double pointers when modifying the head of a list

---

## Files

| File | Description |
|------|-------------|
| `lists.h` | Header file containing the `list_t` structure and function prototypes |
| `0-print_list.c` | Prints all the elements of a linked list |
| `1-list_len.c` | Returns the number of elements in a linked list |
| `2-add_node.c` | Adds a new node at the beginning of a linked list |

---

## Structure

```c
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;
```

---

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o linked_list
```

---

## Example

```text
[5] Hello
[5] World
```

---

## Concepts Used

- Structures
- Pointers
- Double pointers
- Dynamic memory allocation (`malloc`)
- Memory deallocation (`free`)
- String duplication (`strdup`)
- String length (`strlen`)
- Linked list traversal

---

## Authors

- Thomas
- Holberton School
