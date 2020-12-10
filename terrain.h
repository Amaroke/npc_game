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


/**
 * \brief L'initialisation d'un bloc.
 * \param block Le bloc.
 * \param x Les abscisses.
 * \param y Les ordonnées.
 * \param h La hauteur.
 * \param w La largeur.
 * \param is_visible La visibilité.
 * \param effet L'effet du bloc.
 * \param collision Les collisions avec le bloc.
 **/ 
void init_block(block_t *block, int x, int y, int h, int w, bool is_visible, int effet, bool collision);


#endif