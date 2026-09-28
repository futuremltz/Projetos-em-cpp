#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

int sortearNumero(int min, int max){
  int quantidade = max - min + 1;
  return rand() % quantidade + min;
}

void darDica(int chute, int alvo){
  if(chute > alvo){
    std::cout << "O numero e menor" << std::endl;
  }else if(chute < alvo){
    std::cout << "O numero e maior" << std::endl;
  }
}

int calcularLimite(int min, int max){
  int quantidade = max - min + 1;
  int limite = 0;
  int cobertos = 0;
  while (cobertos < quantidade) {
    cobertos = cobertos * 2 + 1;
    limite++;
  }
  return limite;
}

int lerNumero() {
    int numero;
    while (true) {
        std::cin >> numero;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida, tente de novo." << std::endl;
        } else {
            return numero;
        }
    }
}

int main(){
  srand(time(nullptr));
  int min = 0, max = 0, copia = 0, chute = 0;
  int resposta = 0;
  int tentativas = 0;
  int limite = 0;
  bool acertou = false;
  std::string comecar;

  std::cout << "---- Bem-Vindo ao jogo de adivinhação ---- " << "\n" << "Voce tem um limite de tentativas para acertar um numero que voce escolhe o range" << "\n" 
  << "Vamos começar? ";
  std::cin >> comecar;
  if(comecar == "s" || comecar == "S"){
    std::cout << "Qual valores voce deseja pra minimo e maximo? digite assim ex: A B : ";
    min = lerNumero();
    max = lerNumero();
    if(min > max){
      copia = min;
      min = max;
      max = copia;
    }
    resposta = sortearNumero(min , max);
    limite = calcularLimite(min, max);

    while(tentativas < limite && !acertou)
    {
      std::cout << "Tentativa numero " << tentativas+1 << " de " << limite << ": "; 
      chute = lerNumero();
      
      if (chute == resposta)
      {
        acertou = true;
      }else{
        darDica(chute, resposta);
      }
      tentativas++;
    }
    if(acertou){
      std::cout << "Parabens voce ganhou em: " << tentativas << " tentativas" << std::endl;
    }else{
      std::cout << "Voce perdeu o numero era: " << resposta << std::endl;
    }
  }else{
    std::cout << "Até mais" << std::endl;
  }
  
  return 0;
}