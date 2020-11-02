/**
 *\file biblio.h
 *\brief Le module des include généraux et des define.
 *\author MOSELLE Marie Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef BIBLIO_H
#define BIBLIO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sdl2-light.h"
#include "sdl2-ttf-light.h"
#include "math.h"

/**
 *\brief Largeur de l'écran de jeu.
*/
#define SCREEN_WIDTH 300

/**
 *\brief Hauteur de l'écran de jeu.
*/
#define SCREEN_HEIGHT 480

/**
 *\brief Taille d'un vaisseau.
*/
#define SHIP_SIZE 32

/**
 *\brief Taille des missiles du joueur.
*/
#define MISSILE_SIZE 8

/**
 *\brief Vitesse des missiles du joueur.
*/
#define MISSILE_SPEED 10

/**
 *\brief Le nombre de points de vie du boss.
*/
#define BOSS_HP 20

/**
 *\brief La vitesse verticale du boss.
*/
#define BOSS_SPEED_Y ENEMY_SPEED

/**
 *\brief Le nombre de missiles du boss.
*/
#define BOSS_MISSILES 10

/**
 *\brief Le nombre de missiles du boss.
*/
#define BOSS_SIZE SHIP_SIZE * 2

/**
 *\brief Vitesse des missiles des ennemis.
*/
#define MISSILE_SPEED_ENEMY 2

/**
 *\brief Vitesse de déplacement horizontale du vaisseau.
*/
#define MOVING_STEP 10

/**
 *\brief Vitesse de déplacement verticale de l'ennemi.
*/
#define ENEMY_SPEED 1

/**
 *\brief Le nombre d'ennemis blue de la vague 1.
*/
#define BLUE_VAGUE_1 5

/**
 *\brief Le nombre d'ennemis blue de la vague 2.
*/
#define BLUE_VAGUE_2 3

/**
 *\brief Le nombre d'ennemis blue de la vague 3.
*/
#define BLUE_VAGUE_3 0

/**
 *\brief Le nombre d'ennemis blue de la vague 4.
*/
#define BLUE_VAGUE_4 3

/**
 *\brief Le nombre d'ennemis blue de la vague 5.
*/
#define BLUE_VAGUE_5 0

/**
 *\brief Le nombre d'ennemis green de la vague 1.
*/
#define GREEN_VAGUE_1 0

/**
 *\brief Le nombre d'ennemis green de la vague 2.
*/
#define GREEN_VAGUE_2 0

/**
 *\brief Le nombre d'ennemis green de la vague 3.
*/
#define GREEN_VAGUE_3 3

/**
 *\brief Le nombre d'ennemis green de la vague 4.
*/
#define GREEN_VAGUE_4 3

/**
 *\brief Le nombre d'ennemis green de la vague 5.
*/
#define GREEN_VAGUE_5 5

/**
 *\brief Le nombre d'ennemis red de la vague 1.
*/
#define RED_VAGUE_1 0

/**
 *\brief Le nombre d'ennemis red de la vague 2.
*/
#define RED_VAGUE_2 2

/**
 *\brief Le nombre d'ennemis red de la vague 3.
*/
#define RED_VAGUE_3 2

/**
 *\brief Le nombre d'ennemis red de la vague 4.
*/
#define RED_VAGUE_4 3

/**
 *\brief Le nombre d'ennemis red de la vague 5.
*/
#define RED_VAGUE_5 3

/**
 *\brief Le nombre d'ennemis purple de la vague 1.
*/
#define PURPLE_VAGUE_1 0

/**
 *\brief Le nombre d'ennemis purple de la vague 2.
*/
#define PURPLE_VAGUE_2 0

/**
 *\brief Le nombre d'ennemis purple de la vague 3.
*/
#define PURPLE_VAGUE_3 0

/**
 *\brief Le nombre d'ennemis purple de la vague 4.
*/
#define PURPLE_VAGUE_4 2

/**
 *\brief Le nombre d'ennemis purple de la vague 5.
*/
#define PURPLE_VAGUE_5 3

/**
 *\brief Le nombre d'ennemis orange de la vague 1.
*/
#define ORANGE_VAGUE_1 0

/**
 *\brief Le nombre d'ennemis orange de la vague 2.
*/
#define ORANGE_VAGUE_2 0

/**
 *\brief Le nombre d'ennemis orange de la vague 3.
*/
#define ORANGE_VAGUE_3 0

/**
 *\brief Le nombre d'ennemis orange de la vague 4.
*/
#define ORANGE_VAGUE_4 2

/**
 *\brief Le nombre d'ennemis orange de la vague 5.
*/
#define ORANGE_VAGUE_5 3

/**
 *\brief Le nombre total d'ennemis blue.
*/
#define TOTAL_BLUE BLUE_VAGUE_1 + BLUE_VAGUE_2 + BLUE_VAGUE_3 + BLUE_VAGUE_4 + BLUE_VAGUE_5

