*This project has been created as part of the 42 curriculum by Henrique (hhonorio).*

# get_next_line

## Description

`get_next_line` is a function that reads any file descriptor **one line at a time**. Each successive call returns the next line read from the descriptor, including the terminating newline character (`\n`) when present, until there is nothing left to read.

The challenge of the project is that the `read` system call has no notion of "lines" — it returns raw bytes in fixed-size chunks (`BUFFER_SIZE`). A single `read` may return half a line, several lines at once, or the end of one line glued to the start of the next. The function must therefore impose the concept of a *line* on top of this raw byte stream, while:

- reading the descriptor in chunks and accumulating them until a newline is found;
- preserving the leftover bytes (the start of the next line) **between calls**, without using global variables and without `lseek`;
- managing all dynamically allocated memory without leaks.

The goal is to build a deep, practical understanding of file descriptors, buffered reading, dynamic memory management, and static storage duration in C.

### Prototype

```c
char *get_next_line(int fd);
```

**Returns:** the next line (a newly allocated, null-terminated string), or `NULL` when there is nothing more to read or on error.

## How it works

State that must survive between calls is kept in a single `static char *` (the *stash*). The combination of `static` (which keeps the **pointer** alive across calls) and `malloc` (which keeps the **bytes** alive on the heap) provides persistence without globals.

A single call performs four steps:

1. **Read & accumulate** — repeatedly `read` into a buffer and concatenate it onto the stash until the stash contains a `\n`, or `read` reaches end-of-file, or returns an error.
2. **Extract the line** — copy everything up to and including the first `\n` (or the whole stash if EOF was reached without a `\n`).
3. **Update the stash** — keep only the remainder (the bytes after the `\n`) for the next call.
4. **Return the line.**

## Project structure

| File | Contents |
|------|----------|
| `get_next_line.c` | `get_next_line` and its static helpers (read loop, line extraction, remainder extraction) |
| `get_next_line_utils.c` | helper functions: `ft_strlen`, `ft_memcpy`, `ft_strjoin`, `ft_strchr` |
| `get_next_line.h` | header guard, default `BUFFER_SIZE`, system includes, and public prototypes |

## Instructions

### Compilation

`BUFFER_SIZE` is **not** hard-coded; it is supplied at compile time with the `-D` flag. The header provides a default value in case the flag is omitted.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c main.c -o gnl
```

`BUFFER_SIZE` can be set to any non-negative value (the function works the same way regardless — `1`, `42`, `9999`, etc.).

### Usage

Include the header and call `get_next_line` in a loop, **freeing each returned line**:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int   fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // the line already includes its '\n'
        free(line);         // the caller owns and frees each line
    }
    close(fd);
    return (0);
}
```

The function also works with standard input (`fd 0`).

### Edge cases handled

- Empty files (returns `NULL` immediately).
- A final line with no trailing `\n` (returned as-is; a `\n` is never invented).
- Files containing only newlines.
- Very small (`1`) and very large `BUFFER_SIZE` values.
- Invalid descriptors and read errors (returns `NULL`, no leaks).

## Resources

Classic references on the topics involved:

- `man 2 read`, `man 3 malloc`, `man 3 free` — the only allowed functions; the manuals describe their exact return values and behavior.
- Brian W. Kernighan & Dennis M. Ritchie, *The C Programming Language* (K&R) — pointers, strings, and I/O.
- The C standard on **static storage duration** (why a `static` local keeps its value between calls and is zero-initialized).
- General material on **Unix file descriptors** and buffered reading.
- [cppreference.com](https://en.cppreference.com/) — reference for the C standard library.

### Use of AI

An AI assistant (Anthropic's Claude) was used **strictly as a Socratic tutor and pair-programming partner — it did not write the source code.** All of the C code in this repository was written by the author. The AI was used for the following tasks:

- **Concept building:** understanding static storage duration, dynamic memory and the persistent-buffer (stash) mechanism, file descriptors, and the meaning of `read`'s return values (`> 0`, `0`, `-1`).
- **Algorithm reasoning:** working out the read/accumulate loop and its stopping conditions, and the split between the returned line and the leftover, through guided questions.
- **Debugging logic:** identifying classes of bugs as they appeared — use-after-free, memory leaks (freeing the old stash, freeing on error), uninitialized variables, a buffer overflow in the `read` size, off-by-one in line length, and pointer/`char` type confusions.
- **Architecture & norm:** deciding how to decompose the logic into helper functions to respect the 42 Norm (≤ 25 lines per function, ≤ 5 functions per file) and where ownership of the allocated memory should live.
- **Documentation:** producing study notes and this README.

The workflow was deliberately question-driven: the assistant explained *why* each decision mattered and pointed out flaws, while every line of the implementation was reasoned about and typed by the author.