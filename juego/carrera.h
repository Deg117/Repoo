#include "raylib.h"
#include <stdio.h>
Texture2D paco;
Texture2D imagen;
Texture2D boton_iniciar;
Texture2D boton_salir;
Texture2D fondo2;
Texture2D confi;
Texture2D volmas;
Texture2D volmenos;
Texture2D paco_corriendo;

Sound inicio;
void texturas();
void ventana_inicio();
void correr();
void configuraciones();

void ventana_inicio()
{
    InitAudioDevice();

    int salir = 0;
    texturas();
    Rectangle rect_boton = {500, 440, (float)boton_iniciar.width, (float)boton_iniciar.height};
    Rectangle rect_salir = {545, 520, (float)boton_salir.width, (float)boton_salir.height};
    Rectangle rect_confi = {1300, 20, (float)confi.width, (float)confi.height};

    PlaySound(inicio);                         // inicia el sonido
    while (!WindowShouldClose() && salir == 0) // mientras que no se pulse la x de cerrar ventana esta sigue abierta
    {

        Vector2 mouse = GetMousePosition(); // pa saber onde anda el cursor

        BeginDrawing();         // inicia el dibujo
        ClearBackground(BLACK); // borra el fondo y lo pone negro

        DrawTexture(imagen, 0, 0, WHITE);   // inicio
        DrawTexture(paco, 600, 660, WHITE); // paco

        DrawTexture(boton_iniciar, 500, 440, WHITE); // boton star
        DrawTexture(boton_salir, 545, 520, WHITE);   // boton exit
        DrawTexture(confi, 1300, 20, WHITE);

        if (CheckCollisionPointRec(mouse, rect_boton))
        {
            DrawRectangleLinesEx(rect_boton, 3, RED); // solo para saber si esta dentro del boton
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                // meter funcion del juego inicia
                correr();
            }
        }
        if (CheckCollisionPointRec(mouse, rect_salir))
        {
            // el juego termina

            DrawRectangleLinesEx(rect_salir, 3, RED); // solo para saber si esta dentro del boton
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                salir = 1;
            }
        }
        if (CheckCollisionPointRec(mouse, rect_confi))
        {
            DrawRectangleLinesEx(rect_confi, 3, RED); // solo para saber si esta dentro del boton
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                // meter opciones de configuracion sonido etc
                configuraciones();
            }
        }

        EndDrawing();
    }
    UnloadTexture(imagen);
    UnloadTexture(paco);
    UnloadTexture(boton_iniciar);
    UnloadTexture(boton_salir);
    UnloadSound(inicio); // Libera memoria del sonido
    CloseAudioDevice();  // Cierra el audio
    UnloadTexture(confi);
    CloseWindow();
}

void texturas()
{
    paco = LoadTexture("paco.png");
    imagen = LoadTexture("fondo.png");
    boton_iniciar = LoadTexture("start.png");
    boton_salir = LoadTexture("exit.png");
    inicio = LoadSound("sonido_vecinos.mp3");
    fondo2 = LoadTexture("fondo2.png");
    confi = LoadTexture("confi.png");
    volmas = LoadTexture("volmas.png");
    volmenos = LoadTexture("volmenos.png");
    paco_corriendo = LoadTexture("corriendo.png");
}

void correr()
{
    Vector2 posicion = {600, 660}; // Posición fija del personaje
    float velocidad_fondo = 2.0f;
    float aceleracion = 0.01f;
    float velocidad_maxima = 10.0f;
    float fondo_x = 0;

    // Datos del sprite animado
    int frame_actual = 0;
    int total_frames = 4;
    int frame_ancho = paco_corriendo.width / total_frames;
    int frame_alto = paco_corriendo.height;
    int frame_contador = 0;
    int frame_velocidad = 8;

    Rectangle sourceRec = {0, 0, (float)frame_ancho, (float)frame_alto};

    while (!WindowShouldClose())
    {
        // Movimiento del fondo
        fondo_x -= velocidad_fondo;
        if (fondo_x <= -1360)
            fondo_x = 0;

        if (velocidad_fondo < velocidad_maxima)
            velocidad_fondo += aceleracion;

        // Animación del personaje
        frame_contador++;
        if (frame_contador >= frame_velocidad)
        {
            frame_actual = (frame_actual + 1) % total_frames;
            frame_contador = 0;
        }
        sourceRec.x = frame_actual * frame_ancho;

        // Rectángulos para fondo animado
        Rectangle source = {0, 0, (float)fondo2.width, (float)fondo2.height};
        Rectangle dest1 = {fondo_x, 0, 1360, 920};
        Rectangle dest2 = {fondo_x + 1360, 0, 1360, 920};

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujo del fondo animado
        DrawTexturePro(fondo2, source, dest1, (Vector2){0, 0}, 0.0f, WHITE);
        DrawTexturePro(fondo2, source, dest2, (Vector2){0, 0}, 0.0f, WHITE);

        // Dibujo del personaje
        DrawTextureRec(paco_corriendo, sourceRec, posicion, WHITE);

        EndDrawing();

        // Salida con ESC
        if (IsKeyPressed(KEY_ESCAPE))
            break;
    }
}

void configuraciones()
{
    float volumen = 0.5f;
    SetSoundVolume(inicio, volumen);

    Rectangle rect_vmas = {400, 300, (float)volmas.width, (float)volmas.height};
    Rectangle rect_vmenos = {300, 300, (float)volmenos.width, (float)volmenos.height};

    while (!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, rect_vmas) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangleLinesEx(rect_vmas, 3, RED);
            volumen += 0.1f;
            if (volumen > 1.0f)
                volumen = 1.0f;
            SetSoundVolume(inicio, volumen);
        }

        if (CheckCollisionPointRec(mouse, rect_vmenos) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            DrawRectangleLinesEx(rect_vmenos, 3, RED);
            volumen -= 0.1f;
            if (volumen < 0.0f)
                volumen = 0.0f;
            SetSoundVolume(inicio, volumen);
        }
        // aca es para la pantalla completa
        /* if (CheckCollisionPointRec(mouse, rect_pantalla) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
          {
               DrawRectangleLinesEx(rect_pantalla, 3, RED);
              ToggleFullscreen();
          }*/

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawTexture(fondo2, 0, 0, WHITE);
        DrawTexture(volmenos, (int)rect_vmenos.x, (int)rect_vmenos.y, WHITE);
        DrawTexture(volmas, (int)rect_vmas.x, (int)rect_vmas.y, WHITE);

        EndDrawing();
    }
}
