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
	clean_texture(ressources->ship);
	clean_texture(ressources->boss);
	clean_texture(ressources->enemy_blue);
	clean_texture(ressources->enemy_red);
	clean_texture(ressources->enemy_green);
	clean_texture(ressources->enemy_purple);
	clean_texture(ressources->enemy_orange);
	clean_texture(ressources->missile);
	clean_texture(ressources->missile_purple);
	clean_texture(ressources->missile_orange);
	clean_texture(ressources->missile_boss);
	clean_font(ressources->font);
}

void init_ressources(SDL_Renderer *renderer, ressources_t *ressources)
{
	ressources->background = load_image("ressources/space-background.bmp", renderer);
	ressources->ship = load_image("ressources/spaceship.bmp", renderer);
	ressources->boss = load_image("ressources/boss.bmp", renderer);
	ressources->enemy_blue = load_image("ressources/blue.bmp", renderer);
	ressources->enemy_red = load_image("ressources/red.bmp", renderer);
	ressources->enemy_green = load_image("ressources/green.bmp", renderer);
	ressources->enemy_purple = load_image("ressources/purple.bmp", renderer);
	ressources->enemy_orange = load_image("ressources/orange.bmp", renderer);
	ressources->missile = load_image("ressources/missile.bmp", renderer);
	ressources->missile_purple = load_image("ressources/missile_purple.bmp", renderer);
	ressources->missile_orange = load_image("ressources/missile_orange.bmp", renderer);
	ressources->missile_boss = load_image("ressources/missile_boss.bmp", renderer);
	ressources->font = load_font("ressources/Minecraft.ttf", 16); //Modifier la taille de la police, modifie les performances.
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources)
{
	if (ressources->background != NULL)
	{
		apply_texture(ressources->background, renderer, 0, 0);
	}
}
