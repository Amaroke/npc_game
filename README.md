# Projet de programmation avancée

faire un world 
refresh graphics

-NPC_TEST_WIDTH/8
world->player->sprite.x-NPC_TEST_WIDTH/8

à faire prochainement

void clean_player(player_t *player)

void init_player(player_t *player)
{
    player->orientation = 0;
    for (int i = 0; i < 4; ++i)
    {
        player->animation[i] = array_sprite_down[i];
        player->animation[i + 4] = array_sprite_right[i];
        player->animation[i + 8] = array_sprite_up[i];
        player->animation[i + 12] = array_sprite_right[i];
    }

}


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 650

  /*                 switch (game->player->orientation)
                {
                case ORIENTATION_RIGHT:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 1:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                case ORIENTATION_RIGHT + 2:
                    game->player->orientation = game->player->orientation + 1;
                    break;

                default:
                    game->player->orientation = ORIENTATION_RIGHT;
                    break;
                } */