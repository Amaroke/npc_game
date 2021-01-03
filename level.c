/**
 *\file joueur.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
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
        init_vortex(game->vortex, 40, 60);
        init_enemy(game->enemy[0], 200, 100, 4, 1, true);
        init_enemy(game->enemy[1], 300, 100, 4, 2, true);
        init_enemy(game->enemy[2], 400, 100, 4, 3, true);
        int_to_block(game->block, txt_to_int("ressources/levels/test_collisions.txt"));
        break;
    case LEVEL_1:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_1.txt"));
        break;
    case LEVEL_2:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_2.txt"));
        break;
    case LEVEL_3:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_3.txt"));
        break;
    case LEVEL_4:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_4.txt"));
        break;
    case LEVEL_5:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_5.txt"));
        break;
    case LEVEL_6:
        game->etat_partie = IN_GAME;
        init_player(game->player, 40, 30);
        init_vortex(game->vortex, 40, 60);
        int_to_block(game->block, txt_to_int("ressources/levels/level_6.txt"));
        break;
    }
}