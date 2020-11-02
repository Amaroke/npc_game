#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "fonctions_SDL.h"

int main(){

    SDL_Window* fenetre;
    SDL_Event evenements;
    bool terminer = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf(
            "Erreur d'initialisation de la SDL: %s",
            SDL_GetError()
        );

        SDL_Quit();
        return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow(
        "Fenêtre SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        600,
        600,
        SDL_WINDOW_RESIZABLE
    );

    if(fenetre == NULL){
        printf(
            "Erreur de la création de la fenêtre: %s",
            SDL_GetError()
        );

        SDL_Quit();
        return EXIT_FAILURE; 
    }

    SDL_Renderer* ecran = SDL_CreateRenderer(
        fenetre,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    SDL_Texture* fond = charger_image(
        "fond.bmp", 
        ecran
    );

    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;
    SDL_Texture* obj = charger_image_transparente(
        "obj.bmp",
        ecran,
        r,
        g,
        b
    );

    int objetW;
    int objetH;

    SDL_QueryTexture(obj, NULL, NULL, &objetW, &objetH);

    SDL_Rect SrcR;
    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = objetW;
    SrcR.h = objetH;

    SDL_Rect DestR;
    DestR.x = 350;
    DestR.y = 350;
    DestR.w = objetW / 3;
    DestR.h = objetH / 3;


    while(!terminer){

        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
        SDL_RenderCopy(ecran, obj, &SrcR, &DestR);

        SDL_PollEvent(&evenements);

        switch(evenements.type){

            case SDL_QUIT:
                terminer = true;
                break;

            case SDL_KEYDOWN:

                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer = true;
                        break;
                }
        }

        SDL_RenderPresent(ecran);
    }

    SDL_DestroyTexture(fond);
    SDL_DestroyTexture(obj);
    SDL_DestroyRenderer(ecran);

    printf("FIN.\n");
    return EXIT_SUCCESS;
}