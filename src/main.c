#include "raylib.h"
#include "structs.h"
#include "game.h"
#include "startpage.h"

enum game_status state = start_page;

int main (void) {
//  Initialize all variables
    Initialize();
//  Game Loop
    while (!WindowShouldClose()) {
        if (state == game_page)
            state = GameLoop();
        else if (state == start_page)
            state = StartPageLoop();
    }
    return 0;
}
