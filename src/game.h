#ifndef GAME_H
#define GAME_H

#include "structs.h"
#include "raylib.h"
#include "startpage.h"


// Function Declarations
enum game_status GameLoop();
void DrawGraphics();
void Initialize();
void Physics();
void ServeBall(int *x, int *y, int *x_direction, int *speed);

#endif // GAME_H
