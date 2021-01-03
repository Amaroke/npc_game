/**
 *\file level.c
 *\brief Définition des fonctions niveaux.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 3 janvier 2020
*/

#include "level.h"

void init_level(game_t *game, level_t level)
{
    init_data(game);
    switch (level)
    {
    case CHOIX:
        break;
    case QUITTER:
        break;
    case DEBUG:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_enemy(game->enemy[0], 200, 100, 4, 1, true);
        init_enemy(game->enemy[1], 300, 100, 4, 2, true);
        init_enemy(game->enemy[2], 400, 100, 4, 3, true);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/test_collisions.txt"));
        break;
    case LEVEL_1:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 287, 225);
        int_to_block(game->block, txt_to_int("ressources/levels/level_1.txt"));
        break;
    case LEVEL_2:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 672, 416);
        int_to_block(game->block, txt_to_int("ressources/levels/level_2.txt"));
        break;
    case LEVEL_3:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_enemy(game->enemy[0], 120, 160, 4, 1, true);
        init_enemy(game->enemy[1], 548, 278, 4, 1, true);
        init_enemy(game->enemy[2], 400, 160, 4, 1, true);
        init_vortex(game->vortex, 736, 352);
        int_to_block(game->block, txt_to_int("ressources/levels/level_3.txt"));
        break;
    case LEVEL_4:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_enemy(game->enemy[0], 332, 282, 4, 1, true);
        init_enemy(game->enemy[1], 422, 352, 4, 2, true);
        init_enemy(game->enemy[2], 486, 284, 4, 2, true);
        init_enemy(game->enemy[3], 808, 94, 4, 2, true);
        init_vortex(game->vortex, 928, 92);
        int_to_block(game->block, txt_to_int("ressources/levels/level_4.txt"));
        break;
    case LEVEL_5:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_enemy(game->enemy[0], 332, 282, 4, 1, true);
        init_enemy(game->enemy[1], 422, 352, 4, 2, true);
        init_enemy(game->enemy[2], 486, 284, 4, 2, true);
        init_enemy(game->enemy[3], 940, 408, 4, 3, true);
        init_enemy(game->enemy[4], 618, 155, 4, 3, true);
        init_enemy(game->enemy[5], 300, 152, 4, 1, true);
        init_enemy(game->enemy[6], 876, 94, 4, 2, true);
        init_vortex(game->vortex, 865, 480);
        int_to_block(game->block, txt_to_int("ressources/levels/level_5.txt"));
        break;
    case LEVEL_6:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_enemy(game->enemy[0], 40, 88, 4, 3, true);
        init_enemy(game->enemy[1], 168, 222, 4, 3, true);
        init_enemy(game->enemy[2], 168, 348, 4, 3, true);
        init_enemy(game->enemy[3], 558, 476, 4, 3, true);
        init_enemy(game->enemy[4], 800, 278, 4, 3, true);
        init_enemy(game->enemy[5], 810, 100, 4, 3, true);
        init_enemy(game->enemy[6], 938, 152, 4, 3, true);
        init_enemy(game->enemy[7], 676, 88, 4, 3, true);
        init_vortex(game->vortex, 480, 32);
        int_to_block(game->block, txt_to_int("ressources/levels/level_6.txt"));
        break;
    }
}