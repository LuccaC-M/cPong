#ifndef GAME_H
#define GAME_H

#include "structs.h"

// Global game variables
int screen_width, screen_height;
Ball ball;
Player right_player, left_player;
// Function Declarations
void DrawGraphics();
void Initialize();
void Physics();
void ServeBall(int *x, int *y, int *x_direction, int *speed);

#endif // GAME_H
