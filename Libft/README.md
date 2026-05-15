# Libft

Este projeto recria algumas funcoes da biblioteca padrao de C, usando apenas
implementacoes proprias. A ideia principal e entender como funcoes basicas
trabalham por baixo: comparacao de caracteres, percorrimento de strings,
ponteiros, retorno de enderecos e organizacao de codigo em biblioteca estatica.

## Conceitos gerais aprendidos

- Uma string em C e um array de `char` finalizado por `'\0'`.
- Caracteres tambem podem ser comparados como numeros, usando seus codigos ASCII.
- Funcoes de verificacao normalmente retornam um valor diferente de zero para
  verdadeiro e `0` para falso.
- Ponteiros permitem retornar a posicao exata de um caractere dentro de uma
  string.
- `NULL` representa ausencia de endereco valido.
- `unsigned char` ajuda a tratar corretamente valores recebidos como `int` em
  funcoes que trabalham com caracteres.
- O arquivo `libft.h` concentra os prototipos para que outras funcoes possam
  usar a biblioteca.
- O `Makefile` automatiza a compilacao dos `.c`, a criacao dos `.o` e a geracao
  da biblioteca `libft.a`.

## Anotacoes por funcao

### `ft_strlen.c`

**Funcao:** `ft_strlen`

Conta quantos caracteres existem em uma string ate encontrar o caractere nulo
`'\0'`.

**Conceito aprendido:**

- Percorrer uma string usando indice.
- Entender que `'\0'` marca o fim da string.
- Usar um contador para medir tamanho.

**Ponto de atencao:**

- A versao padrao de `strlen` retorna `size_t`. Esta implementacao retorna
  `int`, o que funciona para exercicios simples, mas pode ser limitado para
  strings muito grandes.

### `ft_isupper.c`

**Funcao:** `ft_isupper`

Verifica se o caractere recebido esta entre `'A'` e `'Z'`.

**Conceito aprendido:**

- Caracteres maiusculos ocupam uma faixa continua na tabela ASCII.
- Comparacoes com caracteres literais deixam o codigo mais legivel do que usar
  numeros como `65` e `90`.

### `ft_islower.c`

**Funcao:** `ft_islower`

Verifica se o caractere recebido esta entre `'a'` e `'z'`.

**Conceito aprendido:**

- Caracteres minusculos tambem ocupam uma faixa continua na tabela ASCII.
- E possivel criar funcoes pequenas e reutilizaveis para compor outras funcoes.

### `ft_isalpha.c`

**Funcao:** `ft_isalpha`

Verifica se o caractere e uma letra, usando `ft_isupper` ou `ft_islower`.

**Conceito aprendido:**

- Reutilizar funcoes ja criadas evita repetir logica.
- O operador `||` representa "ou logico": basta uma das condicoes ser verdadeira.
- Uma funcao pode ser construida combinando outras funcoes menores.

### `ft_isdigit.c`

**Funcao:** `ft_isdigit`

Deveria verificar se o caractere recebido representa um digito entre `'0'` e
`'9'`.

**Conceito aprendido:**

- Digitos tambem possuem uma faixa continua na tabela ASCII.
- Existe diferenca entre o numero inteiro `0` e o caractere `'0'`.

**Ponto de atencao:**

- A implementacao atual usa `c >= 0 && c <= 9`. Isso testa os valores numericos
  de 0 a 9, nao os caracteres `'0'` a `'9'`.
- Para seguir o comportamento esperado, a comparacao deveria ser feita com
  `c >= '0' && c <= '9'`.

### `ft_isalnum.c`

**Funcao:** `ft_isalnum`

Verifica se o caractere e alfanumerico, ou seja, se e letra ou digito.

**Conceito aprendido:**

- Uma funcao pode representar uma regra maior combinando regras menores.
- `ft_isalpha(c) || ft_isdigit(c)` expressa diretamente a ideia de "letra ou
  numero".

**Ponto de atencao:**

- Como depende de `ft_isdigit`, qualquer erro em `ft_isdigit` tambem afeta
  `ft_isalnum`.

### `ft_isascii.c`

**Funcao:** `ft_isascii`

Verifica se o valor recebido esta dentro da tabela ASCII padrao, entre `0` e
`127`.

**Conceito aprendido:**

- ASCII padrao usa valores de 0 a 127.
- Nem todo `int` recebido por uma funcao representa um caractere ASCII valido.

### `ft_isprint.c`

**Funcao:** `ft_isprint`

Verifica se o caractere e imprimivel, ou seja, se esta entre espaco (`32`) e
til (`126`) na tabela ASCII.

**Conceito aprendido:**

- Alguns caracteres ASCII sao de controle e nao aparecem visualmente na tela.
- Caracteres imprimiveis comecam no espaco e vao ate `~`.

### `ft_strchr.c`

**Funcao:** `ft_strchr`

Procura a primeira ocorrencia de um caractere dentro de uma string e retorna um
ponteiro para essa posicao.

**Conceito aprendido:**

- Percorrer uma string caractere por caractere.
- Comparar cada posicao da string com o caractere procurado.
- Retornar o endereco de uma posicao usando `&s[i]`.
- Fazer cast para retornar `char *` mesmo recebendo `const char *`.
- Retornar `NULL` quando o caractere nao e encontrado.
- Converter `c` para `unsigned char` aproxima o comportamento da funcao padrao.

**Ponto de atencao:**

- A funcao padrao `strchr` tambem deve conseguir encontrar o caractere nulo
  `'\0'` no final da string.
- Na implementacao atual, o `while (s[i])` para antes de testar o `'\0'`, entao
  `ft_strchr(s, '\0')` retorna `NULL`.
- O bloco `if (s[i] == '\0') ;` nao tem efeito pratico, porque essa condicao nao
  sera verdadeira dentro do `while (s[i])`.

### `ft_strrchr.c`

**Funcao:** `ft_strrchr`

Procura a ultima ocorrencia de um caractere dentro de uma string e retorna um
ponteiro para essa posicao.

**Conceito aprendido:**

- Guardar a ultima posicao encontrada em uma variavel auxiliar.
- Continuar percorrendo a string mesmo depois de encontrar uma ocorrencia.
- Usar `NULL` como valor inicial para indicar que nada foi encontrado ainda.
- Retornar o ultimo endereco salvo ao final do loop.

**Ponto de atencao:**

- A funcao padrao `strrchr` tambem deve retornar o endereco do `'\0'` quando o
  caractere buscado for `'\0'`.
- Na implementacao atual, a verificacao `if (uc == '\0')` esta dentro do
  `while (s[i])`, entao ela retorna o caractere atual antes de chegar ao
  terminador real da string. O ideal e tratar `'\0'` depois do loop ou percorrer
  ate incluir o terminador.

## Como compilar

Use:

```sh
make
```

Isso gera a biblioteca estatica:

```sh
libft.a
```

Para remover os arquivos objeto:

```sh
make clean
```

Para remover os objetos e a biblioteca:

```sh
make fclean
```

Para recompilar do zero:

```sh
make re
```

## Checklist de estudo

- Conferir se cada funcao retorna o mesmo resultado da funcao padrao
  correspondente.
- Testar casos comuns e casos de borda, como string vazia e busca por `'\0'`.
- Comparar caracteres usando literais (`'0'`, `'A'`, `'a'`) quando isso deixar o
  codigo mais claro.
- Manter os prototipos atualizados em `libft.h`.
