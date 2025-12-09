#include <iostream>
#include <string>
#include <variant>
using val = std::variant<int, std::string>;

int main() {
  auto lang = "C++";
  for (int i = 1; i <= 5; i++) {
    std::cout << "i = " << i;
  }
  val v1 = 10;
  val v2 = "C++";

  // value se mueve
  // 
  // int arr[10];
  // auto x = arr; x es un int* CUIDADO AHI
  // decaimento de tipo con AUTO, cuidadoito
  // decltype es lo contrario a este 
  // te da el tipo litera
  // pero lo que hace decltype -> evaluar expresionnomas
  std::visit([](auto&& value){
      // todo opor culpa del auto
      // queremos el tipo exacto de value
      // decltype -> nos da la forma exacta de la variable
      // int* | int& -> int
      using T = std::decay_t<decltype(value)>;
      // luego decay_t lo transforma en su tipo primitivo 
      // lo limpia 
      // arr[10] -> int
      // int& -> int
      // int* -> int

      // constexpr -> se evalua en tiempo de compilacion
      if constexpr (std::is_same_v<T, int>) 
      {
        std::cout << "int: " << value << '\n';
        value = value + value;
        std::cout << "int: " << value << '\n';
      }
      else if constexpr (std::is_same_v<T, std::string>) 
        std::cout << "string: " << value << '\n';
      } , v1);
//instead of using auto types, declare the variables in the types tthat the variable is going to be used fuckin moron
  return 0;
}
