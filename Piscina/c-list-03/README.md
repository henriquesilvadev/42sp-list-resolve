# C-03 - Anotações e Comandos

Este repositório contém os exercícios da lista **C-03** da Piscina de C da 42. O foco desta lista é a manipulação avançada de **strings**, incluindo comparação, concatenação e busca de substrings.

## Resumo dos Exercícios

### ex00: ft_strcmp (`ft_strcmp.c`)
Reproduz o comportamento da função `strcmp` (man strcmp). Compara duas strings lexicograficamente.
- **Função:** `int ft_strcmp(char *s1, char *s2)`
- **Lógica:** Retorna 0 se as strings são iguais. Retorna um valor negativo se `s1 < s2` e positivo se `s1 > s2`. A comparação é feita caractere por caractere usando valores ASCII.

### ex01: ft_strncmp (`ft_strncmp.c`)
Reproduz o comportamento da função `strncmp` (man strncmp). Compara no máximo `n` caracteres de duas strings.
- **Função:** `int ft_strncmp(char *s1, char *s2, unsigned int n)`
- **Lógica:** Similar a `strcmp`, mas compara apenas os primeiros `n` caracteres. Se as strings forem diferentes antes de `n` caracteres serem processados, retorna imediatamente.

### ex02: ft_strcat (`ft_strcat.c`)
Reproduz o comportamento da função `strcat` (man strcat). Concatena a string `src` ao final de `dest`.
- **Função:** `char *ft_strcat(char *dest, char *src)`
- **Lógica:** Encontrar o terminador nulo de `dest`, copiar `src` a partir desse ponto, e adicionar novo terminador nulo. Retornar `dest`.

### ex03: ft_strncat (`ft_strncat.c`)
Reproduz o comportamento da função `strncat` (man strncat). Concatena no máximo `n` caracteres de `src` ao final de `dest`.
- **Função:** `char *ft_strncat(char *dest, char *src, unsigned int nb)`
- **Lógica:** Encontrar o terminador nulo de `dest`, copiar até `nb` caracteres de `src`, e adicionar novo terminador nulo. Retornar `dest`.

### ex04: ft_strstr (`ft_strstr.c`)
Reproduz o comportamento da função `strstr` (man strstr). Localiza a primeira ocorrência de uma substring em uma string.
- **Função:** `char *ft_strstr(char *str, char *to_find)`
- **Lógica:** Iterar através de `str` testando se cada posição começa com `to_find`. Retornar um ponteiro para a primeira ocorrência ou `NULL` se não encontrado.

### ex05: ft_strlcat (`ft_strlcat.c`)
Reproduz o comportamento da função `strlcat` (man strlcat). Concatena strings de forma segura, garantindo que o resultado não ultrapasse um tamanho máximo.
- **Função:** `unsigned int ft_strlcat(char *dest, char *src, unsigned int size)`
- **Lógica:** Encontrar o comprimento de `dest`, adicionar caracteres de `src` até atingir `size - 1` bytes totais, terminador nulo no final. Retornar o comprimento total que teria resultado (strlen(dest) + strlen(src)).

## Conceitos Aprendidos
- **Comparação de Strings**: Análise lexicográfica baseada em valores ASCII.
- **Concatenação Segura**: Garantir que operações de concatenação não causem buffer overflow.
- **Busca em Strings**: Encontrar substrings dentro de strings.
- **Manipulação de Ponteiros de Strings**: Navegar e modificar cadeias de caracteres.
- **Terminador Nulo (`\0`)**: Importância crítica para delimitar strings em C.

