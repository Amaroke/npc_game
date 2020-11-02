/**
 *\file sprite.c
 *\brief Gestion des sprites.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#include "sprite.h"

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, int visible, int hp)
{
	sprite->x = x;
	sprite->y = y;
	sprite->w = w;
	sprite->h = h;
	sprite->v = v;
	sprite->is_visible = visible;
	sprite->hp = hp;
}

void print_sprite(sprite_t *sprite)
{
	printf("%d\n", sprite->x);
	printf("%d\n", sprite->y);
	printf("%d\n", sprite->w);
	printf("%d\n", sprite->h);
	printf("%d\n", sprite->v);
	printf("%d\n", sprite->is_visible);
	printf("%d\n", sprite->hp);
}

void set_visible(sprite_t *sprite)
{
	sprite->is_visible = 1;
}

void set_invisible(sprite_t *sprite)
{
	sprite->is_visible = 0;
}