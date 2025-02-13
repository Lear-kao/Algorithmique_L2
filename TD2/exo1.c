#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"

//CONSTANTE
#define max_noeuds 15

//fonction
enfant* creer_noeud(int info);
void saisie_dEnfant( void );
void imprimmer__enfant( void );



//variable
int n = 8;
enfant *fils[max_noeuds]; //tableau de  pointeur
/* 
Ex1:
Ecrire un programme en permettant, d'afficher les noeuds d'un arbre général par le parcours BFS.
Lister les noeuds selon leur niveau .
En déduire la hauteur de l'arbre.
*/

//a- Utilisons une file de listes chainées.

/* 
L'arbre A est  numéroté selon BFS:
1 2 3 4 5 6 7 8 9 10 11
N0-1
N1- 2, 3, 4
N2- 5, 6, 7, 8, 9
N3- 9, 10, 11
*/


void bfs( int i )
/* 
lister les noeuds de A dans l'ordre BFS
A est représenté par les listes de ses enfants.
*/
{
    enfiler(i);
    while( tete != NULL)
    {
        int j = defiler();
        //enfiler tout les enfants de j. Les fils sont déja saisies
        for ( link t = fils[j]; t!= NULL; t = t->suiv)
        {
            enfiler(t->info);
        }
    }
}