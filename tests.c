/**
 *\file tests.c
 *\brief Création d'un environnement de tests.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 novembre 2020
*/

#include "affichage.h"
#include "fonctions_SDL.h"
#include "sprite.h"
#include "ressources.h"
#include "joueur.h"
#include "jeu.h"
#include "event.h"
#include <stdio.h>
#include <stdlib.h>

void test_init_sprite()
{
    sprite_t *sprite_test;
    sprite_test = malloc(sizeof(sprite_t));
    init_sprite(sprite_test, 0, 0, 0, 0, 0, false);
    if (sprite_test->x != 0 || sprite_test->y != 0 || sprite_test->w != 0 || sprite_test->h != 0 || sprite_test->s != 0 || sprite_test->is_visible != false)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 0, y = 0, w = 0, h = 0, s = 0, is_visible = false");
    }
    init_sprite(sprite_test, 10, 10, 10, 10, 1, true);
    if (sprite_test->x != 10 || sprite_test->y != 10 || sprite_test->w != 10 || sprite_test->h != 10 || sprite_test->s != 1 || sprite_test->is_visible != true)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 10, y = 10, w = 10, h = 10, s = 1, is_visible = true");
    }
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

void test_player()
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

void test_print_block() {

}

int main(int argc, char *argv[])
{
    int choix = 0;
    while (choix != 1 || choix != 2 || choix != 3)
    {
        printf("Menu test affichage\n0 : Quitter.\n1 : Tester l'initialisation d'un sprite.\n2 : Tester l'affichage d'un fond.\n3 : Tester l'affichage, les déplacements et les animations du joueur.\n4 : Tester l'afichage d'un bloc et son initialisation.\n");
        printf(">>> ");
        scanf("%i", &choix);
        getchar();

        switch (choix)
        {
            case 0:
                return EXIT_SUCCESS;
                break;
            case 1:
                test_init_sprite();
                choix = 0;
                break;
            case 2:
                test_apply_background();
                choix = 0;
                break;
            case 3:
                test_player();
                break;
            case 4 :
                test_print_block();
                break;
            default:
                printf("Choix invalide !");
                choix = 0;
                break;
        }
    }
    return EXIT_SUCCESS;
}