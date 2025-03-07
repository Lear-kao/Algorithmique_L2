#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"

/* 
Tournoi:
Def: C'est  un  arbre binaire  dans lequel la valeur de noeud d'un
Papa = max(noeud_gauche,noeud_droit)
10
    9
        9

        6

    10
        10

        8
            7

            8
*/

/* 
Algo: Transformer le  tableau t : 
[7,2,3,9,6,10,12,1,4] 
en un tournois.

Utilisons *divide and conquer*

    t[0:4] -------- t[5:8]

t[0:2]---t[3:4]|t[5:6]---t[7:8]]
ect...
*/

/* 
fct utilisée
arbre_bin *creerNoeudArbreBinaire(int info)
*/


int max_t(arbre_bin *a)
{
    if (a->left == NULL) return a->right->info;
    if (a->right == NULL) return a->left->info;
    if( a->right->info > a->left->info ) return a->right->info;
    return a->left->info;
}


arbre_bin *tournoi(int *tab, int g,int d)
/* 
Transformer le tableau T en un tournoi binaire
*/
{
    int m = (g+d)/2; // *Divide*
    arbre_bin *p = creerNoeudArbreBinaire(tab[m]);
    if( g==d ) return p;
    p->left = tournoi(tab,g,m);
    p->right = tournoi(tab,m+1,d);
    p->info = max_t(p);
    return p;
}


int main( void )
{
    int t[8] = {13,3,6,9,12,4,7,1};
    arbre_bin *a = tournoi(t,0,7);
    imprimer_arbre(a,4);
    postfixeIte(a);
    return 0;
}