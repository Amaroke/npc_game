#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include"fonctions_SDL.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer* renderer)
{
    // Charger une image
    SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;
    // Convertir la surface de l’image au format texture avant de l’appliquer
    return SDL_CreateTextureFromSurface(renderer, surface) ;
   
}