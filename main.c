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

static const int TITLE_WIDTH = 500;
static const int TITLE_HEIGHT = 60;

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

    int choix = -1;
    init(&window, &renderer, &ressources, &game);  
    char str[] = "NPC Game";
    apply_text(renderer, SCREEN_WIDTH/2 - TITLE_WIDTH/2, 20, TITLE_WIDTH, TITLE_HEIGHT, str, ressources.font, 255, 255, 255);
    update_screen(renderer);
    while (choix !=0)
    {
        choix = choix_menu(&event, window, &game);
        game.etat_partie = MENU;

        switch (choix)
        {
        case 1:
            init_data(&game, 100, 100, 300, 100);
            game.etat_partie = LEVEL_1;
            int_to_block(game.block, txt_to_int("ressources/levels/level_1.txt"));
            choix = 0;
            break;
        
        case 2:
            game.etat_partie = LEVEL_2;
            int_to_block(game.block, txt_to_int("ressources/levels/test.txt"));
            choix = 0;
            break;
        }
    }
    while (game.gameover == false) //Tant que le jeu n'est pas fini.
    {
        movement_player(&event, &game, window);
        update_data(&game);
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
    return EXIT_SUCCESS;
}