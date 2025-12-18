#include "stdio.h"
#include "stdlib.h"
#include "game.h"
#include "display.h"
#include "controls.h"

int main(void)
{
    InitWindow(DEFAULT_WINDOW_X, DEFAULT_WINDOW_Y, "CRPG");
    float scr_x = DEFAULT_WINDOW_X;
    float scr_y = DEFAULT_WINDOW_Y;
    Sprite ts; // test sprite
    Sprite es; // enemy sprite

    ts.color = YELLOW;
    ts.dir = (Vector2){.x = 1, .y = 0};
    ts.pos = (Vector2){0};

    Camera2D cam = (Camera2D){0};
    cam.target = (Vector2){0};
    cam.offset = (Vector2){scr_x / 2.0f, scr_y / 2.0f};
    cam.rotation = 0;
    cam.zoom = 2.0f;

    Sprite *tss = &ts;

    Image map = LoadImage("resources/fantasy_map_banna.png");
    //ImageResize(&map, scr_x, scr_y);
    Texture map_t = LoadTextureFromImage(map);
    Texture *current_t;
    current_t = &map_t;

    while (!WindowShouldClose())
    {
        // [=============] SCREEN SPACE [=============]
        cam.target = tss->pos;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("x:%.2f, y:%.2f", tss->pos.x, tss->pos.y), 20, 20, 20, WHITE);

        BeginMode2D(cam);
        // [=============] WORLD SPACE [=============]
        DrawTexture(*current_t, -current_t->width/2, -current_t->height/2, WHITE);

        control(tss);
        DrawRectangle(tss->pos.x, tss->pos.y, 50 / 3, 50 / 3, tss->color);
        // DrawRectangle(es.pos.x, es.pos.y, 50, 50, es.color);

        
        EndMode2D();
        
        EndDrawing();
    }

    return 0;
}