/**
 *\file jeu.h
 *\brief Déclaration des fonctions du jeu.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 30 novembre 2020
*/

#ifndef MONDE_H
#define MONDE_H

#include <stdbool.h>
#include "sprite.h"
#include "ressources.h"
#include "joueur.h"
#include "terrain.h"
#include "vortex.h"
#include "ennemis.h"

typedef enum game_state_e
{
	MENU,
	IN_GAME,
	LOOSE,
	WIN
} game_state_t;

typedef struct game_s
{
	bool gameover;			  /*!< Champ indiquant si l'on est à la fin du jeu.*/
	bool fullscreen;		  /*!< Si le jeu est en full screen ou non. */
	game_state_t etat_partie; /*!< État de la partie. 0 = en cours 1 = gagné 2 = perdu.*/
	int score;				  /*!< Score.*/
	int timer;				  /*!< Le temps.*/
	player_t *player;		  /*!< Le joueur.*/
	enemy_t *enemy[10];		  /*!<Un tableau de 10 ennemis maximum.*/
	vortex_t *vortex;		  /*!< Le vortex.*/
	block_t **block;		  /*!< Un bloc.*/
} game_t;

/**
 *\brief La fonction initialise les données jeu.
 *\param game Le jeu.
*/
void init_data(game_t *game);

/**
 *\brief La fonction met à jour les données jeu.
 *\param game Le jeu.
*/
void update_data(game_t *game);

/**
 *\brief La fonction nettoie les données du jeu.
 *\param game Le jeu.
*/
void clean_data(game_t *game);

#endif