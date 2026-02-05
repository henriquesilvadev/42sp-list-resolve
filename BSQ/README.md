# BSQ - O Maior Quadrado

O projeto **BSQ** (Biggest Square) é o projeto final da Piscina de C da 42. O objetivo é encontrar o maior quadrado possível em um mapa retangular que contenha obstáculos, evitando-os e exibindo o resultado.

## Compilação e Uso

O projeto inclui um `Makefile` para facilitar a compilação.

### Como Compilar
Para gerar o executável `bsq`, utilize o comando:
```bash
make
```

### Como Executar
O programa pode ler mapas diretamente de arquivos ou da entrada padrão.

**Via arquivo:**
```bash
./bsq maps/example_map
```

**Múltiplos arquivos:**
```bash
./bsq maps/map1 maps/map2
```

**Via entrada padrão:**
```bash
cat maps/example_map | ./bsq
```

## Formato do Mapa

O mapa deve seguir uma estrutura específica na primeira linha:
- O número de linhas do mapa.
- Três caracteres especiais:
    1. **Vazio:** Caractere que representa espaço livre.
    2. **Obstáculo:** Caractere que representa um impedimento.
    3. **Cheio:** Caractere usado para marcar o maior quadrado encontrado.

**Exemplo de mapa (`example_map`):**
```text
9.ox
..................
....o.............
............o.....
........o.........
....o.............
..................
......o...........
..................
........o.........
```
Neste exemplo: `9` linhas, `.` (vazio), `o` (obstáculo), `x` (cheio).

## Conceitos Aprendidos

- **Algoritmo de Programação Dinâmica:** Utilização de uma matriz auxiliar para calcular o tamanho do maior quadrado em tempo linear O(n*m).
- **Gerenciamento de Memória:** Alocação dinâmica de matrizes e liberação correta para evitar memory leaks.
- **Manipulação de Arquivos e `read`:** Leitura eficiente de grandes volumes de dados e tratamento de erros de formato de mapa.
- **Parsing e Validação:** Garantia de que o mapa segue rigorosamente as regras do projeto (comprimento de linhas constante, caracteres válidos, etc).

## Comandos do Makefile
- `make`: Compila o projeto.
- `make clean`: Remove os arquivos objeto (`.o`).
- `make fclean`: Remove os arquivos objeto e o executável.
- `make re`: Executa `fclean` e `make` novamente.
