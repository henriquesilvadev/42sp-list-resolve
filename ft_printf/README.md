# ft_printf
![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

<p align="left">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge" />
</p>

This project reimplements the `printf` function from the C standard library. The goal is to understand how variadic functions work, how format strings are parsed, and how different data types are converted to their text representations.

## Description

**ft_printf** is the second project of the 42 curriculum. The objective is to recreate a subset of the original `printf` behavior, handling multiple format specifiers through variadic arguments (`va_list`).

By building this function from scratch, students deepen their understanding of how C handles variable argument lists, character-level output, numeric base conversion, and pointer representation. The result is a static library `libftprintf.a` that wraps the custom implementation and can be reused in future projects.

### Supported conversions

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string (outputs `(null)` if pointer is NULL) |
| `%p` | Prints a pointer address in hexadecimal with `0x` prefix |
| `%d` | Prints a decimal integer |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned integer in lowercase hexadecimal |
| `%X` | Prints an unsigned integer in uppercase hexadecimal |
| `%%` | Prints a literal `%` character |

### Internal functions

| Function | Description |
|---|---|
| `ft_printf` | Main entry point — parses the format string and dispatches conversions |
| `handle_conversion` | Matches the format specifier and calls the appropriate output function |
| `ft_putnbr_count` | Prints a signed integer and returns the number of characters written |
| `ft_putnbr_unsigned` | Prints an unsigned integer and returns the number of characters written |
| `ft_putnbr_base_fd` | Prints an unsigned number in an arbitrary base to a file descriptor |

---

## Instructions

### Requirements

- `gcc` compiler
- `make`
- Unix-based OS (Linux or macOS)

### Compilation

Clone the repository and run `make` in the project root:

```bash
git clone https://github.com/hhonorio/ft_printf.git
cd ft_printf
make
```

This will compile `libft` as a dependency and generate the `libftprintf.a` static library.

### Available Makefile rules

| Rule | Description |
|---|---|
| `make` | Compiles libft and the printf library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` then `make` |

### Using ft_printf in your project

Copy `libftprintf.a` and `libftprintf.h` to your project, then compile with:

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

---

## Resources

### Documentation & References

- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c) — comprehensive reference for standard C functions including `printf`
- [printf man page — man7.org](https://man7.org/linux/man-pages/man3/printf.3.html) — official manual for the original `printf` behavior
- [Variadic Functions in C — GNU libc manual](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html) — explains `va_list`, `va_start`, `va_arg`, and `va_end`
- [42 Docs — ft_printf subject](https://github.com/42School/norminette) — project subject and Norminette rules

### AI Usage

**Claude (Anthropic)** was used during the development of this project for the following purposes:

- **Conceptual clarification** — understanding how `va_list` works, how `va_arg` extracts arguments by type, and the difference between `%d`/`%i` vs `%u`
- **Debugging assistance** — identifying edge cases such as NULL pointer handling in `%s` and correct byte counting across all specifiers
- **README writing** — structuring and writing this documentation file

> AI was used exclusively as a learning and support tool. All code was written and understood by the author.

## License

This project is part of the 42 curriculum and intended for educational use.
