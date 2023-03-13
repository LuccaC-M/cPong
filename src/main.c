#include "raylib.h"

void DrawGraphics();

int main (void) {

    InitWindow(800, 460, "Pong");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        DrawGraphics();
    }
    
    return 0;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground(WHITE);

        DrawText("Hello", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}
