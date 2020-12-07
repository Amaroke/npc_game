/**
 *\file terrain.h
 *\brief Déclaration des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL2/SDL.h>
#include "sprite.h"

typedef struct block_s
{
    sprite_t sprite; /*!<Le sprite du bloc.*/
    int effet;       /*!<L'effet que le bloc applique sur les entités.*/
    bool collision;  /*!<Vrai si c'est un mur, Faux si on peut marcher dessus*/
} block_t;


void init_block(sprite_t *sprite, int x, int y, int h, int w, bool collision, bool is_visible);


#endif