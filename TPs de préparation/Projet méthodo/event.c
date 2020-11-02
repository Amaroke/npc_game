/**
 *\file event.c
 *\brief Fonctions des interactions du joueur avec le jeu.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#include "event.h"

void handle_events(SDL_Event *event, world_t *world)
{
	Uint8 *keystates;
	while (SDL_PollEvent(event))
	{
		//Si l'utilisateur ferme la fenêtre :
		if (event->type == SDL_QUIT)
		{
			//On indique la fin du jeu.
			world->gameover = 1;
		}

		//Si une touche est appuyée :
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_RIGHT)
			{
				printf("La touche ➡️ est appuyée ! \n");
				for (int i = 0; i < MOVING_STEP; ++i)
				{
					if (world->ship->x + (world->ship->w / 2) < SCREEN_WIDTH)
					{
						++world->ship->x;
					}
				}
			}
			if (event->key.keysym.sym == SDLK_LEFT)
			{
				printf("La touche ⬅️ est appuyée ! \n");
				for (int i = 0; i < MOVING_STEP; ++i)
				{
					if (world->ship->x - (world->ship->w / 2) > 0)
					{
						--world->ship->x;
					}
				}
			}
			if (event->key.keysym.sym == SDLK_ESCAPE)
			{
				printf("La touche échap est appuyée ! \n");
				world->gameover = 1;
			}
			if (event->key.keysym.sym == SDLK_SPACE && world->ship->is_visible == 1)
			{
				printf("La touche espace est appuyée ! \n");
				for (int i = 0; i < NB_MISSILES - 1; i++)
				{
					//On gère le missile à envoyer, on lui donne sa vitesse et un point de vie après l'avoir rendu visible.
					if (world->missile[0]->is_visible == 0)
					{
						world->missile[i]->is_visible = 1;
						world->missile[i]->v = MISSILE_SPEED;
						world->missile[i]->hp = 1;
						i = NB_MISSILES - 1;
					}
					else if (world->missile[i]->is_visible == 1 && world->missile[i + 1]->is_visible == 0)
					{
						world->missile[i + 1]->is_visible = 1;
						world->missile[i + 1]->v = MISSILE_SPEED;
						world->missile[i + 1]->hp = 1;
						i = NB_MISSILES - 1;
					}
				}
			}
		}
	}
}