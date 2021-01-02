/**
 *\file ressources.c
 *\brief Gestion des ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "ressources.h"

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources)
{
	ressources->background = load_picture("ressources/background.bmp", renderer, 0, 0, 0);
	ressources->player = load_picture("ressources/player_sprite/player.bmp", renderer, 0, 0, 0);
	ressources->vortex = load_picture("ressources/vortex_sprite/vortex.bmp", renderer, 0, 0, 0);
	ressources->health = load_picture("ressources/block_sprite/health.bmp", renderer, 255, 0, 0);
	ressources->ice = load_picture("ressources/block_sprite/ice.bmp", renderer, 0, 0, 0);
	ressources->light_oak = load_picture("ressources/block_sprite/light_oak.bmp", renderer, 0, 0, 0);
	ressources->magma = load_picture("ressources/block_sprite/magma.bmp", renderer, 0, 0, 0);
	ressources->wall = load_picture("ressources/block_sprite/wall.bmp", renderer, 0, 0, 0);
	ressources->water = load_picture("ressources/block_sprite/water.bmp", renderer, 0, 0, 0);
	ressources->font = load_font("ressources/font/font.ttf", 16);
}

void clean_ressources(ressources_t *ressources)
{
	clean_texture(ressources->background);
	clean_texture(ressources->player);
	clean_texture(ressources->health);	  // Identifiant : 6
	clean_texture(ressources->ice);		  // Identifiant : 4
	clean_texture(ressources->light_oak); // Identifiant : 5
	clean_texture(ressources->magma);	  // Identifiant : 3
	clean_texture(ressources->wall);	  // Identifiant : 1
	clean_texture(ressources->water);	  // identifiant : 2
	clean_font(ressources->font);
}
