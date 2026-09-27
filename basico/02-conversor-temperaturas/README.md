# 🌡️ Conversor de temperaturas
 
Conversor de terminal com menu interativo que converte temperaturas entre **Celsius**, **Fahrenheit** e **Kelvin**. O usuário escolhe a conversão, digita o valor e vê o resultado. O programa só termina quando a opção **Sair** é escolhida.
 
Segundo projeto do repositório, feito para praticar funções, tipos numéricos e validação de dados.
 
---
 
## ✨ Funcionalidades
 
- **Celsius → Fahrenheit**
- **Celsius → Kelvin**
- **Fahrenheit → Celsius**
- **Kelvin → Celsius**
- **Validação do zero absoluto**: o programa recusa temperaturas que resultariam em Kelvin negativo
- **Validação de entrada**: se o usuário digitar letras ou qualquer coisa que não seja número, o programa pede de novo
- Aviso de **opção inválida** no menu
- Menu em loop até o usuário escolher sair
---
 
## 📐 Fórmulas usadas
 
| Conversão | Fórmula |
|---|---|
| Celsius → Fahrenheit | `F = C × 9/5 + 32` |
| Celsius → Kelvin | `K = C + 273.15` |
| Fahrenheit → Celsius | `C = (F − 32) × 5/9` |
| Kelvin → Celsius | `C = K − 273.15` |
 
> **Zero absoluto:** 0 K (ou −273.15 °C) é a menor temperatura possível. Por isso não existe Kelvin negativo.
 
---
 
## 🖥️ Exemplo de uso
 
```
---- Menu conversor de temperatura ----
1. Celsius para Fahrenheit
2. Celsius para Kelvin
3. Fahrenheit para Celsius
4. Kelvin para Celsius
5. Sair
Escolha a opçao que deseja: 1
Digite a temperatura que deseja converter: 100
O resultado de celsius para fahrenheit foi: 212
---- Menu conversor de temperatura ----
...
Escolha a opçao que deseja: 2
Digite a temperatura que deseja converter: -300
Não existe kelvin menor que zero
---- Menu conversor de temperatura ----
...
Escolha a opçao que deseja: 4
Digite a temperatura que deseja converter: 300
O resultado de kelvin para celsius foi: 26.85
```
 
---
 
## 🧩 Como o código está organizado
 
Cada conversão fica em uma função própria:
 
| Função | O que faz |
|---|---|
| `celsiusParaFahrenheit` | recebe °C e retorna °F |
| `celsiusParaKelvin` | recebe °C e retorna K |
| `fahrenheitParaCelsius` | recebe °F e retorna °C |
| `kelvinParaCelsius` | recebe K e retorna °C |
| `kelvinValido` | retorna `true` se o valor em Kelvin é maior ou igual a zero |
| `exibirMenu` | mostra as opções na tela |
| `lerNumero` | lê um número e, se a entrada for inválida, limpa o erro do `cin` e pede de novo |
| `main` | controla o loop do menu com `while` + `switch` |
 
### Destaques
 
**Validação do zero absoluto nos dois sentidos:** a mesma função `kelvinValido` é usada em dois momentos diferentes.
 
- **Celsius → Kelvin:** primeiro converte e depois valida o **resultado**. Se o usuário digitar −300 °C, o resultado seria −26.85 K, que não existe.
- **Kelvin → Celsius:** valida a **entrada** antes de converter. Se o usuário digitar um Kelvin negativo, nem chega a fazer a conta.
```cpp
if (kelvinValido(numero)) {
    resultado = kelvinParaCelsius(numero);
    // mostra o resultado
} else {
    // avisa que não existe Kelvin negativo
}
```
 
**Cuidado com divisão inteira:** em `fahrenheitParaCelsius` a fórmula usa `5.0/9` em vez de `5/9`. Em C++, `5/9` entre dois inteiros dá **0**, e a conversão sempre retornaria zero. Com `5.0`, a conta é feita em ponto flutuante.
 
**Validação de entrada com `cin.fail()`:** quando o usuário digita algo que não é número, o `cin` entra em estado de erro. Então o programa:
1. limpa o erro com `std::cin.clear()`;
2. descarta o que foi digitado com `std::cin.ignore(...)`;
3. pede o número de novo.
---
 
## 📚 Conceitos praticados
 
- Funções com parâmetros e retorno
- Funções que retornam `bool` para validação
- Aritmética com `double` e o problema da divisão inteira
- `while` e `switch`
- Entrada e saída com `std::cin` / `std::cout`
- Tratamento de erros de entrada (`cin.fail`, `cin.clear`, `cin.ignore`)
---
 
## ▶️ Como compilar e executar
 
```bash
g++ main.cpp -o conversor
./conversor
```
 
> No Windows: `conversor.exe`
 
---
 
## 🚀 Próximas melhorias
 
- [ ] Conversões que faltam: **Fahrenheit ↔ Kelvin** e **Kelvin → Fahrenheit**
- [ ] Validar o zero absoluto também em **Fahrenheit → Celsius** (abaixo de −459.67 °F)
- [ ] Limitar o resultado a 2 casas decimais com `std::fixed` e `std::setprecision`
---
 
⬅️ [Voltar para a lista de projetos](../../README.md)