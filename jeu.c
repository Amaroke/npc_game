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
    game->timer = 300;
    game->score = 0;
    game->fullscreen = false;
    game->player = malloc(sizeof(player_t));
    game->etat_partie = MENU;
    game->vortex = malloc(sizeof(vortex_t));
    game->block = malloc(sizeof(block_t) * ROW * COLUMN);
    for (int i = 0; i < ROW; i++)
    {
        game->block[i] = malloc(sizeof(block_t) * COLUMN);
    }
    for (int i = 0; i < 10; i++)
    {
        game->enemy[i] = malloc(sizeof(enemy_t));
        init_enemy(game->enemy[i], -50, -50, 4, 0, false);
    }
}

void update_data(game_t *game)
{

    game->vortex->current_frame++;
    if (game->vortex->current_frame == NB_ANIMATIONS_VORTEX * 5)
    {
        game->vortex->current_frame = 0;
    }
    if (vortex_collide(game->vortex, &game->player->sprite))
    {

        game->etat_partie = WIN;
        game->timer--;
        if (game->timer == 0)
        {
            game->gameover = true;
        }
    }
    for (int i = 0; i < 10; i++)
    {

        if (game->enemy[i]->sprite.is_visible)
        {
            if (game->enemy[i]->movement == 0)
            {
                game->enemy[i]->movement = 200;
            }
            sprite_t *copy = copy_sprite(&game->enemy[i]->sprite);
            if (sprite_collide(copy, ))
                game->enemy[i]->orientation = rand() % (4 - 1)*4;
                switch (rand() % (4 - 1)*4)
                {

                case 1:
                    /* code */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    /* code */
                    break;
                default:
                    break;
                }
            game->player->is_moving = true;
            game->player->last_orientation = ORIENTATION_RIGHT;
            game->player->orientation = ORIENTATION_RIGHT + game->player->current_frame;
            for (int i = 0; i < MOVING_STEP * game->player->sprite.s; ++i)
            {
                copy->x++;
                if (!bloc_collide(copy, game->block))
                {
                    game->player->sprite.x++;
                }
            }
        }
    }

    if (game->player->health_point <= 0)
    {
        game->player->sprite.is_visible = false;
        game->etat_partie = LOOSE;
        game->timer--;
        if (game->timer == 0)
        {
            game->gameover = true;
        }
    }
    apply_block_effect(game->player, game->block);
}

void clean_data(game_t *game)
{
    free(game->player);
    free(game->vortex);
    for (int i = 0; i < 10; i++)
    {
        free(game->enemy[i]);
    }
}
