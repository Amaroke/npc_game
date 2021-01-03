/**
 *\file level.h
 *\brief Déclaration des fonctions d'un niveau.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 3 janvier 2020
*/

#include "fonctions_SDL.h"
#include "ressources.h"
#include "event.h"
#include "affichage.h"

#ifndef LEVEL_H
#define LEVEL_H

#define LEVEL_MAX 7

typedef enum level_e
{
    DEBUG,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4,
    LEVEL_5,
    LEVEL_6,
    CHOIX,
    QUITTER
} level_t;

/**
 *\brief La fonction initialise le niveau.
 *\param game Le jeu.
 *\param level Le niveau.
 */
void init_level(game_t *game, level_t level);

#endif