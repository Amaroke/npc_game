/**
 *\file affichage.h
 *\brief Déclaration des fonctions d'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 14 novembre 2020
*/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//Constantes

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 500

#include <SDL2/SDL.h>
#include "sprite.h"
#include "ressources.h"
#include "joueur.h"

/**
 *\brief La fonction initialise le jeu.
 *\param window La fenêtre.
 *\param renderer L'affichage.
 *\param ressources Les ressources.
*/
void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources);

/**
 *\brief La fonction nettoie le jeu.
 *\param window La fenêtre.
 *\param renderer L'affichage.
 *\param ressources Les ressources.
*/
void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources);

void update_graphics(SDL_Renderer *renderer,player_t *player, SDL_Rect *src, ressources_t *ressources);

/**
 *\brief La fonction applique la texture du sprite sur l'affichage lié à l'écran de jeu.
 *\param renderer L'affichage.
 *\param texture La texture du sprite.
 *\param sprite Le sprite.
 *\param src Le rectangle source.
 *\param x Le décalage sur les abscisses.
 *\param y Le décalage sur les ordonnées.
*/
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite, SDL_Rect src, int x, int y);

/**
 *\brief La fonction applique la texture du fond sur le renderer lié l'affichage lié à l'écran de jeu.
 *\param renderer L'affichage.
 *\param ressources Les ressources.
*/
void apply_background(SDL_Renderer *renderer, ressources_t *ressources);

#endif