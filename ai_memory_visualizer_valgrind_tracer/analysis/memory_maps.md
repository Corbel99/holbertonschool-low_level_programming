# C Memory Analysis & Visualizer

This document provides a detailed low-level analysis of memory behavior, object lifetimes, stack frame evolution, pointer aliasing, and dynamic allocation across the provided C programs.

---

## 1. Stack Memory Analysis: `stack_example.c`

### Overview & Execution Flow
`stack_example.c` demonstrates how recursive call stacks operate in C. Each function invocation pushes a new **stack frame** onto the call stack, containing its parameters, local variables, and return address. When a function finishes, its frame is popped, and memory is reclaimed automatically.

### Key Memory Execution Points

1. **Initial Call (`main` -> `walk_stack(0, 3)`):**
   * Frame for `walk_stack(depth=0)` is allocated on the stack.
   * Local variable `marker` is assigned `0`.
   * Invokes `dump_frame("enter", 0)`, creating a frame containing `local_int = 100`, `p_local` pointing to `local_int`, and `local_buf = ['A', '\0']`.
   * Upon returning from `dump_frame`, its frame is destroyed.

2. **Recursive Descent (`walk_stack(depth=1..3)`):**
   * As `depth` increments from 0 to 3, new stack frames for `walk_stack` are pushed sequentially.
   * On typical architectures where the stack grows downward (toward lower addresses), addresses for `&marker` and `&local_int` decrease with each recursive call.

3. **Max Depth Base Case (`depth = 3`):**
   * Condition `depth < max_depth` (3 < 3) evaluates to `false`. Recursion stops.
   * Execution reaches `dump_frame("exit", 3)`.

4. **Recursive Unwinding:**
   * Stack frames for `walk_stack` are popped sequentially from depth 3 down to depth 0.
   * Variables in higher depth frames are no longer valid once their respective frame pops.

### Stack Memory Layout Diagram

```text
Higher Memory Addresses
+---------------------------------------------------+
| main() Frame                                      |
+---------------------------------------------------+
| walk_stack(depth=0) Frame                         |
|   - depth: 0, max_depth: 3                        |
|   - marker: 0 (Address: e.g., 0x7fff500)          |
+---------------------------------------------------+
| walk_stack(depth=1) Frame                         |
|   - depth: 1, max_depth: 3                        |
|   - marker: 10 (Address: e.g., 0x7fff4d0)         |
+---------------------------------------------------+
| ...                                               |
+---------------------------------------------------+
| dump_frame("enter", 3) Frame                      |
|   - label: "enter", depth: 3                      |
|   - local_int: 103 (Address: e.g., 0x7fff400)     |
|   - p_local: 0x7fff400                            |
|   - local_buf: ['D', '\0', ...]                   |
+---------------------------------------------------+
Lower Memory Addresses (Stack grows downward)
```

### Lifetime Analysis
* **`marker` / `local_int` / `local_buf`**: Local automatic variables (`auto`). Their lifetimes are strictly bound to the scope and duration of their enclosing function call. Once `dump_frame` or `walk_stack` returns, their stack frames are invalidated, making any pointer to them a **dangling pointer**.

---

## 2. Pointer Aliasing & Use-After-Free Analysis: `aliasing_example.c`

### Overview & Execution Flow
`aliasing_example.c` demonstrates pointer aliasing and memory ownership flaws leading to **Use-After-Free (UAF)** and **Invalid Write** vulnerabilities.

### Key Memory Execution Points

1. **Heap Allocation (`make_numbers(5)`):**
   * `malloc(5 * sizeof(int))` allocates 20 contiguous bytes on the **Heap**.
   * `arr` points to the base heap address (e.g., `0x55aa0010`).
   * Array elements are initialized: `[0, 11, 22, 33, 44]`.

2. **Pointer Aliasing (`b = a`):**
   * Variable `a` stores the heap address `0x55aa0010`.
   * Assigning `b = a` creates an **alias**. Both pointers hold identical address values (`a == b == 0x55aa0010`) and refer to the exact same block of heap memory.
   * Either pointer can read or modify the underlying data.

3. **Deallocation (`free(a)`):**
   * `free(a)` releases the 20-byte block back to the heap allocator.
   * Pointer `a` still holds address `0x55aa0010`, but the memory block is marked as unallocated.
   * Pointer `b` is now a **dangling pointer** because it still references address `0x55aa0010`, which no longer holds a valid heap allocation.

