/**
 *\file event.c
 *\brief Définition des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/

#include "event.h"

void movement_player(SDL_Event *event, game_t *game)
{

    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            game->gameover = 1;
        }
        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_d)
            {

                printf("La touche ➡️ est appuyée ! \n");

                switch (game->player->orientation)
                {
                case ORIENTATION_RIGHT:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_RIGHT;
                    break;
                }
                game->player->sprite.x += MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
            {
                printf("La touche ⬅️ est appuyée ! \n");

                switch (game->player->orientation)
                {
                case ORIENTATION_LEFT:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_LEFT + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_LEFT + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_LEFT;
                    break;
                }

                game->player->sprite.x -= MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
            {
                printf("La touche ⬇️ est appuyée ! \n");

                switch (game->player->orientation)
                {
                case ORIENTATION_DOWN:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_DOWN + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_DOWN + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_DOWN;
                    break;
                }
                game->player->sprite.y += MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
            {
                printf("La touche ⬆️ est appuyée ! \n");

                switch (game->player->orientation)
                {
                case ORIENTATION_UP:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_UP + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_UP + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_UP;
                    break;
                }
                game->player->sprite.y -= MOVING_STEP;
            }
            printf("orientation = %i\n", game->player->orientation);
            printf("%i %i\n", game->player->sprite.x, game->player->sprite.y);
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                game->gameover = true;
            }
            
        }
    }
}