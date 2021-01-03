/**
 *\file terrain.h
 *\brief Déclaration des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "sprite.h"
#include "joueur.h"

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
 * \param tab_block Le tableau qui récupère les blocs.
 * \param tab_int Le tableau d'int.
 **/
void int_to_block(block_t **tab_block, int **tab_int);

/**
 * \brief Applique les effets des blocs.
 * \param player Le joueur sur lequel appliqué l'effet.
 * \param block Les blocs.
 **/
void apply_block_effect(player_t *player, block_t **block);

/**
 * \brief Conversion du contenu d'un fichier txt en un tableau d'entiers.
 * \param fichier Le fichier à traiter
 **/
int **txt_to_int(char *fichier);

/**
 * \brief Test de la collision entre le joueur et le terrain.
 * \param game Le jeu.
 **/
bool bloc_collide(sprite_t *player, block_t  **block);

#endif