# Analysis: Pointer Aliasing & Use-After-Free (aliasing_example.c)

## 1. Executive Summary
This report analyzes the memory safety violations present in aliasing_example.c, specifically pointer aliasing and Use-After-Free (UAF) access on heap-allocated memory.

## 2. Pointer Aliasing Mechanism

In main(), memory is allocated on the heap via make_numbers(5) and assigned to pointer a.

b = a;

* Aliasing occurs when two distinct variables (a and b) store the same virtual memory address.
* Both a and b point to the exact same heap memory block holding an array of 5 integers.

## 3. Vulnerability Analysis: Use-After-Free (UAF)

### Causal Chain:
1. Ownership Confusion: free(a) deallocates the heap memory block. However, variable b is not updated and remains pointing to the deallocated memory location (dangling pointer).
2. Invalid Memory Read: Executing printf("reading b[2]=%d\n", b[2]) attempts to read memory that is no longer owned by the process.
3. Invalid Memory Write: Executing b[3] = 1234 attempts to modify heap memory that has already been returned to the allocator, risking heap corruption.

## 4. Valgrind Diagnostic Mapping

When running valgrind ./aliasing_example, Valgrind detects two major categories of errors:

* Invalid read of size 4: Triggered when reading b[2] after free(a). Valgrind explicitly states that the address is inside a block of memory that was previously freed.
* Invalid write of size 4: Triggered when writing to b[3] after free(a).
* Block Allocation History: Valgrind traces the origin of the block back to the malloc call in make_numbers.

## 5. Corrective Action & Recommendations

To eliminate Use-After-Free vulnerabilities:
1. Avoid unnecessary pointer aliasing when ownership management is complex.
2. Set pointers to NULL immediately after freeing them to prevent accidental re-use.
3. If multiple aliases exist, invalidate all referencing pointers before continuing execution.

Corrected code pattern:
free(a);
a = NULL;
b = NULL; /* Invalidate alias to prevent Use-After-Free */