# C-02 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-02** da Piscina de C da 42. O foco desta lista é a manipulação de **strings**, validação de caracteres e operações com memória.

## Resumo dos Exercícios

### ex00: ft_strcpy (`ft_strcpy.c`)
Reproduz o comportamento da função `strcpy` (man strcpy). Copia a string `src` para `dest` (incluindo o `\0`).
- **Função:** `char *ft_strcpy(char *dest, char *src)`
- **Lógica:** Copiar caractere a caractere `dest[i] = src[i]` até encontrar `\0`. Retorna `dest`.

### ex01: ft_strncpy (`ft_strncpy.c`)
Reproduz o comportamento da função `strncpy` (man strncpy). Copia no máximo `n` caracteres de `src` para `dest`.
- **Função:** `char *ft_strncpy(char *dest, char *src, unsigned int n)`
- **Lógica:** Copiar até `n` ocorrer ou `src` acabar. Se `src` for menor que `n`, preencher o restante de `dest` com `\0`.

### ex02: ft_str_is_alpha (`ft_str_is_alpha.c`)
Verifica se a string contém apenas caracteres alfabéticos.
- **Função:** `int ft_str_is_alpha(char *str)`
- **Lógica:** Retorna 1 se `str` for vazia ou só tiver letras. Retorna 0 se encontrar algo fora de `[A-Za-z]`.

### ex03: ft_str_is_numeric (`ft_str_is_numeric.c`)
Verifica se a string contém apenas dígitos numéricos.
- **Função:** `int ft_str_is_numeric(char *str)`
- **Lógica:** Retorna 1 se `str` vazia ou só dígitos `[0-9]`. Caso contrário, 0.

### ex04: ft_str_is_lowercase (`ft_str_is_lowercase.c`)
Verifica se a string contém apenas letras minúsculas.
- **Função:** `int ft_str_is_lowercase(char *str)`
- **Lógica:** Checa se caracteres estão no intervalo `[a-z]`.

### ex05: ft_str_is_uppercase (`ft_str_is_uppercase.c`)
Verifica se a string contém apenas letras maiúsculas.
- **Função:** `int ft_str_is_uppercase(char *str)`
- **Lógica:** Checa se caracteres estão no intervalo `[A-Z]`.

### ex06: ft_str_is_printable (`ft_str_is_printable.c`)
Verifica se a string contém apenas caracteres imprimíveis.
- **Função:** `int ft_str_is_printable(char *str)`
- **Lógica:** Caracteres imprimíveis estão entre ASCII 32 (espaço) e 126 (~).

### ex07: ft_strupcase (`ft_strupcase.c`)
Transforma todas as letras minúsculas da string em maiúsculas.
- **Função:** `char *ft_strupcase(char *str)`
- **Lógica:** Se `str[i]` estiver entre `a` e `z`, subtrair 32 para obter a maiúscula.

### ex08: ft_strlowcase (`ft_strlowcase.c`)
Transforma todas as letras maiúsculas da string em minúsculas.
- **Função:** `char *ft_strlowcase(char *str)`
- **Lógica:** Se `str[i]` estiver entre `A` e `Z`, somar 32.

### ex09: ft_strcapitalize (`ft_strcapitalize.c`)
Capitaliza a primeira letra de cada palavra e deixa o resto em minúsculo.
- **Função:** `char *ft_strcapitalize(char *str)`
- **Lógica:** "Palavras" são delimitadas por não-alfanuméricos. Detectar início de palavra e ajustar case.

### ex10: ft_strlcpy (`ft_strlcpy.c`)
Reproduz o comportamento de `strlcpy` (man strlcpy). Copia string de forma mais segura, garantindo terminação nula, e retorna o tamanho da fonte.
- **Função:** `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`
- **Lógica:** Copiar `src` para `dest` até `dstsize - 1`. Retornar `strlen(src)`.

### ex11: ft_putstr_non_printable (`ft_putstr_non_printable.c`)
Exibe uma string trocando caracteres não imprimíveis por sua representação hexadecimal (ex: `\n` vira `\0a`).
- **Função:** `void ft_putstr_non_printable(char *str)`
- **Lógica:** Se char for não-imprimível, exibir `\` e o valor hex em 2 dígitos.

### ex12: ft_print_memory (`ft_print_memory.c`)
Exibe a memória em formato de hex dump (endereço, conteúdo em hex, conteúdo em char).
- **Função:** `void *ft_print_memory(void *addr, unsigned int size)`
- **Lógica:** Exibir endereço de 64 bits, seguido de 16 bytes em hex (agrupados ou espaçados), seguido pela representação ASCII (ponto para não-imprimíveis).

## Conceitos Aprendidos
- **Strings em C**: Arrays de `char` terminados por nulo `\0`.
- **ASCII**: Manipulação baseada em valores numéricos dos caracteres.
- **Aritmética de Ponteiros e Arrays**: Percorrer strings eficientemente.
- **Hexadecimal**: Representação de dados binários/memória.
