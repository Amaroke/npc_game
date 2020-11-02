/**
 *\file world.h
 *\brief Bibliothèque de world.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef WORLD_H
#define WORLD_H
#include "biblio.h"
#include "sprite.h"

/**
 *\struct world_t
 *\brief Représentation du monde du jeu.
*/
typedef struct world_s
{
	sprite_t *ship;							/*!< Sprite du vaisseau. */
	sprite_t *boss;							/*!< Sprite du boss. */
	sprite_t *blue[TOTAL_BLUE];				/*!< Tableau d'ennemis blue. */
	sprite_t *red[TOTAL_RED];				/*!< Tableau d'ennemis red. */
	sprite_t *green[TOTAL_GREEN];			/*!< Tableau d'ennemis green. */
	sprite_t *purple[TOTAL_PURPLE];			/*!< Tableau d'ennemis purple. */
	sprite_t *orange[TOTAL_ORANGE];			/*!< Tableau d'ennemis orange. */
	sprite_t *missile[NB_MISSILES];			/*!< Sprites des missiles. */
	sprite_t *missile_purple[TOTAL_PURPLE]; /*!< Sprites des missiles ennemis purple. */
	sprite_t *missile_orange[TOTAL_ORANGE]; /*!< Sprites des missiles ennemis orange. */
	sprite_t *missile_boss[BOSS_MISSILES];	/*!< Sprites des missiles du boss. */
	int gameover;							/*!< Champ indiquant si l'on est à la fin du jeu. */
	unsigned int compteur;					/*!< Compteur de vaisseaux sortis. */
	int etat_partie;						/*!< État de la partie. */
	int score;								/*!< Score.*/
	int timer;								/*!< Le timer. */
	int vague;								/*!< La vague. */
	int boss_speed_x;						/*!< La vitesse horizontale du boss. */
	int boss_speed_y;						/*!< La vitesse verticale du boss. */
} world_t;

/**
 *\brief La fonction initialise les données du monde du jeu.
 *\param world Les données du monde.
*/
void init_data_1(world_t *world);

/**
 *\brief La fonction initialise les données des tableaux du monde du jeu.
 *\param tab Les données des tableaux du monde.
 *\param total Nombre total.
*/
void init_data_2(sprite_t *tab[], int total);

/**
 *\brief La fonction nettoie les données du monde.
 *\param world Les données du monde.
*/
void clean_data_1(world_t *world);

/**
 *\brief La fonction nettoie les données du monde.
 *\param tab Les données des tableaux du monde.
 *\param total Nombre total.
*/
void clean_data_2(sprite_t *tab[], int total);

/**
 *\brief La fonction indique si le jeu est fini en fonction des données du monde.
 *\param world Les données du monde.
 *\return 1 si le jeu est fini, 0 sinon.
*/
int is_game_over(world_t *world);

/**
 *\brief Generation d’un nombre entier compris entre a et b (ce dernier non inclus).
 *\param a Borne inférieure.
 *\param b Borne supérieure.
 *\return Un nombre généré aléatoirement entre \a a et \a b.
*/
int generate_number(int a, int b);

/**
 *\brief Maximum entre a et b.
 *\param a Entier a.
 *\param b Entier b.
 *\return Le maximum entre \a a et \a b.
*/
int max(int a, int b);

/**
 *\brief La fonction initialise les données des ennemis blue.
 *\param blue Le tableau d'ennemis blue.
*/
void init_blue(sprite_t *blue[]);

/**
 *\brief La fonction initialise les données des ennemis red.
 *\param red Le tableau d'ennemis red.
*/
void init_red(sprite_t *red[]);

/**
 *\brief La fonction initialise les données des ennemis green.
 *\param green Le tableau d'ennemis green.
*/
void init_green(sprite_t *green[]);

/**
 *\brief La fonction initialise les données des ennemis purple.
 *\param purple Le tableau d'ennemis purple.
*/
void init_purple(sprite_t *purple[]);

/**
 *\brief La fonction initialise les données des ennemis orange.
 *\param orange Le tableau d'ennemis orange.
*/
void init_orange(sprite_t *orange[]);

