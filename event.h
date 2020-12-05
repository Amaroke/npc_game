/**
 *\file event.c
 *\brief Déclaration des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/


#ifndef EVENT_H
#define EVENT_H
#include "monde.h"


/**
 *\brief La fonction initialise le player.
 *\param event Les évenements clavier.
 *\param world Le monde.
*/
void movement_player(SDL_Event *event, world_t *world);

#endif