/**
 *\file entrees.c
 *\brief Définition des fonctins d'entrées.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 23 novembre 2020
*/

#include "entrees.h"

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