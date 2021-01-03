/**
 *\file vortex.h
 *\brief Déclaration des fonctions du vortex.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 31 décembre 2020
*/

#ifndef VORTEX_H
#define VORTEX_H

#define NB_ANIMATIONS_VORTEX 8

#include "fonctions_SDL.h"
#include "sprite.h"

typedef struct vortex_s
{
    sprite_t sprite;       /*!<Le sprite du vortex.*/
    SDL_Rect animation[8]; /*!<Les sprites découpés des animations du vortex.*/
    int animation_speed;   /*!<La vitesse d'animation.*/
    int frames;            /*!<Le nombre de sprites qui compose une animation complète.*/
    int current_frame;     /*!<Le calcul de la frame suivante.*/
} vortex_t;

/**
 *\brief La fonction initialise le vortex.
 *\param vortex Le vortex à initialiser.
 *\param x Abscisse où l'initialiser.
 *\param y Ordonnée où l'initialiser.
*/
void init_vortex(vortex_t *vortex, int x, int y);

/**
 *\brief La collision du joueur avec le vortex.
 *\param vortex Le vortex.
 *\param player Le joueur.
*/
bool vortex_collide(vortex_t *vortex, sprite_t *player);

#endif