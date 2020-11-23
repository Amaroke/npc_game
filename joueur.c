/**
 *\file joueur.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "joueur.h"

void init_player(player_t *player, int orientation)
{
    player->orientation = orientation;
}

void input_player(SDL_Event *event, player_t *player) {
    Uint8 *keystates;
    while (SDL_PollEvent(event))
	{
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_d)
			{
				move_right(player);
			}
            if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
			{
				move_left(player);
			}
            if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
			{
				move_down(player);
			}
            if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
			{
				move_up(player);
			}
        }
    }
}

void move_left(player_t *player)
{
    player->x -= MOVING_STEP;
}

void move_right(player_t *player)
{
    player->x += MOVING_STEP;
}

void move_up(player_t *player)
{
    player->y += MOVING_STEP;
}

void move_down(player_t *player)
{
    player->y -= MOVING_STEP;
}
