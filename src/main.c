#include "raylib.h"

// Structures
typedef struct {
    // Cordinates
    int posX, posY;
}Ball;

// Global Variables
int screen_width, screen_height;
Ball ball;
int right_player_y, left_player_y;
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
    left_player_y = (screen_height - 50) / 2;
    right_player_y = (screen_height - 50) / 2;
    while (!WindowShouldClose()) {
        DrawGraphics();
    }
    
    return 0;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground(BLACK);
        // Left Player
        DrawRectangle(screen_width / 10, left_player_y, 15, 100, WHITE);
        // Right Player
        DrawRectangle(screen_width * 9 / 10, right_player_y, 15, 100, WHITE);
        // Ball
        DrawCircle(ball.posX, ball.posY, 5, WHITE);
    EndDrawing();
}
