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
        printf("Test d'initialisation n°1 d'un sprite réussi !\n");
    }

    init_sprite(sprite_test, 10, 10, 10, 10, 1, true);
    if (sprite_test->x != 10 || sprite_test->y != 10 || sprite_test->w != 10 || sprite_test->h != 10 || sprite_test->s != 1 || sprite_test->is_visible != true)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 10, y = 10, w = 10, h = 10, s = 1, is_visible = true");
    }
    else
    {
        printf("Test d'initialisation n°2 d'un sprite réussi !\n");
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
    printf("Cliquer sur la croix pour fermer la fenêtre\n");
    while (!game.gameover)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game.gameover = 1;
            }
        }
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }

    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
}

void test_player_animation()
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

void test_init_block()
{

    block_t *block_test;
    block_test = malloc(sizeof(block_t));
    init_block(block_test, 0, 0, 0, 0, false, 0, false);
    if (block_test->sprite.x != 0 || block_test->sprite.y != 0 || block_test->sprite.w != 0 || block_test->sprite.h != 0 || block_test->sprite.s != 0 || block_test->sprite.is_visible != false || block_test->effet != 0 || block_test->collision != false)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 0, y = 0, w = 0, h = 0, s = 0, is_visible = false, effet = 0, collision = false\n");
    }
    else
    {
        printf("Test d'initialisation n°1 d'un bloc réussi !\n");
    }

    init_block(block_test, 10, 10, 10, 10, true, 1, true);
    if (block_test->sprite.x != 10 || block_test->sprite.y != 10 || block_test->sprite.w != 10 || block_test->sprite.h != 10 || block_test->sprite.s != 0 || block_test->sprite.is_visible != true || block_test->effet != 1 || block_test->collision != true)
    {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x = 10, y = 10, w = 10, h = 10, s = 0, is_visible = true, effet = 0, collision = false\n");
    }
    else
    {
        printf("Test d'initialisation n°2 d'un bloc réussi !\n");
    }
}

void test_affichage_bloc()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;
    SDL_Event event;
    init(&window, &renderer, &ressources, &game);
    printf("Cliquer sur la croix pour fermer la fenêtre\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            init_block(&game.block[i][j], BLOC_SIZE * i, 20, BLOC_SIZE, BLOC_SIZE, true, 1, 1);
        }
    }
    apply_block(renderer, ressources, game.block);
    update_screen(renderer);
    while (!game.gameover)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game.gameover = 1;
            }
        }
        pause(10);
    }

    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
}

void test_int_to_block()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;
    SDL_Event event;
    int **int_tab = malloc(sizeof(int) * ROW * COLUMN);
    init(&window, &renderer, &ressources, &game);
    printf("Cliquer sur la croix pour fermer la fenêtre\n");
    for (int i = 0; i < ROW; i++)
    {
        int_tab[i] = malloc(sizeof(int) * COLUMN);
        for (int j = 0; j < COLUMN; j++)
        {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COLUMN - 1)
            {
                int_tab[i][j] = 1;
            }
            else
            {
                int_tab[i][j] = 5;
            }
        }
    }
    int_to_block(game.block, int_tab);
    apply_block(renderer, ressources, game.block);
    update_screen(renderer);
    while (!game.gameover)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game.gameover = 1;
            }
        }
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
}

void test_txt_to_int()
{
    int **res = malloc(sizeof(int) * 18 * 32);
    res = txt_to_int("ressources/levels/test.txt");
    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            printf("%i ", res[i][j]);
        }
        printf("\n");
    }
    printf("Test d'affichage réussi !\n");
}

void test_collision()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    game_t game;
    SDL_Event event;
    init(&window, &renderer, &ressources, &game);
    printf("Cliquer sur la croix pour fermer la fenêtre\n");
    int_to_block(game.block, txt_to_int("ressources/levels/test_collisions.txt"));
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    while (!game.gameover) //Tant que le jeu n'est pas fini.
    {
        movement_player(&event, &game);
        update_data(&game);
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
}

int main(void)
{
    int choix = 0;
    while (choix == 0)
    {
        printf("\nMenu test affichage\n0 : Quitter.\n1 : Tester l'initialisation d'un sprite.\n2 : Tester l'affichage d'un fond et d'un sprite de joueur.\n3 : Tester l'affichage et les animations du joueur.\n4 : Tester l'initialisation d'un bloc.\n5 : Tester l'affichage d'un bloc\n6 : Tester la conversion d'un tableau de block.\n7 : Tester la gestion fichier.\n8 : Tester les collisions.\n");
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
            test_player_animation();
            choix = 0;
            break;
        case 4:
            test_init_block();
            choix = 0;
            break;
        case 5:
            test_affichage_bloc();
            choix = 0;
            break;
        case 6:
            test_int_to_block();
            choix = 0;
            break;
        case 7:
            test_txt_to_int();
            choix = 0;
            break;
        case 8:
            test_collision();
            choix = 0;
            break;
        default:
            printf("Choix invalide !\n");
            choix = 0;
            break;
        }
    }
    return EXIT_SUCCESS;
}