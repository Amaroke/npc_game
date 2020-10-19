#include <stdio.h>
#include "fonctions_fichiers.h"

char** allouer_tab_2D(int n, int m){
    char** tab = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        tab[i]=malloc(m*sizeof(char));
        for(int j=0;j<m;j++){
            tab[i][j]=' ';
        }
    }
    return tab;
}

void desallouer_tab_2D(char** tab, int n)
{
    for(int i=0;i<n;i++)
    {
        free(tab[i]);
    }
    free(tab);
}

void afficher_tab_2D(char** tab, int n, int m){

}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){

}

char** lire_fichier(const char* nomFichier){

}
