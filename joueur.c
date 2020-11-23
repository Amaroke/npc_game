/**
 *\file joueur.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "joueur.h"

void init_player(player_t *player, int x, int y, int s)
{
    player->x = x;
    player->y = y;
    player->s = s;
}

void move_left(player_t *player)
{
    player->x -= MOVING_STEP;
}

void move_right(player_t *player)
{
    player->x += MOVING_STEP;
}

void move_up(player_t *player)
{
    player->y += MOVING_STEP;
}

void move_down(player_t *player)
{
    player->y -= MOVING_STEP;
}
