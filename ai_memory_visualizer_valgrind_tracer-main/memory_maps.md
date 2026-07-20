# Memory Maps

## stack_example.c

### Program purpose

This program demonstrates how recursive function calls create multiple stack frames and how local variables exist only during the execution of their function.

---

### Key execution points where memory changes

#### 1. Program starts

- `main()` is called.
- A stack frame is created for `main()`.

#### 2. First call to `walk_stack(0, 3)`

- A new stack frame is created.
- Local variables are initialized:
  - `depth`
  - `max_depth`
  - `marker`

#### 3. Call to `dump_frame("enter", depth)`

- Another stack frame is created.
- Local variables are allocated:
  - `local_int`
  - `local_buf`
  - `p_local`
- `p_local` stores the address of `local_int`.

#### 4. Recursive call

If `depth < max_depth`, `walk_stack()` calls itself.

- A new stack frame is created.
- The previous stack frames remain active.
- Each recursive call owns its own copy of the local variables.

#### 5. Function return

When `dump_frame()` returns, its stack frame is destroyed.

When `walk_stack()` returns, its stack frame is also destroyed.

The recursive calls return in reverse order until execution goes back to `main()`.

---

### Memory observations

- Only the **stack** is used.
- No heap memory is allocated.
- No memory is freed with `free()`.
- Each recursive call creates an independent stack frame.
