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

    int choix = 0;
    init(&window, &renderer, &ressources, &game);
    char *str = malloc(sizeof(char) * 20); //On réserve une chaine de 20 caractères pour le score.
    sprintf(str, "NPC TEST");     //On réserve un emplacement à la valeur du score.
    apply_text(renderer, 5, 5, 50, 30, str, ressources.font);
    update_screen(renderer);
    while (choix == 0)
    {
        printf("Welcome to NPC GAME\n");
        printf("Select your level\n");
        printf("Level 1\n");
        printf("Level 2\n");
        printf("Level 3\n");
        printf("Select 0 to exit\n");
        printf(">>> ");
        scanf("%i", &choix);
        getchar();

        switch (choix)
        {
        case 0:
            printf("\nExiting ...\n");
            return EXIT_SUCCESS;
            break;
        case 1:

            int_to_block(game.block, txt_to_int("ressources/levels/level_1.txt"));
            break;

        case 2:

            int_to_block(game.block, txt_to_int("ressources/levels/level_2.txt"));
            break;

        case 3:

            int_to_block(game.block, txt_to_int("ressources/levels/level_3.txt"));
            break;

        case 4:
            int_to_block(game.block, txt_to_int("ressources/levels/test_collisions.txt"));
            break;

        default:
            choix = 0;
            printf("\nSaisie invalide\n");
            break;
        }
    }
    while (game.gameover == false) //Tant que le jeu n'est pas fini.
    {
        printf("%i\n", game.gameover);
        movement_player(&event, &game, &window);
        update_data(&game);
        refresh_graphics(renderer, &game, &ressources);
        pause(10);
    }
    clean(window, renderer, &ressources, &game);
    printf("Test d'affichage réussi !\n");
    return EXIT_SUCCESS;
}