# Analysis: Heap Memory & Memory Leaks (`heap_example.c`)

## 1. Executive Summary
This report details the memory lifecycle, pointer ownership, and memory leak vulnerabilities present in `heap_example.c`.

## 2. Memory Ownership & Allocation Model

Every `Person` instance requires a two-tiered heap allocation:
1. Outer allocation: `malloc(sizeof(Person))` to store the struct fields (`name` pointer and `age` integer).
2. Inner allocation: `malloc(len + 1)` to store the string buffer assigned to `p->name`.

### Ownership Principle
The `Person` structure holds **exclusive ownership** over the buffer allocated for `p->name`. Therefore, destroying a `Person` requires a two-step deep deallocation:
1. Freeing `p->name` first.
2. Freeing `p` second.

## 3. Vulnerability & Causal Chain Analysis

### The Bug: Incomplete Deallocation (`person_free_partial`)
In `main()`, the program deallocates `bob` cleanly by executing `free(bob->name)` followed by `free(bob)`.

However, for `alice`, the program calls `person_free_partial(alice)`:
```c
static void person_free_partial(Person *p)
{
    if (!p)
        return;

    free(p);
}
Chain of Causal Events:
free(p) deallocates the memory block holding the Person structure.

The inner pointer alice->name (which addresses the heap memory holding "Alice") is lost without ever calling free().

The allocated buffer for "Alice" becomes an unreachable memory leak (definitely lost memory).

4. Valgrind Diagnostic Mapping
When executing Valgrind (valgrind --leak-check=full ./heap_example), the output reports:

Definitely lost: 6 bytes in 1 blocks (corresponding to "Alice\0" allocated via malloc(len + 1) in person_new).

All heap blocks were freed -- NO: 2 allocs, 1 frees recorded.

5. Corrective Action
To fix the memory leak, person_free_partial must perform a complete deep free:

C
static void person_free(Person *p)
{
    if (!p)
        return;

    free(p->name); /* Free inner allocation first */
    free(p);       /* Free outer struct allocation second */
}
