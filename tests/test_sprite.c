/**
 *\file test_sprite.c
 *\brief Gestion des tests de sprite.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 9 novembre 2020
*/

#include "../sprite.h"
#include <stdio.h>
#include <stdlib.h>

void test_init_sprite()
{
    sprite_t *sprite_test;
    sprite_test = malloc(sizeof(sprite_t));
    init_sprite(sprite_test, 0, 0, 0, 0, 0, true);
    print_sprite_test(sprite_test);
    init_sprite(sprite_test, 1, 1, 1, 1, 1, false);
    print_sprite_test(sprite_test);
    init_sprite(sprite_test, -50, 20, 10, 0, 1, false);
    print_sprite_test(sprite_test);
}

/**
 *\brief Programme principal qui effectue les tests.
*/
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    test_init_sprite();
    return EXIT_SUCCESS;
}