4. **Use-After-Free Read (`reading b[2]`):**
   * Program reads `b[2]` (offset +8 bytes from `0x55aa0010`).
   * This is an **Invalid Read** (Use-After-Free). The value might still show `22` temporarily if memory wasn't re-allocated or overwritten, but reading it invokes **Undefined Behavior**.

5. **Use-After-Free Write (`b[3] = 1234`):**
   * Program writes `1234` to `b[3]` (offset +12 bytes).
   * This is an **Invalid Write** (Use-After-Free). It risks corrupting internal heap allocator metadata, potentially leading to immediate crashes or arbitrary code execution vulnerabilities.

### Memory State Map

```text
   STACK VARIABLES                     HEAP MEMORY
+--------------------+            +-------------------+
| a: 0x55aa0010      | ---------> | [0]  : 0          |
+--------------------+            | [1]  : 11         |
| b: 0x55aa0010      | -----------| [2]  : 22         |
+--------------------+            | [3]  : 33 -> 1234 |
                                  | [4]  : 44         |
                                  +-------------------+
                                  (AFTER free(a): INVALID REGION)
```

### Lifetime & Ownership Analysis
* **Owner**: `a` initially owned the heap chunk allocated inside `make_numbers`.
* **Aliasing**: `b` shared access without taking ownership.
* **Flaw**: Freeing memory via `a` invalidated the memory destination for `b`. Modifying `b` afterwards triggers Undefined Behavior due to missing nullification of aliased pointers.

---

## 3. Dynamic Allocation & Memory Leaks: `heap_example.c`

### Overview & Execution Flow
`heap_example.c` demonstrates nested heap allocations (`struct Person` and string buffers) and illustrates a **partial free memory leak**.

### Key Memory Execution Points

1. **Double Heap Allocation (`person_new`):**
   * Call 1: `malloc(sizeof(Person))` allocates 16 bytes on the Heap for the structure metadata (`p`).
   * Call 2: `malloc(len + 1)` allocates dynamic buffer space on the Heap for `p->name` string bytes.

2. **Deallocation of `bob` (Correct):**
   * `free(bob->name)` frees the heap buffer containing `"Bob\0"`.
   * `free(bob)` frees the structure metadata block.
   * `bob` is cleanly deallocated with no leaks.

3. **Partial Deallocation of `alice` (Memory Leak):**
   * `person_free_partial(alice)` calls `free(p)`.
   * It frees the `Person` structure metadata block at `alice`.
   * **Leak**: `alice->name` (which points to heap memory containing `"Alice\0"`) was **never freed**.
   * Because the parent struct pointer `alice` was freed first, the pointer address stored in `alice->name` is lost forever. The allocated string memory becomes unreachable, creating a **definitely lost memory leak** reported by Valgrind.

---

## 4. Critical Evaluation of AI-Generated Analysis

### AI Error Case Study

During analysis setup, an AI model was asked to evaluate the memory state of `heap_example.c` at line `person_free_partial(alice)`.

#### AI Misleading Explanation:
> *"Calling `person_free_partial(alice)` frees all memory associated with Alice. Because `alice` is passed to `free()`, C automatically cleans up inner struct members including dynamically allocated pointers like `alice->name`."*

#### Why the AI Explanation was Incorrect:
1. **False Automation Assumption**: C has no automatic garbage collection, destructors, or deep-free mechanism for primitive structs.
2. **Ignorance of Memory Independence**: The `Person` struct block and the `name` string buffer are two entirely separate heap allocations returned by two distinct `malloc()` calls.
3. **Dangling Access & Leak Mechanics**: Calling `free(p)` only releases the bytes occupied by the struct itself (`name` pointer variable + `age` integer). The memory buffer holding `"Alice"` remains allocated on the heap. Once `p` is freed, the address referencing `"Alice"` is lost, making it impossible to free later.

#### Corrected Analysis:
To prevent a memory leak in nested structures, deallocation must strictly proceed from the **innermost/child allocations to the outer/parent allocation**:

```c
/* Corrected Deallocation Pattern */
static void person_free_full(Person *p)
{
    if (!p)
        return;
    
    free(p->name); /* 1. Free child allocation first */
    free(p);       /* 2. Free parent struct block second */
}
```
