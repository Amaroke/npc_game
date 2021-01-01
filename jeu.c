/**
 *\file monde.c
 *\brief Définition des fonctions du monde.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 30 novembre 2020
*/

#include "jeu.h"

void init_data(game_t *game)
{
    // On initialise toutes les deonnées de base du monde.
    game->gameover = false;
    game->timer = 0;
    game->score = 0;
    game->fullscreen = false;
    game->player = malloc(sizeof(player_t));
    init_player(game->player);
    init_sprite(&game->player->sprite, 50, 50, NPC_TEST_WIDTH / 4, NPC_TEST_HEIGHT / 4, 1, true);
    game->vortex = malloc(sizeof(vortex_t));
    init_vortex(game->vortex);
    init_sprite(&game->vortex->sprite, 100, 100, BLOC_SIZE, BLOC_SIZE, 0, true);
    game->block = malloc(sizeof(block_t) * ROW * COLUMN);
    for (int i = 0; i < ROW; i++)
    {
        game->block[i] = malloc(sizeof(block_t) * COLUMN);
    }
}

void update_data(game_t *game)
{
    game->vortex->current_frame++;
    if(game->vortex->current_frame == NB_ANIMATIONS_VORTEX * 5)
    {
        game->vortex->current_frame = 0;
    }
    if(vortex_collide(game->vortex, &game->player->sprite)) {
        printf("Level Clear\n");
        pause(1000);
        game->gameover = true;
    }
    if(game->player->health_point <= 0)
    {
        game->player->sprite.is_visible = false;
        printf("Game Over\n");
        pause(1000);
        game->gameover = true;
    }
    apply_block_effect(game->player, game->block);
}

void clean_data(game_t *game)
{
    free(game->player);
    free(game->vortex);
}
