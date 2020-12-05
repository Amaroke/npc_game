/**
 *\file monde.c
 *\brief Définition des fonctions du monde.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 30 novembre 2020
*/

#include "monde.h"

void init_data(world_t *world)
{
    // On initialise toutes les deonnées de base du monde.
    world->gameover = false;
    world->timer = 0;
    world->score = 0;
    world->etat_partie = 0;
    world->player = malloc(sizeof(sprite_t));
    init_player(world->player);
    init_sprite(&world->player->sprite, 10, 10, NPC_TEST_WIDTH / 4, NPC_TEST_HEIGHT / 4, 1, true);
}

void clean_data(world_t *world)
{
    free(&world->player->sprite);
    free(world->player);
    free(world);
}

