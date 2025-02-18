#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"

//CONSTANTE
#define max_noeuds 15

//variable
int n = 11;
enfant *fils[max_noeuds]; //tableau de  pointeurs


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


void bfs( int i, link *fils, int n )
/* 
lister les noeuds de A dans l'ordre BFS
A est représenté par les listes de ses enfants.
*/
{
    int l[n];
    l[i] = 0;
    link head;
    link tail;
    enfiler(&head,&tail,i);
    while( head != NULL)
    {
        int j = defiler(&head,&tail);
        //enfiler tout les enfants de j. Les fils sont déja saisies
        for ( link t = fils[j]; t!= NULL; t = t->next)
        {
            enfiler(&head,&tail,t->info);
            l[t->info] = l[j]+1; //niveaud'un noeud = niveau deson papa + 1
     
        }
    }
    //affichage
    int h = max(l, n);
    for(  int i = 0; i < h; i++)
    {
        printf("voici les  noeuds au  niveau %d\n", i);
        for(  int j = 0; j  < n; j++)
        {
            if( l[j] == i )
            {
                printf("%d-",j);
            }
        }
        printf("\n");
    }

}

arbre_bin *search(arbre_bin *root, int data)
/* 
Recherche  de data dans un  arbre  binaire de recherchede manière récursive
*/
{
    if( root -> info == data)
    {
        return root;
    }
    if (data > root -> info )
    {
        search( root -> right, data );
    }
    else 
        search( root -> left, data );
    return NULL;
}

arbre_bin *search_it(arbre_bin *root, int data)
/* 
Recherche  de data dans un  arbre  binaire de recherchede manière récursive
*/
{
    while( root != NULL )
    {
        if( root -> info == data)
        {
            return root;
        }
        if (data > root -> info )
        {
            root = root -> right;
        }
        else 
            root = root -> left;
    }
    return NULL;
}

int main( void )
{
    link list[11];
    saisie_dEnfant(11,list);
    bfs(1,list,11);
    return 0;
}