/**
 *\brief La fonction initialise les données des missiles du joueur.
 *\param world Les données du monde.
*/
void init_missile(world_t *world);

/**
 *\brief La fonction initialise les données des missiles des ennemis.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param enemy Tableau des sprites des missiles.
 *\param total Nombre d'ennemis total.
*/
void init_missile_enemy(world_t *world, sprite_t *enemy[], sprite_t *missile[], int total);

/**
 *\brief La fonction initialise les données des missiles du boss.
 *\param world Les données du monde.
*/
void init_missile_boss(world_t *world);

/**
 *\brief La fonction incrémente le compteur et supprime les ennemis qui dépassent la bordure inférieure.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param total Nombre d'ennemis total.
*/
void depassement_enemy_vertical(world_t *world, sprite_t *enemy[], int total);

/**
 *\brief La fonction indrémente le compteur et supprime les ennemis violets qui dépassent la bordure inférieure.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param total Nombre d'ennemis total.
 *\param limite Limite de l'écran à ne pas dépasser.
*/
void depassement_enemy_horizontal(world_t *world, sprite_t *enemy[], int total, int limite);

/**
 *\brief La fonction incrémente le compteur et supprime les ennemis oranges qui dépassent la bordure inférieure.
 *\param world Les données du monde.
*/
void depassement_orange(world_t *world);

/**
 *\brief La fonction supprime le missile s'il dépasse le haut de l'écran de jeu.
 *\param missile Les missiles du joueur.
*/
void depassement_missile(sprite_t *missile[]);

/**
 *\brief La fonction supprime le missile s'il dépasse le bas de l'écran de jeu.
 *\param missile Les missiles.
 *\param total Le total.
*/
void depassement_missile_enemy(sprite_t *missile[], int total);

/**
 *\brief La fonction supprime le missile s'il dépasse le bas de l'écran de jeu.
 *\param world Les données du monde.
*/
void depassement_missile_boss(world_t *world);

/**
 *\brief La fonction vérifie s'il y a collision entre deux sprites.
 *\param sp2 L'un des sprites.
 *\param sp1 L'autre sprite.
 *\param world Les données du monde.
 *\return 1 si les sprites se collisionnent, 0 sinon.
*/
int sprite_collide(sprite_t *sp2, sprite_t *sp1, world_t *world);

/**
 *\brief La fonction traite l'évènement de collision en rendant invisible les sprites et les arrêtant.
 *\param sp1 L'un des sprites.
 *\param sp2 L'autre sprite.
 *\param world Les données du monde.
*/
void handle_sprite_collide(sprite_t *sp1, sprite_t *sp2, world_t *world);

/**
 *\brief La fonction met à jour les données des ennemis à déplacement vertical.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param total Nombre d'ennemis total.
*/
void update_enemy_vertical(world_t *world, sprite_t *enemy[], int total);

/**
 *\brief La fonction met à jour les données des ennemis à déplacement horizontal.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param total Nombre d'ennemis total.
 *\param limite Limite de l'écran à ne pas dépasser.
*/
void update_enemy_horizontal(world_t *world, sprite_t *enemy[], int total, int limite);

/**
 *\brief La fonction met à jour les données du boss.
 *\param world Les données du monde.
*/
void update_boss(world_t *world);

/**
 *\brief La fonction met à jour les données du missile.
 *\param world Les données du monde.
*/
void update_missile(world_t *world);

/**
 *\brief La fonction met à jour les données du missile de l'ennemi.
 *\param world Les données du monde.
 *\param enemy Tableau des sprites d'ennemis.
 *\param missile  Tableau des missiles d'ennemis.
 *\param total Nombre d'ennemis total.
*/
void update_missile_enemy(world_t *world, sprite_t *enemy[], sprite_t *missile[], int total);

/**
 *\brief La fonction met à jour les données du missile du boss.
 *\param world Les données du monde.
*/
void update_missile_boss(world_t *world);

/**
 *\brief La fonction donne l'état de la partie.
 *\param world Les données du monde.
*/
void compute_game(world_t *world);

/**
 *\brief La fonction met à jour les données en tenant compte de la physique du monde.
 *\param world Les données du monde.
*/
void update_data(world_t *world);

#endif
