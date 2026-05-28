# Libft
![42 São Paulo](https://img.shields.io/badge/42-São_Paulo-black?style=flat-square&logo=42)

<p align="left">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge" />
</p>

This project recreates some functions from the C standard library using only custom implementations. The main idea is to understand how basic functions work under the hood: character comparison, string traversal, pointers, returning addresses, and organizing code into a static library.

## General concepts learned

- A string in C is an array of `char` terminated by `\0`.
- Characters can also be compared as numbers using their ASCII codes.
- Verification functions normally return a non-zero value for true and `0` for false.
- Pointers allow returning the exact position of a character within a string.
- `NULL` represents the absence of a valid address.
- `unsigned char` helps correctly handle values received as `int` in functions that work with characters.
- The `libft.h` file concentrates the prototypes so that other functions can use the library.
- The `Makefile` automates the compilation of `.c` files, the creation of `.o` files, and the generation of the `libft.a` library.

## How to compile

Use:

```sh
make
```

This generates the static library:

```sh
libft.a
```

To remove object files:

```sh
make clean
```

To remove objects and library:

```sh
make fclean
```

To recompile from scratch:

```sh
make re
```

## Study checklist

- Check if each function returns the same result as the corresponding standard function.
- Test common cases and edge cases, such as empty string and searching for `\0`.
- Compare characters using literals (`'0'`, `'A'`, `'a'`) when it makes the code clearer.
- Keep prototypes updated in `libft.h`.

## License

This project is part of the 42 curriculu#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
m and intended for educational use.