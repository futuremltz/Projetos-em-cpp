# 🔧 Projetos em C++
 
Repositório com os projetos que estou desenvolvendo enquanto aprendo C++, do básico até orientação a objetos e estruturas de dados. Cada projeto fica em uma pasta própria, com código comentado e instruções para compilar.
 
![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Compilador](https://img.shields.io/badge/compilador-g%2B%2B-A42E2B?logo=gnu&logoColor=white)
![Editor](https://img.shields.io/badge/editor-VS%20Code-007ACC?logo=visualstudiocode&logoColor=white)
![Status](https://img.shields.io/badge/status-em%20andamento-yellow)
 
---
 
## 📋 Legenda de status
 
| Ícone | Significado |
|---|---|
| ⬜ | Não iniciado |
| 🔄 | Em andamento |
| ✅ | Concluído |
 
---
 
## 🟢 Nível básico
 
Foco em fundamentos: tipos, condicionais, loops, funções, arrays, `std::string` e entrada/saída.
 
| # | Projeto | Conceitos praticados | Status |
|---|---|---|---|
| 01 | [Calculadora simples](basico/01-calculadora-simples) | funções, `switch`/`if`, tratamento de divisão por zero | ✅ |
| 02 | [Conversor de temperaturas](basico/02-conversor-temperaturas) | tipos numéricos, funções, menu | ✅ |
| 03 | [Jogo de adivinhação de números](basico/03-adivinhacao) | números aleatórios, `while`, contagem de tentativas | ✅ |
| 04 | [Tabuada interativa](basico/04-tabuada) | loops aninhados, formatação de saída | ⬜ |
| 05 | [Verificador de números primos](basico/05-primos) | loops, otimização até √n, complexidade | ⬜ |
| 06 | [Calculadora de IMC](basico/06-imc) | `double`, faixas com `else if` | ⬜ |
| 07 | [Sistema de médias escolares](basico/07-medias-escolares) | arrays/`vector`, média, aprovação/reprovação | ⬜ |
| 08 | [Jogo da velha (texto)](basico/08-jogo-da-velha) | matriz 3×3, verificação de vitória, turnos | ⬜ |
| 09 | [Agenda de contatos](basico/09-agenda-contatos) | `struct`, `vector`, busca | ⬜ |
| 10 | [Conversor de unidades/moedas](basico/10-conversor-unidades) | `map`, menus, validação de entrada | ⬜ |
 
---
 
## 🟡 Nível intermediário
 
Foco em STL, orientação a objetos (classes em `.h`/`.cpp`), arquivos e algoritmos.
 
| # | Projeto | Conceitos praticados | Status |
|---|---|---|---|
| 11 | [Gerenciador de biblioteca](intermediario/11-biblioteca) | classes, `vector` de objetos, empréstimos | ⬜ |
| 12 | [Lista de tarefas com persistência](intermediario/12-lista-tarefas) | `fstream`, salvar/carregar em arquivo | ⬜ |
| 13 | [Jogo da forca](intermediario/13-forca) | `std::string`, `set` de letras usadas | ⬜ |
| 14 | [Simulador de banco](intermediario/14-simulador-banco) | classes, herança, polimorfismo *(documentação própria na pasta)* | 🔄 |
| 15 | [Parser de expressões matemáticas](intermediario/15-parser-expressoes) | pilha, precedência de operadores, recursão | ⬜ |
| 16 | [Controle de estoque](intermediario/16-controle-estoque) | classes, `map`, relatórios | ⬜ |
| 17 | [Labirinto em texto](intermediario/17-labirinto) | matriz, BFS/DFS, busca de caminho | ⬜ |
| 18 | [Estruturas de dados](intermediario/18-estruturas-de-dados) | lista ligada, pilha e fila com ponteiros brutos (`new`/`delete`) | ⬜ |
| 19 | [Cadastro de alunos com POO](intermediario/19-cadastro-alunos) | classes, encapsulamento, `.h`/`.cpp` | ⬜ |
| 20 | [Cifra de César / criptografia simples](intermediario/20-cifra-cesar) | manipulação de `char`, aritmética modular | ⬜ |
 
---
 
## 📁 Estrutura do repositório
 
```
Projetos-em-cpp/
├── basico/
│   ├── 01-calculadora-simples/
│   │   ├── main.cpp
│   │   └── README.md
│   └── ...
├── intermediario/
│   ├── 14-simulador-banco/
│   │   ├── main.cpp
│   │   ├── Conta.h
│   │   ├── Conta.cpp
│   │   └── README.md
│   └── ...
└── README.md
```
 
Projetos com classes seguem o padrão **`.h` (declaração) + `.cpp` (implementação) + `main.cpp`**.
 
---
 
## ▶️ Como compilar e executar
 
Pré-requisito: ter o **g++** instalado.
 
**Projeto de um arquivo só:**
```bash
cd basico/01-calculadora-simples
g++ main.cpp -o programa
./programa
```
 
**Projeto com vários arquivos** (liste todos os `.cpp`, nunca os `.h`):
```bash
cd intermediario/14-simulador-banco
g++ main.cpp Conta.cpp -o programa
./programa
```
 
> No Windows, execute com `programa.exe` em vez de `./programa`.
 
---
 
## 🎯 Objetivos
 
- Fixar os fundamentos de C++ na prática, um projeto por vez.
- Evoluir do código procedural para orientação a objetos.
- Entender gerenciamento de memória (ponteiros, stack vs heap) implementando estruturas de dados do zero.
- Manter todo o código comentado, explicando o que cada parte faz.
---
 
## 📈 Progresso
 
**Básico:** 3/10 · **Intermediário:** 0/10 (1 em andamento) · **Total:** 3/20
 
---
 
Feito por [futuremltz](https://github.com/futuremltz) 🚀
