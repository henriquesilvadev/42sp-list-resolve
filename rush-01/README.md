# Rush-01 (Skyscrapers 4x4) - README

## Visao geral

Este projeto resolve o puzzle "Skyscrapers" 4x4 (Rush-01). O desafio:
preencher uma grade 4x4 com numeros de 1 a 4, sem repeticao por linha
ou coluna, respeitando 16 dicas de visibilidade (quantos predios sao
vistos de cada lado).

O programa recebe as 16 dicas em uma unica string (separadas por espaco)
e tenta montar uma solucao valida. Se nao houver solucao, imprime "Error".

## Como compilar e executar

```sh
cc -Wall -Wextra -Werror *.c -o rush-01
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

## Estrutura do algoritmo

- Parseia a entrada e valida se existem exatamente 16 numeros (1..4).
- Inicializa a grade 4x4 com zeros.
- Usa backtracking para preencher cada celula com valores 1..4.
- Ao final, valida todas as visibilidades das 16 dicas.
- Imprime a grade ou "Error".

## Codigo comentado (passo a passo)

### `main.c`

```c
#include <unistd.h>

int     parse_input(char *str, int views[16]);
void    init_grid(int grid[4][4]);
int     solve(int grid[4][4], int views[16], int pos);
void    print_grid(int grid[4][4]);
void    ft_putstr(char *str);

int main(int argc, char **argv)
{
    int grid[4][4];
    int views[16];

    // Espera exatamente 1 argumento com as 16 dicas.
    // Se o parse falhar, encerra com erro.
    if (argc != 2 || !parse_input(argv[1], views))
    {
        ft_putstr("Error\n");
        return (1);
    }

    // Preenche a grade com zeros (vazia).
    init_grid(grid);

    // Tenta resolver via backtracking.
    // Se nao houver solucao, retorna erro.
    if (!solve(grid, views, 0))
    {
        ft_putstr("Error\n");
        return (1);
    }

    // Imprime a grade final.
    print_grid(grid);
    return (0);
}
```

### `parse_input.c`

```c
int parse_input(char *str, int views[16])
{
    int i;
    int j;

    i = 0;
    j = 0;

    // Varre a string inteira.
    while (str[i])
    {
        // Aceita apenas numeros entre '1' e '4'.
        if (str[i] >= '1' && str[i] <= '4')
        {
            // Se ja existem 16 valores, falha.
            if (j >= 16)
                return (0);

            // Converte o caractere para inteiro.
            views[j++] = str[i] - '0';
        }
        // Permite apenas espaco como separador.
        else if (str[i] != ' ')
            return (0);

        i++;
    }

    // Entrada valida apenas se tiver exatamente 16 numeros.
    return (j == 16);
}
```

### `grid_init.c`

```c
void init_grid(int grid[4][4])
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        // Zera todas as colunas da linha atual.
        while (j < 4)
            grid[i][j++] = 0;
        i++;
    }
}
```

### `constraints.c`

```c
int is_valid(int grid[4][4], int row, int col, int num)
{
    int i;

    i = 0;

    // Verifica se o numero ja existe na linha ou coluna.
    while (i < 4)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return (0);
        i++;
    }

    return (1);
}
```

### `solver.c`

```c
int is_valid(int grid[4][4], int row, int col, int num);
int check_views(int grid[4][4], int views[16]);

int solve(int grid[4][4], int views[16], int pos)
{
    int row;
    int col;
    int num;

    // Se todas as 16 posicoes foram preenchidas,
    // valida as visibilidades.
    if (pos == 16)
        return (check_views(grid, views));

    // Converte o indice linear para linha/coluna.
    row = pos / 4;
    col = pos % 4;

    // Tenta numeros de 1 a 4.
    num = 1;
    while (num <= 4)
    {
        // Se nao viola repeticao, tenta fixar.
        if (is_valid(grid, row, col, num))
        {
            grid[row][col] = num;

            // Avanca para a proxima posicao.
            if (solve(grid, views, pos + 1))
                return (1);

            // Backtrack: desfaz a tentativa.
            grid[row][col] = 0;
        }
        num++;
    }

    // Nenhum numero funcionou aqui.
    return (0);
}
```

### `check_visibility.c`

```c
int check_line(int *line, int expected)
{
    int i;
    int max;
    int seen;

    i = 0;
    max = 0;
    seen = 0;

    // Conta quantos "predios" aparecem ao olhar a linha.
    // Um predio e visivel se for maior que todos anteriores.
    while (i < 4)
    {
        if (line[i] > max)
        {
            max = line[i];
            seen++;
        }
        i++;
    }

    return (seen == expected);
}

int check_views(int grid[4][4], int views[16])
{
    int i;
    int line[4];

    i = 0;

    // Primeiras 4 dicas: olhando de cima para baixo (colunas).
    // Proximas 4: olhando de baixo para cima (colunas invertidas).
    while (i < 4)
    {
        line[0] = grid[0][i];
        line[1] = grid[1][i];
        line[2] = grid[2][i];
        line[3] = grid[3][i];
        if (!check_line(line, views[i]))
            return (0);

        line[0] = grid[3][i];
        line[1] = grid[2][i];
        line[2] = grid[1][i];
        line[3] = grid[0][i];
        if (!check_line(line, views[i + 4]))
            return (0);
        i++;
    }

    i = 0;

    // Proximas 4 dicas: olhando da esquerda para a direita (linhas).
    // Ultimas 4: olhando da direita para a esquerda.
    while (i < 4)
    {
        if (!check_line(grid[i], views[i + 8]))
            return (0);

        line[0] = grid[i][3];
        line[1] = grid[i][2];
        line[2] = grid[i][1];
        line[3] = grid[i][0];
        if (!check_line(line, views[i + 12]))
            return (0);
        i++;
    }

    return (1);
}
```

### `print_grid.c`

```c
#include <unistd.h>

void ft_putchar(char c);

void print_grid(int grid[4][4])
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            // Converte inteiro para caractere numerico.
            ft_putchar(grid[i][j] + '0');
            if (j < 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}
```

### `utils.c`

```c
#include <unistd.h>

void ft_putchar(char c)
{
    // Escreve 1 caractere no stdout.
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    // Escreve a string caractere por caractere.
    while (*str)
        write(1, str++, 1);
}

int ft_isdigit(char c)
{
    // Retorna verdadeiro se for um digito ASCII.
    return (c >= '0' && c <= '9');
}

int ft_strlen(char *str)
{
    int len = 0;

    // Conta caracteres ate o terminador nulo.
    while (str[len])
        len++;
    return (len);
}
```
