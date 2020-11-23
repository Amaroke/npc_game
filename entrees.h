/**
 *\file entrees.h
 *\brief Déclaration des fonctions d'entrées.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 23 novembre 2020
*/

#ifndef ENTREES_H
#define ENTREES_H

#include <SDL2/SDL.h>
#include "joueur.h"

/**
 *\brief La fonction gère les entrées clavier pour le joueur.
 *\param event Les évènements claviers.
 *\param player Le joueur.
*/
void input_player(SDL_Event *event, player_t *player);

#endif