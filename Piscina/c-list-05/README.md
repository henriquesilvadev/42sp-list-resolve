# C-05 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-05** da Piscina de C da 42. O foco desta lista é trabalhar com **recursão** e algoritmos matemáticos, incluindo fatoriais, potências, sequência de Fibonacci, raízes quadradas e números primos.

## Resumo dos Exercícios

### ex00: ft_iterative_factorial (`ft_iterative_factorial.c`)
Escreve uma função que retorna o fatorial de um número inteiro usando iteração.
- **Função:** `int ft_iterative_factorial(int nb)`
- **Lógica:** Multiplicar todos os números de 1 até `nb` em um loop. Retornar 1 para valores <= 1. Retornar 0 se `nb` for negativo ou maior que um limite (overflow).

### ex01: ft_recursive_factorial (`ft_recursive_factorial.c`)
Escreve uma função que retorna o fatorial de um número inteiro usando recursão.
- **Função:** `int ft_recursive_factorial(int nb)`
- **Lógica:** Caso base: se `nb <= 1`, retornar 1. Caso recursivo: retornar `nb * ft_recursive_factorial(nb - 1)`.

### ex02: ft_iterative_power (`ft_iterative_power.c`)
Escreve uma função que retorna o resultado de `base` elevada à potência `power` usando iteração.
- **Função:** `int ft_iterative_power(int nb, int power)`
- **Lógica:** Multiplicar `nb` por si mesmo `power` vezes em um loop. Retornar 1 se `power` for 0. Retornar 0 se `power` for negativo.

### ex03: ft_recursive_power (`ft_recursive_power.c`)
Escreve uma função que retorna o resultado de `base` elevada à potência `power` usando recursão.
- **Função:** `int ft_recursive_power(int nb, int power)`
- **Lógica:** Caso base: se `power == 0`, retornar 1. Caso recursivo: retornar `nb * ft_recursive_power(nb, power - 1)`.

### ex04: ft_fibonacci (`ft_fibonacci.c`)
Escreve uma função que retorna o elemento no índice `index` da sequência de Fibonacci.
- **Função:** `int ft_fibonacci(int index)`
- **Lógica:** Sequência de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, ... Usar recursão com `fib(n) = fib(n-1) + fib(n-2)`. Retornar -1 se `index` for negativo. (Otimização: considerar memoization para evitar recálculos).

### ex05: ft_sqrt (`ft_sqrt.c`)
Escreve uma função que retorna a raiz quadrada de um número inteiro.
- **Função:** `int ft_sqrt(int nb)`
- **Lógica:** Retornar a raiz quadrada inteira (sem decimais) se `nb` for um quadrado perfeito. Retornar 0 caso contrário. Usar busca binária ou iteração linear.

### ex06: ft_is_prime (`ft_is_prime.c`)
Escreve uma função que retorna 1 se o número for primo, 0 caso contrário.
- **Função:** `int ft_is_prime(int nb)`
- **Lógica:** Números primos são maiores que 1 e divisíveis apenas por 1 e por eles mesmos. Testar divisibilidade até raiz quadrada de `nb`.

### ex07: ft_find_next_prime (`ft_find_next_prime.c`)
Escreve uma função que retorna o próximo número primo maior ou igual ao número passado.
- **Função:** `int ft_find_next_prime(int nb)`
- **Lógica:** Começar de `nb` e testar cada número com `ft_is_prime` até encontrar um primo.

### ex08: ft_ten_queens_puzzle (`ft_ten_queens_puzzle.c`)
Escreve uma função que resolve o problema das 10 rainhas em um tabuleiro de xadrez 10x10.
- **Função:** `int ft_ten_queens_puzzle(void)`
- **Lógica:** Usar backtracking para posicionar 10 rainhas no tabuleiro de forma que nenhuma rainha ataque outra. Exibir todas as soluções válidas.

## Conceitos Aprendidos
- **Recursão**: Funções que chamam a si mesmas com casos base e casos recursivos.
- **Iteração vs Recursão**: Quando usar loops vs chamadas recursivas.
- **Algoritmos Matemáticos**: Fatoriais, potências, Fibonacci, raízes e primos.
- **Otimização**: Memoization, busca binária e técnicas para evitar cálculos redundantes.
- **Backtracking**: Exploração de espaço de soluções com retrocesso.

