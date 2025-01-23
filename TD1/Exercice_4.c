#include <stdio.h>
#include <stdlib.h>

#define max_noeuds 15
typedef struct noeud
{
    enfant *suiv;
    int val;
}enfant;

int n;
noeud *fils[max_noeuds]; //tableau de  pointeur

/*creer noeud avec l'info donné*/
noeud* creer_noeud(int info)
{
    noeud *temp = (noeud*)malloc(sizeof(noeud));
    temp -> val = info;
    temp -> suiv = NULL;
    return temp;
}

void saise_dEnfant( void )
{
    noeud  *t;
    int ne;
    /*initialisation de tab*/
    for  (int i = 0; i < n)
    {
        fils[i] = NULL;
    }
    //saisie des enfants de chaque noeuds
    for(int i = 0;i < n; i++)
    {
        printf("nombre d'enfant stp\n");
        scanf("%d", &ne);
        for( int j = 0; j < ne; j++)
        {
            printf("entrer val");
            int e;
            scanf("%d",&e);
            noeud *temp = creer_noeud(e);
            //attacher les  enfants à temp et temp à la tête
        }
    }
}


