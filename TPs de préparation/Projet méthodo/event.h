/**
 *\file event.h
 *\brief Bibliothèque de event.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef EVENT_H
#define EVENT_H
#include "world.h"
#include "biblio.h"

/**
 *\brief La fonction gère les interactions de l'utilisateur.
 *\param event Paramètre qui contient les événements.
 *\param world Les données du monde.
*/
void handle_events(SDL_Event *event, world_t *world);

#endif