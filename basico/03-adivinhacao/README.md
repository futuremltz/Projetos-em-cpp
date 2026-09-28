# 🎯 Jogo de adivinhação de números
 
Jogo de terminal em que o computador sorteia um número secreto e o jogador tenta adivinhá-lo. O próprio jogador escolhe o intervalo do sorteio, e o **número de tentativas é calculado automaticamente** a partir do tamanho desse intervalo. A cada chute errado, o jogo dá uma dica dizendo se o número é **maior** ou **menor**.
 
Terceiro projeto do repositório, feito para praticar números aleatórios, loops com condição de parada e um pouco de lógica de algoritmos.
 
---
 
## ✨ Funcionalidades
 
- O jogador **escolhe o intervalo** (mínimo e máximo) do número sorteado
- Se o mínimo for digitado maior que o máximo, o programa **inverte os valores** automaticamente
- **Limite de tentativas justo**: calculado de acordo com o tamanho do intervalo
- **Dicas** a cada erro: "maior" ou "menor"
- Contador de tentativas na tela (`Tentativa 2 de 7`)
- No final, mostra em quantas tentativas o jogador ganhou ou qual era o número, se ele perdeu
- **Validação de entrada**: se o jogador digitar letras ou qualquer coisa que não seja número, o programa pede de novo
---
 
## 🖥️ Exemplo de uso
 
**Vitória** (intervalo de 1 a 100 → 7 tentativas):
```
---- Bem-Vindo ao jogo de adivinhação ----
Voce tem um limite de tentativas para acertar um numero que voce escolhe o range
Vamos começar? s
Qual valores voce deseja pra minimo e maximo? digite assim ex: A B : 1 100
Tentativa numero 1 de 7: 50
O numero e menor
Tentativa numero 2 de 7: 25
O numero e maior
Tentativa numero 3 de 7: 37
Parabens voce ganhou em: 3 tentativas
```
 
**Derrota:**
```
...
Tentativa numero 7 de 7: 12
O numero e maior
Voce perdeu o numero era: 14
```
 
---
 
## 🧩 Como o código está organizado
 
| Função | O que faz |
|---|---|
| `sortearNumero` | recebe o mínimo e o máximo e retorna um número aleatório dentro desse intervalo (incluindo os dois extremos) |
| `darDica` | compara o chute com o número secreto e diz se o alvo é maior ou menor |
| `calcularLimite` | calcula quantas tentativas o jogador terá, com base no tamanho do intervalo |
| `lerNumero` | lê um inteiro e, se a entrada for inválida, limpa o erro do `cin` e pede de novo |
| `main` | cuida da introdução, lê o intervalo, sorteia o número e controla o loop de tentativas |
 
### Destaques
 
**Limite de tentativas baseado em busca binária:** a melhor estratégia nesse jogo é sempre chutar o **meio** do intervalo que ainda sobra. Cada dica elimina metade das possibilidades. O `calcularLimite` calcula exatamente quantos chutes essa estratégia precisa no pior caso:
 
```cpp
while (cobertos < quantidade) {
    cobertos = cobertos * 2 + 1;   // 1, 3, 7, 15, 31, 63, 127...
    limite++;
}
```
 
Com `k` tentativas, dá para garantir o acerto em até `2^k − 1` números. Então:
 
| Intervalo | Quantidade de números | Tentativas |
|---|---|---|
| 1 a 10 | 10 | 4 |
| 1 a 100 | 100 | 7 |
| 1 a 1000 | 1000 | 10 |
 
Resultado: quem joga com a estratégia certa **sempre consegue ganhar**, e quem chuta aleatoriamente corre o risco de perder.
 
**Sorteio dentro de um intervalo:** `rand()` retorna um número grande qualquer. Para trazê-lo para o intervalo `[min, max]`, o código faz:
 
```cpp
int quantidade = max - min + 1;       // quantos números existem no intervalo
return rand() % quantidade + min;     // resto da divisão (0 até quantidade-1) + deslocamento
```
 
Exemplo: com `min = 10` e `max = 20`, `quantidade` vale 11. Então `rand() % 11` vai de 0 a 10 e, somando 10, o resultado fica entre 10 e 20.
 
**Semente com o relógio:** `srand(time(nullptr))` usa o horário atual como ponto de partida do gerador. Sem essa linha, `rand()` sortearia sempre a mesma sequência de números a cada execução.
 
**Loop com duas condições de parada:** o jogo continua enquanto ainda restam tentativas **e** o jogador não acertou.
 
```cpp
while (tentativas < limite && !acertou) {
    // ...
}
```
 
Depois do loop, o valor de `acertou` decide se o jogador ganhou ou perdeu.
 
**Troca de valores com variável auxiliar:** se o jogador digitar `100 1`, o código guarda o mínimo em `copia`, faz a troca e o intervalo vira `1 100`.
 
---
 
## 📚 Conceitos praticados
 
- Números aleatórios com `rand()` e `srand()`
- Operador de resto (`%`) para limitar intervalos
- Ideia de **busca binária** e crescimento logarítmico
- `while` com condição composta (`&&`, `!`)
- Variáveis de controle (`bool acertou`, contador de tentativas)
- Troca de valores entre variáveis
- Comparação de `std::string`
- Tratamento de erros de entrada (`cin.fail`, `cin.clear`, `cin.ignore`)
---
 
## ▶️ Como compilar e executar
 
```bash
g++ main.cpp -o adivinhacao
./adivinhacao
```
 
> No Windows: `adivinhacao.exe`
 
---
 
## 🚀 Próximas melhorias
 
- [ ] Opção de **jogar de novo** sem reiniciar o programa
- [ ] Avisar quando o chute estiver **fora do intervalo** escolhido
- [ ] **Níveis de dificuldade**: o difícil poderia dar uma tentativa a menos que o limite calculado
- [ ] Trocar `rand()` pela biblioteca `<random>` (`std::mt19937` + `std::uniform_int_distribution`), que é a forma moderna de sortear números em C++
---
 
⬅️ [Voltar para a lista de projetos](../../README.md)
 