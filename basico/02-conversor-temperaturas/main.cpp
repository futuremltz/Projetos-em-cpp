#include <iostream>
#include <limits>


double celsiusParaFahrenheit(double c){
  return c * 9/5 + 32;
}

double celsiusParaKelvin(double c){
  return  c + 273.15;
}

double fahrenheitParaCelsius(double f){
  return  (f - 32) * 5.0/9;
}

double kelvinParaCelsius(double k){
  return k - 273.15;

}

bool kelvinValido(double k){
  return k >= 0;
}

void exibirMenu(){
  std::cout << "---- Menu conversor de temperatura ----" << "\n"
  << "1. Celsius para Fahrenheit" << "\n" << "2. Celsius para Kelvin" << "\n"
  << "3. Fahrenheit para Celsius" << "\n" "4. Kelvin para Celsius" << "\n"
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

int main(){
  double resultado = 0;
  double numero = 0;
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
      std::cout << "Digite a temperatura que deseja converter: ";
      numero = lerNumero();
      resultado = celsiusParaFahrenheit(numero);
      std::cout << "O resultado de celsius para fahrenheit foi: " << resultado << std::endl;
      break;
    case 2:
      std::cout << "Digite a temperatura que deseja converter: ";
      numero = lerNumero();
      resultado = celsiusParaKelvin(numero);
      if (kelvinValido(resultado))
      {
        std::cout << "O resultado de celsius para kelvin foi: " <<  resultado << std::endl;
      }else{
        std::cout << "Não existe kelvin menor que zero" << std::endl;
      }
      break;
    case 3:
      std::cout << "Digite a temperatura que deseja converter: ";
      numero = lerNumero();
      resultado = fahrenheitParaCelsius(numero);
      std::cout << "O resultado de farenheit para celsius foi: " << resultado << std::endl;
      break;
    case 4:
      std::cout << "Digite a temperatura que deseja converter: ";
      numero = lerNumero();
      if(kelvinValido(numero)){
        resultado = kelvinParaCelsius(numero);
        std::cout << "O resultado de kelvin para celsius foi: " << resultado << std::endl;
      }else{
        std::cout << "Não é possivel com kelvin menor que zero" << std::endl;
      }
      break;
    case 5:
      std::cout << "Obrigado por utilizar o conversor de temperatura" << std::endl;
      menu = false;
      break;
    default:
      std::cout << "Opção invalida" << std::endl;
      break;
    }
  }
}
