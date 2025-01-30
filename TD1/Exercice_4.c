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
Exercice 10:
*/
void parcour_prefixe( int i )
{
    printf("%d ",i);
    for ( enfant *temp = fils[i]; temp != NULL; temp =  temp-> suiv) parcour_prefixe(temp->val);
}

void parcour_postfixe( int i )
{
    for ( enfant *temp = fils[i]; temp != NULL; temp =  temp-> suiv) parcour_prefixe(temp->val);
    printf("%d ",i);
}

void parcour_infixe( int i )
{
    if ( fils[i]-> suiv != NULL ) parcour_infixe(fils[i]->suiv->val);
    printf("%d ", i);
    for( enfant *temp = fils[i]->suiv->suiv; temp != NULL; temp = temp->suiv) parcour_infixe(temp->val);

}

int main( void )
{
    saisie_dEnfant();
    parcour_prefixe(0);
    return 1;
}