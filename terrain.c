/**
 *\file terrain.c
 *\brief Définition des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/


#include "terrain.h"
#include "sprite.h"



void init_block(block_t *block, int x, int y, int h, int w, bool is_visible, int effet, bool collision)
{
    init_sprite(&block->sprite, x, y, h, w, 0, is_visible);
    block->effet = effet;
    block->collision = collision;  
}

