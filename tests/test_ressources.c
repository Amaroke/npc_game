/**
 *\file test_ressources.c
 *\brief Gestion des tests de ressources.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 9 novembre 2020
*/

#include "../ressources.h"
#include <stdio.h>
#include <stdlib.h>
#include "../sprite.h"
#include "../affichage.h"

/**
 *\brief Programme principal qui effectue les tests.
*/
int main(int argc, char *argv[]){
    (void)argc;
    (void)argv;
    SDL_Renderer *renderer;
    SDL_Window *window;
    ressources_t ressources;
    sprite_t sprite;
    init_sprite(&sprite, 1, 1, 10, 10, 1, true);
    init(&window, &renderer, &ressources);

    apply_background(renderer, &ressources);
    apply_sprite(renderer, ressources.player, &sprite);
    update_screen(renderer);
    int a = 0;
    while(a == 0)
    {
        scanf("%i", &a);
    }

    clean(window, renderer, &ressources);
    return EXIT_SUCCESS;
}


