/**
 *\file terrain.c
 *\brief Définition des fonctions pour la gestion du terrain.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/

#include "terrain.h"
#include "sprite.h"
#include "affichage.h"

void init_block(block_t *block, int x, int y, int h, int w, bool is_visible, int effet, bool collision)
{
    init_sprite(&block->sprite, x, y, h, w, 0, is_visible);
    block->effet = effet;
    block->collision = collision;
}

block_t **int_to_block(int **tab_int, int row, int column)
{
    block_t **tab_block = malloc(sizeof(block_t) * row * column);
    for (int i = 0; i < row; i++)
    {
        tab_block[i] = malloc(sizeof(block_t) * column);
        for (int j = 0; j < column; j++)
        {
            if (tab_int[i][j] == 0 || tab_int[i][j] == 1)
            {
                init_block(&tab_block[i][j], j * 32, i * 32, BLOC_SIZE, BLOC_SIZE, true, tab_int[i][j], true);
            }
            else
            {
                init_block(&tab_block[i][j], j * 32, i * 32, BLOC_SIZE, BLOC_SIZE, true, tab_int[i][j], false);
            }
        }
    }
    return tab_block;
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
        printf("Erreur fichier");
    }
    else
    {
        while (c != EOF)
        {
            c = fgetc(file);
            //printf("%c", c);
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