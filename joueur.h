/**
 *\file joueur.h
 *\brief Déclaration du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#ifndef JOUEUR_H
#define JOUEUR_H

//Constantes

#define MOVING_STEP 10

#include "sprite.h"

typedef struct player_s
{
    sprite_t player;
    int x;           /*!< Abscisses par rapport au centre de l'image.*/
    int y;           /*!< Ordonnée par rapport au centre de l'image. */
    int s;           /*!< Vitesse de déplacement du sprite. */
} player_t;

/**
 *\brief La fonction initialise le player.
 *\param player Le player à initialiser.
 *\param x L'abscisse.
 *\param y L'ordonnée.
 *\param s La vitesse.
*/
void init_player(player_t *player, int x, int y, int s);

/**
 *\brief La fonction permet au joueur de se déplacer vers la gauche.
*/
void move_left(player_t *player);

/**
 *\brief La fonction permet au joueur de se déplacer vers la droite.
*/
void move_right(player_t *player);

/**
 *\brief La fonction permet au joueur de se déplacer vers le haut.
*/
void move_up(player_t *player);

/**
 *\brief La fonction permet au joueur de se déplacer vers le bas.
*/
void move_down(player_t *player);

#endif