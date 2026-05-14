# Libft — Explicação Traduzida do Subject

## Introdução
O projeto **Libft** da 42 consiste em criar sua própria biblioteca em C (`libft.a`), implementando diversas funções básicas da linguagem e funções utilitárias que serão usadas em praticamente todos os projetos futuros.

A ideia principal é:
- Entender como funções da libc funcionam internamente.
- Aprender manipulação de memória.
- Trabalhar com strings.
- Aprender alocação dinâmica.
- Criar listas encadeadas.
- Melhorar lógica e organização em C.

---

# Regras Gerais

## O projeto deve:
- Ser escrito em **C**.
- Seguir a **Norminette**.
- Não causar:
  - segmentation fault
  - bus error
  - double free
- Liberar toda memória corretamente.
- Compilar com:
```bash
-Wall -Wextra -Werror
```

---

# Makefile Obrigatório

Seu Makefile deve conter:

```make
NAME
all
clean
fclean
re
```

E deve:
- usar `cc`
- usar `ar` para criar a biblioteca
- evitar relink desnecessário

---

# Estrutura Esperada

```bash
libft/
├── Makefile
├── libft.h
├── ft_strlen.c
├── ft_memcpy.c
├── ...
└── libft.a
```

---

# Parte 1 — Funções da Libc

Você deve recriar funções da libc com prefixo `ft_`.

Exemplo:
```c
strlen -> ft_strlen
```

---

# Funções Obrigatórias

## Funções de verificação de caracteres

### ft_isalpha
Verifica se o caractere é letra.

```c
ft_isalpha('A') -> 1
ft_isalpha('1') -> 0
```

### ft_isdigit
Verifica se é número.

### ft_isalnum
Verifica se é letra ou número.

### ft_isascii
Verifica se está na tabela ASCII.

### ft_isprint
Verifica se o caractere é imprimível.

---

# Manipulação de Strings

## ft_strlen
Conta o tamanho da string.

```c
"Hello" -> 5
```

## ft_strchr
Busca primeira ocorrência de um caractere.

## ft_strrchr
Busca última ocorrência.

## ft_strncmp
Compara duas strings.

## ft_strnstr
Procura substring dentro de string.

---

# Manipulação de Memória

## ft_memset
Preenche memória com um valor.

## ft_bzero
Zera memória.

## ft_memcpy
Copia memória.

⚠️ Não funciona com sobreposição.

## ft_memmove
Copia memória com segurança mesmo com overlap.

## ft_memchr
Busca byte na memória.

## ft_memcmp
Compara regiões de memória.

---

# Conversões

## ft_atoi
Converte string para inteiro.

```c
"42" -> 42
```

## ft_toupper
Converte para maiúsculo.

## ft_tolower
Converte para minúsculo.

---

# Funções com malloc

## ft_strdup
Duplica string usando malloc.

## ft_calloc
Aloca memória zerada.

⚠️ Regra importante:
Mesmo com:
```c
calloc(0, 0)
```

deve retornar um ponteiro válido para `free()`.

---

# Parte 2 — Funções Adicionais

## ft_substr

Cria substring.

```c
ft_substr("Hello", 1, 3)
-> "ell"
```

## ft_strjoin

Concatena duas strings.

```c
"Hello" + "World"
-> "HelloWorld"
```

## ft_strtrim

Remove caracteres do início e fim.

```c
ft_strtrim("  Hello  ", " ")
-> "Hello"
```

## ft_split

Divide string por delimitador.

```c
ft_split("a,b,c", ',')
```

Resultado:
```c
["a", "b", "c", NULL]
```

⚠️ Muito importante:
- Cada string deve ter malloc próprio.
- O array também precisa de malloc.
- Deve terminar com `NULL`.

## ft_itoa

Converte inteiro para string.

```c
42 -> "42"
-42 -> "-42"
```

## ft_strmapi

Aplica função em cada caractere e retorna nova string.

## ft_striteri

Percorre string modificando caracteres por referência.

---

# Funções de File Descriptor

## ft_putchar_fd

Escreve caractere.

```c
ft_putchar_fd('A', 1);
```

## ft_putstr_fd

Escreve string.

## ft_putendl_fd

Escreve string + quebra de linha.

## ft_putnbr_fd

Escreve número.

---

# Parte 3 — Linked List

Você implementará listas encadeadas.

## Estrutura Obrigatória

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

## Conceitos

### content
Armazena qualquer dado.

### next
Aponta para próximo nó.

---

# Funções de Lista

## ft_lstnew
Cria novo nó.

## ft_lstadd_front
Adiciona no começo.

## ft_lstsize
Conta quantidade de nós.

## ft_lstlast
Retorna último nó.

## ft_lstadd_back
Adiciona no final.

## ft_lstdelone
Libera um único nó.

⚠️ Não deve liberar o próximo.

## ft_lstclear
Libera lista inteira.

## ft_lstiter
Percorre lista aplicando função.

## ft_lstmap
Cria nova lista transformada.

Muito importante:
- Se malloc falhar:
  - liberar tudo corretamente.

---

# Regras Importantes da 42

## Proibido:
- Variáveis globais
- Vazamento de memória
- Arquivos desnecessários
- Funções fora da Norm

---

# Sobre IA (Artificial Intelligence)

A 42 deixa claro:

✅ IA pode ajudar no aprendizado.

❌ Não pode substituir seu raciocínio.

A escola valoriza:
- resolução de problemas
- tentativa e erro
- peer learning
- construção de lógica

---

# README Obrigatório

Seu repositório precisa conter:

```bash
README.md
```

Com:
- descrição do projeto
- instruções de compilação
- recursos utilizados
- explicação do uso de IA
- descrição da biblioteca

---

# Compilação Esperada

## Criar biblioteca

```bash
make
```

## Limpar objetos

```bash
make clean
```

## Limpar tudo

```bash
make fclean
```

## Recompilar

```bash
make re
```

---

# Dicas para passar na Libft

## Ordem recomendada

### Primeiro:
- ft_strlen
- ft_strdup
- ft_memcpy
- ft_strncmp

### Depois:
- ft_split
- ft_substr
- ft_itoa

### Por último:
- linked list

---

# Funções Mais Difíceis

## ft_split
Porque envolve:
- malloc múltiplo
- contagem de palavras
- free em caso de erro

## ft_itoa
Por causa do:
```c
INT_MIN
```

## ft_lstmap
Porque exige:
- nova lista
- controle de erros
- limpeza completa em falha

---

# Conclusão

A Libft é um dos projetos mais importantes da 42 porque:
- cria sua base em C
- ensina memória
- ensina ponteiros
- ensina organização
- será usada em quase todos os próximos projetos
