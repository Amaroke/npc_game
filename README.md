# Projet de programmation avancée

faire un world 
refresh graphics

-NPC_TEST_WIDTH/8
world->player->sprite.x-NPC_TEST_WIDTH/8

à faire prochainement

void clean_player(player_t *player)

void init_player(player_t *player)
{
    player->orientation = 0;
    for (int i = 0; i < 4; ++i)
    {
        player->animation[i] = array_sprite_down[i];
        player->animation[i + 4] = array_sprite_right[i];
        player->animation[i + 8] = array_sprite_up[i];
        player->animation[i + 12] = array_sprite_right[i];
    }

}


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 650

  /*                 switch (game->player->orientation)
                {
                case ORIENTATION_RIGHT:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_RIGHT;
                    break;
                } */


                /**
 *\file test_affichage.c
 *\brief Gestion des tests d'affichage.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 14 novembre 2020
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

void test_apply_sprite()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    SDL_Event event;
    world_t world;

    init(&window, &renderer, &ressources, &world);

    while (!world.gameover) //Tant que le jeu n'est pas fini.
    {
        movement_player(&event, &world);
        refresh_graphics(renderer, &world, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &world);
}

void test_apply_background()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    world_t world;

    init(&window, &renderer, &ressources, &world);

    apply_background(renderer, &ressources);
    update_screen(renderer);
    pause(1000);
    clean(window, renderer, &ressources, &world);
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
        case 4 
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


/**
 *\file test_sprite.c
 *\brief Gestion des tests de sprite.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 9 novembre 2020
*/

#include "../sprite.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

/**
 *\brief Programme principal qui effectue les tests de sprite.
*/
int main(int argc, char *argv[])
{
    test_init_sprite();
    return EXIT_SUCCESS;
}