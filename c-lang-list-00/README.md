# C-00 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-00** da Piscina de C da 42. O objetivo desta lista é introduzir os conceitos básicos da linguagem C, como a função `write`, variáveis e o laço `while`.

## Resumo dos Exercícios

### ex00: ft_putchar (`ft_putchar.c`)
Escreve uma função que exibe o caractere passado como parâmetro na saída padrão.
- **Função:** `void ft_putchar(char c)`
- **Conceito:** Uso da `write(1, &c, 1)`.

### ex01: ft_print_alphabet (`ft_print_alphabet.c`)
Escreve uma função que exibe o alfabeto em minúsculo numa única linha, em ordem crescente, começando pela letra 'a'.
- **Função:** `void ft_print_alphabet(void)`
- **Lógica:** Loop de 'a' (97) até 'z' (122).

### ex02: ft_print_reverse_alphabet (`ft_print_reverse_alphabet.c`)
Escreve uma função que exibe o alfabeto em minúsculo numa única linha, em ordem decrescente, começando pela letra 'z'.
- **Função:** `void ft_print_reverse_alphabet(void)`
- **Lógica:** Loop de 'z' (122) até 'a' (97).

### ex03: ft_print_numbers (`ft_print_numbers.c`)
Escreve uma função que exibe todos os dígitos numa única linha, em ordem crescente.
- **Função:** `void ft_print_numbers(void)`
- **Lógica:** Loop de '0' (48) até '9' (57).

### ex04: ft_is_negative (`ft_is_negative.c`)
Escreve uma função que exibe 'N' ou 'P' dependendo do sinal do inteiro passado como parâmetro. Se n for negativo, exibe 'N'. Se n for positivo ou nulo, exibe 'P'.
- **Função:** `void ft_is_negative(int n)`
- **Lógica:** Condicional `if (n < 0)`.

## Conceitos Aprendidos
- **write**: Syscall para escrever em descritores de arquivo (1 = stdout).
- **ASCII**: Representação numérica de caracteres.
- **Unistd.h**: Biblioteca necessária para usar a função `write`.
