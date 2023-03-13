#include "raylib.h"
#include "structs.h"
#include "game.h"

int main (void) {
//  Initialize all variables
    Initialize();
//  Game Loop
    while (!WindowShouldClose()) {
        GameLoop();
    }
    
    return 0;
}
