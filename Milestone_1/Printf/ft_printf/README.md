*This project has been created as part of the 42 curriculum by kdzwigal.*

## Description

**ft_printf** is a custom implementation of the standard C library function `printf()`. The primary goal of this project is to learn how to handle variadic functions in C (functions that accept a variable number of arguments) and to dive deeper into string manipulation, type conversion, and formatted output.

The library compiles into a static archive named `libftprintf.a`. Unlike the original `printf()`, this implementation does not implement internal buffer management; it outputs characters directly to the standard output file descriptor using the `write()` system call.

The prototype of my function  is:

```c
int	ft_printf(const char *str, ...);
```

### Supported Conversions

The function handles the following format specifiers:

* `%c` — Prints a single ASCII character.
* `%s` — Prints a string of characters (handles `NULL` pointers according to standard conventions).
* `%p` — Prints a `void *` pointer argument in hexadecimal format (e.g., `0x557b68bef008`).
* `%d` / `%i` — Prints a signed decimal (base 10) integer.
* `%u` — Prints an unsigned decimal (base 10) integer.
* `%x` — Prints an unsigned integer in hexadecimal (base 16) using lowercase formatting (`0–9`, `a–f`).
* `%X` — Prints an unsigned integer in hexadecimal (base 16) using uppercase formatting (`0–9`, `A–F`).
* `%%` — Prints a literal percent sign.

## Algorithm and Data Structure Justification

### Data Structures

* `va_list` **(Variadic List):** The standard C `<stdarg.h>` macros (`va_start`, `va_arg`, `va_copy`, `va_end`) are used to traverse the variable arguments.
* **Minimalist Scalar Variables / Dispatcher:** No complex dynamic data structures (like linked lists or heavy structs) are used. Because the mandatory scope excludes flag buffering and complex formatting options (like width, precision, or flags `-0.+ #`), a lightweight procedural approach is optimal. If extended, a simple structure to hold formatting state could be introduced, but for the mandatory conversions, direct dispatching minimizes memory overhead and execution time.

### Algorithm

1. **Single-Pass Linear Parsing ($O(n)$):** The algorithm iterates through the `str` string character by character from left to right.
2. **Direct Output & Counting:**
   * When a regular character (not `%`) is encountered, it is immediately written to standard output (`write(1, &str[i], 1)`), and an internal integer counter is incremented (`total_printed++`).
   * When a `%` is encountered, the algorithm advances to the next character to identify the conversion specifier (`if (str[i] == '%'`).
3. **Dispatching & Conversion:**
   * Based on the specifier (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`), the algorithm calls a dedicated helper function (e.g., `print_char(args)`, `print_string(args)`, `print_integer(args)`).
   * These helper functions fetch the corresponding type from the `va_list` using `va_arg()`, format/convert the data into character representations (using recursion division for numerical bases), and write them to standard output.
4. **Return Value:** Each helper function returns the exact number of bytes it wrote. This count is added to the total return value. Once the end of the format string (`\0`) is reached, `va_end()` is called to clean up the memory, and the total character count is returned to match the behavior of `libc`'s `printf()`.

## Instructions

### Compilation

The project includes a `Makefile` that compiles the source files into the static library `libftprintf.a`. It strictly uses the `ar` command for archive creation.

To compile the library, run:

```bash
make
```

### Available Makefile Rules

* `make` or `make all`: Compiles the source files and generates `libftprintf.a`.
* `make clean`: Removes all object (`.o`) files generated during compilation.
* `make fclean`: Removes object files and the compiled library (`libftprintf.a`).
* `make re`: Performs a full re-build by running `fclean` followed by `all`.

### Usage & Execution

To use `ft_printf` in your own C project:

1. Include the header file in your C code:

   ```c
   #include "ft_printf.h"
   
   int main(void)
   {
       ft_printf("Hello, %s! The answer is %d, and pointer is %p.\n", "world", 42, &main);
       return (0);
   }
   ```

2. Compile your program by linking it with the generated `libftprintf.a` library:

   ```bash
   cc your_main_name.c -L. -lftprintf -o your_program_name
   ```

## Resources

### Classic References

* **Man Pages:**
  * `man 3 printf` — Standard manual for understanding exact behaviors, edge cases, and return values of format specifiers.
  * `man 3 stdarg` — Manual for variadic macros (`va_start`, `va_arg`, `va_copy`, `va_end`).
 
* **Articles:**
  * [cplusplus.com](https://cplusplus.com/reference/cstdio/printf/) — Print formatted data to stdout.
  * [Microsoft Learn](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170) — Accesses variable-argument lists.

### AI Usage

In alignment with 42 curriculum guidelines, Artificial Intelligence (LLMs) was utilized in a limited and transparent manner during this project for the following specific tasks:

* **Concept Verification:** Asking AI to explain the underlying memory alignment mechanisms of `va_arg()` across different architectures (32-bit vs. 64-bit systems).
* **Edge Case Brainstorming:** Generating a checklist of potential edge cases to test against the standard libc `printf()` (e.g., behavior when printing `INT_MIN`, `LONG_MAX`, or passing a `NULL` pointer to `%s` and `%p`).
* **Documentation:** Assisting in structuring and formatting this `README.md` file to adhere cleanly to Markdown standards and project requirements.

*(Note: All core logic, algorithms, writing of source code, and debugging were performed manually without generating direct implementation code from AI).*
