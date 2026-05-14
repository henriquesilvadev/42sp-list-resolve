# C-06 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-06** da Piscina de C da 42. O foco desta lista é trabalhar com **argumentos de linha de comando (argc/argv)** e manipulação de parâmetros passados ao programa.

## Resumo dos Exercícios

### ex00: ft_print_program_name (`ft_print_program_name.c`)
Escreve uma função que exibe o nome do programa (argv[0]) na saída padrão.
- **Função:** `int main(int argc, char **argv)`
- **Lógica:** Acessar `argv[0]` que contém o nome do programa e exibir com `ft_putstr` ou `write`. Adicionar uma quebra de linha ao final.

### ex01: ft_print_params (`ft_print_params.c`)
Escreve uma função que exibe todos os argumentos passados ao programa, um por linha.
- **Função:** `int main(int argc, char **argv)`
- **Lógica:** Iterar de `argv[1]` até `argv[argc - 1]`, exibindo cada argumento seguido de uma quebra de linha. Ignorar `argv[0]` (nome do programa).

### ex02: ft_rev_params (`ft_rev_params.c`)
Escreve uma função que exibe todos os argumentos passados ao programa em ordem reversa, um por linha.
- **Função:** `int main(int argc, char **argv)`
- **Lógica:** Iterar de `argv[argc - 1]` até `argv[1]` em ordem reversa, exibindo cada argumento com quebra de linha. Ignorar `argv[0]`.

### ex03: ft_sort_params (`ft_sort_params.c`)
Escreve uma função que exibe todos os argumentos passados ao programa em ordem alfabética (ordenados), um por linha.
- **Função:** `int main(int argc, char **argv)` com função auxiliar `void ft_sort_string_tab(char **tab, int size)`
- **Lógica:** Copiar ponteiros de `argv[1]` até `argv[argc - 1]` em um array, ordenar usando algoritmo de comparação (ex: Bubble Sort com `strcmp`), e exibir os argumentos ordenados.

## Conceitos Aprendidos
- **Argumentos de Linha de Comando**: Como acessar parâmetros passados ao executar o programa.
- **argc e argv**: 
  - `argc`: número de argumentos (incluindo o nome do programa).
  - `argv`: array de ponteiros para strings contendo os argumentos.
- **Manipulação de argv**: Iteração, acesso direto e modificação de argumentos.
- **Ordenação de Strings**: Uso de `strcmp` para comparação lexicográfica e algoritmos de sort.
- **Função main com parâmetros**: Sintaxe correta para receber argumentos da linha de comando.

