# 🏊‍♂️ 42 Piscina C - [42 São Paulo](https://www.42sp.org.br/)

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Shell-Bash-4EAA25?style=for-the-badge&logo=gnu-bash&logoColor=white" />
  <img src="https://img.shields.io/badge/Platform-Linux/macOS-000000?style=for-the-badge&logo=linux&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge" />
</p>

---

## 📝 Sobre o Projeto

Este repositório contém as minhas resoluções e anotações durante a **Piscina de C da 42 São Paulo**. A Piscina é um período intensivo de 26 dias focado em lógica de programação, desenvolvimento em C e Shell, e trabalho colaborativo.

> [!IMPORTANT]
> Todo o código aqui presente segue a **Norma v3** da 42, garantindo clareza, legibilidade e conformidade com os padrões da escola.

---

## 🛠️ Tecnologias e Ferramentas

- **Linguagem:** C (C99 compatível)
- **Scripting:** Shell (Bash/Zsh)
- **Compilador:** `cc` ou `gcc` com flags `-Wall -Wextra -Werror`
- **Linter:** Norminette (v3)
- **Editor:** Vim / VS Code

---

## 📊 Progresso dos Módulos

Abaixo está o status atual de cada lista de exercícios:

| Módulo | Descrição | Status |
| :--- | :--- | :---: |
| [Shell 00](https://github.com/henriquesilvadev/42sp-list-resolve/tree/main/anotacoes/Piscina_C_Shell_00) | Fundamentos de Shell e Git | ✅ Finalizado |
| [Shell 01](https://github.com/henriquesilvadev/42sp-list-resolve/tree/main/anotacoes/Piscina_C_Shell_01) | Comandos Avançados de Shell | ⏳ Em breve |
| **C 00** | Primeiros passos em C | ⏳ Em breve |
| **C 01** | Ponteiros e Memória | ⏳ Em breve |
| **C 02** | Manipulação de Strings | ⏳ Em breve |
| **C 03** | Funções de bibliotecas padrão | ⏳ Em breve |
| **C 04** | Conversão de tipos e Recursão | ⏳ Em breve |
| **C 05** | Algoritmos Matemáticos | ⏳ Em breve |

---

## 📏 A Norma

Na 42, escrevemos código que não apenas funciona, mas que é elegante. Algumas regras principais:
- Máximo de 25 linhas por função.
- Máximo de 5 funções por arquivo.
- Não usar `for`, `do...while`, `switch` ou `case`.
- Declaração de variáveis sempre no topo da função.

Para verificar a norma, execute:
```bash
norminette -R CheckForbiddenSourceHeader [arquivo.c]
```

---

## 🚀 Como Executar

Para compilar qualquer exercício, utilize o seguinte comando:

```bash
cc -Wall -Wextra -Werror [arquivo.c] -o [nome_do_executavel]
```

Exemplo:
```bash
cc -Wall -Wextra -Werror ft_putchar.c -o putchar
./putchar
```

---

<p align="center">
  Desenvolvido por <b>Henrique Honório</b> (hhonorio)<br>
  <a href="https://github.com/henriquehsilva">Github</a> • <a href="https://linkedin.com/in/henriquesilvadev">LinkedIn</a>
</p>
