#include "raylib.h"

// Structures
typedef struct {
    // Cordinates
    int x, y;
    // Movement Variables
    int speed, direction;
}Ball;

typedef struct {
    // Cordinates
    int x, y;
    // Movement variables
    int speed;
}Player;

// Global Variables
int screen_width, screen_height;
Ball ball;
Player right_player, left_player;
// Function Declarations
void DrawGraphics();
void Initialize();

int main (void) {
    Initialize();

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_W)) {
            left_player.y -= left_player.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_S)) {
            left_player.y += left_player.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_I)) {
            right_player.y -= right_player.speed * GetFrameTime();
        }
        if (IsKeyDown(KEY_K)) {
            right_player.y += right_player.speed * GetFrameTime();
        }
        DrawGraphics();
    }
    
    return 0;
}

void Initialize() {
//  Initialize the window
    InitWindow(0, 0, "Pong");
    ToggleFullscreen();
    SetTargetFPS(60);
//  Screen Variables
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
//  Ball
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
//  Players
    left_player.y = (screen_height - 50) / 2;
    left_player.x = screen_width / 10;
    left_player.speed = 400;
    right_player.y = (screen_height - 50) / 2;
    right_player.x = screen_width * 9 / 10;
    right_player.speed = 400;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground(BLACK);
        // Left Player
        DrawRectangle(left_player.x, left_player.y, 15, 100, WHITE);
        // Right Player
        DrawRectangle(right_player.x, right_player.y, 15, 100, WHITE);
        // Ball
        DrawCircle(ball.x, ball.y, 5, WHITE);
    EndDrawing();
}
