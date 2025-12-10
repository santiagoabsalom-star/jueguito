#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numbers>
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

  return 0;
}
bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius) {
  // la vuelta completa
  float pi_rad = PI*2; // 360
                       // osea la definicion
  float SEGMENTS = 400;
  Vector2 pos[600];
  for (float i = 0; i <= SEGMENTS; i++){

    float dist = i / SEGMENTS;
    // angle para cada segmento
    float angle = pi_rad * (dist); // i / segmentos -> esto hace que sea de 0 a 360 o lo que seria en numeros/float de 0 a 1
                                         // aca entra el (x,y) cos(tita)*r, sin(tita)*r 
    float x = cos(angle) * radius + center.x;
    float y = sin(angle) * radius + center.y;

    Vector2 pixel_current = {x, y};
    float vertx3 = center.x;
    float verty3 = y;
    // vertice 3 del triangulo
    // dibjuamos desde el centro hasta el punto vertx 
    DrawPixel(vertx3, verty3, BLUE);
    DrawPixel(x, y , RED);
    DrawPixel(x, center.y, GREEN);


  }

    // base * altura * 2
  return true;

}


void raylib() {


  SetConfigFlags(FLAG_MSAA_4X_HINT);
  //try on raylib jajaj;D
  Vector2 p={300,225};
  Vector2 v={100, 100};
  float radius=50;
  InitWindow(600, 450, "Try on raylib");
  SetTargetFPS(165);
  bool is_drag = false;
  while (!WindowShouldClose())
  {
    // if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(GetMousePosition(), p, radius)){
    //   is_drag = true;
    // }

    radius += GetMouseWheelMove() * 3;

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
      is_drag = false;
    }
    if(is_drag){
      p = GetMousePosition();
    }
    std::string fps = std::to_string( GetFPS());
    char const *fps_char = fps.c_str();
    BeginDrawing();
    //little drag test fuck I don't know why it's so slow
    //    little first test
    bool t = CheckCollisionPointCircle(
        GetMousePosition(),
        p,
        radius
    );

    if( IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      p=GetMousePosition();
    }
    DrawText(fps_char,0, 0, 30, RED );
    ClearBackground(RAYWHITE);
    // DrawCircleV(p, radius, RED);
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

