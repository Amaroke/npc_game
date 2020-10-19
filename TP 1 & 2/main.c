#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_SDL.h"

int main(void)
{
    SDL_Window *fenetre;  // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre
    bool terminer = false;
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
    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer *ecran;
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture *fond = charger_image("fond.bmp", ecran);
    // Charger l’image avec la transparence
    Uint8 r = 255, g = 255, b = 255;
    SDL_Texture *objet_transp = charger_image_transparente("obj.bmp", ecran, r, g, b);
    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = 640;
    SrcR.h = 192;
    SDL_Rect DestR;
    DestR.x = 350;
    DestR.y = 350;
    DestR.w = 640 / 3;
    DestR.h = 192 / 3;
    // Charger les sprites
    SDL_Texture *sprites = charger_image_transparente("sprites.bmp", ecran, 0, g, b);
    SDL_Rect SrcR_sprites;
    SrcR_sprites.x = 0;
    SrcR_sprites.y = 0;
    SrcR_sprites.w = 285/3; // Largeur du sprite
    SrcR_sprites.h = 250/2; // Hauteur du sprite
    SDL_Rect DestR_sprite[6];
    for(int i=0; i<6; i++)
    {
        DestR_sprite[i].x = i > 2 ? 60*(i+1)+100 : 60*(i+1);
        DestR_sprite[i].y = i > 2 ? 60 : 120;
        DestR_sprite[i].w = 285/3; // Largeur du sprite
        DestR_sprite[i].h = 250/2; // Hauteur du sprite
    }
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("./arial.ttf",28);
    SDL_Color color = {0,0,0,0};
    char msg[] = "TP sur Makefile et SDL";
    SDL_Texture* texte = charger_texte(msg,ecran,font,color);
    SDL_Rect text_pos; // Position du texte
    text_pos.x = 10;
    text_pos.y = 100;
    text_pos.w = 300; // Largeur du texte en pixels (à récupérer)
    text_pos.h = 40; // Hauteur du texte en pixels (à récupérer)


    // Boucle principale
    while (!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, objet_transp, &SrcR, &DestR);
        //Appliquer la surface du texte sur l’écran
        SDL_RenderCopy(ecran,texte,NULL,&text_pos);
        for(int i=0; i<6; i++)
        {
            SDL_RenderCopy(ecran, sprites, &SrcR_sprites, &DestR_sprite[i]);
        }
        while (SDL_PollEvent(&evenements))
            switch (evenements.type)
            {
            case SDL_QUIT:
                terminer = true;
                break;
            case SDL_KEYDOWN:
                switch (evenements.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                case SDLK_q:
                    terminer = true;
                    break;
                }
            }
        SDL_RenderPresent(ecran);
    }
    // Libération de l’écran (renderer)
    SDL_DestroyRenderer(ecran);
    // Fermer la police et quitter SDL_ttf
    TTF_CloseFont( font );
    TTF_Quit();
    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}