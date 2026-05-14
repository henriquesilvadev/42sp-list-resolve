# C-04 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-04** da Piscina de C da 42. O foco desta lista é a manipulação de **números inteiros**, conversão de bases numéricas e operações com strings para representação de dados numéricos.

## Resumo dos Exercícios

### ex00: ft_strlen (`ft_strlen.c`)
Escreve uma função que conta e retorna o número de caracteres de uma string.
- **Função:** `int ft_strlen(char *str)`
- **Lógica:** Loop incrementando contador até encontrar o terminador nulo `\0`.

### ex01: ft_putstr (`ft_putstr.c`)
Escreve uma função que exibe uma string na saída padrão.
- **Função:** `void ft_putstr(char *str)`
- **Lógica:** Loop `while (*str)` usando `write(1, &c, 1)` para escrever cada caractere.

### ex02: ft_putnbr (`ft_putnbr.c`)
Escreve uma função que exibe um número inteiro na saída padrão.
- **Função:** `void ft_putnbr(int nb)`
- **Lógica:** Tratar o caso negativo separadamente, converter dígitos para caracteres e exibir recursivamente ou iterativamente.

### ex03: ft_atoi (`ft_atoi.c`)
Reproduz o comportamento da função `atoi` (man atoi). Converte uma string em número inteiro.
- **Função:** `int ft_atoi(char *str)`
- **Lógica:** Pular espaços e sinais (`+/-`), então iterar caracteres numéricos multiplicando o resultado por 10 e adicionando o dígito. Aplicar o sinal ao final.

### ex04: ft_putnbr_base (`ft_putnbr_base.c`)
Escreve uma função que exibe um número inteiro em uma base numérica especificada.
- **Função:** `void ft_putnbr_base(int nbr, char *base)`
- **Lógica:** Converter o número para a base fornecida usando divisão sucessiva (nbr % strlen(base)) e recursão ou iteração para exibir.

### ex05: ft_atoi_base (`ft_atoi_base.c`)
Escreve uma função que converte uma string representada em uma base numérica para um número inteiro em base 10.
- **Função:** `int ft_atoi_base(char *str, char *base)`
- **Lógica:** Para cada caractere em `str`, encontrar seu índice em `base` e acumular o valor: `resultado = resultado * strlen(base) + índice`. Tratar sinal negativo.

## Conceitos Aprendidos
- **Conversão de String para Inteiro**: Análise de dígitos e armazenamento de valores.
- **Conversão de Inteiro para String**: Decomposição de números em dígitos.
- **Bases Numéricas**: Compreensão de sistemas decimais, hexadecimais, binários, etc.
- **Aritmética Modular**: Uso de operador `%` para extrair dígitos em diferentes bases.
- **Strings e Números**: Relação entre representação textual e valores numéricos.
- **Tratamento de Sinais**: Manipulação correta de números negativos em conversões.

