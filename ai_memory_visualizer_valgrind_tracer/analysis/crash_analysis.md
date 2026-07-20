# Analysis: NULL Pointer Dereference & Crash (crash_example.c)

## 1. Executive Summary
This report analyzes the deterministic crash present in crash_example.c, caused by an unverified NULL pointer dereference leading to a Segmentation Fault (SIGSEGV).

## 2. Root Cause Analysis

In main(), the program initializes n to 0 and calls allocate_numbers(n):

nums = allocate_numbers(0);

Inside allocate_numbers:
1. The function checks if n <= 0.
2. Since n = 0, the function immediately returns NULL without allocating memory.
3. In main(), the return value is assigned to nums, making nums a NULL pointer.

### The Crash Mechanism:
Immediately after allocation, the program attempts to access the memory without checking if nums is valid:

nums[0] = 42;

Dereferencing a NULL pointer (address 0x0) triggers an invalid memory access exception at the OS level, resulting in a Segmentation Fault (SIGSEGV).

## 3. Valgrind Diagnostic Mapping

When executing valgrind ./crash_example, Valgrind pinpoints the exact cause:
* Invalid write of size 4: Occurs at the line nums[0] = 42.
* Address 0x0 is not stack'd, malloc'd or (recently) free'd: Valgrind explicitly shows that the memory operation targeted address 0x0 (NULL).
* Process terminating with signal 11 (SIGSEGV).

## 4. Corrective Action & Best Practices

To prevent NULL pointer dereferences:
1. Always validate return values of functions that return pointers before accessing them.
2. Handle initialization errors gracefully.

Corrected code implementation:

nums = allocate_numbers(n);
if (!nums)
{
    fprintf(stderr, "Error: Allocation failed or invalid size\n");
    return 1;
}

nums[0] = 42;
