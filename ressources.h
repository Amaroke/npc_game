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
#include "fonctions_ttf.h"

/**
 *\struct texture_t
 *\brief Représentation pour stocker les ressources nécessaires à l'affichage graphique.
*/
typedef struct ressources_s
{
	SDL_Texture *background; /*!<Texture liée à l'image du sol.*/
	SDL_Texture *player;	 /*!<Texture liée au joueur.*/
	SDL_Texture *vortex;	 /*!<Texture liée au vortex.*/
	SDL_Texture *dark_oak;	 /*!<Texture en bois de chêne noir.*/
	SDL_Texture *grass;		 /*!<Texture d'herbe.*/
	SDL_Texture *stone;		 /*!<Texture de pierre.*/
	SDL_Texture *ice;		 /*!<Texture de glace.*/
	SDL_Texture *sand;		 /*!<Texture de sable.*/
	SDL_Texture *light_oak;	 /*!<Texture en bois de chêne.*/
	SDL_Texture *magma;		 /*!<Texture de magma.*/
	SDL_Texture *wall;		 //*!<Texture en pierre taillée.*/
	SDL_Texture *water;		 /*!<Texture de l'eau.*/
	TTF_Font *font;			 /*!<Texture de la police d'écriture.*/
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
