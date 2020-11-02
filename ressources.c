/**
 *\file ressources.c
 *\brief Gestion des ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "ressources.h"

void clean_ressources(ressources_t *ressources)
{
	clean_texture(ressources->background);
}

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources)
{
	ressources->background = charger_image("ressources/background.bmp", renderer, 0, 0, 0);
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources)
{
	if (ressources->background != NULL)
	{
		apply_texture(ressources->background, renderer, 0, 0);
	}
}
