/**
 *\file ressources.h
 *\brief Bibliothèque de ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <SDL2/SDL.h>

/**
 *\struct texture_t
 *\brief Représentation pour stocker les ressources nécessaires à l'affichage graphique.
*/
typedef struct ressources_s
{
	SDL_Texture	*background; /*!<Texture liée à l'image du sol.*/
} ressources_t;

/**
 *\brief La fonction nettoie les ressources.
 *\param ressources Les ressources.
*/
void clean_ressources(ressources_t *ressources);

/**
 *\brief La fonction initialise les textures.
 *\param screen La surface correspondant à l'écran de jeu.
 *\param ressources Les ressources du jeu.
*/
void init_ressources(SDL_Renderer *renderer, ressources_t *ressources);

/**
 *\brief La fonction applique la texture du fond sur le renderer lié à l'écran de jeu.
 *\param renderer Le renderer.
 *\param ressources Les ressources du jeu.
*/
void apply_background(SDL_Renderer *renderer, ressources_t *ressources);

#endif
