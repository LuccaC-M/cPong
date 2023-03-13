#include "raylib.h"
#include "structs.h"

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
        ball.y += ball.speed * ball.y_direction * GetFrameTime();
        ball.x += ball.speed * ball.x_direction * GetFrameTime();
        if (ball.x <= 0)
            right_player.score++;
        if (ball.x >= screen_width)
            left_player.score++;

        if (ball.y <= 0 || ball.y >= screen_height)
            ball.y_direction *= -1;

        if (CheckCollisionCircleRec((Vector2) {ball.x, ball.y}, 5, (Rectangle) {left_player.x, left_player.y, 15, 100})
                || CheckCollisionCircleRec((Vector2) {ball.x, ball.y}, 5, (Rectangle) {right_player.x, right_player.y, 15, 100}))
            ball.x_direction *= -1;
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
    ball.speed = 500;
    ball.x_direction = 1;
    ball.y_direction = 1;
//  Left player
    left_player.y = (screen_height - 50) / 2;
    left_player.x = screen_width / 10;
    left_player.speed = 400;
    left_player.score = 0;
//  Right player
    right_player.y = (screen_height - 50) / 2;
    right_player.x = screen_width * 9 / 10;
    right_player.speed = 400;
    left_player.score = 0;
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
