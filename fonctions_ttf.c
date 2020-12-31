/**
 *\file fonctions_ttf.c
 *\brief Définitions des fonctions d'affichage de textes.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 31 décembre 2020
*/


#include "fonctions_ttf.h"



void init_ttf()
{
    if (TTF_Init() == -1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
    }
}


TTF_Font *load_font(const char *path, int font_size)
{
    TTF_Font *font = TTF_OpenFont(path, font_size);
    if (font == NULL)
    {
        fprintf(stderr, "Erreur pendant chargement font: %s\n", SDL_GetError());
    }
    return font;
}

void apply_text(SDL_Renderer *renderer, int x, int y, int w, int h, const char *text, TTF_Font *font)
{
    SDL_Color color = {0, 255, 0, 0};

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect2 = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect2);
}

void clean_font(TTF_Font *font)
{
    TTF_CloseFont(font);
}