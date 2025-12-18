#pragma once
#include "raylib.h"
#include "raymath.h"
#include "display.h"

#define SPEED .2

void control(Sprite* s)
{
    bool fwd = IsKeyDown(KEY_W);
    bool back = IsKeyDown(KEY_S);
    bool left = IsKeyDown(KEY_A);
    bool right = IsKeyDown(KEY_D);
    bool diagnol_up = fwd && (left || right);
    bool diagnol_down = back && (left || right);
    bool movement = (fwd||back||left||right || diagnol_up || diagnol_down);

    if (!(movement)) {return;}    

    Vector2 delta = Vector2Zero();

    if (fwd)
    {
        delta.y--;
    }
    if (back)
    {
        delta.y++;
    }
    if (right)
    {
        delta.x++;
    }
    if (left)
    {
        delta.x--;
    }
    delta = Vector2Normalize(delta);
    delta = Vector2Scale(delta, SPEED);
    
    s->pos = Vector2Add(s->pos, delta);
}