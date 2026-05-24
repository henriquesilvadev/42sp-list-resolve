# Libft Test Suite

Test suite for the [42 School](https://42.fr) **Libft** project — a C standard library reimplementation built from scratch.

---

## Testing Framework

This suite uses [**greatest**](https://github.com/silentbicycle/greatest) — a lightweight, single-header unit testing library for C.

| Property | Detail |
|---|---|
| Library | greatest v1.5.0 |
| Distribution | Single header (`greatest.h`) |
| Dependencies | None — pure C99 |
| License | ISC |

### Why greatest?

- Zero dependencies, zero setup — drop in one `.h` file and go
- Readable output with `PASS` / `FAIL` per test case
- Supports test suites, setup/teardown, and assertions with descriptive messages
- Works seamlessly with `gcc` and `make`

---

## Running the Tests

```bash
# Compile all tests
make

# Compile and run all tests
make run

# Clean binaries
make clean
```

Each function gets its own binary. On `make run`, every binary runs in sequence and the terminal prints a color-coded report: **green** for passing, **red** for failing.

---

## Test Structure

Each test file follows this pattern:

```c
#include "greatest.h"
#include "../libft.h"

TEST test_case_name(void)
{
    ASSERT_EQ(expected, ft_function(input));
    PASS();
}

SUITE(suite_function_name)
{
    RUN_TEST(test_case_name);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite_function_name);
    GREATEST_MAIN_END();
}
```

---

## Implementation Progress

43 functions total across mandatory (Part 1 + Part 2) and bonus (linked list).

### Part 1 — Libc Reimplementations (21 functions)

| Function | Prototype | Status |
|---|---|:---:|
| `ft_isalpha` | `int ft_isalpha(int c)` | ✅ |
| `ft_isdigit` | `int ft_isdigit(int c)` | ✅ |
| `ft_isalnum` | `int ft_isalnum(int c)` | ✅ |
| `ft_isascii` | `int ft_isascii(int c)` | ✅ |
| `ft_isprint` | `int ft_isprint(int c)` | ✅ |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | ✅ |
| `ft_memset` | `void *ft_memset(void *b, int c, size_t len)` | ✅ |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | ✅ |
| `ft_memcpy` | `void *ft_memcpy(void *dst, const void *src, size_t n)` | ✅ |
| `ft_memmove` | `void *ft_memmove(void *dst, const void *src, size_t len)` | ✅ |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | ✅ |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | ✅ |
| `ft_toupper` | `int ft_toupper(int c)` | ✅ |
| `ft_tolower` | `int ft_tolower(int c)` | ✅ |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | ✅ |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | ✅ |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | ✅ |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | ✅ |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | ⬜ |
| `ft_strnstr` | `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | ✅ |
| `ft_atoi` | `int ft_atoi(const char *str)` | ✅ |

### Part 2 — Additional Functions (13 functions)

| Function | Prototype | Status |
|---|---|:---:|
| `ft_calloc` | `void *ft_calloc(size_t count, size_t size)` | ✅ |
| `ft_strdup` | `char *ft_strdup(const char *s1)` | ✅ |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | ✅ |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | ✅ |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | ✅ |
| `ft_split` | `char **ft_split(char const *s, char c)` | ⬜ |
| `ft_itoa` | `char *ft_itoa(int n)` | ✅ |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | ⬜ |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | ⬜ |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | ⬜ |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | ⬜ |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | ⬜ |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | ⬜ |

### Bonus — Linked List (9 functions)

| Function | Prototype | Status |
|---|---|:---:|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | ⬜ |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | ⬜ |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | ⬜ |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | ⬜ |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | ⬜ |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | ⬜ |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | ⬜ |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | ⬜ |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | ⬜ |

---

## Summary

| Section | Done | Total |
|---|:---:|:---:|
| Part 1 — Libc | 18 | 21 |
| Part 2 — Additional | 8 | 13 |
| Bonus — Linked List | 0 | 9 |
| **Total** | **26** | **43** |
