#pragma once
#include "raylib.h"
#include "raymath.h"

#define MAX_SPELLS 5
#define MAX_PHYSICAL_ATKS 5
#define MAX_ATACKS 10
#define MAX_PARTY_SIZE 3

#define MAX_HP 100
#define MAX_MP 100
#define MAX_SP 99
#define MAX_EXP 999
#define MAX_ITEMS 99

#define DEFAULT_ATTACK_TYPE 0
#define DEAULT_ATTACK_NAME "ATTACK 0"
#define DEAULT_ATTACK_ATTACK_TYPE PHYSICAL // 1
#define DEAULT_ATTACK_PHYSICAL_EFFECT NULL_PE // 0
// or should everything have one 
#define DEAULT_ATTACK_ELEMENT NULL_E // 0
#define DEAULT_ATTACK_ID 0
#define DEAULT_ATTACK_MP_COST 0
#define DEAULT_ATTACK_SP_COST 0 
#define DEAULT_ATTACK_STRENGTH 0
#define DEAULT_ATTACK  (atk_i) {}

#define DEFAULT_SPELL (atk_i){}



typedef enum attack_type
{
    NONE_ATTACK,
    PHYSICAL,
    MAGIC,
    OTHER
} atk_t;

typedef enum physical_effect
{
    NULL_PE,
    CONCUSSION,
    BLEED
} p_effect_t;

typedef enum elemental_type
{
    NULL_E,
    FIRE,
    WATER,
    EARTH,
    WIND,
    LIGHT,
    DARK
} element_t;

typedef struct attack_info
{
    char* name;
    atk_t attack_type;
    p_effect_t p_type;
    element_t spell_type;
    int id;
    int mp_cost;
    int sp_cost;
    int atk_strength;
 } atk_i;

 typedef struct item
 {
    char* name;
    int id;
 } item;

typedef struct character_stats
{
    char* name;
    int hp;
    int mp;
    int sp;
    float exp;
    Vector2 pos;
    atk_i physcial_attacks[MAX_PHYSICAL_ATKS]; // or atk_i* 
    atk_i magic_attacks[MAX_SPELLS]; // or atk_i*
    item inventory[MAX_ITEMS];
} c_stats;

// 3 vs 3
c_stats player_party[MAX_PARTY_SIZE];
c_stats enemey_party[MAX_PARTY_SIZE];

atk_i get_default_atk()
{
    atk_i attack = (atk_i)
    {
        .atk_strength = 1,
        .attack_type = PHYSICAL,
        .id = 0,
        .mp_cost = 0,
        .name = "DEFAULT",
        .p_type = NULL_PE,
        .sp_cost = 0,
        .spell_type = NULL_E
    };
    return attack;
}
c_stats init_cstat(c_stats character)
{
    character.name = "";
    character.hp = MAX_HP;
    character.mp = MAX_MP;
    character.sp = MAX_SP;
    character.exp = MAX_EXP;
    character.pos = (Vector2){0};
    //character.physcial_attacks[MAX_PHYSICAL_ATKS] = (atk_i){.}; // or atk_i* 
    character.magic_attacks[MAX_SPELLS]; // or atk_i*
    character.inventory[MAX_ITEMS];
}