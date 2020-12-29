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

/**
 * \brief Conversion d'un tableau d'int en un tableau de blocks.
 * \param tab_int Le tableau d'int.
 * \param row Le nombre de lignes.
 * \param column Le nombre de colonnes.
 **/
block_t **int_to_block(int **tab_int, int row, int column);

/**
 * \brief Conversion du contenu d'un fichier txt en un tableau d'entiers.
 * \param fichier Le fichier à traiter
 **/
int **txt_to_int(char* fichier);


#endif