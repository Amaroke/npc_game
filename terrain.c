/**
 *\file terrain.c
 *\brief Définition des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/


#include "terrain.h"
#include "sprite.h"



void init_block(sprite_t *sprite, int x, int y, int h, int w, bool collision, bool is_visible)
{
    init_sprite(sprite, x, y, h, w, 0, is_visible);

    
}

