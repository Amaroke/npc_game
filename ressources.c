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
	//ressources->stone = load_picture("ressources/block_sprite/.bmp", renderer, 0, 0, 0);
	ressources->dark_oak = load_picture("ressources/block_sprite/dark_oak.bmp", renderer, 0, 0, 0);
	ressources->ice = load_picture("ressources/block_sprite/ice.bmp", renderer, 0, 0, 0);
	ressources->light_oak = load_picture("ressources/block_sprite/light_oak.bmp", renderer, 0, 0, 0);
	ressources->magma = load_picture("ressources/block_sprite/magma.bmp", renderer, 0, 0, 0);
	ressources->brick = load_picture("ressources/block_sprite/wall.bmp", renderer, 0, 0, 0);
	ressources->water = load_picture("ressources/block_sprite/water.bmp", renderer, 0, 0, 0);
}

void clean_ressources(ressources_t *ressources)
{
	clean_texture(ressources->background);
	clean_texture(ressources->player);
	clean_texture(ressources->dark_oak);
	clean_texture(ressources->ice);
	clean_texture(ressources->light_oak);
	clean_texture(ressources->magma);
	clean_texture(ressources->brick);
	clean_texture(ressources->water);
}
