/**
 *\file event.c
 *\brief Définition des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/

#include "event.h"

void movement_player(SDL_Event *event, world_t *world)
{

    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_QUIT)
        {
            world->gameover = 1;
        }
        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_d)
            {

                printf("La touche ➡️ est appuyée ! \n");

                switch (world->player->orientation)
                {
                case ORIENTATION_RIGHT:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_RIGHT + 1:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_RIGHT + 2:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                default:
                    world->player->orientation = ORIENTATION_RIGHT;
                    printf("default");
                    break;
                }
                world->player->sprite.x += MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
            {
                printf("La touche ⬅️ est appuyée ! \n");

                switch (world->player->orientation)
                {
                case ORIENTATION_LEFT:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_LEFT + 1:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_LEFT + 2:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                default:
                    world->player->orientation = ORIENTATION_LEFT;
                    printf("default");
                    break;
                }

                world->player->sprite.x -= MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
            {
                printf("La touche ⬇️ est appuyée ! \n");

                switch (world->player->orientation)
                {
                case ORIENTATION_DOWN:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_DOWN + 1:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_DOWN + 2:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                default:
                    world->player->orientation = ORIENTATION_DOWN;
                    printf("default");
                    break;
                }
                world->player->sprite.y += MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
            {
                printf("La touche ⬆️ est appuyée ! \n");

                switch (world->player->orientation)
                {
                case ORIENTATION_UP:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_UP + 1:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                case ORIENTATION_UP + 2:
                    world->player->orientation = world->player->orientation + 1;
                    printf("case");
                    break;

                default:
                    world->player->orientation = ORIENTATION_UP;
                    printf("default");
                    break;
                }
                world->player->sprite.y -= MOVING_STEP;
            }
            printf("orientation = %i\n", world->player->orientation);
            printf("%i %i\n", world->player->sprite.x, world->player->sprite.y);
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                world->gameover = true;
            }
            
        }
    }
}