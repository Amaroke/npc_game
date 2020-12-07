/**
 *\file level_test.c
 *\brief Création d'un environnement de tests.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 novembre 2020
*/

#include "../affichage.h"
#include "../fonctions_SDL.h"
#include "../sprite.h"
#include "../ressources.h"
#include "../joueur.h"
#include "../jeu.h"
#include "../event.h"
#include <stdio.h>
#include <stdlib.h>

void test_apply_sprite()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    SDL_Event event;
    game_t game;

    init(&window, &renderer, &ressources, &game);

    while (!game.gameover) //Tant que le jeu n'est pas fini.
    {
        movement_player(&event, &game);
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
}

void test_apply_background()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;

    init(&window, &renderer, &ressources, &game);

    apply_background(renderer, &ressources);
    update_screen(renderer);
    pause(1000);
    clean(window, renderer, &ressources, &game);
}

/**
 *\brief Programme principal qui effectue les tests de affichage.
*/
int main(int argc, char *argv[])
{
    int choix = 0;
    while (choix != 1 || choix != 2 || choix != 3)
    {
        printf("Menu test affichage\n1 : Appliquer un sprite.\n2 : Appliquer un fond.\n3 : Quitter.\n");
        printf(">>>");
        scanf("%i", &choix);
        getchar();

        switch (choix)
        {
        case 1:
            test_apply_sprite();
            choix = 0;
            break;

        case 2:
            test_apply_background();
            choix = 0;
            break;
        case 3:
            return EXIT_SUCCESS;
            break;

        default:
            printf("Choix invalide !");
            choix = 0;
            break;
        }
    }

    return EXIT_SUCCESS;
}