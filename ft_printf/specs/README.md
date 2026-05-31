# ft_printf Test Suite

Test suite for the [42 School](https://42.fr) **ft_printf** project — a custom reimplementation of the standard C `printf` function.

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

Each specifier gets its own test binary. On `make run`, every binary runs in sequence and the terminal prints a color-coded report: **green** for passing, **red** for failing.

---

## Test Structure

Each test file uses `capture.h` to redirect stdout via `dup`/`dup2`, capturing `ft_printf` output into a buffer for assertion. Both the output content and the return value are verified.

```c
#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST test_case_name(void)
{
    char buf[32];
    int  ret;

    capture_start();
    ret = ft_printf("%c", 'A');
    capture_end(buf, sizeof(buf));
    ASSERT_STR_EQ("A", buf);
    ASSERT_EQ(1, ret);
    PASS();
}

SUITE(suite_c)
{
    RUN_TEST(test_case_name);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite_c);
    GREATEST_MAIN_END();
}
```

---

## Coverage

9 format specifiers across mandatory requirements.

| Specifier | Description | Test File | Status |
|---|---|---|:---:|
| `%c` | Single character | `ft_printf_c_test.c` | ✅ |
| `%s` | String (handles NULL) | `ft_printf_s_test.c` | ✅ |
| `%p` | Pointer address | `ft_printf_p_test.c` | ✅ |
| `%d` | Signed decimal integer | `ft_printf_d_test.c` | ✅ |
| `%i` | Signed integer (base 10) | `ft_printf_i_test.c` | ✅ |
| `%u` | Unsigned decimal integer | `ft_printf_u_test.c` | ✅ |
| `%x` | Unsigned hex (lowercase) | `ft_printf_hex_test.c` | ✅ |
| `%X` | Unsigned hex (uppercase) | `ft_printf_hex_test.c` | ✅ |
| `%%` | Literal percent sign | `ft_printf_percent_test.c` | ✅ |

---

## Summary

| Section | Done | Total |
|---|:---:|:---:|
| Mandatory specifiers | 9 | 9 |
| **Total** | **9** | **9** |
