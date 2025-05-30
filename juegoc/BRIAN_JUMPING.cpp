#include "salto.h"

int main(void)
{
    int sali = 0;
    InitAudioDevice();
    InitWindow(518, 970, "Cima_run"); // inicia una ventana de esa escala
    SetTargetFPS(60);                 // Establece los FPS a 60
    texturas();

    Rectangle iniciar = {130, 750, (float)boton_iniciar.width, (float)boton_iniciar.height};
    Rectangle salir = {180, 850, (float)boton_salir.width, (float)boton_salir.height};
    Rectangle configuracion = {450, 900, (float)confi.width, (float)confi.height};
    Rectangle pou_sond = {200, 600, (float)piratita.width, (float)piratita.height};
    while (!WindowShouldClose() && sali == 0) // mientras que no se pulse la x de cerrar ventana esta sigue abierta
    {
        Vector2 mouse = GetMousePosition();
        BeginDrawing();         // inicia el dibujo
        ClearBackground(BLACK); // borra el fondo y lo pone negro

        DrawTexture(fondo, 0, 0, WHITE);        // piratita
        DrawTexture(piratita, 200, 600, WHITE); // fondo de inicio
        DrawTexture(boton_iniciar, 130, 750, WHITE);
        DrawTexture(boton_salir, 180, 850, WHITE);
        DrawTexture(confi, 450, 900, WHITE);
        DrawTexture(plataformas, 100, 440, WHITE);
        if (CheckCollisionPointRec(mouse, iniciar))
        {
            DrawRectangleLinesEx(iniciar, 3, (Color){0, 0, 0, 0});
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                // meter funcion del juego inicia
                saltar();
            }
        }
        if (CheckCollisionPointRec(mouse, salir))
        {
            DrawRectangleLinesEx(salir, 3, (Color){0, 0, 0, 0}); // solo para saber si esta dentro del boton
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                sali = 1;
            }
        }
        if (CheckCollisionPointRec(mouse, configuracion))
        {
            DrawRectangleLinesEx(configuracion, 3, (Color){0, 0, 0, 0});
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                configuraciones();
            }
        }
        if (CheckCollisionPointRec(mouse, pou_sond))
        {
            DrawRectangleLinesEx(pou_sond, 3, (Color){0, 0, 0, 0});
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) //  se asegura que haya clic
            {
                PlaySound(toquele);
            }
        }

        EndDrawing();
    }

    UnloadTexture(fondo);
    CloseWindow();

    return 0;
}
