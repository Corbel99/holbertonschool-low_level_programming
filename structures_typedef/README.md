# C - Structures, typedef

## Description

This project introduces two important concepts in the C programming language:

- Structures (`struct`)
- Type definitions (`typedef`)

The goal is to learn how to group different data types into a single structure, create new type names using `typedef`, and manipulate structures in different ways.

---

## Learning Objectives

At the end of this project, I am able to:

- Understand what a structure is.
- Know when and why to use structures.
- Declare and use structures.
- Access structure members using `.` and `->`.
- Understand and use `typedef`.

---

## Requirements

- Ubuntu 20.04 LTS
- GCC
- Compilation flags:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

- Betty style compliant
- No global variables
- Maximum 5 functions per file

---

## Files

| File | Description |
|------|-------------|
| `dog.h` | Defines the `struct dog` type |
| `0-dog.c` | Project task implementation |
| `1-init_dog.c` | Project task implementation |
| `2-print_dog.c` | Project task implementation |
| `3-dog_t.h` | Defines the `dog_t` type using `typedef` |
| `4-new_dog.c` | Creates a new dog |
| `5-free_dog.c` | Frees allocated memory |

---

## Author

Thomas