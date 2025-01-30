#include <stdio.h>
#include <stdlib.h>

typedef struct  noeud
{
    int info;
    struct noeud *gauche;
    struct noeud *droit;    
} noeud;

typedef noeud *link;

link arbre_pe(int n)
{
    int ng,nd;
    link  temp;
    if( n==0 ) return NULL;
    ng = n/2;
    nd =  n - ng - 1;
    int x;
    printf("Entrer stp un entier");
    scanf("%d",&x);
    temp = (link)malloc(sizeof(noeud));
    temp->info = x;
    temp->gauche = arbre_pe(ng);
    temp->droit = arbre_pe(nd);
    return temp;
}

void imprimer_arbre( link r, int niveau)
{
    if( r!= NULL )
    {
    imprimer_arbre( r->droit, niveau+1);
    for(int i = 0; i < niveau; i++) printf("   ");
    printf("%d\n", r->info);
    imprimer_arbre(r->gauche, niveau + 1);
    }
}

int main(  void )
{
    int n;
    link racine;
    printf("lect n");
    scanf("%d",&n);
    racine = arbre_pe(n);
    imprimer_arbre(racine,n);
    return 0;
}
