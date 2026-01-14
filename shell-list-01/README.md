# Shell-01 - Anotações e Comandos

Este repositório contém os exercícios da lista **Shell-01** da Piscina de C da 42. Abaixo estão as descrições de cada exercício e os comandos principais utilizados.

## Resumo dos Exercícios

### ex01: Lista de Grupos (`print_groups.sh`)
Exibe a lista de grupos aos quais o usuário definido na variável `FT_USER` pertence, separados por vírgula e sem espaços.
- **Comandos:** `groups`, `tr`, `id`
- **Comando Final:** `groups $FT_USER | tr ' ' ',' | tr -d '\n'`

### ex02: Procurar arquivos `.sh` (`find_sh.sh`)
Procura no diretório atual e subpastas por arquivos que terminam com `.sh` e exibe apenas seus nomes, sem o caminho e sem a extensão.
- **Comandos:** `find`, `basename`
- **Exemplo:** `find . -type f -name "*.sh" -exec basename {} .sh \;`

### ex03: Contagem de Arquivos (`count_files.sh`)
Conta o número total de arquivos regulares e diretórios no diretório atual e subpastas, incluindo o diretório atual.
- **Comandos:** `find`, `wc -l`
- **Exemplo:** `find . \( -type f -o -type d \) | wc -l`

### ex04: Endereço MAC (`MAC.sh`)
Exibe os endereços MAC (Ethernet) das interfaces de rede presentes na máquina.
- **Comandos:** `ifconfig`, `grep`, `awk`
- **Exemplo:** `ifconfig | grep ether | awk '{print $2}'`

### ex05: Marvin (Arquivo Especial)
Criação de um arquivo com um nome extremamente complexo contendo caracteres especiais e o conteúdo `42` (2 bytes, sem quebra de linha).
- **Nome do Arquivo:** `"\?$*'MaRViN'*$?\"`
- **Comando para criar:** `printf "42" > 'ex05/"\?$*'\''MaRViN'\''*$?\"'`

### ex06: Pular Linhas (`skip.sh`)
Exibe o resultado de `ls -l` pulando uma linha a cada duas, começando pela primeira linha (incluindo a linha de "total").
- **Comandos:** `ls -l`, `awk`
- **Comando Final:** `ls -l | awk 'NR % 2 == 1'`

### ex07: Transformação de Dados (`r_dwssap.sh`)
Script para processar logins do sistema, inverter strings e filtrar por intervalos definidos por variáveis de ambiente.
- **Comandos:** `cat`, `grep`, `awk`, `cut`, `rev`, `sort`, `paste`, `sed`
- **Lógica:** Remove comentários, seleciona uma linha a cada duas começando pela segunda, inverte logins, ordena inversamente, filtra pelo intervalo `FT_LINE1` a `FT_LINE2`, junta com `, ` e finaliza com `.`.
- **Comando Final:** Veja o arquivo `ex07/r_dwssap.sh` para a pipeline completa.

## Comandos Úteis Aprendidos
- `tr`: Traduz ou deleta caracteres (ex: `tr -d '\n'` para remover quebras de linha).
- `awk`: Utilizado para filtrar colunas (`$2`) ou linhas baseadas em condições (`NR % 2 == 0`).
- `rev`: Inverte os caracteres de cada linha.
- `paste`: Une linhas de arquivos ou da entrada padrão (ex: `paste -sd','` para unir com vírgulas).
- `sed`: Utilizado para substituições de texto (ex: `sed 's/,/, /g'`).
- `printf`: Mais preciso que `echo` para criar arquivos sem newline automática.
