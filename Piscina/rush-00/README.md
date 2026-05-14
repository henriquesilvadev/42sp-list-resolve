# rush.c — Desenho de Retângulo em C

Este arquivo implementa a função `rush`, responsável por desenhar um retângulo
utilizando caracteres ASCII, escrevendo a saída caractere por caractere através
da função `ft_putchar`.

O desenho respeita as seguintes regras:

- Cantos: `o`
- Bordas horizontais (topo e base): `-`
- Bordas verticais (laterais): `|`
- Interior do retângulo: espaço (` `)

---

## Visão Geral da Arquitetura

O código é dividido em **três funções principais**, cada uma com uma
responsabilidade clara:

1. `rush` — controla os loops de linhas e colunas
2. `bool_draw` — determina a posição atual (topo, base, esquerda, direita)
3. `print_shape` — decide qual caractere deve ser impresso

Essa separação melhora a **legibilidade**, **manutenção** e **entendimento da lógica**.

---

## Função `rush`

```c
void rush(int x, int y);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:32:04 by hhonorio          #+#    #+#             */
/*   Updated: 2026/01/17 12:06:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Declaração externa da função ft_putchar.
** Ela é responsável por imprimir um único caractere na saída padrão.
*/
extern void	ft_putchar(char c);

/*
** Protótipos das funções auxiliares:
** - bool_draw: calcula a posição atual no desenho
** - print_shape: decide qual caractere imprimir
*/
void	bool_draw(int x, int y, int row, int col);
void	print_shape(int is_top, int is_bottom, int is_left, int is_right);

/*
** Função principal do rush.
** Recebe a largura (x) e a altura (y) do retângulo.
** Percorre linha por linha e coluna por coluna.
*/
void	rush(int x, int y)
{
	int	row;
	int	col;

	row = 0;
	while (row < y)            /* percorre as linhas */
	{
		col = 0;
		while (col < x)        /* percorre as colunas */
		{
			/*
			** Para cada posição (row, col),
			** delega a decisão do caractere à função bool_draw.
			*/
			bool_draw(x, y, row, col);
			col++;
		}
		/*
		** Ao final de cada linha, imprime uma quebra de linha.
		*/
		ft_putchar('\n');
		row++;
	}
}

/*
** Função responsável por identificar a posição atual no retângulo.
** Define flags booleanas que indicam se o ponto atual está:
** - no topo
** - na base
** - à esquerda
** - à direita
*/
void	bool_draw(int x, int y, int row, int col)
{
	int	is_top;
	int	is_bottom;
	int	is_left;
	int	is_right;

	is_top = (row == 0);        /* primeira linha */
	is_bottom = (row == y - 1);/* última linha */
	is_left = (col == 0);       /* primeira coluna */
	is_right = (col == x - 1);  /* última coluna */

	/*
	** Envia as informações de posição para a função print_shape,
	** que decidirá qual caractere deve ser impresso.
	*/
	print_shape(is_top, is_bottom, is_left, is_right);
}

/*
** Função responsável por imprimir o caractere correto
** com base na posição atual.
**
** Regras:
** - Cantos: 'o'
** - Bordas horizontais: '-'
** - Bordas verticais: '|'
** - Interior: espaço
*/
void	print_shape(int is_top, int is_bottom, int is_left, int is_right)
{
	int	is_corner;

	/*
	** Um ponto é considerado canto se estiver:
	** - no topo ou na base
	** E
	** - na esquerda ou na direita
	*/
	is_corner = (is_top || is_bottom) && (is_left || is_right);

	if (is_corner)
		ft_putchar('o');
	else if (is_top || is_bottom)
		ft_putchar('-');
	else if (is_left || is_right)
		ft_putchar('|');
	else
		ft_putchar(' ');
}
