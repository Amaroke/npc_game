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

typedef struct wall_s
{
    sprite_t sprite;        /*!<Le sprite du mur.*/
    int code;               /*!<L'orientation du joueur.*/
    int x;                  /*!<Les abscisses*/
    int y;                  /*!<Les ordonnées*/
} wall_t;

typedef struct ground_s
{
    sprite_t sprite;        /*!<Le sprite du sol.*/
    int code;               /*!<L'orientation du joueur.*/
    int x;                  /*!<Les abscisses*/
    int y;                  /*!<Les ordonnées*/
} ground_t;


#endif