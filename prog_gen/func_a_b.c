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
    for(int i = 0; i < niveau; i++) printf("   ");
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
