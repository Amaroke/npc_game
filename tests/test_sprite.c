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
    if (sprite_test->x != 0 && sprite_test->y != 0 && sprite_test->w != 0 && sprite_test->h != 0 && sprite_test->s != 0 && sprite_test->is_visible != false) {
        printf("Il y a un problème, lors de l'initialisation d'un sprite avec comme paramètres : x=0, y=0, w=0, h=0, s=0, is_visible=false");
    }
}ss

/**
 *\brief Programme principal qui effectue les tests de sprite.
*/
int main(int argc, char *argv[])
{
    test_init_sprite();
    return EXIT_SUCCESS;
}