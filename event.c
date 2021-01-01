/**
 *\file event.c
 *\brief Définition des évenements clavier.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 5 décembre 2020
*/

#include "event.h"

void movement_player(SDL_Event *event, game_t *game, SDL_Window *window)
{
    while (SDL_PollEvent(event))
    {
        sprite_t *copy = copy_sprite(&game->player->sprite);

        if (event->type == SDL_QUIT)
        {
            game->gameover = true;
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
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_RIGHT;
                game->player->orientation = ORIENTATION_RIGHT + game->player->current_frame;
                copy->x += MOVING_STEP;
                if (!bloc_collide(copy, game->block))
                {
                    game->player->sprite.x += MOVING_STEP;
                }
            }
            else if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
            {
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_LEFT;
                game->player->orientation = ORIENTATION_LEFT + game->player->current_frame;
                copy->x -= MOVING_STEP;
                if (!bloc_collide(copy, game->block))
                {
                    game->player->sprite.x -= MOVING_STEP;
                }
            }
            else if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
            {
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_DOWN;
                game->player->orientation = ORIENTATION_DOWN + game->player->current_frame;
                copy->y += MOVING_STEP;
                if (!bloc_collide(copy, game->block))
                {
                    game->player->sprite.y += MOVING_STEP;
                }
            }
            else if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
            {
                game->player->is_moving = true;
                game->player->last_orientation = ORIENTATION_UP;
                game->player->orientation = ORIENTATION_UP + game->player->current_frame;
                copy->y -= MOVING_STEP;
                if (!bloc_collide(copy, game->block))
                {
                    game->player->sprite.y -= MOVING_STEP;
                }
            }
            else
            {
                game->player->is_moving = false;
                game->player->orientation = game->player->last_orientation;
                game->player->current_frame = 0;
                game->player->frame = 0;
            }
            if (event->key.keysym.sym == SDLK_ESCAPE)
            {
                game->gameover = true;
            }
            if (event->key.keysym.sym == SDLK_F11)
            {
                if(!game->fullscreen) {
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                    game->fullscreen = true;
                }
                else {
                    SDL_SetWindowFullscreen(window, 0);
                    game->fullscreen = false;
                }
            }
        }
    }
}