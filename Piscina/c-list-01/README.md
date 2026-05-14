# C-01 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-01** da Piscina de C da 42. O foco desta lista é o uso de **ponteiros**, manipulação de endereços de memória e arrays básicos.

## Resumo dos Exercícios

### ex00: ft_ft (`ft_ft.c`)
Escreve uma função que recebe um ponteiro para um inteiro e atribui o valor `42` a esse inteiro.
- **Função:** `void ft_ft(int *nbr)`
- **Lógica:** Desreferenciar o ponteiro (`*nbr = 42`).

### ex01: ft_ultimate_ft (`ft_ultimate_ft.c`)
Escreve uma função que recebe um ponteiro para ponteiro... (9 níveis) para um inteiro e atribui o valor `42`.
- **Função:** `void ft_ultimate_ft(int *********nbr)`
- **Lógica:** Acessar os 9 níveis de indireção (`*********nbr = 42`).

### ex02: ft_swap (`ft_swap.c`)
Escreve uma função que troca o conteúdo de dois inteiros cujos endereços são passados como parâmetros.
- **Função:** `void ft_swap(int *a, int *b)`
- **Lógica:** Uso de variável temporária para troca.

### ex03: ft_div_mod (`ft_div_mod.c`)
Escreve uma função que divide dois parâmetros `a` e `b` e armazena o resultado no inteiro apontado por `div` e o resto no inteiro apontado por `mod`.
- **Função:** `void ft_div_mod(int a, int b, int *div, int *mod)`
- **Lógica:** Operadores `/` e `%`.

### ex04: ft_ultimate_div_mod (`ft_ultimate_div_mod.c`)
Escreve uma função que divide os inteiros apontados por `a` e `b`. O resultado da divisão é armazenado no ponteiro `a` e o resto no ponteiro `b`.
- **Função:** `void ft_ultimate_div_mod(int *a, int *b)`
- **Lógica:** Armazenar `*a` e `*b` antes de sobrescrevê-los.

### ex05: ft_putstr (`ft_putstr.c`)
Escreve uma função que exibe uma string na saída padrão.
- **Função:** `void ft_putstr(char *str)`
- **Lógica:** Loop `while (*str)` usando `write`.

### ex06: ft_strlen (`ft_strlen.c`)
Escreve uma função que conta e retorna o número de caracteres de uma string.
- **Função:** `int ft_strlen(char *str)`
- **Lógica:** Loop incrementando contador até o terminador nulo `\0`.

### ex07: ft_rev_int_tab (`ft_rev_int_tab.c`)
Escreve uma função que inverte a ordem dos elementos de um array de inteiros.
- **Função:** `void ft_rev_int_tab(int *tab, int size)`
- **Lógica:** Loop até `size / 2` trocando elementos.

### ex08: ft_sort_int_tab (`ft_sort_int_tab.c`)
Escreve uma função que ordena um array de inteiros em ordem crescente.
- **Função:** `void ft_sort_int_tab(int *tab, int size)`
- **Lógica:** Algoritmo de ordenação (ex: Bubble Sort).

## Conceitos Aprendidos
- **Ponteiros**: Variáveis que armazenam endereços de memória.
- **Desreferenciação (*)**: Acesso ao valor apontado pelo ponteiro.
- **Endereço (&)**: Operador para obter o endereço de uma variável.
- **Arrays**: Relação entre arrays e ponteiros.
- **Strings**: Arrays de caracteres terminados em nulo.
