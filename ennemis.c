/**
 *\file ennemis.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 janvier 2021
*/

#include "ennemis.h"
#include "ressources.h"

SDL_Rect array_sprite_down_enemy[NB_ANIMATIONS_ENEMY] = {{0, 0, 16, 32}, {16, 0, 16, 32}, {32, 0, 16, 32}, {48, 0, 16, 32}};
SDL_Rect array_sprite_right_enemy[NB_ANIMATIONS_ENEMY] = {{0, 32, 16, 32}, {16, 32, 16, 32}, {32, 32, 16, 32}, {48, 32, 16, 32}};
SDL_Rect array_sprite_up_enemy[NB_ANIMATIONS_ENEMY] = {{0, 64, 16, 32}, {16, 64, 16, 32}, {32, 64, 16, 32}, {48, 64, 16, 32}};
SDL_Rect array_sprite_left_enemy[NB_ANIMATIONS_ENEMY] = {{0, 96, 16, 32}, {16, 96, 16, 32}, {32, 96, 16, 32}, {48, 96, 16, 32}};

void init_enemy(enemy_t *enemy, int x, int y, int orientation, int speed, bool is_visible)
{
    enemy->orientation = orientation;
    enemy->movement = 0;
    enemy->last_orientation = ORIENTATION_ENEMY_DOWN;
    for (int i = 0; i < NB_ANIMATIONS_ENEMY; ++i)
    {
        enemy->animation[i] = array_sprite_down_enemy[i];
        enemy->animation[i + 4] = array_sprite_right_enemy[i];
        enemy->animation[i + 8] = array_sprite_up_enemy[i];
        enemy->animation[i + 12] = array_sprite_left_enemy[i];
    }
    enemy->current_frame = 0;
    enemy->frames = NB_ANIMATIONS_ENEMY;
    enemy->frame = 0;
    enemy->is_moving = false;
    enemy->movement = 0;
    enemy->animation_speed = 2;
    init_sprite(&enemy->sprite, x, y, NPC_WIDTH / 4, NPC_HEIGHT / 4, speed, is_visible);
}