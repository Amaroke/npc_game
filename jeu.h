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
#include "joueur.h"

typedef struct game_s
{
    bool gameover;							/*!< Champ indiquant si l'on est à la fin du jeu.*/
	int etat_partie;						/*!< État de la partie. */
	int score;								/*!< Score.*/
	int timer;	                            /*!< Le temps.*/
    player_t *player;						/*!< Le joueur.*/
	block_t **block;							/*!< Un bloc.*/	
} game_t;



/**
 *\brief La fonction initialise le monde.
 *\param game Le jeu.
*/
void init_data(game_t *game);

/**
 *\brief La fonction initialise le monde.
 *\param game Le jeu.
*/
void update_data(game_t game);

/**
 *\brief La fonction nettoie le monde.
 *\param game Le jeu.
*/
void clean_data(game_t *game);


#endif