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
#include <stdio.h>
#include <stdlib.h>

void test_apply_sprite()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *texture;
    SDL_Rect src = {32, 96, 16, 32};
    ressources_t ressources;
    sprite_t *sprite;
    SDL_Event *event = malloc(sizeof(SDL_Event));
    player_t *player = malloc(sizeof(player_t));
    init_player(player, 0);

    sprite = malloc(sizeof(sprite_t));
    init(&window, &renderer, &ressources);
    texture = load_picture("ressources/sprites/player/NPC_test.bmp", renderer, 0, 0, 0);
    init_sprite(sprite, 10, 10, NPC_TEST_WIDTH/4, NPC_TEST_HEIGHT/4, 1, true);

    apply_sprite(renderer, texture, sprite, src, sprite->x-NPC_TEST_WIDTH/8, sprite->y-NPC_TEST_HEIGHT/8);
    update_screen(renderer);
    //pause(1000);
    printf("%i %i", player->sprite.x, player->sprite.y);
    while (player->sprite.x < 200) //Tant que le jeu n'est pas fini.
	{
		//Gestion des évènements :
		movement_player(event, player);
		//Mise à jour des données liée à la physique du monde :
		update_graphics(renderer, player, &src, &ressources);
		//Rafraichissement de l'écran :
        
		pause(10);
	}
    clean(window, renderer, &ressources);
}

void test_apply_background()
{
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    sprite_t *sprite;

    sprite = malloc(sizeof(sprite_t));
    init(&window, &renderer, &ressources);
    init_sprite(sprite, 1, 1, 10, 10, 1, true);

    apply_background(renderer, &ressources);
    update_screen(renderer);
    pause(1000);
    clean(window, renderer, &ressources);
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