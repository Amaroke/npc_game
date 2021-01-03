/**
 *\file event.h
 *\brief Déclaration des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/

#ifndef EVENT_H
#define EVENT_H
#include <math.h>
#include "fonctions_SDL.h"
#include "jeu.h"
#include "level.h"

/**
 *\brief La fonction permet de déplacer le joueur.
 *\param event Les évenements clavier.
 *\param game Le jeu.
 *\param window La fenètre de jeu.
*/
void movement_player(SDL_Event *event, game_t *game, SDL_Window *window);

/**
 *\brief La fonction gère le choix du menu.
 *\param event Les évenements clavier.
 *\param window La fenètre de jeu.
 *\param game Le jeu.
*/
int choix_menu(SDL_Event *event, SDL_Window *window, game_t *game);

/**
 *\brief La fonction gère le choix du niveau.
 *\param event Les évenements clavier.
 *\param window La fenètre de jeu.
 *\param game Le jeu.
*/
level_t choisir_level(SDL_Event *event, SDL_Window *window, game_t *game);
#endif