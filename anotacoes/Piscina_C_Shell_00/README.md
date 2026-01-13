# 42sp-list-resolve — Anotações e Explicações dos Comandos

Este repositório contém **apenas anotações e resoluções das listas de exercícios**, com foco em **listagem de arquivos, permissões Unix e sistema de arquivos**, no contexto da **42 São Paulo**.

Os scripts criados **não editam a saída do `ls -l`**.  
Eles manipulam os **metadados reais do sistema de arquivos** para que a saída exibida corresponda exatamente ao formato exigido nos exercícios.

Este README documenta **todos os comandos utilizados**, explicando o motivo e o efeito de cada um.

---

## ⚠️ Observação Fundamental

O comando `ls -l` apenas **mostra informações reais do filesystem**:

- tipo do arquivo
- permissões
- número de links
- dono e grupo
- tamanho em bytes
- data e hora

➡️ Portanto, **não existe “alterar a saída do ls” diretamente**.  
Tudo é feito alterando corretamente esses atributos.

---

## `ls`

### O que faz
Lista arquivos e exibe seus metadados.

### Uso
```bash
ls -l
ls -l test0 test1 test2 test3 test4 test5 test6
```

## `chmod`

### O que faz
Altera as permissões de arquivos e diretórios.

### Uso com modo octal
```bash
chmod 455 testShell00   # -r--r-xr-x
chmod 715 test0         # drwx--xr-x
chmod 714 test1         # -rwx--xr--
chmod 504 test2         # dr-x---r--
chmod 404 test3         # -r-----r--
chmod 641 test4         # -rw-r----x
```

### Tabela de referência rápida
| Valor | Permissão |
| :--- | :--- |
| 7 | rwx |
| 6 | rw- |
| 5 | r-x |
| 4 | r-- |
| 1 | --x |

## `touch`

### O que faz
Cria arquivos vazios ou altera data e hora (timestamp).

### Ajustar data e hora
```bash
touch -t 202606012347 test1
```
**Formato:** `YYYYMMDDhhmm`

### Em links simbólicos (macOS)
```bash
touch -h -t 202606012220 test6
```
Em links simbólicos, o comportamento pode variar conforme o sistema.

## `printf`

### O que faz
Cria arquivos com tamanho exato em bytes.
`echo` pode adicionar uma quebra de linha (`\n`). `printf` evita isso e garante precisão.

### Exemplos
```bash
printf "ABCD" > test1   # 4 bytes
printf "A"    > test3   # 1 byte
printf "AB"   > test4   # 2 bytes
```

## `mkdir`

### O que faz
Cria diretórios.
```bash
mkdir test0
mkdir -p test2
```
`-p` evita erro caso o diretório já exista.

## `ln`

### O que faz
Cria links.

### Link simbólico
```bash
ln -s test0 test6
```
**Resultado:** `test6 -> test0`

### Hard link (incrementa contador de links)
```bash
ln test3 .test3_link
```
Isso faz `ls -l test3` mostrar 2 links. Hard links não funcionam para diretórios.

## `rm`

### O que faz
Remove arquivos, links e diretórios.
```bash
rm -f test1 test3 test4 test5 test6 .test3_link
rm -rf test0 test2
```
**Flags usadas:**
- `-f`: força remoção
- `-r`: remove recursivamente

## `chown`

### O que faz
Altera dono e grupo de arquivos.
```bash
sudo chown XX:XX test1
```
Para links simbólicos:
```bash
sudo chown -h XX:XX test6
```
⚠️ Requer `sudo` e o usuário/grupo precisa existir no sistema.

## `id`

### O que faz
Exibe informações do usuário atual.
```bash
id -un   # usuário
id -gn   # grupo
```
Usado para definir valores padrão quando não se força `XX`.

## `date`

### O que faz
Obtém informações de data, usado para montar timestamps.
```bash
date +%Y
```
Retorna o ano atual.

---

## Bash / Shell — Recursos Utilizados

### Shebang
```bash
#!/usr/bin/env bash
```

### Modo seguro
```bash
set -euo pipefail
```
- `-e`: interrompe no primeiro erro
- `-u`: erro em variável não definida
- `pipefail`: falha se qualquer comando do pipeline falhar

### Variáveis
```bash
YEAR="$(date +%Y)"
FILE="test1"
```

### Condicionais
```bash
if [ -f "$FILE" ]; then
  ...
fi
```

---

## Limitações do Sistema

Alguns atributos não podem ser forçados completamente:
- Permissões de symlink (`lrwxrwxrwx`) são padrão do sistema.
- Dono/grupo exigem permissões de administrador.
- Timestamps de symlink variam conforme o OS.

---

## Fluxo Geral Usado nos Scripts

1. **Limpeza do ambiente:** `rm -rf test*`
2. **Criação da estrutura:**
   ```bash
   mkdir test0
   printf "ABCD" > test1
   ln -s test0 test6
   ```
3. **Ajuste de permissões:**
   ```bash
   chmod 715 test0
   chmod 714 test1
   ```
4. **Ajuste de datas:** `touch -t 202606012146 test1`
5. **Ajuste do número de links:** `ln test3 .test3_link`
6. **Validação final:** `ls -l`
