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
    else
    {
        printf("Test réussi d'initialisation 1 !\n");
    }

    init_sprite(sprite_test, 10, 10, 10, 10, 1, true);
    if (sprite_test->x != 10 || sprite_test->y != 10 || sprite_test->w != 10 || sprite_test->h != 10 || sprite_test->s != 1 || sprite_test->is_visible != true)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 10, y = 10, w = 10, h = 10, s = 1, is_visible = true");
    }
    else
    {
        printf("Test réussi d'initialisation 2 !\n");
    }
}

void test_affichage()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;
    SDL_Event event;

    init(&window, &renderer, &ressources, &game);

    refresh_graphics(renderer, &game, &ressources);
    pause(2000);

    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
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

void test_print_block()
{
}

int main(int argc, char *argv[])
{
    int choix = 0;
    while (choix != 1 || choix != 2 || choix != 3)
    {
        printf("\nMenu test affichage\n0 : Quitter.\n1 : Tester l'initialisation d'un sprite.\n2 : Tester l'affichage d'un fond.\n3 : Tester l'affichage, les déplacements et les animations du joueur.\n4 : Tester l'afichage d'un bloc et son initialisation.\n");
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
            test_affichage();
            choix = 0;
            break;
        case 3:
            test_player();
            break;
        case 4:
            test_print_block();
            break;
        default:
            printf("Choix invalide !");
            choix = 0;
            break;
        }
    }
    printf("\033[H\033[2J");
    return EXIT_SUCCESS;
}