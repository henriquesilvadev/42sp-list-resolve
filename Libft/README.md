# Libft

Este projeto recria algumas funções da biblioteca padrão de C, usando apenas
implementações próprias. A ideia principal é entender como funções básicas
trabalham por baixo: comparação de caracteres, percorrimento de strings,
ponteiros, retorno de endereços e organização de código em biblioteca estática.

## Conceitos gerais aprendidos

- Uma string em C é um array de `char` finalizado por `\0`.
- Caracteres também podem ser comparados como números, usando seus códigos ASCII.
- Funções de verificação normalmente retornam um valor diferente de zero para
  verdadeiro e `0` para falso.
- Ponteiros permitem retornar a posição exata de um caractere dentro de uma
  string.
- `NULL` representa ausência de endereço válido.
- `unsigned char` ajuda a tratar corretamente valores recebidos como `int` em
  funções que trabalham com caracteres.
- O arquivo `libft.h` concentra os protótipos para que outras funções possam
  usar a biblioteca.
- O `Makefile` automatiza a compilação dos `.c`, a criação dos `.o` e a geração
  da biblioteca `libft.a`.

## Anotações por função

### `ft_strlen.c`

**Função:** `ft_strlen`

Conta quantos caracteres existem em uma string até encontrar o caractere nulo
`\0`.

**Conceito aprendido:**

- Percorrer uma string usando índice.
- Entender que `\0` marca o fim da string.
- Usar um contador para medir tamanho.

**Ponto de atenção:**

- A versão padrão de `strlen` retorna `size_t`. Esta implementação retorna
  `int`, o que funciona para exercícios simples, mas pode ser limitado para
  strings muito grandes.

### `ft_isupper.c`

**Função:** `ft_isupper`

Verifica se o caractere recebido está entre `'A'` e `'Z'`.

**Conceito aprendido:**

- Caracteres maiúsculos ocupam uma faixa contínua na tabela ASCII.
- Comparações com caracteres literais deixam o código mais legível do que usar
  números como `65` e `90`.

### `ft_islower.c`

**Função:** `ft_islower`

Verifica se o caractere recebido está entre `'a'` e `'z'`.

**Conceito aprendido:**

- Caracteres minúsculos também ocupam uma faixa contínua na tabela ASCII.
- É possível criar funções pequenas e reutilizáveis para compor outras funções.

### `ft_isalpha.c`

**Função:** `ft_isalpha`

Verifica se o caractere é uma letra, usando `ft_isupper` ou `ft_islower`.

**Conceito aprendido:**

- Reutilizar funções já criadas evita repetir lógica.
- O operador `||` representa "ou lógico": basta uma das condições ser verdadeira.
- Uma função pode ser construída combinando outras funções menores.

### `ft_isdigit.c`

**Função:** `ft_isdigit`

Deveria verificar se o caractere recebido representa um dígito entre `'0'` e
`'9'`.

**Conceito aprendido:**

- Dígitos também possuem uma faixa contínua na tabela ASCII.
- Existe diferença entre o número inteiro `0` e o caractere `'0'`.

**Ponto de atenção:**

- A implementação atual usa `c >= 0 && c <= 9`. Isso testa os valores numéricos
  de 0 a 9, não os caracteres `'0'` a `'9'`.
- Para seguir o comportamento esperado, a comparação deveria ser feita com
  `c >= '0' && c <= '9'`.

### `ft_isalnum.c`

**Função:** `ft_isalnum`

Verifica se o caractere é alfanumérico, ou seja, se é letra ou dígito.

**Conceito aprendido:**

- Uma função pode representar uma regra maior combinando regras menores.
- `ft_isalpha(c) || ft_isdigit(c)` expressa diretamente a ideia de "letra ou
  número".

**Ponto de atenção:**

- Como depende de `ft_isdigit`, qualquer erro em `ft_isdigit` também afeta
  `ft_isalnum`.

### `ft_isascii.c`

**Função:** `ft_isascii`

Verifica se o valor recebido está dentro da tabela ASCII padrão, entre `0` e
`127`.

**Conceito aprendido:**

- ASCII padrão usa valores de 0 a 127.
- Nem todo `int` recebido por uma função representa um caractere ASCII válido.

### `ft_isprint.c`

**Função:** `ft_isprint`

Verifica se o caractere é imprimível, ou seja, se está entre espaço (`32`) e
til (`126`) na tabela ASCII.

**Conceito aprendido:**

- Alguns caracteres ASCII são de controle e não aparecem visualmente na tela.
- Caracteres imprimíveis começam no espaço e vão até `~`.

### `ft_strchr.c`

**Função:** `ft_strchr`

Procura a primeira ocorrência de um caractere dentro de uma string e retorna um
ponteiro para essa posição.

**Conceito aprendido:**

- Percorrer uma string caractere por caractere.
- Comparar cada posição da string com o caractere procurado.
- Retornar o endereço de uma posição usando `&s[i]`.
- Fazer cast para retornar `char *` mesmo recebendo `const char *`.
- Retornar `NULL` quando o caractere não é encontrado.
- Converter `c` para `unsigned char` aproxima o comportamento da função padrão.

**Ponto de atenção:**

- A função padrão `strchr` também deve conseguir encontrar o caractere nulo
  `\0` no final da string.
- Na implementação atual, o `while (s[i])` para antes de testar o `\0`, então
  `ft_strchr(s, '\0')` retorna `NULL`.
- O bloco `if (s[i] == '\0') ;` não tem efeito prático, porque essa condição não
  será verdadeira dentro do `while (s[i])`.

### `ft_strrchr.c`

**Função:** `ft_strrchr`

Procura a última ocorrência de um caractere dentro de uma string e retorna um
ponteiro para essa posição.

**Conceito aprendido:**

- Guardar a última posição encontrada em uma variável auxiliar.
- Continuar percorrendo a string mesmo depois de encontrar uma ocorrência.
- Usar `NULL` como valor inicial para indicar que nada foi encontrado ainda.
- Retornar o último endereço salvo ao final do loop.

**Ponto de atenção:**

- A função padrão `strrchr` também deve retornar o endereço do `\0` quando o
  caractere buscado for `\0`.
- Na implementação atual, a verificação `if (uc == '\0')` está dentro do
  `while (s[i])`, então ela retorna o caractere atual antes de chegar ao
  terminador real da string. O ideal é tratar `\0` depois do loop ou percorrer
  até incluir o terminador.

## Como compilar

Use:

```sh
make
```

Isso gera a biblioteca estática:

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

- Conferir se cada função retorna o mesmo resultado da função padrão
  correspondente.
- Testar casos comuns e casos de borda, como string vazia e busca por `\0`.
- Comparar caracteres usando literais (`'0'`, `'A'`, `'a'`) quando isso deixar o
  código mais claro.
- Manter os protótipos atualizados em `libft.h`.
