/**
 *\file main.c
 *\brief Programme principal du jeu.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 02 nov 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "fonctions_SDL.h"
#include "sprite.h"
#include "ressources.h"
#include "joueur.h"
#include "jeu.h"
#include "event.h"
#include "menu.h"

/**
 *\brief Programme principal qui implémente la boucle du jeu.
*/
int main(void)
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;
    SDL_Event event;

    init(&window, &renderer, &ressources, &game);
    start_menu(renderer, ressources, &event, window, &game);
    while (game.gameover == false)
    {
        movement_player(&event, &game, window);
        update_data(&game);
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
    return EXIT_SUCCESS;
}