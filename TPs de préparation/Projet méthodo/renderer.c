/**
 *\file renderer.c
 *\brief Fonctions de l'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#include "renderer.h"
void refresh_graphics(SDL_Renderer *renderer, world_t *world, ressources_t *ressources)
{
	//On vide le renderer :
	clear_renderer(renderer);

	//Application des ressources dans le renderer :
	apply_background(renderer, ressources);
	apply_sprite(renderer, ressources->ship, world->ship);
	apply_sprite_boss(renderer, ressources->boss, world->boss);
	refresh_missile(renderer, ressources->missile, world->missile, NB_MISSILES);
	refresh_missile(renderer, ressources->missile_purple,  world->missile_purple, TOTAL_PURPLE);
	refresh_missile(renderer, ressources->missile_orange,  world->missile_orange, TOTAL_ORANGE);
	refresh_missile(renderer, ressources->missile_boss,  world->missile_boss, BOSS_MISSILES);
	refresh_enemy(renderer, ressources->enemy_blue, world->blue, TOTAL_BLUE);
	refresh_enemy(renderer, ressources->enemy_red, world->red,TOTAL_RED);
	refresh_enemy(renderer, ressources->enemy_green, world->green,TOTAL_GREEN);
	refresh_enemy(renderer, ressources->enemy_purple, world->purple,TOTAL_PURPLE);
	refresh_enemy(renderer, ressources->enemy_orange, world->orange,TOTAL_ORANGE);
	//Gestion de l'affichage du score des vagues et des PV :
	if (world->etat_partie == EN_COURS)
	{
		char *str = malloc(sizeof(char) * 20); //On réserve une chaine de 20 caractères pour le score.
		sprintf(str, "%6d", world->score);	   //On réserve un emplacement à la valeur du score.
		apply_text(renderer, 5, 5, 50, 30, str, ressources->font);
		char *wave = malloc(sizeof(char) * 15);	   //On réserve une chaine de 15 caractères pour les vagues.
		sprintf(wave, "WAVE : %1d", world->vague); //On concatène "WAVE : " avec la valeur de la vague.
		apply_text(renderer, 215, 5, 80, 25, wave, ressources->font);
		char *health = malloc(sizeof(char) * 15);	  //On réserve une chaine de 15 caractères pour les points de vie.
		sprintf(health, "HP : %1d", world->ship->hp); //On concatène "HP : " avec la valeur des points de vie.
		apply_text(renderer, 239, 455, 56, 24, health, ressources->font);
	}
	//On affiche un message entre les vagues :
	if (world->compteur == TOTAL_VAGUE_1)
	{
		world->vague = 2;
	}
	if (world->compteur == TOTAL_VAGUE_1 + TOTAL_VAGUE_2)
	{
		world->vague = 3;
	}
	if (world->compteur == TOTAL_VAGUE_1 + TOTAL_VAGUE_2 + TOTAL_VAGUE_3)
	{
		world->vague = 4;
	}
	if (world->compteur == TOTAL_VAGUE_1 + TOTAL_VAGUE_2 + TOTAL_VAGUE_3 + TOTAL_VAGUE_4)
	{
		world->vague = 5;
	}
	if (world->compteur == TOTAL_VAGUE_1 + TOTAL_VAGUE_2 + TOTAL_VAGUE_3 + TOTAL_VAGUE_4 + TOTAL_VAGUE_5)
	{
		world->vague = 6;
	}
	//On affiche un message en fin de partie :
	if (world->etat_partie == PERDU)
	{
		char *str = malloc(sizeof(char) * 20);		//On réserve une chaine de 20 caractères pour le score.
		sprintf(str, "Result : %6d", world->score); //On concatène "Score : " avec la valeur du score.
		apply_text(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 75, 200, 100, "LOST !", ressources->font);
		apply_text(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 10, 200, 50, str, ressources->font);
	}
	if (world->etat_partie == PARFAIT || world->etat_partie == GAGNE)
	{
		char *str = malloc(sizeof(char) * 20);		//On réserve une chaine de 20 caractères pour le score.
		sprintf(str, "Result : %6d", world->score); //On concatène "Score : " avec la valeur du score.
		apply_text(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 75, 200, 100, "WON !", ressources->font);
		apply_text(renderer, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 10, 200, 50, str, ressources->font);
	}

	//On met à jour l'écran :
	update_screen(renderer);
}


void refresh_enemy(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total)
{
	for (int i = 0; i < total; i++)
	{
		apply_sprite(renderer, texture, tab[i]);
	}
}

void refresh_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *tab[], int total)
{
	for (int i = 0; i < total; i++)
	{
		apply_sprite_missile(renderer, texture, tab[i]);
	}
}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, world_t *world)
{
	clean_data_1(world);
	clean_ressources(ressources);
	clean_sdl(renderer, window);
}

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, world_t *world)
{
	init_ttf();
	init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
	init_data_1(world);
	init_ressources(*renderer, ressources);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
	if (sprite->is_visible == 1)
	{
		apply_texture(texture, renderer, sprite->x - (SHIP_SIZE / 2), sprite->y - (SHIP_SIZE / 2)); //On donne les coordonnées du coin en haut à gauche du sprite et non pas du centre du sprite.
	}
}

void apply_sprite_boss(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
	if (sprite->is_visible == 1)
	{
		apply_texture(texture, renderer, sprite->x - (BOSS_SIZE / 2), sprite->y - (BOSS_SIZE / 2)); //On donne les coordonnées du coin en haut à gauche du sprite et non pas du centre du sprite.
	}
}

void apply_sprite_missile(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite)
{
	if (sprite->is_visible == 1)
	{
		apply_texture(texture, renderer, sprite->x - (MISSILE_SIZE / 2), sprite->y - (MISSILE_SIZE / 2)); //On donne les coordonnées du coin en haut à gauche du sprite et non pas du centre du sprite.
	}
}
