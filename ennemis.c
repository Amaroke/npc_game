/**
 *\file ennemis.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 janvier 2021
*/


#include "ennemis.h"
#include "ressources.h"

// Constantes

SDL_Rect array_sprite_down[NB_ANIMATIONS_ENEMY] = {{0, 0, 16, 32}, {16, 0, 16, 32}, {32, 0, 16, 32}, {48, 0, 16, 32}};
SDL_Rect array_sprite_right[NB_ANIMATIONS_ENEMY] = {{0, 32, 16, 32}, {16, 32, 16, 32}, {32, 32, 16, 32}, {48, 32, 16, 32}};
SDL_Rect array_sprite_up[NB_ANIMATIONS_ENEMY] = {{0, 64, 16, 32}, {16, 64, 16, 32}, {32, 64, 16, 32}, {48, 64, 16, 32}};
SDL_Rect array_sprite_left[NB_ANIMATIONS_ENEMY] = {{0, 96, 16, 32}, {16, 96, 16, 32}, {32, 96, 16, 32}, {48, 96, 16, 32}};

void init_enemy(enemy_t *enemy, int x, int y, int orientation, int speed)
{
    enemy->orientation = orientation;
    enemy->last_orientation = ORIENTATION_ENEMY_DOWN;
    for (int i = 0; i < NB_ANIMATIONS_ENEMY; ++i)
    {
        enemy->animation[i] = array_sprite_down[i];
        enemy->animation[i + 4] = array_sprite_right[i];
        enemy->animation[i + 8] = array_sprite_up[i];
        enemy->animation[i + 12] = array_sprite_left[i];
    }
    enemy->animation_speed = 10;
    enemy->current_frame = 0;
    enemy->frames = NB_ANIMATIONS_ENEMY;
    enemy->frame = 0;
    enemy->is_moving = false;
    init_sprite(&enemy->sprite, x, y, NPC_WIDTH / 4, NPC_HEIGHT / 4, speed, true);
}