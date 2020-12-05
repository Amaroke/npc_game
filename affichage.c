/**
 *\file affichage.c
 *\brief Définition des fonctions d'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 14 novembre 2020
*/

#include "affichage.h"

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, world_t * world)
{
    init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ressources(*renderer, ressources);
    init_data(world);
}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, world_t *world)
{
    clean_data(world);
    clean_ressources(ressources);
    clean_sdl(renderer, window);
}

void refresh_graphics(SDL_Renderer *renderer, world_t *world, ressources_t *ressources)
{
    clear_renderer(renderer);
    apply_background(renderer, ressources);
    apply_sprite(renderer, ressources->player, &world->player->sprite, world->player->animation[world->player->orientation], world->player->sprite.x,  world->player->sprite.y);
    update_screen(renderer);
}

void apply_sprite(SDL_Renderer *renderer, SDL_Texture *texture, sprite_t *sprite, SDL_Rect src, int x, int y)
{
    if (sprite->is_visible == true)
    {
        apply_texture(texture, renderer, src, x, y);
    }
}

void apply_background(SDL_Renderer *renderer, ressources_t *ressources)
{
    if (ressources->background != NULL)
    {
        SDL_Rect dst = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
        apply_texture(ressources->background, renderer, dst, 0, 0);
    }
}