/**
 *\file fonctions_SDL.c
 *\brief Gestion de la bibliothèque SDL2.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 nov 2020
*/

#include "fonctions_SDL.h"

SDL_Texture *charger_image(const char *nomfichier, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(nomfichier);
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

void clean_sdl(SDL_Renderer *renderer, SDL_Window *window)
{
    if (NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if (NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y)
{
    SDL_Rect dst = {0, 0, 0, 0};

    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    dst.x = x;
    dst.y = y;

    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

/**
 * \brief La fonction initialise la SDL.
 * Elle crée la fenêtre du jeu ainsi que le renderer
 * \param window la fenêtre du jeu
 * \param renderer le renderer
 * \param width largeur de l'écran de jeu
 * \param height hauteur de l'écran de jeu
 * \return -1 en cas d'erreur, 0 sinon
*/

int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height)
{
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        fprintf(stderr, "Erreur initialisation de la SDL : %s", SDL_GetError());
        return -1;
    }
    if (0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur lors de la creation de l'image et du renderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if (fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }