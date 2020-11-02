/* Allouer un tableau de caractères de taille n x m,
où n et m sont les nombres de lignes et de colonnes, 
et initialiserce tableau avec le caractère espace (’ ’).*/
char** allouer_tab_2D(int n, int m);

/* Libérer un tableau à deux dimensions, de n lignes et de colonnes m.*/
void desallouer_tab_2D(char** tab, int n, int m);

/* Afficher le contenu d'un tableau de caractères de taille n x m.*/
void afficher_tab_2D(char** tab, int n, int m);

/* Compter le nombre max de lignes (nbLig) et de colonnes (nbCol) dans le fichier dont le nom estnomFichier.*/
void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);

/* Lire un fichier dont le nom est nomFichier,
et retourner le tableau qui contient les caractères du fichier tel
qu’une ligne du tableau correspond à une ligne du fichier.*/
char** lire_fichier(const char* nomFichier);

/* Retourner un nouveau tableau, dans lequel toutes les occurrences du caractère ancien sont remplacées par le caractère nouveau. */
char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);

/* Écrire le tableautabde taille n x m dans un fichier dont le nom estnomFichier. */
void ecrire_fichier(const char* nomFichier, char** tab, int n, int m);