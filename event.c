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
        if (game->player->is_moving)
        {
            game->player->frame++;
            if (game->player->frame > game->player->animation_speed)
            {
                game->player->frame = 0;
            }
        }
        int index = (game->player->frame * game->player->frames) / game->player->animation_speed;
        game->player->current_frame = fmin(index, game->player->frames - 1);

        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_d)
            {
                printf("La touche ➡️ est appuyée ! \n");
                if (!bloc_collide(game))
                {
                    game->player->is_moving = true;
                    game->player->last_orientation = ORIENTATION_RIGHT;
                    game->player->orientation = ORIENTATION_RIGHT + game->player->current_frame;
                    game->player->sprite.x += MOVING_STEP;
                }
            }
            else if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
            {
                printf("La touche ⬅️ est appuyée ! \n");
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_LEFT;
                game->player->orientation = ORIENTATION_LEFT + game->player->current_frame;
                game->player->sprite.x -= MOVING_STEP;
            }
            else if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
            {
                printf("La touche ⬇️ est appuyée ! \n");
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_DOWN;
                game->player->orientation = ORIENTATION_DOWN + game->player->current_frame;
                game->player->sprite.y += MOVING_STEP;
            }
            else if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
            {
                printf("La touche ⬆️ est appuyée ! \n");
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_UP;
                game->player->orientation = ORIENTATION_UP + game->player->current_frame;
                game->player->sprite.y -= MOVING_STEP;
            }
            else
            {
                game->player->is_moving = false;
                game->player->orientation = game->player->last_orientation;
                game->player->current_frame = 0;
                game->player->frame = 0;
            }

            printf("orientation = %i\n", game->player->orientation);
            printf("%i, %i\n", game->player->sprite.x, game->player->sprite.y);
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                game->gameover = true;
            }
        }
    }
}