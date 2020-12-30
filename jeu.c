/**
 *\file monde.c
 *\brief Définition des fonctions du monde.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 30 novembre 2020
*/

#include "jeu.h"
#include "terrain.h"
#include "affichage.h"

void init_data(game_t *game)
{
    // On initialise toutes les deonnées de base du monde.
    game->gameover = false;
    game->timer = 0;
    game->score = 0;
    game->etat_partie = 0;
    game->player = malloc(sizeof(player_t));
    init_player(game->player);
    init_sprite(&game->player->sprite, 10, 10, NPC_TEST_WIDTH / 4, NPC_TEST_HEIGHT / 4, 1, true);
    game->block = malloc(sizeof(block_t) * ROW * COLUMN);
    for (int i = 0; i < ROW; i++)
    {
        game->block[i] = malloc(sizeof(block_t) * COLUMN);
    }
}

void clean_data(game_t *game)
{
    free(game->player);
}

