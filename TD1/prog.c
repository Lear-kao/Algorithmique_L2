#include <stdio.h>
#define MAX_NOEUDS 20

int papa[MAX_NOEUDS], feuille[MAX_NOEUDS];
int n, n_feuille = 0;//n <= MAX_NOEUDS

//saisie d'un arbre par tableau de papa

void saisie( int n )
{
    for(int i = 0; i < n; n++)
    {
        printf("entrer papa noeud %d stp",i);
        scanf("%d",&(papa[i]));
    }
}

void feuille_arbre(int n)
{
    for(int i = 0; i < n; i++)
    {
        /* tester si i est une feuille */
        int est_feuille = 1;
        int j = 0;
        while( est_feuille != 0 && j < n)
        {
            if( papa[j] == i )
            {
                est_feuille = 0;
            }
            j++;
        }
        if ( est_feuille == 1 )
        {
            feuille[n_feuille] = i;
            n_feuille++;
        }
        est_feuille = 1;
    }
}