/**
 *\file joueur.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "affichage.h"
#include "ressources.h"
#include "joueur.h"

// Constantes

SDL_Rect array_sprite_down[NB_ANIMATIONS] = {{0, 0, 16, 32}, {16, 0, 16, 32}, {32, 0, 16, 32}, {48, 0, 16, 32}};
SDL_Rect array_sprite_right[NB_ANIMATIONS] = {{0, 32, 16, 32}, {16, 32, 16, 32}, {32, 32, 16, 32}, {48, 32, 16, 32}};
SDL_Rect array_sprite_up[NB_ANIMATIONS] = {{0, 64, 16, 32}, {16, 64, 16, 32}, {32, 64, 16, 32}, {48, 64, 16, 32}};
SDL_Rect array_sprite_left[NB_ANIMATIONS] = {{0, 96, 16, 32}, {16, 96, 16, 32}, {32, 96, 16, 32}, {48, 96, 16, 32}};

void init_player(player_t *player, int orientation)
{
    player->orientation = orientation;
    for (int i = 0; i < 4; ++i)
    {
        player->animation[i] = array_sprite_down[i];
        player->animation[i + 4] = array_sprite_right[i];
        player->animation[i + 8] = array_sprite_up[i];
        player->animation[i + 12] = array_sprite_right[i];
    }
}

void movement_player(SDL_Event *event, player_t *player)
{

    while (SDL_PollEvent(event))
    {
        if (event->type == SDL_KEYDOWN)
        {
            if (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_d)
            {
                player->sprite.x += MOVING_STEP;
                printf("La touche ➡️ est appuyée ! \n");
                printf("%i %i", player->sprite.x, player->sprite.y);
            }
            if (event->key.keysym.sym == SDLK_LEFT || event->key.keysym.sym == SDLK_q)
            {
                player->sprite.x -= MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_DOWN || event->key.keysym.sym == SDLK_s)
            {
                player->sprite.y += MOVING_STEP;
            }
            if (event->key.keysym.sym == SDLK_UP || event->key.keysym.sym == SDLK_z)
            {
                player->sprite.y -= MOVING_STEP;
            }
        }
    }
}
