
#include <chrono>
#include <iostream>
#include <string>
#include <variant>
#include <raylib.h>
#include <raymath.h>
#define WIDTH 640
#define HEIGHT 480
using val = std::variant<int, std::string>;
void tests();



void raylib();
int main() {

  val v1 = 10;
  val v2 = "C++";
raylib();



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

void raylib() {


//try on raylib jajaj;D
  Vector2 p={300,225};
  Vector2 v={100, 100};
  float radius=20;
  InitWindow(600, 450, "Try on raylib");
  SetTargetFPS(165);
  while (!WindowShouldClose())
  {


    std::string fps = std::to_string( GetFPS());
    char const *fps_char = fps.c_str();
    BeginDrawing();
    p=GetMousePosition();
    //little drag test fuck I don't know why it's so slow
    // if ((GetMousePosition().x==p.x+radius || GetMousePosition().y==p.y+radius) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)  ) {
    //    little first test
    //   p=GetMousePosition();
    // }
    DrawText(fps_char,0, 0, 30, RED );
    ClearBackground(RAYWHITE);
    DrawCircleV(p, radius, RED);
    EndDrawing();


  }
  //pseudocodigo ajjajakjkas
// if((posicionMouse.x==p.x+radius || posicionMouse.y=p+radius)) && isButtonDown(MOUSE_BUTTON_LEFT){
// p=posicionMouse;
// }
  CloseWindow();

}

void tests() {
   const std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
  for (int i = 1; i <= 10000; i++) {

    if (i & 1) {
      printf("%d es puto fracasado y no es par\n", i);

    }



  }const std::chrono::system_clock::time_point stop = std::chrono::system_clock::now();
  const long time = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
    std::cout << "El tiempo es: "<< time << " ms"<< '\n';
  std::cout << "Ahora con el fuckin % " << '\n';
    const std::chrono::system_clock::time_point start1 = std::chrono::system_clock::now();
  for (int x = 1; x <= 10000; x++) {
      if (x%2!=0) {
        printf("%d es puto fracasado y no es par\n", x);
      }


    }
const std::chrono::system_clock::time_point stop1 = std::chrono::system_clock::now();
    const long time1 = std::chrono::duration_cast<std::chrono::seconds>(stop1 - start1).count();
  std::cout << "El tiempo es: "<< time1 <<" ms"<< '\n';
}

