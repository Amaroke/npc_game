#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "fonctions_fichiers.h"

int main()
{
    char** tab = allouer_tab_2D(5, 5);
    afficher_tab_2D(tab, 5, 5);
    char** tab2 = modifier_caractere(tab, 5, 5, '.', '@');
    afficher_tab_2D(tab2, 5, 5);
    printf("Exit...")
    return EXIT_SUCCESS;
}