#include <iostream>
#include <limits>

double somar(double a, double b){
  return a+b;
}

double subtrair(double a, double b){
  return a-b;
}

double multiplicar(double a, double b){
  return a*b;
}

bool dividir(double a, double b, double &resultado){
  if(b == 0){
    return false;
  }else{
    resultado = a/b;
    return true;
  }
}

void exibirMenu(){
  std::cout << "---- Menu da Calculadora ----" << "\n"
  << "1. Soma" << "\n" << "2. Subtrair" << "\n"
  << "3. Multiplicar" << "\n" "4. Dividir" << "\n"
  << "5. Sair" << std::endl;
}

double lerNumero() {
    double numero;
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

void lerDoisNumeros(double &a, double &b){
  std::cout << "Digite o primeiro numero: ";
  a = lerNumero();
  std::cout << "Digite o segundo numero: ";
  b = lerNumero();
}

int main(){
  double a = 0, b = 0;
  double resultado = 0;
  int escolha = 0;
  bool menu = true;

  while (menu)
  {
    exibirMenu();
    std::cout << "Escolha a opçao que deseja: ";
    escolha = lerNumero();

    switch (escolha)
    {
    case 1:
      lerDoisNumeros(a,b);
      std::cout << "O resultado da soma foi: " << somar(a, b) << std::endl;
      break;
    case 2:
      lerDoisNumeros(a,b);
      std::cout << "O resultado da subtração foi: " << subtrair(a, b) << std::endl;
      break;
    case 3:
      lerDoisNumeros(a,b);
      std::cout << "O resultado da multiplicação foi: " << multiplicar(a, b) << std::endl;
      break;
    case 4:
      lerDoisNumeros(a,b);
      if(dividir(a,b,resultado)){
        std::cout << "O resultado da divisão foi: " << resultado << std::endl;
      }else{
        std::cout << "Não é possivel dividir por zero" << std::endl;
      }
      break;
    case 5:
      std::cout << "Obrigado por utilizar a calculadora" << std::endl;
      menu = false;
      break;
    default:
      std::cout << "Opção invalida" << std::endl;
      break;
    }
  }
}