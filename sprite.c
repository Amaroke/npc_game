/**
 *\file sprite.c
 *\brief Gestion des sprites.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "sprite.h"
#include "fonctions_SDL.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int s, bool is_visible)
{
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
    sprite->s = s;
    sprite->is_visible = is_visible;
}

bool sprite_collide(sprite_t *player, sprite_t *sprite)
{
    if (sprite->is_visible)
    {
        if (player->x > sprite->x - 16 && player->x < sprite->x + BLOC_SIZE && player->y < sprite->y + BLOC_SIZE - 20 && player->y > sprite->y - BLOC_SIZE + 5)
        {
            return true;
        }
    }
    return false;
}

sprite_t *copy_sprite(sprite_t *sprite)
{
    sprite_t *copy = malloc(sizeof(sprite_t));
    init_sprite(copy, sprite->x, sprite->y, sprite->w, sprite->h, sprite->s, sprite->is_visible);
    return copy;
}