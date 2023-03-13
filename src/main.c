#include "raylib.h"

// Structures
typedef struct {
    // Cordinates
    int posX, posY;
}Ball;

// Global Variables
int screen_width, screen_height;
Ball ball;
// Function Declarations
void DrawGraphics();

int main (void) {

    InitWindow(0, 0, "Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
    ball.posX = screen_width / 2;
    ball.posY = screen_height / 2;
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
        // Ball
        DrawCircle(ball.posX, ball.posY, 5, WHITE);
    EndDrawing();
}
