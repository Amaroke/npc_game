/**
 *\file terrain.c
 *\brief Définition des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/

#include "terrain.h"
#include "fonctions_SDL.h"

void init_block(block_t *block, int x, int y, int h, int w, bool is_visible, int effet, bool collision)
{
    init_sprite(&block->sprite, x, y, h, w, 0, is_visible);
    block->effet = effet;
    block->collision = collision;
}

void int_to_block(block_t **tab_block, int **tab_int)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (tab_int[i][j] == 1) //Gestion des collisions
            {
                init_block(&tab_block[i][j], j * BLOC_SIZE, i * BLOC_SIZE, BLOC_SIZE, BLOC_SIZE, true, tab_int[i][j], true);
            }
            else
            {
                init_block(&tab_block[i][j], j * BLOC_SIZE, i * BLOC_SIZE, BLOC_SIZE, BLOC_SIZE, true, tab_int[i][j], false);
            }
        }
    }
}

int **txt_to_int(char *fichier)
{
    FILE *file;
    int **res = malloc(sizeof(int) * 18 * 32);
    for (int i = 0; i < 18; i++)
    {
        res[i] = malloc(sizeof(block_t) * 32);
        for (int j = 0; j < 32; j++)
        {
            res[i][j] = 0;
        }
    }
    int c, i, j;
    i = 0;
    j = 0;
    file = fopen(fichier, "r");
    if (file == NULL)
    {
        printf("\nErreur fichier !\n");
    }
    else
    {
        while (c != EOF)
        {
            c = fgetc(file);
            if (c != EOF && c != 10) // 10 correspont au saut à la ligne en ASCII.
            {
                res[i][j] = c - '0'; // 0 par rapport à la table ASCII.
                j++;
            }
            if (c == 10)
            {
                j = 0;
                i++;
            }
        }
        fclose(file);
    }
    return res;
}

bool sprite_collide(sprite_t *player, sprite_t *block)
{
    if (block->is_visible)
    {
        if (player->x > block->x - 16 && player->x < block->x + BLOC_SIZE && player->y < block->y + BLOC_SIZE - 20 && player->y > block->y - BLOC_SIZE + 5)
        {
            return true;
        }
    }
    return false;
}

bool bloc_collide(sprite_t *player, block_t **block)
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            if (block[i][j].collision)
            {
                if (sprite_collide(player, &block[i][j].sprite))
                {
                    return true;
                }
            }
        }
    }
    return false;
}