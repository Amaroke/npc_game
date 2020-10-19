#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Texture *charger_image(const char *nomfichier, SDL_Renderer *renderer)
{
    SDL_Surface *surface = SDL_LoadBMP(nomfichier);
    return SDL_CreateTextureFromSurface(renderer, surface);
}

SDL_Texture *charger_image_transparente(const char *nomfichier, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Surface *surface = SDL_LoadBMP(nomfichier);
    Uint32 color = SDL_MapRGB(surface->format, r, g, b);
    SDL_SetColorKey(surface, SDL_TRUE, color);
    return SDL_CreateTextureFromSurface(renderer, surface);
}

SDL_Texture *charger_texte(const char *message, SDL_Renderer *renderer, TTF_Font *font, SDL_Color color)
{
    SDL_Surface *sur = TTF_RenderText_Solid(font, message, color);
    return SDL_CreateTextureFromSurface(renderer, sur);
}