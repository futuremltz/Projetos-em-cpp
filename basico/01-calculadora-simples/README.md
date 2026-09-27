# 🧮 Calculadora simples

Calculadora de terminal com menu interativo. O usuário escolhe uma operação, digita dois números e vê o resultado. O programa só termina quando a opção **Sair** é escolhida.

Primeiro projeto do repositório, feito para praticar os fundamentos de C++.

---

## ✨ Funcionalidades

- **Soma**, **subtração**, **multiplicação** e **divisão**
- Tratamento de **divisão por zero**, com uma mensagem em vez de travar o programa
- **Validação de entrada**: se o usuário digitar letras ou qualquer coisa que não seja número, o programa pede de novo
- Aviso de **opção inválida** no menu
- Menu em loop até o usuário escolher sair

---

## 🖥️ Exemplo de uso

```
---- Menu da Calculadora ----
1. Soma
2. Subtrair
3. Multiplicar
4. Dividir
5. Sair
Escolha a opçao que deseja: 4
Digite o primeiro numero: 10
Digite o segundo numero: 0
Não é possivel dividir por zero
---- Menu da Calculadora ----
...
Escolha a opçao que deseja: 1
Digite o primeiro numero: abc
Entrada inválida, tente de novo.
7
Digite o segundo numero: 3
O resultado da soma foi: 10
```

---

## 🧩 Como o código está organizado

Cada responsabilidade fica em uma função própria:

| Função | O que faz |
|---|---|
| `somar`, `subtrair`, `multiplicar` | recebem dois `double` e retornam o resultado |
| `dividir` | retorna `bool` dizendo se a divisão foi possível e entrega o resultado por **referência** (`double &resultado`) |
| `exibirMenu` | mostra as opções na tela |
| `lerNumero` | lê um número e, se a entrada for inválida, limpa o erro do `cin` e pede de novo |
| `lerDoisNumeros` | pede os dois operandos e os devolve por referência |
| `main` | controla o loop do menu com `while` + `switch` |

### Destaques

**Divisão segura com retorno `bool`:** quando o divisor é zero, a função não inventa um valor. Ela avisa se deu certo e só preenche o resultado quando a divisão é válida.

```cpp
if (dividir(a, b, resultado)) {
    // usa o resultado
} else {
    // avisa que não dá para dividir por zero
}
```

**Validação de entrada com `cin.fail()`:** quando o usuário digita algo que não é número, o `cin` entra em estado de erro. Então o programa:
1. limpa o erro com `std::cin.clear()`;
2. descarta o que foi digitado com `std::cin.ignore(...)`;
3. pede o número de novo.

---

## 📚 Conceitos praticados

- Funções (declaração, parâmetros e retorno)
- Passagem por referência (`&`)
- `while` e `switch`
- Tipos `double`, `int` e `bool`
- Entrada e saída com `std::cin` / `std::cout`
- Tratamento de erros de entrada (`cin.fail`, `cin.clear`, `cin.ignore`)

---

## ▶️ Como compilar e executar

```bash
g++ main.cpp -o calculadora
./calculadora
```

> No Windows: `calculadora.exe`

---

## 🚀 Próximas melhorias

- [ ] Operação de **potência**
- [ ] **Histórico de operações** usando classes e `std::vector`
- [ ] Separar em arquivos `.h` / `.cpp`

---

⬅️ [Voltar para a lista de projetos](../../README.md)