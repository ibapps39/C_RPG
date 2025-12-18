#pragma once 
#include "raylib.h"
#include "raymath.h"


#define DEFAULT_WINDOW_X 1000
#define DEFAULT_WINDOW_Y 1000
#define DEFAULT_RESOLUTION (int)DEFAULT_WINDOW_X * (int)DEFAULT_WINDOW_Y

typedef struct Sprite
{
    Vector2 pos;
    Vector2 dir;
    //Image portrait;
    Color color;
} Sprite;
