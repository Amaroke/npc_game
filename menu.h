/**
 *\file fonctions_ttf.h
 *\brief Déclaration des fonctions d'affichage de textes.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 31 décembre 2020
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

void start_menu(SDL_Renderer *renderer, ressources_t ressources, SDL_Event *event, SDL_Window *window, game_t *game);

#endif