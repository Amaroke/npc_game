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
		//Si une touche est appuyée :
		if (event->type == SDL_KEYDOWN)
		{
			if (event->key.keysym.sym == SDLK_RIGHT)
			{
				move_right(player);
			}
        }
    }
}