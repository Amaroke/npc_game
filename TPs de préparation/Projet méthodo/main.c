/**
 *\file main.c
 *\brief Programme principal du jeu.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef MAIN_C
#define MAIN_C
#include "biblio.h"
#include "event.h"
#include "sprite.h"
#include "ressources.h"
#include "world.h"
#include "renderer.h"
#endif

/**
 *\brief Programme principal qui implémente la boucle du jeu.
*/
int main(int argc, char *args[])
{
	srand(time(NULL));
	SDL_Event event;
	world_t world;
	ressources_t ressources;
	SDL_Renderer *renderer;
	SDL_Window *window;
	//Initialisation du jeu :
	init(&window, &renderer, &ressources, &world);

	//Boucle du jeu :
	while (!is_game_over(&world)) //Tant que le jeu n'est pas fini.
	{
		//Gestion des évènements :
		handle_events(&event, &world);
		//Mise à jour des données liée à la physique du monde :
		update_data(&world);
		//Rafraichissement de l'écran :
		refresh_graphics(renderer, &world, &ressources);
		//Pause de 10 ms pour controler la vitesse de rafraichissement :
		pause(10);
	}

	//Nettoyage final :
	clean(window, renderer, &ressources, &world);

	return EXIT_SUCCESS;
}
