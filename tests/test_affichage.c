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
#include "../monde.h"
#include <stdio.h>
#include <stdlib.h>

void test_apply_sprite()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    SDL_Event *event = malloc(sizeof(SDL_Event));
    world_t *world = malloc(sizeof(world_t));

    init(&window, &renderer, &ressources, world);

    apply_sprite(renderer, ressources.player, &world->player->sprite, world->player->animation[0], 50,  50);
    printf("%i %i", world->player->sprite.x, world->player->sprite.y);
    while (world->player->sprite.x < 200) //Tant que le jeu n'est pas fini.
	{
		movement_player(event, world->player);
		refresh_graphics(renderer, world,&ressources);
		pause(10);
	}
    clean(window, renderer, &ressources, world);
}

void test_apply_background()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    world_t *world = malloc(sizeof(world_t));

    init(&window, &renderer, &ressources, world);

    apply_background(renderer, &ressources);
    update_screen(renderer);
    pause(1000);
    clean(window, renderer, &ressources, world);
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