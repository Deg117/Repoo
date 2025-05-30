#include "raylib.h"

Texture2D piratita;
Texture2D fondo;
Texture2D boton_iniciar;
Texture2D boton_salir;
Texture2D confi;
Texture2D pantalla_completa;
Texture plataformas;
Sound toquele;

void texturas();
void saltar();
void configuraciones();
void texturas()
{
    piratita = LoadTexture("piratita.png");
    fondo = LoadTexture("fondoc.png");
    boton_iniciar = LoadTexture("start.png");
    boton_salir = LoadTexture("exit.png");
    confi = LoadTexture("confi.png");
    pantalla_completa = LoadTexture("pantalla_completa.png");
    plataformas = LoadTexture("plataforma.png");
    toquele = LoadSound("gemi.mp3");
}

void configuraciones()
{
    Rectangle pantalla_comp = {20, 50, (float)pantalla_completa.width, (float)pantalla_completa.height};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(fondo, 0, 0, WHITE);
        DrawTexture(pantalla_completa, 20, 50, WHITE);

        Vector2 mouse = GetMousePosition();
        if (CheckCollisionPointRec(mouse, pantalla_comp))
        {
            DrawRectangleLinesEx(pantalla_comp, 3, RED);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                ToggleFullscreen();
            }
        }

        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE))
            break;
    }
}

void saltar()
{
    float x = 200, y = 600;
    float velocidady = 0;
    const float gravedad = 800;
    const float salto = -650;
    const float velocidadx = 400;
    bool isOnGround = false;

    // Define la plataforma
    Rectangle plataforma = {100, 425, (float)plataformas.width, (float)plataformas.height};

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Movimiento horizontal
        if (IsKeyDown(KEY_LEFT))
            x -= velocidadx * deltaTime;
        if (IsKeyDown(KEY_RIGHT))
            x += velocidadx * deltaTime;

        // Limites de la pantalla
        if (x < 0)
            x = 0;
        if (x > GetScreenWidth() - piratita.width)
            x = GetScreenWidth() - piratita.width;

        // Rectángulo del personaje
        Rectangle jugador = {x, y, (float)piratita.width, (float)piratita.height};

        // Verifica si está en el suelo o en la plataforma
        isOnGround = false;
        if (y >= 600)
        {
            y = 600;
            velocidady = 0;
            isOnGround = true;
        }
        else if (CheckCollisionRecs(jugador, plataforma) && velocidady >= 0 && y + piratita.height <= plataforma.y + 20)
        {
            y = plataforma.y - piratita.height;
            velocidady = 0;
            isOnGround = true;
        }

        // Salto solo si esta en el suelo o plataforma
        if (isOnGround)
        {
            velocidady = salto;
            isOnGround = false;
        }
        // Aplicar gravedad
        if (!isOnGround)
        {
            velocidady += gravedad * deltaTime;
            y += velocidady * deltaTime;
        }

        // Dibujo
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(fondo, 0, 0, WHITE);
        DrawTexture(piratita, (int)x, (int)y, WHITE);
        DrawTexture(plataformas, (int)plataforma.x, (int)plataforma.y, WHITE);
        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }
    }
}
