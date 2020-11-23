/**
 *\file affichage.c
 *\brief Définition des fonctions d'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 14 novembre 2020
*/

#include "affichage.h"

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources)
{
    init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ressources(*renderer, ressources);
}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources)
{
    clean_sdl(renderer, window);
    clean_ressources(ressources);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite, SDL_Rect dst)
{
    if (sprite->is_visible == true)
    {
        apply_texture(texture, renderer, dst); //coordonnées+demi sprite
    }
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources)
{
    if (ressources->background != NULL)
    {
        SDL_Rect dst = {0, 0, 0, 0};
        apply_texture(ressources->background, renderer, dst);
    }
}