/**
 *\brief Le nombre total d'ennemis red.
*/
#define TOTAL_RED RED_VAGUE_1 + RED_VAGUE_2 + RED_VAGUE_3 + RED_VAGUE_4 + RED_VAGUE_5

/**
 *\brief Le nombre total d'ennemis green.
*/
#define TOTAL_GREEN GREEN_VAGUE_1 + GREEN_VAGUE_2 + GREEN_VAGUE_3 + GREEN_VAGUE_4 + GREEN_VAGUE_5

/**
 *\brief Le nombre total d'ennemis purple.
*/
#define TOTAL_PURPLE PURPLE_VAGUE_1 + PURPLE_VAGUE_2 + PURPLE_VAGUE_3 + PURPLE_VAGUE_4 + PURPLE_VAGUE_5

/**
 *\brief Le nombre total d'ennemis orange.
*/
#define TOTAL_ORANGE ORANGE_VAGUE_1 + ORANGE_VAGUE_2 + ORANGE_VAGUE_3 + ORANGE_VAGUE_4 + ORANGE_VAGUE_5

/** 
 *\brief Le nombre maximum d'un type d'ennemi dans la vague 1.
*/
#define MAX_VAGUE_1 max(BLUE_VAGUE_1, max(RED_VAGUE_1, max(GREEN_VAGUE_1, PURPLE_VAGUE_1)))

/** 
 *\brief Le nombre maximum d'un type d'ennemi dans la vague 2.
*/
#define MAX_VAGUE_2 max(BLUE_VAGUE_2, max(RED_VAGUE_2, max(GREEN_VAGUE_2, PURPLE_VAGUE_2)))

/** 
 *\brief Le nombre maximum d'un type d'ennemi dans la vague 3.
*/
#define MAX_VAGUE_3 max(BLUE_VAGUE_3, max(RED_VAGUE_3, max(GREEN_VAGUE_3, PURPLE_VAGUE_3)))

/** 
 *\brief Le nombre maximum d'un type d'ennemi dans la vague 4.
*/
#define MAX_VAGUE_4 max(BLUE_VAGUE_4, max(RED_VAGUE_4, max(GREEN_VAGUE_4, PURPLE_VAGUE_4)))

/** 
 *\brief Le nombre maximum d'un type d'ennemi dans la vague 5.
*/
#define MAX_VAGUE_5 max(BLUE_VAGUE_5, max(RED_VAGUE_5, max(GREEN_VAGUE_5, PURPLE_VAGUE_5)))

/** 
 *\brief Le nombre total d'ennemis dans la vague 1.
*/
#define TOTAL_VAGUE_1 BLUE_VAGUE_1 + RED_VAGUE_1 + GREEN_VAGUE_1 + PURPLE_VAGUE_1 + ORANGE_VAGUE_1

/** 
 *\brief Le nombre total d'ennemis dans la vague 2.
*/
#define TOTAL_VAGUE_2 BLUE_VAGUE_2 + RED_VAGUE_2 + GREEN_VAGUE_2 + PURPLE_VAGUE_2 + ORANGE_VAGUE_2

/** 
 *\brief Le nombre total d'ennemis dans la vague 3.
*/
#define TOTAL_VAGUE_3 BLUE_VAGUE_3 + RED_VAGUE_3 + GREEN_VAGUE_3 + PURPLE_VAGUE_3 + ORANGE_VAGUE_3

/** 
 *\brief Le nombre total d'ennemis dans la vague 4.
*/
#define TOTAL_VAGUE_4 BLUE_VAGUE_4 + RED_VAGUE_4 + GREEN_VAGUE_4 + PURPLE_VAGUE_4 + ORANGE_VAGUE_4

/** 
 *\brief Le nombre total d'ennemis dans la vague 5.
*/
#define TOTAL_VAGUE_5 BLUE_VAGUE_5 + RED_VAGUE_5 + GREEN_VAGUE_5 + PURPLE_VAGUE_5 + ORANGE_VAGUE_5

/**
 *\brief Le nombre de missiles du joueur.
*/
#define NB_MISSILES 3

/**
 *\brief La distance entre 2 ennemies.
*/
#define ENEMY_DIST 3 * SHIP_SIZE

/**
 *\brief Le temps entre deux vagues.
*/
#define PAUSE_VAGUE 5

/**
 *\brief La constante de l'état de partie correspondant à la défaite.
*/
#define PERDU 1

/**
 *\brief La constante de l'état de partie correspondant à la destruction de tous les ennemies.
*/
#define PARFAIT 2

/**
 *\brief La constante de l'état de partie correspondant à la victoire.
*/
#define GAGNE 3

/**
 *\brief La constante de l'état de partie correspondant à une partie en cours.
*/
#define EN_COURS 4

#endif