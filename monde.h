/**
 *\file monde.c
 *\brief Déclaration des fonctions du monde.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 30 novembre 2020
*/

#ifndef MONDE_H
#define MONDE_H

#include <stdbool.h>
#include "sprite.h"
#include "ressources.h"
#include "affichage.h"

typedef struct world_s
{
    bool gameover;							/*!< Champ indiquant si l'on est à la fin du jeu.*/
	int etat_partie;						/*!< État de la partie. */
	int score;								/*!< Score.*/
	int timer;	                            /*!< Le temps.*/
    player_t *player;						/*!< Le joueur.*/	
} world_t;



/**
 *\brief La fonction initialise le monde.
 *\param world Le monde.
*/
void init_data(world_t *world);

/**
 *\brief La fonction nettoie le monde.
 *\param world Le monde.
*/
void clean_data(world_t *world);

#endif