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
	SDL_Texture *background; 	/*!<Texture liée à l'image du sol.*/
	SDL_Texture *player;	 	/*!<Texture liée au joueur.*/
	wall_t *stone_brick_wall; 	/*!<Texture liée au mur en pierre taillée.*/
	wall_t *dark_oak_wall;		/*!<Texture liée au mur en bois de chêne noir.*/
	ground_t *grass_ground; 	/*!<Texture liée au sol d'herbe.*/
	ground_t *stone_ground; 	/*!<Texture liée au sol de pierre.*/
	ground_t *ice_ground;		/*!<Texture liée au sol de glace.*/
	ground_t *sand_ground;		/*!<Texture liée au sol de sable.*/
	ground_t *oak_ground;		/*!<Texture liée au sol en bois de chêne.*/
	ground_t *magma_ground;		/*!<Texture liée au sol de magma.*/
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
