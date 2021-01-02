/**
 *\file joueur.c
 *\brief Définition du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#include "menu.h"

static const int TITLE_WIDTH = 500;
static const int TITLE_HEIGHT = 60;

void start_menu(SDL_Renderer *renderer, ressources_t ressources, SDL_Event *event, SDL_Window *window, game_t *game, bool *jeu_en_cours)
{
    int choix = 0;
    char *str = malloc(sizeof(char) * 100);
    SDL_Rect rectangle = {0, 0, BLOC_SIZE * 1.5, BLOC_SIZE * 1.5};
    init_player(game->player, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 60, 122);
    init_vortex(game->vortex, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 190, 124);
    while (choix != -1)
    {
        game->etat_partie = MENU;
        switch (choix)
        {
        case 0:
            clear_renderer(renderer);
            str = "NPC Game";
            apply_text(renderer, SCREEN_WIDTH / 2 - TITLE_WIDTH / 2, 75, TITLE_WIDTH, TITLE_HEIGHT + 50, str, ressources.font, 255, 255, 255);
            str = "1 : Choisir un level";
            apply_text(renderer, SCREEN_WIDTH / 2 - TITLE_WIDTH / 2, 250, TITLE_WIDTH, TITLE_HEIGHT, str, ressources.font, 0, 255, 0);
            str = "2 : Comment jouer";
            apply_text(renderer, SCREEN_WIDTH / 2 - TITLE_WIDTH / 2, 350, TITLE_WIDTH, TITLE_HEIGHT, str, ressources.font, 0, 0, 255);
            str = "3 : Quitter";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 100, 450, TITLE_WIDTH - 200, TITLE_HEIGHT, str, ressources.font, 255, 0, 0);
            update_screen(renderer);
            choix = 5;
            break;
        case 1:
            str = "Choix Level";
            apply_text(renderer, SCREEN_WIDTH / 2 - TITLE_WIDTH / 2, 75, TITLE_WIDTH, TITLE_HEIGHT + 50, str, ressources.font, 255, 255, 255);
            clear_renderer(renderer);
            str = "0 : Retour";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 100, 450, TITLE_WIDTH - 200, TITLE_HEIGHT, str, ressources.font, 255, 0, 0);
            update_screen(renderer);
            level_t choix_level = CHOIX;
            while (choix_level == CHOIX)
            {
                choix_level = choisir_level(event, window, game);
            }
            if (choix_level != QUITTER)
            {
                init_level(game, choix_level);
                choix = -1;
            }
            else {
                choix = 0;
            }
            break;
        case 2:
            clear_renderer(renderer);
            str = "Regles du jeu";
            apply_text(renderer, SCREEN_WIDTH / 2 - TITLE_WIDTH / 2, 25, TITLE_WIDTH, TITLE_HEIGHT, str, ressources.font, 255, 255, 255);
            str = "Vous devez ammener";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) - 200, 125, TITLE_WIDTH / 2, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "jusqu'au";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 90, 125, TITLE_WIDTH / 2 - 155, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = ", cependant le sol a un effet sur vous :";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 225, 125, TITLE_WIDTH / 2 + 125, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "Quitter : 3";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 425, 475, TITLE_WIDTH - 200, TITLE_HEIGHT, str, ressources.font, 255, 0, 0);
            str = "0 : Retour";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) - 225, 475, TITLE_WIDTH - 200, TITLE_HEIGHT, str, ressources.font, 0, 0, 255);
            str = "Ce bloc est un mur.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) - 135, 210, TITLE_WIDTH / 2, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "L'eau vous ralentis.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) - 135, 310, TITLE_WIDTH / 2, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "La glace vous accelere.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) - 135, 410, TITLE_WIDTH / 2 + 50, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "Le sol vous est neutre.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 365, 210, TITLE_WIDTH / 2, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "Le magma vous blesse.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 365, 310, TITLE_WIDTH / 2, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            str = "Le bloc de soin vous soigne.";
            apply_text(renderer, (SCREEN_WIDTH / 2 - TITLE_WIDTH / 2) + 365, 410, TITLE_WIDTH / 2 + 100, TITLE_HEIGHT / 2, str, ressources.font, 255, 255, 255);
            apply_texture(ressources.wall, renderer, rectangle, 50, 200);
            apply_texture(ressources.water, renderer, rectangle, 50, 300);
            apply_texture(ressources.ice, renderer, rectangle, 50, 400);
            apply_texture(ressources.light_oak, renderer, rectangle, 550, 200);
            apply_texture(ressources.magma, renderer, rectangle, 550, 300);
            apply_texture(ressources.health, renderer, rectangle, 550, 400);
            apply_sprite(renderer, ressources.player, &game->player->sprite, game->player->animation[game->player->orientation], game->player->sprite.x, game->player->sprite.y);
            apply_sprite(renderer, ressources.vortex, &game->vortex->sprite, game->vortex->animation[game->vortex->current_frame / 5], game->vortex->sprite.x, game->vortex->sprite.y);
            update_screen(renderer);
            choix = 5;
            break;
        case 3:
            game->gameover = true;
            *jeu_en_cours = false;
            choix = -1;
            break;
        case 4:
            game->gameover = true;
            choix = -1;
            break;
        case 5:
            choix = choix_menu(event, window, game);
            break;
        default:
            choix = 5;
            break;
        }
    }
}
