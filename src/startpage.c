#include "startpage.h"
#include "raylib.h"

enum game_status StartPageLoop() {
    StartPageDraw();
    if (IsKeyPressed(KEY_ENTER)) {
        return game_page;
    }
    return start_page;
}

void StartPageDraw() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press Enter To Start!", GetScreenWidth() / 2, GetScreenHeight() * 3 / 4, 50, BLACK);
    EndDrawing();
}
