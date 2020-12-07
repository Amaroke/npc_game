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

typedef struct bloc_s
{
    sprite_t sprite; /*!<Le sprite du bloc.*/
    int effet;       /*!<L'effet que le bloc applique sur les entités.*/
    int x;           /*!<Les abscisses*/
    int y;           /*!<Les ordonnées*/
    bool collision;  /*!<Vrai si c'est un mur, Faux si on peut marcher dessus*/
} bloc_t;


#endif