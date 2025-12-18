#pragma once
#include "raylib.h"
#include "raymath.h"


int IN_BATTLE_STATE_G = 0;

// Max values
#define MAX_SPELLS 5
#define MAX_PHYSICAL_ATKS 5
#define MAX_ATTACKS 10
#define MAX_PARTY_SIZE 3
#define MAX_HP 100
#define MAX_MP 100
#define MAX_SP 99
#define MAX_EXP 999
#define MAX_ITEMS 99

// Default attack constants
#define DEFAULT_ATTACK_NAME "ATTACK 0"
#define DEFAULT_ATTACK_ATTACK_TYPE PHYSICAL
#define DEFAULT_ATTACK_PHYSICAL_EFFECT NO_PHYSICAL_EFFECT
#define DEFAULT_ATTACK_ELEMENT NULL_E
#define DEFAULT_ATTACK_MAGIC_SIDE_EFFECT NO_MAGICAL_SIDE_EFFECT
#define DEFAULT_ATTACK_ID 0
#define DEFAULT_ATTACK_MP_COST 0
#define DEFAULT_ATTACK_SP_COST 0
#define DEFAULT_ATTACK_STRENGTH 0


// Default attack macros (defined after structs)
#define DEFAULT_ATTACK (atk_i){ \
    .name = DEFAULT_ATTACK_NAME, \
    .attack_type = DEFAULT_ATTACK_ATTACK_TYPE, \
    .p_type = DEFAULT_ATTACK_PHYSICAL_EFFECT, \
    .spell_type = DEFAULT_ATTACK_ELEMENT, \
    .side_effect_m = DEFAULT_ATTACK_MAGIC_SIDE_EFFECT, \
    .id = DEFAULT_ATTACK_ID, \
    .mp_cost = DEFAULT_ATTACK_MP_COST, \
    .sp_cost = DEFAULT_ATTACK_SP_COST, \
    .atk_strength = DEFAULT_ATTACK_STRENGTH \
}

#define DEFAULT_SPELL (atk_i){ \
    .name = "SPELL 0", \
    .attack_type = MAGIC, \
    .p_type = NO_PHYSICAL_EFFECT, \
    .spell_type = NULL_E, \
    .side_effect_m = NO_MAGICAL_SIDE_EFFECT,\
    .id = 0, \
    .mp_cost = 0, \
    .sp_cost = 0, \
    .atk_strength = 0 \
}

// Enums
typedef enum attack_type
{
    NONE_ATTACK,
    PHYSICAL,
    MAGIC,
    OTHER
} atk_t;

typedef enum physical_effect
{
    NO_PHYSICAL_EFFECT,
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
typedef enum magic_effect
{
    NO_MAGICAL_SIDE_EFFECT,
    SILENCE,
    PETRIFY,
    TERRIFY,
    BERSERK,
    BLIND
} m_effect_t;
// Structs
typedef struct attack_info
{
    char* name;
    atk_t attack_type;
    p_effect_t p_type;
    element_t spell_type;
    m_effect_t side_effect_m;
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
    atk_i physical_attacks[MAX_PHYSICAL_ATKS];
    atk_i magic_attacks[MAX_SPELLS];
    item inventory[MAX_ITEMS];
    p_effect_t current_physical_side_effect;
    m_effect_t current_magic_side_effect;
} c_stats;


// Global party arrays
c_stats player_party[MAX_PARTY_SIZE];
c_stats enemy_party[MAX_PARTY_SIZE];

// Function to initialize character stats
c_stats init_character_stats(c_stats character)
{
    character.name = "";
    character.hp = MAX_HP;
    character.mp = MAX_MP;
    character.sp = MAX_SP;
    character.exp = 0; // Starting exp should be 0, not MAX_EXP
    character.pos = (Vector2){0, 0};
    
    // Initialize all physical attacks to default
    for(int i = 0; i < MAX_PHYSICAL_ATKS; i++) {
        character.physical_attacks[i] = DEFAULT_ATTACK;
    }
    
    // Initialize all magic attacks to default spell
    for(int i = 0; i < MAX_SPELLS; i++) {
        character.magic_attacks[i] = DEFAULT_SPELL;
    }
    
    // Initialize inventory to empty
    for(int i = 0; i < MAX_ITEMS; i++) {
        character.inventory[i] = (item){.name = NULL, .id = 0};
    }

    character.current_magic_side_effect = NO_MAGICAL_SIDE_EFFECT;
    character.current_physical_side_effect = NO_PHYSICAL_EFFECT;
    
    return character;
}