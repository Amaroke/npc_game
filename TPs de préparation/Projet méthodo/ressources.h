/**
 *\file ressources.h
 *\brief Bibliothèque de ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef RESSOURCES_H
#define RESSOURCES_H
#include "biblio.h"

/**
 *\struct texture_t
 *\brief Représentation pour stocker les ressources nécessaires à l'affichage graphique.
*/
typedef struct ressources_s
{
	SDL_Texture *background;	 /*!< Texture liée à l'image du fond de l'écran. */
	SDL_Texture *ship;			 /*!< Texture liée à l'image du vaisseau. */
	SDL_Texture *boss;			 /*!< Texture liée à l'image du boss. */
	SDL_Texture *enemy_blue;	 /*!< Texture liée à l'image de l'ennemi blue. */
	SDL_Texture *enemy_red;		 /*!< Texture liée à l'image de l'ennemi red. */
	SDL_Texture *enemy_green;	 /*!< Texture liée à l'image de l'ennemi green. */
	SDL_Texture *enemy_purple;	 /*!< Texture liée à l'image de l'ennemi purple. */
	SDL_Texture *enemy_orange;	 /*!< Texture liée à l'image de l'ennemi orange. */
	SDL_Texture *missile;		 /*!< Texture liée à l'image d'un missile du joueur. */
	SDL_Texture *missile_purple; /*!< Texture liée à l'image d'un missile ennemi purple. */
	SDL_Texture *missile_orange; /*!< Texture liée à l'image d'un missile ennemi orange. */
	SDL_Texture *missile_boss;	 /*!< Texture liée à l'image d'un missile du boss. */
	TTF_Font *font;				 /*!< Texture de la police. */
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
