/**
 *\file joueur.h
 *\brief Déclaration du joueur.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
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
    LEVEL_6
} level_t;

 void init_level(game_t *game, level_t level);

#endif