#include "raylib.h"
#include "structs.h"
#include "game.h"

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
