#pragma once
#include "raylib.h"
#include "raymath.h"
#include "game.h"
#include "display.h"

#define BATTLE_MENU_BOX_COLOR_GRADIENT BLUE

typedef struct battle_menu
{
    Rectangle menu_rec;
    Color menu_grad;
    Color trim;

} bm;

Rectangle battle_menu_rec {
    .width = GetScreenWidth(),
    .height = GetScreenHeight(),
    .x = 0,
    .y = GetScreenHeight() - GetScreenHeight()/4
};

typedef struct battle_menu_option
{
    
} bm_option;


void display_attack_options(c_stats c)
{
    int size = sizeof(c.physical_attacks) / sizeof(c.physical_attacks[0]);
    // for each attack option element, show some text 
    for (size_t i = 0; i < size; i++)
    {
        
    }
    
    c.physical_attacks

}

// int intra_battle_map[3][2] =
// {
//     {0,0},
//     {0,0},
//     {0,0}
// };

// void BATTLE_MENU()
// {
    
//     DrawRectangleGradientEx()
// }