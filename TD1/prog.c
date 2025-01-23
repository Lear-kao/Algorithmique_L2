#include <stdio.h>
#define MAX_NOEUDS 20

int papa[MAX_NOEUDS], feuille[MAX_NOEUDS];
int n, n_feuille;//n <= MAX_NOEUDS

//saisie d'un arbre par tableau de papa

void saisie( int n )
{
    for(int i = 0; i < n; n++)
    {
        printf("entrer papa noeud %d stp",i);
        scanf("%d",&(papa[i]));
    }
}
