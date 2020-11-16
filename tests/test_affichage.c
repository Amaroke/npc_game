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
    ressources_t ressources;
    sprite_t *sprite;

    sprite = malloc(sizeof(sprite_t));
    init(&window, &renderer, &ressources);
    texture = load_picture("ressources/sprites/sprite_test.bmp", renderer, 0, 0, 0);
    init_sprite(sprite, 1, 1, 10, 10, 1, true);

    apply_sprite(renderer, texture, sprite);
    update_screen(renderer);

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
}

/**
 *\brief Programme principal qui effectue les tests de affichage.
*/
int main(int argc, char *argv[])
{

    test_apply_sprite();
    test_apply_background();
    return EXIT_SUCCESS;
}