# Rush-02 - README

## Visao geral

O Rush-02 implementa um **conversor de numeros para palavras** usando um
arquivo de dicionario. A entrada pode ser apenas o numero (usa o
`numbers.dict` padrao) ou o caminho do dicionario + numero

O programa:
- carrega o dicionario em memoria (`t_entry`),
- valida a entrada (somente inteiros, sem ponto/virgula),
- converte recursivamente o numero para palavras,
- imprime o resultado ou uma mensagem de erro.

Mensagens:
- `Error` para entrada invalida.
- `Dict Error` para falha de leitura/consulta do dicionario.

---

## Como compilar e executar

Dentro de `rush-02/ex00`:

```sh
make
./rush-02 42
./rush-02 numbers.pt.dict 1234567
```

Formato esperado:
- `./rush-02 <numero>`
- `./rush-02 <caminho_dict> <numero>`

---

## Estrutura do projeto

```
ex00/
  includes/
    dict.h         # structs e prototipos do dicionario
    library.h      # prototipos gerais e constantes
  src/
    main.c         # entrada do programa
    parser_dict.c  # leitura e parse do dicionario
    constraints.c  # validacoes e utilitarios
    converter.c    # logica de conversao numero -> texto
  utils/
    string_utils.c # funcoes de string
    memory_utils.c # alocacao e join
    special_utils.c# ft_strtok e zero-check
  numbers.dict     # dicionario padrao
```

---

## Fluxo principal (resumo do algoritmo)

1. **main.c** escolhe o dicionario (padrao ou informado).
2. **parser_dict.c** carrega o arquivo e separa `chave: valor`.
3. **constraints.c** valida o numero e orquestra a conversao.
4. **converter.c** resolve:
   - casos pequenos (0..99),
   - divisao por potencias de 10 (mil, milhao, etc),
   - concatenacao do resultado.

---

## Codigo comentado (passo a passo)

### `main.c`

```c
int main(int argc, char **argv)
{
    t_entry dict[MAX_ENTRIES];

    // 1 argumento: usa dicionario padrao
    if (argc == 2)
        ft_process_args(argv[1], FILE_PATH, dict);
    // 2 argumentos: dicionario custom + numero
    else if (argc == 3)
        ft_process_args(argv[2], argv[1], dict);
    else
        write(1, "Error\n", 6);
    return (0);
}
```

### `parser_dict.c`

```c
int ft_dict_load(t_entry *d, const char *pathfile)
{
    // Abre arquivo, le buffer inteiro e separa por '\n'
    // Cada linha vira um entry: "numero : texto"
    // Retorna quantidade de entradas validas
}

char *ft_dict_get(t_entry *d, int size, const char *key)
{
    // Procura a chave no vetor de entradas
    // Retorna o valor correspondente ou NULL
}
```

### `constraints.c`

```c
void ft_process_args(char *num, char *dict_path, t_entry *dict)
{
    int d_size = ft_dict_load(dict, dict_path);
    if (d_size < 0)
        return (write(1, "Dict Error\n", 11), (void)0);

    // Bloqueia numero com ponto ou virgula
    if (is_float(num))
        return (write(1, "Error\n", 6), (void)0);

    // Converte numero para palavras
    char *res = ft_convert_number(num, dict, d_size);
    if (!res)
        return (write(1, "Dict Error\n", 11), (void)0);

    write(1, res, ft_strlen(res));
    write(1, "\n", 1);
    free(res);
}
```

### `converter.c` (ideia central)

```c
char *ft_convert_number(char *nbr, t_entry *dict, int size)
{
    // Caso especial: "0"
    // Se for pequeno (<=2 digitos), usa dicionario direto
    // Caso contrario:
    // 1) divide em esquerda/direita por potencia de 10
    // 2) converte a parte esquerda + nome da potencia
    // 3) anexa a parte direita se nao for zero
}
```

---

## Observacoes importantes

- Limitacoes do dicionario:
  - `MAX_ENTRIES = 100`, `MAX_LEN = 256`, `BUFFER_SIZE = 1024`.
  - o parser carrega apenas o que cabe no buffer.
- O programa aceita **apenas inteiros** (sem sinal, ponto ou virgula).
- O join entre palavras sempre adiciona um espaco (`" "`).

---

## Dicas de teste rapido

```sh
./rush-02 0
./rush-02 10
./rush-02 42
./rush-02 1001
./rush-02 numbers.pt.dict 123456789
```
