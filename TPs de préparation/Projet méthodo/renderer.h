/**
 *\file renderer.h
 *\brief Bibliothèque de renderer.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef RENDERER_H
#define RENDERER_H
#include "biblio.h"
#include "world.h"
#include "ressources.h"

/**
 *\brief La fonction rafraîchit l'écran en fonction de l'état des données du monde.
 *\param renderer La surface de l'écran de jeu.
 *\param world Les données du monde.
 *\param ressources Les ressources.
*/
void refresh_graphics(SDL_Renderer *renderer, world_t *world, ressources_t *ressources);

/**
 *\brief La fonction rafraîchit l'écran pour les ennemis.
 *\param renderer La surface de l'écran de jeu.
 *\param texture La texture.
 *\param tab Le tableau.
 *\param total Le total.
*/
void refresh_enemy(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total);

/**
 *\brief La fonction rafraîchit l'écran pour les missiles.
 *\param renderer La surface de l'écran de jeu.
 *\param texture La texture.
 *\param tab Le tableau.
 *\param total Le total.
*/
void refresh_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total);

/**
 *\brief La fonction nettoie la partie graphique (SDL), nettoie des ressources et des données.
 *\param window La fenêtre du jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources.
 *\param world Le monde.
*/
void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, world_t *world);

/**
 *\brief La fonction initialise la partie graphique (SDL), charge des ressources et initialise des données.
 *\param window La fenêtre du jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources.
 *\param world Le monde.
*/
void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, world_t *world);

/**
 *\brief La fonction applique la texture du vaisseau sur le renderer lié à l'écran de jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources du jeu.
 *\param sprite Le sprite.
*/
void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

/**
 *\brief La fonction applique la texture du boss sur le renderer lié à l'écran de jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources du jeu.
 *\param sprite Le sprite.
*/
void apply_sprite_boss(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

/**
 *\brief La fonction applique la texture du missile sur le renderer lié à l'écran de jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources du jeu.
 *\param sprite Le sprite.
*/
void apply_sprite_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite);

#endif