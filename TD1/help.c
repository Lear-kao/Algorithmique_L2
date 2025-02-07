/*
Ecrire une fonction permettant d'écrire les noeuds  d'un arbre  genera selon le parcours BFS.
INPUT: N0:1, N1:2 6 7 , N2:3 4 8 17 16 15 14 13,  N3:5 18 9 10 11 12 19
*/
#include <stdio.h>
#include <stdlib.h>

#define max_noeuds 15

void imprimmer__enfant( void );
typedef struct noeud
{
    struct noeud *suiv;
    int val;
}enfant;

int n = 8;
enfant *fils[max_noeuds]; //tableau de  pointeur

/*creer noeud avec l'info donné*/
enfant* creer_noeud(int info)
{
    enfant *temp = (enfant*)malloc(sizeof(enfant));
    temp -> val = info;
    temp -> suiv = NULL;
    return temp;
}

void saisie_dEnfant( void )
{
    enfant  *temp;
    int ne;

    /*initialisation de tab*/
    for  (int i = 0; i < n; i++)fils[i] = NULL;

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
            //on stocke e
            temp = creer_noeud(e);
            //attacher les  enfants à temp et temp à la tête
            temp->suiv = fils[i];
            fils[i] = temp;

        }
    }
}

void imprimmer__enfant( void )
{
    enfant *temp;
    for( int i = 0; i < n; i++)
    {
        temp = fils[i];
        if ( fils[i] = NULL ) return;
        else 
        {
            for( ; temp !=  NULL; temp = temp->suiv ) printf("%d,", temp->val );
            printf("\n");
        } 
    }
}
 
 /*
 ALGO: On utilise une file

 */

void bfs( int i)
/*effectuer bfs d'un arbre  avec la  racine i*/
{
    enfiler(i);
    while(file != NULL)
    {
        int j = defiler(*file);
        printf("%d,",j);
        //enfiler tout les enfants de j
        for(lien t = fils[j]; t != NULL;  t = t->suiv)
        {
            enfiler( t->info )
        }
    }
}

