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
#define ORIENTATION_DOWN 0
#define ORIENTATION_UP 1
#define ORIENTATION_LEFT 2
#define ORIENTATION_RIGHT 3
#define NB_ANIMATIONS 4

#include <SDL2/SDL.h>
#include "sprite.h"

typedef struct player_s
{
    sprite_t sprite;        /*!<Le sprite du joueur.*/
    int orientation;        /*!<L'orientation du joueur.*/
    SDL_Rect animation[16]; /*!<Les sprites découpés des animations du joueur.*/
} player_t;

/**
 *\brief La fonction initialise le player.
 *\param player Le player à initialiser.
 *\param orientation
*/
void init_player(player_t *player, int orientation);

/**
 *\brief La fonction gère les entrées clavier pour le joueur.
 *\param event Les évènements claviers.
 *\param player Le joueur.
*/
void movement_player(SDL_Event *event, player_t *player);

#endif