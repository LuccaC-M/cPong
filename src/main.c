#include "raylib.h"
#include "structs.h"

// Global Variables
int screen_width, screen_height;
Ball ball;
Player right_player, left_player;
// Function Declarations
void DrawGraphics();
void Initialize();
void Physics();
void ServeBall(int *x, int *y, int *x_direction, int *speed);

int main (void) {
    Initialize();
//  Game Loop
    while (!WindowShouldClose()) {
//      Handle Physics
        Physics();
//      Handle player input
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
//      Draw everything to the screen
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
    left_player.speed = 550;
    left_player.score = 0;
//  Right player
    right_player.y = (screen_height - 50) / 2;
    right_player.x = screen_width * 9 / 10;
    right_player.speed = 550;
    left_player.score = 0;
}

void DrawGraphics() {
    BeginDrawing();
        ClearBackground((Color) {43, 43, 43, 1});
        // Scores
        DrawText(TextFormat("%02i", left_player.score), screen_width/ 4, 10, 50, BLUE);
        DrawText(TextFormat("%02i", right_player.score), screen_width * 3/ 4, 10, 50, RED);
        // Left Player
        DrawRectangle(left_player.x, left_player.y, 15, 100, BLUE);
        // Right Player
        DrawRectangle(right_player.x, right_player.y, 15, 100, RED);
        // Ball
        DrawCircle(ball.x, ball.y, 5, WHITE);
    EndDrawing();
}

void Physics() {
//  Calculate new ball x & y positions
    ball.y += ball.speed * ball.y_direction * GetFrameTime();
    ball.x += ball.speed * ball.x_direction * GetFrameTime();

//  A player has scored
    if (ball.x <= 0) {
        right_player.score++;
        ServeBall(&ball.x, &ball.y, &ball.x_direction, &ball.speed);
    }
    if (ball.x >= screen_width) {
        left_player.score++;
        ServeBall(&ball.x, &ball.y, &ball.x_direction, &ball.speed);
    }
//  if the ball is touching the edges bounce it
    if (ball.y <= 0 || ball.y >= screen_height)
        ball.y_direction *= -1;

//  if The ball is touching any of the players bounce it & make it faster
    if (CheckCollisionCircleRec((Vector2) {ball.x, ball.y}, 5, (Rectangle) {left_player.x, left_player.y, 15, 100})
    || CheckCollisionCircleRec((Vector2) {ball.x, ball.y}, 5, (Rectangle) {right_player.x, right_player.y, 15, 100})) {
        ball.x_direction *= -1;
        ball.speed *= 1.1;
    }
}

// After someone has scored put ball in the center, set speed to starting speed, decide where the ball goes
void ServeBall(int *x, int *y, int *x_direction, int *speed) {
    *x = screen_width / 2;
    *y = screen_height / 2;
    *speed = 500;
    *x_direction = right_player.score - left_player.score;
    if (*x_direction == 0)
        *x_direction = 1;
}
