/**
 *\file sprite.c
 *\brief Gestion des sprites.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "sprite.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, bool is_visible) {
    sprite->x = x;
    sprite->y = y;
    sprite->w = w;
    sprite->h = h;
    sprite->v = v;
    sprite->is_visible = is_visible;
}

void print_sprite_test(sprite_t *sprite)
{
	printf("x : %d, y : %d, w : %d, h : %d, v : %d, is_visible : %s\n", sprite->x, sprite->y, sprite->w, sprite->h, sprite->v, sprite->is_visible ? "true" : "false");
}