#include "raylib.h"

// Structures
typedef struct {
    // Cordinates
    int posX, posY;
}Ball;

typedef struct {
    // Cordinates
    int x, y;
    // Movement variables
    int speed, direction;
}Player;

// Global Variables
int screen_width, screen_height;
Ball ball;
Player right_player, left_player;
// Function Declarations
void DrawGraphics();

int main (void) {

    InitWindow(0, 0, "Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
//  Ball
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
//  Players
    left_player.y = (screen_height - 50) / 2;
    left_player.x = screen_width / 10;
    right_player.y = (screen_height - 50) / 2;
    right_player.x = screen_width * 9 / 10;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground(BLACK);
        // Left Player
        DrawRectangle(screen_width / 10, left_player.y, 15, 100, WHITE);
        // Right Player
        DrawRectangle(screen_width * 9 / 10, right_player.x, 15, 100, WHITE);
        // Ball
        DrawCircle(ball.posX, ball.posY, 5, WHITE);
    EndDrawing();
}
