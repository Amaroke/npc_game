# Projet de programmation avancée

+ relancer un niveau test affichage + ecrandacceuil

Entités ennemies

Gestion d'une arme / projectiles

interaction avec element decor (bouton)


//MODIFICATIONS du 01/01/2021
Ajout d'une enum dans jeu pour pouvoir avoir accès à tous les états du jeu.
Modification du init dans affichage.c, l'appel de la méthode init_data ne se fait plus dans init mais
lors du changement d'état du jeu (passage level 1 au 2 etc) afin de pouvoir gérer le point de départ
et le point d'arrivé pour chaque niveau(emplacement initial du joueur et du vortex).