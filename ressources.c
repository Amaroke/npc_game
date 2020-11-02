/**
 *\file ressources.c
 *\brief Gestion des ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#include "ressources.h"

void clean_ressources(ressources_t *ressources)
{
	clean_texture(ressources->background);
}

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources)
{
	//ressources->background = load_image("ressources/background.bmp", renderer);
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources)
{
	if (ressources->background != NULL)
	{
		apply_texture(ressources->background, renderer, 0, 0);
	}
}
