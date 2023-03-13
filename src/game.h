#ifndef GAME_H
#define GAME_H

#include "structs.h"

// Function Declarations
void GameLoop();
void DrawGraphics();
void Initialize();
void Physics();
void ServeBall(int *x, int *y, int *x_direction, int *speed);

#endif // GAME_H
