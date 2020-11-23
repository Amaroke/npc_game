/**
 *\file fonctions_SDL.c
 *\brief Définition des fonctions de la surcouche de la bibliothèque SDL2.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "fonctions_SDL.h"

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
{
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    if (0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void clean_sdl(SDL_Renderer *renderer, SDL_Window *window)
{
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture *load_picture(const char *file, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(file);
    if (NULL == tmp)
    {
        fprintf(stderr, "Erreur pendant le chargement de l'image BMP: %s", SDL_GetError());
        return NULL;
    }
    SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, r, g, b));
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if (NULL == texture)
    {
        fprintf(stderr, "Erreur pendant la création de la texture liée a l'image chargée: %s", SDL_GetError());
        return NULL;
    }
    return texture;
}

void clear_renderer(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void update_screen(SDL_Renderer *renderer)
{
    SDL_RenderPresent(renderer);
}

void pause(int time)
{
    SDL_Delay(time);
}

void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect dst)
{
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = 50;
    dst.y = 50;
    SDL_RenderCopy(renderer, texture, &dst, NULL);
}

void clean_texture(SDL_Texture *texture)
{
    if (NULL != texture)
    {
        SDL_DestroyTexture(texture);
    }
}

