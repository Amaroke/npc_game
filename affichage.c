/**
 *\file affichage.c
 *\brief Définition des fonctions d'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 14 novembre 2020
*/

#include "affichage.h"

void init(SDL_Window **window, SDL_Renderer **renderer, ressources_t *ressources, game_t *game)
{
    init_ttf();
    init_sdl(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    init_ressources(*renderer, ressources);
    init_data(game);
}

void clean(SDL_Window *window, SDL_Renderer *renderer, ressources_t *ressources, game_t *game)
{
    clean_data(game);
    clean_ressources(ressources);
    clean_sdl(renderer, window);
}

void refresh_graphics(SDL_Renderer *renderer, game_t *game, ressources_t *ressources)
{
    if (game->etat_partie != WIN && game->etat_partie != LOOSE)
    {
        clear_renderer(renderer);
        char *str = malloc(sizeof(char) * 100);

        sprintf(str, "HP : %4d", game->player->health_point);
        
        apply_background(renderer, ressources);
        apply_block(renderer, *ressources, game->block);
        apply_sprite(renderer, ressources->vortex, &game->vortex->sprite, game->vortex->animation[game->vortex->current_frame / 5], game->vortex->sprite.x, game->vortex->sprite.y);
        apply_sprite(renderer, ressources->player, &game->player->sprite, game->player->animation[game->player->orientation], game->player->sprite.x, game->player->sprite.y);
        apply_text(renderer, 5, 5, 100, 25, str, ressources->font, 255, 255, 255);
        update_screen(renderer);
    }
    else if (game->etat_partie == WIN)
    {
        char str[] = "Level Clear";
        apply_text(renderer, 250, SCREEN_HEIGHT / 2 + (-100), 500, 200, str, ressources->font, 9, 210, 255);
        update_screen(renderer);
    }
    else if (game->etat_partie == LOOSE)
    {
        char str[] = "Game Over";
        apply_text(renderer, 250, SCREEN_HEIGHT / 2 + (-100), 500, 200, str, ressources->font, 255, 0, 62);
        update_screen(renderer);
    }
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

void apply_block(SDL_Renderer *renderer, ressources_t ressources, block_t **blocks)
{
    SDL_Rect rectangle = {0, 0, BLOC_SIZE, BLOC_SIZE};
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (blocks[i][j].sprite.is_visible)
            {
                switch (blocks[i][j].effet)
                {
                case 1:
                    apply_texture(ressources.wall, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                case 2:
                    apply_texture(ressources.water, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                case 3:
                    apply_texture(ressources.magma, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                case 4:
                    apply_texture(ressources.ice, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                case 5:
                    apply_texture(ressources.light_oak, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                case 6:
                    apply_texture(ressources.health, renderer, rectangle, blocks[i][j].sprite.x, blocks[i][j].sprite.y);
                    break;
                }
            }
        }
    }
}