# Libft
![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

<p align="left">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge" />
</p>

This project recreates some functions from the C standard library using only custom implementations. The main idea is to understand how basic functions work under the hood: character comparison, string traversal, pointers, returning addresses, and organizing code into a static library.

## Description

**libft** is the very first project of the 42 curriculum. The goal is to recreate a set of standard C library functions from scratch, as well as implement additional utility functions that will be reused throughout future projects.

By building this library, students gain a deep understanding of how fundamental C functions work under the hood — from memory manipulation and string handling to linked list operations. The result is a personal `.a` static library that serves as a foundation for all subsequent 42 projects.

### Functions implemented

**Libc functions** (reimplemented with `ft_` prefix):

| Function | Description |
|---|---|
| `ft_isalpha` | Checks if character is alphabetic |
| `ft_isdigit` | Checks if character is a digit |
| `ft_isalnum` | Checks if character is alphanumeric |
| `ft_isascii` | Checks if character is ASCII |
| `ft_isprint` | Checks if character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out a block of memory |
| `ft_memcpy` | Copies memory area |
| `ft_memmove` | Copies memory area (handles overlap) |
| `ft_strlcpy` | Copies string with size limit |
| `ft_strlcat` | Concatenates string with size limit |
| `ft_toupper` | Converts character to uppercase |
| `ft_tolower` | Converts character to lowercase |
| `ft_strchr` | Locates first occurrence of char in string |
| `ft_strrchr` | Locates last occurrence of char in string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_memchr` | Scans memory for a character |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Locates a substring in a string |
| `ft_atoi` | Converts string to integer |
| `ft_calloc` | Allocates and zeroes memory |
| `ft_strdup` | Duplicates a string |

**Additional functions:**

| Function | Description |
|---|---|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Joins two strings into a new one |
| `ft_strtrim` | Trims characters from start and end of string |
| `ft_split` | Splits a string by a delimiter |
| `ft_itoa` | Converts integer to string |
| `ft_strmapi` | Creates new string by applying function to each char |
| `ft_striteri` | Applies function to each char of a string in-place |
| `ft_putchar_fd` | Outputs a character to a file descriptor |
| `ft_putstr_fd` | Outputs a string to a file descriptor |
| `ft_putendl_fd` | Outputs a string followed by newline to fd |
| `ft_putnbr_fd` | Outputs an integer to a file descriptor |

**Bonus — Linked list functions:**

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds node at the beginning of the list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds node at the end of the list |
| `ft_lstdelone` | Deletes a single node |
| `ft_lstclear` | Deletes and frees the entire list |
| `ft_lstiter` | Iterates over the list applying a function |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Instructions

### Requirements

- `gcc` compiler
- `make`
- Unix-based OS (Linux or macOS)

### Compilation

Clone the repository and run `make` in the project root:

```bash
git clone https://github.com/hhonorio/libft.git
cd libft
make
```

This will generate the `libft.a` static library file.


### Available Makefile rules

| Rule | Description |
|---|---|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `make` |

### Using libft in your project

Copy `libft.a` and `libft.h` to your project, then compile with:

```bash
gcc your_file.c -L. -lft -o your_program
```

---

## Resources

### Documentation & References

- [C Standard Library Reference — cppreference.com](https://en.cppreference.com/w/c) — comprehensive reference for all standard C functions
- [The C Programming Language — Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) — the classic book for understanding C fundamentals
- [man pages online](https://man7.org/linux/man-pages/) — official manual pages for each function reimplemented
- [42 Docs — libft subject](https://github.com/42School/norminette) — project subject and Norminette rules

### AI Usage

**Claude (Anthropic)** was used during the development of this project for the following purposes:

- **Conceptual clarification** — understanding the difference between functions such as `strlcat` vs `strcat`, `memmove` vs `memcpy`, and `strmapi` vs `striteri`
- **Debugging assistance** — identifying edge cases (e.g., handling `\0` in `strchr`, null checks in `substr`)
- **README writing** — structuring and writing this documentation file

> AI was used exclusively as a learning and support tool. All code was written and understood by the author.

## License

This project is part of the 42 curriculum and intended for educational use.