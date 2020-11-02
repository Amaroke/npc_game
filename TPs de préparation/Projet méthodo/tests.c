/**
 *\file tests.c
 *\brief Programme de tests.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef TEST_C
#define TEST_C
#include "biblio.h"
#include "event.h"
#include "sprite.h"
#include "ressources.h"
#include "world.h"
#include "renderer.h"
#endif

//On teste init_sprite et print_sprite :
void test_init_sprite_param(sprite_t *sprite, int x, int y, int w, int h, int v, int visible)
{
    printf("Voici les données du sprite (initialisé avec position en x : %d, position en y : %d, largeur : %d, hauteur : %d, vitesse : %d, visibilité : %d) :\n", x, y, w, h, v, visible);
    print_sprite(sprite);
}

void test_init_sprite()
{
    sprite_t *sprite_test;
    sprite_test = malloc(sizeof(sprite_t));
    init_sprite(sprite_test, 0, 0, 0, 0, 0, 0, 1);
    test_init_sprite_param(sprite_test, 0, 0, 0, 0, 0, 0);
    init_sprite(sprite_test, 1, 1, 1, 1, 1, 1, 1);
    test_init_sprite_param(sprite_test, 1, 1, 1, 1, 1, 1);
    init_sprite(sprite_test, 10, 10, 10, 10, 10, 0, 1);
    test_init_sprite_param(sprite_test, 10, 10, 10, 10, 10, 0);
}

//On teste set_visible et set_invisible en même temps :
void test_visible_param(sprite_t *sprite)
{
    if (sprite->is_visible == 0)
    {
        printf("Le sprite est invisible.\n");
    }
    if (sprite->is_visible == 1)
    {
        printf("Le sprite est visible.\n");
    }
}

void test_visible()
{
    sprite_t *sprite_test;
    sprite_test = malloc(sizeof(sprite_t));
    set_invisible(sprite_test);
    test_visible_param(sprite_test);
    set_visible(sprite_test);
    test_visible_param(sprite_test);
}

void test_init_blue_param(sprite_t *blue[])
{
    for (int i = 0; i < TOTAL_BLUE; i++)
    {
        printf("Coordonnées en x : %d et en y : %d.\n", blue[i]->x, blue[i]->y);
    }
}

void test_init_blue()
{
    sprite_t *blue[TOTAL_BLUE];
    for (int i = 0; i < TOTAL_BLUE; i++)
    {
        blue[i] = malloc(sizeof(sprite_t));
    }
    init_blue(blue);
    test_init_blue_param(blue);
}

void test_init_missile_param(world_t *world)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Coordonnées du vaisseau en x : %d et en y : %d.\n", world->ship->x, world->ship->y);
        printf("Coordonnées du missile en x : %d et en y : %d.\n", world->missile[i]->x, world->missile[i]->y);
    }
}

void test_init_missile()
{
    world_t *world_test = malloc(sizeof(world_t));
    init_data(world_test);
    init_missile(world_test);
    test_init_missile_param(world_test);
}

void test_depassement_blue_param(world_t *world)
{
    printf("Le sprite est à %d en y.\nSa vitesse est de %d.\nSa visibilité est de %d.\n", world->blue[0]->y, world->blue[0]->v, world->blue[0]->is_visible);
}

void test_depassement_blue()
{
    world_t *world_test = malloc(sizeof(world_t));
    init_data(world_test);
    init_blue(world_test->blue);
    for (int i = 0; i < 5; i++)
    {
        world_test->blue[i]->is_visible = 1;
        world_test->blue[i]->v = ENEMY_SPEED;
        world_test->blue[i]->y = 495; //Bordure de l'écran pour le sprite en 496.
    }
    depassement_blue(world_test);
    test_depassement_blue_param(world_test);
    for (int j = 0; j < 5; j++)
    {
        ++world_test->blue[j]->y;
    }
    depassement_blue(world_test);
    test_depassement_blue_param(world_test);
}

void test_depassement_missile_param(sprite_t *missile[])
{
    printf("Le sprite est à %d en y.\nSa vitesse est de %d.\nSa visibilité est de %d.\n", missile[0]->y, missile[0]->v, missile[0]->is_visible);
}

void test_depassement_missile()
{
    world_t *world_test = malloc(sizeof(world_t));
    init_data(world_test);
    init_missile(world_test);
    for (int i = 0; i < NB_MISSILES; i++)
    {
        world_test->missile[i]->is_visible = 1;
        world_test->missile[i]->y = 1; //Bordure de l'écran pour le sprite en 0.
    }
    depassement_missile(world_test->missile);
    test_depassement_missile_param(world_test->missile);
    for (int j = 0; j < NB_MISSILES; j++)
    {
        --world_test->missile[j]->y;
    }
    depassement_missile(world_test->missile);
    test_depassement_missile_param(world_test->missile);
}

//On teste handle_sprite_collide et sprite_collide en même temps :
void test_handle_sprite_collide_param(sprite_t *sp1, sprite_t *sp2, world_t *world)
{
    if (sprite_collide(sp2, sp1, world) == 0)
    {
        printf("Il n'y a pas de collision.\n");
        handle_sprite_collide(sp2, sp1, world);
        printf("Pour l'ennemi, la vitesse est de : %d, et la visibilité est : %d\n", world->blue[0]->v, world->blue[0]->is_visible);
        printf("Pour le vaisseau, la vitesse est de : %d, et la visibilité est : %d\n", world->ship->v, world->ship->is_visible);
    }
    else
    {
        printf("Il y a collision !\n");
        handle_sprite_collide(sp2, sp1, world);
        printf("Pour l'ennemi, la vitesse est de : %d, et la visibilité est : %d\n", world->blue[0]->v, world->blue[0]->is_visible);
        printf("Pour le vaisseau, la vitesse est de : %d, et la visibilité est : %d\n", world->ship->v, world->ship->is_visible);
    }
}

void test_handle_sprite_collide()
{
    world_t *world_test = malloc(sizeof(world_t));
    init_data(world_test);
    init_sprite(world_test->blue[0], 10, 10, 10, 10, 10, 1, 1);
    init_sprite(world_test->ship, 0, 0, 10, 10, 10, 1, 1);
    test_handle_sprite_collide_param(world_test->blue[0], world_test->ship, world_test);
    init_sprite(world_test->ship, 10, 10, 10, 10, 10, 1, 1);
    test_handle_sprite_collide_param(world_test->blue[0], world_test->ship, world_test);
}

int main(int argc, char *args[])
{
    srand(time(NULL));
    test_init_sprite();
    printf("\n");
    test_visible();
    printf("\n");
    test_init_blue();
    printf("\n");
    test_init_missile();
    printf("\n");
    test_depassement_blue();
    printf("\n");
    test_depassement_missile();
    printf("\n");
    test_handle_sprite_collide();
    printf("\n");
    return EXIT_SUCCESS;
}
