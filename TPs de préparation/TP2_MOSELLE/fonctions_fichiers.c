#include <stdlib.h>
#include <stdio.h>
#include "fonctions_fichiers.h"



char** allouer_tab_2D(int n, int m)
{
    char** tab = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        tab[i]=malloc(m*sizeof(char));
        for(int j=0;j<m;j++)
        {
            tab[i][j]= '.';
        }
    }
    return tab;
}

void desallouer_tab_2D(char** tab, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        free(tab[i]);
        for(int j=0;j<m;j++)
        {
            free(tab[i][j]);
        }
    }
}


void afficher_tab_2D(char** tab, int n, int m)
{
    int i;
    int j;

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<m;j++)
		{
            printf("%c",tab[i][j]);
        }
		printf("\n");
    }

}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol)
{
    printf("null");
}

char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (tab[i][j]== ancien)
            {
                tab[i][j] = nouveau;
            }
        }
    }
    return tab;
}