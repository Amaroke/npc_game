/**
 *\file world.c
 *\brief Gestion du monde.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#include "world.h"

void init_data_1(world_t *world)
{
	//On initialise les données du monde :
	world->gameover = 0;
	world->compteur = 0;
	world->score = 0;
	world->timer = 0;
	world->vague = 1;
	world->boss_speed_x = ENEMY_SPEED;
	world->boss_speed_y = ENEMY_SPEED;
	world->etat_partie = EN_COURS;
	world->ship = malloc(sizeof(sprite_t));
	world->boss = malloc(sizeof(sprite_t));
	init_data_2(world->blue, TOTAL_BLUE);
	init_data_2(world->red, TOTAL_RED);
	init_data_2(world->green, TOTAL_GREEN);
	init_data_2(world->purple, TOTAL_PURPLE);
	init_data_2(world->orange, TOTAL_ORANGE);
	init_data_2(world->missile, NB_MISSILES);
	init_data_2(world->missile_purple, TOTAL_PURPLE);
	init_data_2(world->missile_orange, TOTAL_ORANGE);
	init_data_2(world->missile_boss, BOSS_MISSILES);
	init_sprite(world->ship, SCREEN_WIDTH / 2, SCREEN_HEIGHT - SHIP_SIZE, SHIP_SIZE, SHIP_SIZE, 0, 1, 5);
	init_sprite(world->boss, SCREEN_WIDTH / 2, -5 * PAUSE_VAGUE * ENEMY_DIST + (-BOSS_SIZE / 2 - ((MAX_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) * ENEMY_DIST)), BOSS_SIZE, BOSS_SIZE, BOSS_SPEED_Y, 1, BOSS_HP);
	init_missile(world);
	init_blue(world->blue);
	init_red(world->red);
	init_green(world->green);
	init_purple(world->purple);
	init_orange(world->orange);
	init_missile_enemy(world, world->purple, world->missile_purple, TOTAL_PURPLE);
	init_missile_enemy(world, world->orange, world->missile_orange, TOTAL_ORANGE);
	init_missile_boss(world);
}

void init_data_2(sprite_t *tab[], int total)
{
	for (int i = 0; i < total; i++)
	{
		tab[i] = malloc(sizeof(sprite_t));
	}
}

void clean_data_1(world_t *world)
{
	//On libère l'espace mémoire des données du monde :
	free(world->ship);
	free(world->boss);
	clean_data_2(world->missile, NB_MISSILES);
	clean_data_2(world->missile_purple, TOTAL_PURPLE);
	clean_data_2(world->missile_orange, TOTAL_ORANGE);
	clean_data_2(world->missile_boss, BOSS_MISSILES);
	clean_data_2(world->blue, TOTAL_BLUE);
	clean_data_2(world->red, TOTAL_RED);
	clean_data_2(world->green, TOTAL_GREEN);
	clean_data_2(world->purple, TOTAL_PURPLE);
	clean_data_2(world->orange, TOTAL_ORANGE);
}

void clean_data_2(sprite_t *tab[], int total)
{
	for (int i = 0; i < total; i++)
	{
		free(tab[i]);
	}
}

int is_game_over(world_t *world)
{
	return world->gameover;
}

int generate_number(int a, int b)
{
	return rand() % (b - a) + a;
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void init_blue(sprite_t *blue[])
{
	//Vague 1 :
	for (int i = 0; i < BLUE_VAGUE_1; i++)
	{
		init_sprite(blue[i], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), (-SHIP_SIZE / 2 - i * ENEMY_DIST), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 2 :
	for (int i = MAX_VAGUE_1; i < BLUE_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(blue[i - (MAX_VAGUE_1 - BLUE_VAGUE_1)], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 3 :
	for (int i = MAX_VAGUE_1 + MAX_VAGUE_2; i < BLUE_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(blue[i - ((MAX_VAGUE_1 + MAX_VAGUE_2) - (BLUE_VAGUE_1 + BLUE_VAGUE_2))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -2 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 4 :
	for (int i = MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < BLUE_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(blue[i - ((MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (BLUE_VAGUE_1 + BLUE_VAGUE_2 + BLUE_VAGUE_3))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -3 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 5 :
	for (int i = MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < BLUE_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(blue[i - ((MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (BLUE_VAGUE_1 + BLUE_VAGUE_2 + BLUE_VAGUE_3 + BLUE_VAGUE_4))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -4 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
}

void init_red(sprite_t *red[])
{
	//Vague 1 :
	for (int i = 0; i < RED_VAGUE_1; i++)
	{
		init_sprite(red[i], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), (-SHIP_SIZE / 2 - i * ENEMY_DIST), SHIP_SIZE, SHIP_SIZE, 2 * ENEMY_SPEED, 1, 1);
	}
	//Vague 2 :
	for (int i = MAX_VAGUE_1; i < RED_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(red[i - (MAX_VAGUE_1 - RED_VAGUE_1)], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -PAUSE_VAGUE * 2 * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * 2 * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, 2 * ENEMY_SPEED, 1, 1);
	}
	//Vague 3 :
	for (int i = MAX_VAGUE_1 + MAX_VAGUE_2; i < RED_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(red[i - ((MAX_VAGUE_1 + MAX_VAGUE_2) - (RED_VAGUE_1 + RED_VAGUE_2))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -2 * PAUSE_VAGUE * 2 * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * 2 * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, 2 * ENEMY_SPEED, 1, 1);
	}
	//Vague 4 :
	for (int i = MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < RED_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(red[i - ((MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (RED_VAGUE_1 + RED_VAGUE_2 + RED_VAGUE_3))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -3 * PAUSE_VAGUE * 2 * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * 2 * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, 2 * ENEMY_SPEED, 1, 1);
	}
	//Vague 5 :
	for (int i = MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < RED_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(red[i - ((MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (RED_VAGUE_1 + RED_VAGUE_2 + RED_VAGUE_3 + RED_VAGUE_4))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -4 * PAUSE_VAGUE * 2 * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * 2 * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, 2 * ENEMY_SPEED, 1, 1);
	}
}

void init_green(sprite_t *green[])
{
	//Vague 1 :
	for (int i = 0; i < GREEN_VAGUE_1; i++)
	{
		init_sprite(green[i], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), (-SHIP_SIZE / 2 - i * ENEMY_DIST), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 2);
	}
	//Vague 2 :
	for (int i = MAX_VAGUE_1; i < GREEN_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(green[i - (MAX_VAGUE_1 - GREEN_VAGUE_1)], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 2);
	}
	//Vague 3 :
	for (int i = MAX_VAGUE_1 + MAX_VAGUE_2; i < GREEN_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(green[i - ((MAX_VAGUE_1 + MAX_VAGUE_2) - (GREEN_VAGUE_1 + GREEN_VAGUE_2))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -2 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 2);
	}
	//Vague 4 :
	for (int i = MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < GREEN_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(green[i - ((MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (GREEN_VAGUE_1 + GREEN_VAGUE_2 + GREEN_VAGUE_3))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -3 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 2);
	}
	//Vague 5 :
	for (int i = MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < GREEN_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(green[i - ((MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (GREEN_VAGUE_1 + GREEN_VAGUE_2 + GREEN_VAGUE_3 + GREEN_VAGUE_4))], generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), -4 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 2);
	}
}

void init_purple(sprite_t *purple[])
{
	//Vague 1 :
	for (int i = 0; i < PURPLE_VAGUE_1; i++)
	{
		init_sprite(purple[i], (-SHIP_SIZE / 2 - i * ENEMY_DIST), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 2 :
	for (int i = MAX_VAGUE_1; i < PURPLE_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(purple[i - (MAX_VAGUE_1 - PURPLE_VAGUE_1)], -PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 3 :
	for (int i = MAX_VAGUE_1 + MAX_VAGUE_2; i < PURPLE_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(purple[i - ((MAX_VAGUE_1 + MAX_VAGUE_2) - (PURPLE_VAGUE_1 + PURPLE_VAGUE_2))], -2 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 4 :
	for (int i = MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < PURPLE_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(purple[i - ((MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (PURPLE_VAGUE_1 + PURPLE_VAGUE_2 + PURPLE_VAGUE_3))], -3 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
	//Vague 5 :
	for (int i = MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < PURPLE_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(purple[i - ((MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (PURPLE_VAGUE_1 + PURPLE_VAGUE_2 + PURPLE_VAGUE_3 + PURPLE_VAGUE_4))], -4 * PAUSE_VAGUE * ENEMY_DIST + (-SHIP_SIZE / 2 - (i * ENEMY_DIST)), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, ENEMY_SPEED, 1, 1);
	}
}

void init_orange(sprite_t *orange[])
{
	//Vague 1 :
	for (int i = 0; i < ORANGE_VAGUE_1; i++)
	{
		init_sprite(orange[i], -(-SCREEN_WIDTH - SHIP_SIZE / 2 - i * ENEMY_DIST), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, -ENEMY_SPEED, 1, 1);
	}
	//Vague 2 :
	for (int i = MAX_VAGUE_1; i < ORANGE_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(orange[i - (MAX_VAGUE_1 - ORANGE_VAGUE_1)], -(-PAUSE_VAGUE * ENEMY_DIST + (-SCREEN_WIDTH - SHIP_SIZE / 2 - (i * ENEMY_DIST))), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, -ENEMY_SPEED, 1, 1);
	}
	//Vague 3 :
	for (int i = MAX_VAGUE_1 + MAX_VAGUE_2; i < ORANGE_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(orange[i - ((MAX_VAGUE_1 + MAX_VAGUE_2) - (ORANGE_VAGUE_1 + ORANGE_VAGUE_2))], -(-2 * PAUSE_VAGUE * ENEMY_DIST + (-SCREEN_WIDTH - SHIP_SIZE / 2 - (i * ENEMY_DIST))), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, -ENEMY_SPEED, 1, 1);
	}
	//Vague 4 :
	for (int i = MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < ORANGE_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(orange[i - ((MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (ORANGE_VAGUE_1 + ORANGE_VAGUE_2 + ORANGE_VAGUE_3))], -(-3 * PAUSE_VAGUE * ENEMY_DIST + (-SCREEN_WIDTH - SHIP_SIZE / 2 - (i * ENEMY_DIST))), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, -ENEMY_SPEED, 1, 1);
	}
	//Vague 5 :
	for (int i = MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i < ORANGE_VAGUE_5 + MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1; i++)
	{
		init_sprite(orange[i - ((MAX_VAGUE_4 + MAX_VAGUE_3 + MAX_VAGUE_2 + MAX_VAGUE_1) - (ORANGE_VAGUE_1 + ORANGE_VAGUE_2 + ORANGE_VAGUE_3 + ORANGE_VAGUE_4))], -(-4 * PAUSE_VAGUE * ENEMY_DIST + (-SCREEN_WIDTH - SHIP_SIZE / 2 - (i * ENEMY_DIST))), generate_number(SHIP_SIZE / 2, SCREEN_WIDTH - SHIP_SIZE / 2), SHIP_SIZE, SHIP_SIZE, -ENEMY_SPEED, 1, 1);
	}
}

void init_missile(world_t *world)
{
	for (int i = 0; i < NB_MISSILES; i++)
	{
		init_sprite(world->missile[i], world->ship->x, world->ship->y, MISSILE_SIZE, MISSILE_SIZE, 0, 0, 1);
	}
}

void init_missile_enemy(world_t *world, sprite_t *enemy[], sprite_t *missile[], int total)
{
	for (int i = 0; i < total; i++)
	{
		init_sprite(missile[i], enemy[i]->x, enemy[i]->y, MISSILE_SIZE, MISSILE_SIZE, 0, 0, 1);
	}
}

void init_missile_boss(world_t *world)
{
	for (int i = 0; i < BOSS_MISSILES; i++)
	{
		init_sprite(world->missile_boss[i], world->boss->x, world->boss->y, MISSILE_SIZE, MISSILE_SIZE, 0, 0, 1);
	}
}

void depassement_enemy_vertical(world_t *world, sprite_t *enemy[], int total)
{
	for (int i = 0; i < total; ++i)
	{
		if (enemy[i]->y == SCREEN_HEIGHT + (SHIP_SIZE / 2))
		{
			enemy[i]->v = 0;
			enemy[i]->y = -SHIP_SIZE;
			set_invisible(enemy[i]);
			if (world->etat_partie == EN_COURS)
			{
				world->score -= 100;
				world->compteur++;
			}
		}
	}
}

void depassement_enemy_horizontal(world_t *world, sprite_t *enemy[], int total, int limite)
{
	for (int i = 0; i < total; ++i)
	{
		if (enemy[i]->x == limite)
		{
			enemy[i]->v = 0;
			enemy[i]->x = -SHIP_SIZE;
			set_invisible(enemy[i]);
			if (world->etat_partie == EN_COURS)
			{
				world->score -= 100;
				world->compteur++;
			}
		}
	}
}

void depassement_missile(sprite_t *missile[])
{
	for (int i = 0; i < NB_MISSILES; ++i)
	{
		if (missile[i]->y <= 0)
		{
			set_invisible(missile[i]);
			missile[i]->v = 0;
		}
	}
}

void depassement_missile_enemy(sprite_t *missile[], int total)
{
	for (int i = 0; i < total; ++i)
	{
		if (missile[i]->y > SCREEN_HEIGHT)
		{
			set_invisible(missile[i]);
			missile[i]->v = 0;
		}
	}
}

void depassement_missile_boss(world_t *world)
{
	for (int i = 0; i < BOSS_MISSILES; ++i)
	{
		if (world->missile_boss[i]->y > SCREEN_HEIGHT)
		{
			set_invisible(world->missile_boss[i]);
			world->missile_boss[i]->v = 0;
		}
	}
}

int sprite_collide(sprite_t *sp2, sprite_t *sp1, world_t *world)
{
	if (sqrt(pow(sp1->x - sp2->x, 2) + pow(sp1->y - sp2->y, 2)) <= (sp1->h + sp2->h) / 2)
	{
		return 1;
	}
	return 0;
}

void handle_sprite_collide(sprite_t *sp1, sprite_t *sp2, world_t *world)
{
	if (sprite_collide(sp1, sp2, world) == 1 && (sp1->is_visible == 1 && sp2->is_visible == 1))
	{
		//On retire un point de vie à chaque sprite, si ses points de vie sont à zéro on le rend invisible.
		--sp1->hp;
		--sp2->hp;
		if (sp1->hp == 0)
		{
			sp1->v = 0;
			set_invisible(sp1);
		}
		//Si les points de vie de l'ennemi sont à zéro, on incrémente le score, le compteur et on retire le vaisseau de l'affichage.
		if (sp2->hp == 0)
		{
			world->score += (SCREEN_HEIGHT - sp2->y) * 500 / SCREEN_HEIGHT;
			world->compteur += 1;
			sp2->v = 0;
			sp2->x = SCREEN_WIDTH + 100;
			sp2->y = SCREEN_HEIGHT + 100;
			set_invisible(sp2);
		}
	}
}

void update_enemy_vertical(world_t *world, sprite_t *enemy[], int total)
{
	depassement_enemy_vertical(world, enemy, total);
	for (int i = 0; i < total; i++)
	{
		enemy[i]->y += enemy[i]->v;
		handle_sprite_collide(world->ship, enemy[i], world);
		for (int j = 0; j < NB_MISSILES; j++)
		{
			handle_sprite_collide(world->missile[j], enemy[i], world);
		}
	}
}

void update_enemy_horizontal(world_t *world, sprite_t *enemy[], int total, int limite)
{
	depassement_enemy_horizontal(world, enemy, total, limite);
	for (int i = 0; i < total; i++)
	{
		enemy[i]->x += enemy[i]->v;
		for (int j = 0; j < NB_MISSILES; j++)
		{
			handle_sprite_collide(world->missile[j], enemy[i], world);
		}
	}
}

void update_boss(world_t *world)
{
	world->boss->y += world->boss_speed_y;
	world->boss->x += world->boss_speed_x;
	if (world->boss->x == SCREEN_WIDTH - BOSS_SIZE / 2)
	{
		world->boss_speed_x = -ENEMY_SPEED;
	}
	if ((world->boss->x == BOSS_SIZE / 2))
	{
		world->boss_speed_x = ENEMY_SPEED;
	}
	if (world->boss->y == SCREEN_HEIGHT * 2 / 3)
	{
		world->boss_speed_y = -ENEMY_SPEED;
	}
	if (world->boss->y > 0 && world->boss->y == BOSS_SIZE / 2)
	{
		world->boss_speed_y = ENEMY_SPEED;
	}
	for (int j = 0; j < NB_MISSILES; j++)
	{
		//On gère la colision du boss avec les missiles ainsi que sa téléportation à chaque coup reçu.
		if (sprite_collide(world->boss, world->missile[j], world) == 1 && (world->boss->is_visible == 1 && world->missile[j]->is_visible == 1))
		{
			handle_sprite_collide(world->missile[j], world->boss, world);
			world->boss->x = generate_number(BOSS_SIZE, SCREEN_WIDTH - BOSS_SIZE);
			world->boss->y = generate_number(BOSS_SIZE, SCREEN_HEIGHT * 2 / 3 - BOSS_SIZE);
			world->boss_speed_y = -world->boss_speed_y;
			world->boss_speed_x = -world->boss_speed_x;
		}
	}
}

void update_missile(world_t *world)
{
	depassement_missile(world->missile);
	for (int i = 0; i < NB_MISSILES; i++)
	{
		if (world->missile[i]->is_visible == 0)
		{
			world->missile[i]->y = world->ship->y;
			world->missile[i]->x = world->ship->x;
		}
		else
		{
			world->missile[i]->y -= world->missile[i]->v;
		}
	}
}

void update_missile_enemy(world_t *world, sprite_t *enemy[], sprite_t *missile[], int total)
{
	depassement_missile_enemy(missile, total);
	for (int i = 0; i < total; i++)
	{
		//Si le missile est visible et que l'ennemi est sur l'écran.
		if (missile[i]->is_visible == 0 && enemy[i]->x < SCREEN_WIDTH && enemy[i]->x > 0)
		{
			//On fais un tirage aléatoire entre 0 et 200.
			int random;
			random = generate_number(0, 200);
			//S'il est de 0, on lance un missile depuis l'ennemi.
			if (random == 0)
			{
				missile[i]->is_visible = 1;
				missile[i]->v = MISSILE_SPEED_ENEMY;
			}
		}
		if (missile[i]->is_visible == 0)
		{
			missile[i]->y = enemy[i]->y;
			missile[i]->x = enemy[i]->x;
		}
		else
		{
			missile[i]->y += missile[i]->v;
		}
		//On gère les collisions des missiles avec le joueur.
		if (sprite_collide(world->ship, missile[i], world) == 1 && (world->ship->is_visible == 1 && missile[i]->is_visible == 1))
		{
			--world->ship->hp;
			--missile[i]->hp;
			if (world->ship->hp == 0)
			{
				world->ship->v = 0;
				set_invisible(world->ship);
			}
			if (missile[i]->hp == 0)
			{
				missile[i]->v = 0;
				set_invisible(missile[i]);
			}
		}
	}
}

void update_missile_boss(world_t *world)
{
	depassement_missile_boss(world);
	if (world->boss->is_visible == 0 && world->etat_partie == EN_COURS)
	{
		world->score += world->ship->hp * 1000;
		for (int i = 0; i < BOSS_MISSILES; i++)
		{
			world->missile_boss[i]->is_visible = 0;
		}
	}
	for (int i = 0; i < BOSS_MISSILES; i++)
	{
		//Si le missile est visible et que l'ennemi est sur l'écran.
		if (world->missile_boss[i]->is_visible == 0 && world->boss->y < SCREEN_WIDTH && world->boss->y > 0 && world->boss->is_visible == 1)
		{
			//On fait un tirage aléatoire entre 0 et 50.
			int random;
			random = generate_number(0, 200);
			//S'il est de 0, on lance un missile depuis le boss.
			if (random == 0)
			{
				world->missile_boss[i]->is_visible = 1;
				world->missile_boss[i]->v = MISSILE_SPEED_ENEMY;
			}
		}
		if (world->missile_boss[i]->is_visible == 0)
		{
			world->missile_boss[i]->y = world->boss->y;
			world->missile_boss[i]->x = world->boss->x;
		}
		else
		{
			world->missile_boss[i]->y += world->missile_boss[i]->v;
		}
		if (sprite_collide(world->ship, world->missile_boss[i], world) == 1 && (world->ship->is_visible == 1 && world->missile_boss[i]->is_visible == 1))
		{
			--world->ship->hp;
			--world->missile_boss[i]->hp;
			if (world->ship->hp == 0)
			{
				world->ship->v = 0;
				set_invisible(world->ship);
			}
			if (world->missile_boss[i]->hp == 0)
			{
				world->missile_boss[i]->v = 0;
				set_invisible(world->missile_boss[i]);
			}
		}
	}
}

void compute_game(world_t *world)
{
	//Le joueur a perdu
	if (world->ship->is_visible == 0)
	{
		world->etat_partie = PERDU;
	}

	//Le joueur a gagné
	if (world->ship->is_visible == 1)
	{
		world->etat_partie = PARFAIT;
		if (world->boss->is_visible == 1)
		{
			world->etat_partie = EN_COURS;
		}
	}

	//Le joueur n'a pas abattu tous les ennemis
	if (world->ship->is_visible == 1 && world->compteur != 0)
	{
		world->etat_partie = GAGNE;
		if (world->boss->is_visible == 1)
		{
			world->etat_partie = EN_COURS;
		}
	}
}

void update_data(world_t *world)
{
	compute_game(world);
	if (world->etat_partie != EN_COURS)
	{
		++world->timer;
	}
	if (world->timer > 500)
	{
		world->gameover = 1;
	}
	update_enemy_vertical(world, world->blue, TOTAL_BLUE);
	update_enemy_vertical(world, world->red, TOTAL_RED);
	update_enemy_vertical(world, world->green, TOTAL_GREEN);
	update_enemy_horizontal(world, world->purple, TOTAL_PURPLE, SCREEN_WIDTH + (SHIP_SIZE / 2));
	update_enemy_horizontal(world, world->orange, TOTAL_ORANGE, -(SHIP_SIZE / 2));
	update_boss(world);
	update_missile(world);
	update_missile_enemy(world, world->purple, world->missile_purple, TOTAL_PURPLE);
	update_missile_enemy(world, world->orange, world->missile_orange, TOTAL_ORANGE);
	update_missile_boss(world);
}