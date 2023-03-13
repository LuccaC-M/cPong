#include "raylib.h"

// Global Variables
int screen_width, screen_height;

// Function Declarations
void DrawGraphics();

int main (void) {

    InitWindow(0, 0, "Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    while (!WindowShouldClose()) {
        DrawGraphics();
    }
    
    return 0;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground(BLACK);
        // Left Player
        DrawRectangle(screen_width / 10, (screen_height - 50) / 2, 15, 100, WHITE);
        // Right Player
        DrawRectangle(screen_width * 9 / 10, (screen_height - 50) / 2, 15, 100, WHITE);
    EndDrawing();
}
