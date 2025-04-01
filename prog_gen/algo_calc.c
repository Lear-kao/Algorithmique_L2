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

/* 
Def:  Invariance de la boucle;
    Assertion, propriétée ou relation entre des variables d'un programme 
    toujours vraie à un point précis dans  une boucle (souvent à l'entrée de la boucle) 
    quel que soit le nombre d'éxecution effectué par la boucle.

Cette notion est utilisée pour la preuve  d'un algo ou d'un programmme.
*/

/* 
Ex_Trouver l'invariant de la boucle :
    pgcd: Algo Euclide
pgcd(m,n):  n si m%n == 0;
            pgcd(n,m%n) si m%n != 0;
*/

int pgcd(int m,int n)
{
    if (m%n == 0) return  n;
    return pgcd(n,m%n);
}

int pgcd_ite(int m,int n)
{
    if (m%n == 0) return  n;
    return pgcd(n,m%n);
}

int pgcd_ite(int m,int n)
/* invariant de la boucle : pgcd(m,n) = pgcd(n,r) */
{
    int r = m%n;
    while( r!= 0)
    {
        m = n;
        n = r;
        r = m%n;
    }
    return r;
}

/* 
Bonus: 
    Etendre le programme  d'évaluation d'une expression préfixe pour les opérateurs
    +,-,*,/,%, ^(exponentiel) et des variables (ex: abc)
EX: (4*2)+5/3
    + * 4 2 / 5 3

*/