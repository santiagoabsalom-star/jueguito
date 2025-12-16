#include <cmath>
#include <iostream>
#include <string>
#include <raylib.h>
#include <raymath.h>
#define WIDTH 640
#define HEIGHT 480

#define DT GetFrameTime()// delta time 60 frames 

void raylib();
// por ahora
// struct forma basica sin encapsulamiento complejo ni 
// control complejo de seguridad 
struct Ship
{
    Vector2 position;
    Vector2 acceleration;
    Vector2 velocity;
    float side_lenght;
    // llike texture sprite mas adel por ahora triangulo
    // aplicar movimiento
    void new_speed(Vector2 new_speed) 
    {
      velocity = new_speed;
    }
    // target position
    void move()
    {
      std::cout << "perra" << DT << std::endl;
      Vector2 desplazamiento = velocity * DT;
      // calcular distancia 
      // el vector de dir 
      // osea si hacemos {100, 100} spawn, { 200, 200} si restamos tenemos {100, 100} que es la dir 
      Vector2 dir = Vector2Subtract(desplazamiento, position );

      float dist = Vector2Length(dir); // con las cordenadas de la dir ahora la distancia es 100
                                          // float result = sqrtf((v.x*v.x) + (v.y*v.y)); que en realidad es esto que ya lo hicmos

      // normalizar
      // si te fijas va indefinidamente hacia alla no hay un tope
      position += velocity * DT;
    }
    void init(Vector2 spawn)
    {
      // centro 
      // centers es el vector para que este en el centro de la pantalla
      // nuestri punto de anclaje
      // en este caso seria el centro de la pantalla
      float centerX = WIDTH / 2;
      float centerY = HEIGHT / 2;

      float height = side_lenght * sqrtf(3) / 2;
      side_lenght = 100; 
      // el de mass arriba
      Vector2 p1 = { 
        spawn.x, 
        spawn.y- height / 2.0f // si le sacamos el 2.0f se hace traingluo isoceles jaa
      };

      Vector2 p2 = { 
        spawn.x- side_lenght / 2.0f, 
        spawn.y+ height / 2.0f 
      };

      Vector2 p3 = { 
        spawn.x+ side_lenght/ 2.0f, 
        spawn.y+ height / 2.0f 
      };
      p1 += position;
      p2 += position;
      p3 += position;
       // SIN POSITION NO IRIA A NIGUN LADO

      DrawTriangle(p1, p2, p3, RED);
    }
    void update_tri()
    {
    }
};
bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius)
{
    // // la vuelta completa
    // // float pi_rad = PI*2; // 360
    //                      // osea la definicion
    // float SEGMENTS = 400;
    // Vector2 pos[600];
    // for (float i = 0; i <= SEGMENTS; i++){
    //
    //   float dist = i / SEGMENTS;
    //   // angle para cada segmento
    //   float angle = pi_rad * (dist); // i / segmentos -> esto hace que sea de 0 a 360 o lo que seria en numeros/float de 0 a 1
    //                                  // aca entra el (x,y) cos(tita)*r, sin(tita)*r
    //   float x = cos(angle) * radius + center.x;
    //   float y = sin(angle) * radius + center.y;
    //
    //   Vector2 pixel_current = {x, y};
    //   float vertx3 = center.x;
    //   float verty3 = y;
    // jaja te veo
    // sali qUE
    const float distance = sqrt(

        ((point.x - center.x) * (point.x - center.x)) + ((point.y - center.y) * (point.y - center.y))

    );
    return (distance <= radius);
}


void raylib()
{
    //try on raylib jajaj;D
    Vector2 centerCircle = {300, 225};

    float radius = 50;
    InitWindow(WIDTH, HEIGHT, "Try on raylib");
    SetTargetFPS(165);

    while (!WindowShouldClose())
    {
        radius += GetMouseWheelMove() * 3;
        std::string fps = std::to_string(GetFPS());
        char const* fps_char = fps.c_str();
        BeginDrawing();
        DrawText(fps_char, 0, 0, 30, RED);
        ClearBackground(GRAY);

        Ship ship;
        ship.init({200, 250});
        ship.new_speed({200, 200});
        ship.move();
        //
        // DrawCircleV(centerCircle, radius, RED);
        // if (CheckCollisionPointCircle(centerCircle, GetMousePosition(), radius) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        // {
        //     centerCircle = GetMousePosition();
        // }
        //
        EndDrawing();
    }

    CloseWindow();
}



int main()
{
    raylib();
    return 0;
}
