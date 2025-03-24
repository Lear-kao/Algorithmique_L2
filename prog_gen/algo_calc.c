#include "../headers/headrs_fils.h"
#include <stdlib.h>
#include <stdio.h>

arbre_bin *parse(int i,char *t)
/* 
Prend en  entrée un tableau de charactère et renvoie un arbre binaire d'opération.
! Bien composer son tableau de charactère
*/
{
    char c = t[i++];
    arbre_bin* p = creerNoeudArbreBinaire(c);
    if( c == '+' || c == '*')
    {
        p->left = parse( i, t);
        p->right = parse( i, t);
    }
    return p;
}

