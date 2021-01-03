/**
 *\file menu.h
 *\brief Déclaration des fonctions du menu.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 3 janvier 2020
*/

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include "fonctions_SDL.h"
#include "ressources.h"
#include "jeu.h"
#include "event.h"
#include "affichage.h"
#include "level.h"

/**
 *\brief La fonction initialise le menu.
 *\param renderer L'écran.
 *\param ressources Les ressources.
 *\param event Les évènements.
 *\param window La fenêtre de jeu.
 *\param game Le jeu.
 *\param jeu_en_cours Si le jeu est en cours.
*/
void start_menu(SDL_Renderer *renderer, ressources_t ressources, SDL_Event *event, SDL_Window *window, game_t *game, bool *jeu_en_cours);

#endif