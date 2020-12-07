/**
 *\file ressources.h
 *\brief Déclaration des ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#ifndef RESSOURCES_H
#define RESSOURCES_H

//Constantes

#define NPC_TEST_WIDTH 64
#define NPC_TEST_HEIGHT 128

#include <SDL2/SDL.h>
#include "fonctions_SDL.h"
#include "terrain.h"

/**
 *\struct texture_t
 *\brief Représentation pour stocker les ressources nécessaires à l'affichage graphique.
*/
typedef struct ressources_s
{
	SDL_Texture *background; /*!<Texture liée à l'image du sol.*/
	SDL_Texture *player;	 /*!<Texture liée au joueur.*/
	bloc_t *dark_oak;		 /*!<Texture en bois de chêne noir.*/
	bloc_t *grass;			 /*!<Texture d'herbe.*/
	bloc_t *stone;			 /*!<Texture de pierre.*/
	bloc_t *ice;			 /*!<Texture de glace.*/
	bloc_t *sand;			 /*!<Texture de sable.*/
	bloc_t *light_oak;		 /*!<Texture en bois de chêne.*/
	bloc_t *magma;			 /*!<Texture de magma.*/
	bloc_t *brick;			 //*!<Texture en pierre taillée.*/
	bloc_t *water;			 /*!<Texture de l'eau.*/
} ressources_t;

/**
 *\brief La fonction initialise les textures.
 *\param renderer La surface correspondant à l'écran de jeu.
 *\param ressources Les ressources du jeu.
*/
void init_ressources(SDL_Renderer *renderer, ressources_t *ressources);

/**
 *\brief La fonction nettoie les ressources.
 *\param ressources Les ressources.
*/
void clean_ressources(ressources_t *ressources);

#endif
