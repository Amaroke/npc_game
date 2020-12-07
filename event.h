/**
 *\file event.h
 *\brief Déclaration des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/


#ifndef EVENT_H
#define EVENT_H
#include "jeu.h"


/**
 *\brief La fonction initialise le player.
 *\param event Les évenements clavier.
 *\param game Le jeu.
*/
void movement_player(SDL_Event *event, game_t *game);

#endif