#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"

arbre_bin *creerNoeudArbreBinaire(int info)
{
    arbre_bin *temp = malloc(sizeof(arbre_bin));
    temp->info = info;
    temp->left = temp->right = NULL;
    return temp;
}

void imprimer_arbre( arbre_bin *r, int niveau)
/* 
Affiche un bst
*/
{
    if( r!= NULL )
    {
        imprimer_arbre( r->right, niveau+1);
        for(int i = 0; i < niveau; i++)
            printf("   ");
        printf("%d\n", r->info);
        imprimer_arbre(r->left, niveau + 1);
    }
}

arbre_bin *insertion( arbre_bin *racine, int info)
/*
inserer une feuille dans un bst
*/
{
    if (racine == NULL)
        racine = creerNoeudArbreBinaire(info);
    else
    {
        if(info < racine-> info)
            racine->left = insertion( racine->left, info);
        else if (info > racine->info)
            racine -> right = insertion(racine->right, info);
    }
    return racine;
}


/* 
Exercice:
Ecrire une fonction non récursive permettant d'afficher
les noeuds d'un arbre binaire dans l'ordre préfixe, infixe, postfixe.
*/
//version récursive
void prefixe( arbre_bin *racine)
{
    if (racine != NULL)
    {
        printf("%d ",racine->info);
        prefixe(racine->left);
        prefixe(racine->right);
    }
}

/*
Algo:
push la racine
Entrer dans la boucle
tant que la  pile != vide
    pop(la  pile)
    et écrire la valeur retournée
    push(enfant droit)
    push( enfant  gauche )

Pile:
On va utiliser une pile pour afficher les  element un par un dès la première rencontre
*/

arbre_bin *pop(pile *p)
{
    if(p->top == 0) return NULL;
    return p->t[p->top--];
}
void push( pile *p, arbre_bin* ptr)
{
    if(p->top==N-1)
    {
        printf("pile pleine\n");
        return;
    }
    p->t[++p->top] = ptr;
}

void prefixeIte( arbre_bin *a)
{
    arbre_bin *courant;
    pile p;
    p.top = 0;
    courant = a;
    if (courant != NULL)
    {
        push(&p,courant);
    }
    while( p.top !=  0)
    {
        courant = pop(&p);
        printf("%d-",courant->info);
        if (courant->right != NULL)
        {
            push(&p,courant->right);
        }
        if (courant->left != NULL)
        {
            push(&p,courant->left);
        }
    }
}

void infixe( arbre_bin *racine)
{
    if (racine != NULL)
    {
        prefixe(racine->left);
        printf("%d ",racine->info);
        prefixe(racine->right);
    }
}

void  infixeIte(arbre_bin *a)
{
    arbre_bin *courant = a;
    pile p;
    p.top = 0;
    while (courant != NULL || p.top != 0 )
    {
        while( courant != NULL){
            push(&p,courant);
            courant = courant->left;
        }
        courant = pop(&p);
        printf("%d-",courant->info);
        courant = courant->right;
    }

}

void postfixeIte( arbre_bin *a)
{
    pile *p1 = malloc(sizeof(pile));
    pile *p2 = malloc(sizeof(pile));
    arbre_bin *courant = a;
    p1->top = 0;
    p2->top = 0;
    push(p1,courant);
    while( p1->top != 0 )
    {
        courant = pop(p1);
        push(p2,courant);
        if( courant->left != NULL) push(p1,courant->left);
        if( courant->right != NULL) push(p1,courant->right);
    }
    while(p2->top != 0)
    {
        arbre_bin *temp = pop(p2);
        printf("%d - ",temp->info);
    }
}

int testTheta(int* tab, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        if(tab[i] < tab[i*2] || tab[i] < tab[2*i+1]) return 0;
    }
    return 1;    
}
