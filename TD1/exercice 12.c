#include <stdio.h>
#include <stdilib.h> //pour qsort
/* 
Ecrire une fonction pour créer un BST parfaitement équilibré.
Illustrons l'algo par  un exemple.

INPUT: 0 1 2 3 4  5 6 7 8  9 10 11 12
       7 3 1 5 2 10 9 8 12 4 13 14 15

OUTPUT: Un bst de hauteur (log2(13))

ALGO: Trier t avec quicksort (complexité de 0(nlogn)en moyenne).
 0 1 2 3 4 5 6 7 8  9  10 11 12
 1 2 3 4 5 7 8 9 10 12 13 14 15
Divide and conquer.

*/    

typedef struct noeud
{
    int info;
    struct noeud *left;
    struct noeud *right;
}noeud;

typedef noeud *lien;

lien creernoeud(int info)
{
    lien temp = (lien)malloc(sizeof(noeud));
    temp->info = info;
    temp->left = temp->right = NULL;
    return temp;
}

lien bstpe( int t[], int debut, int fin)
/*
Construire unr bstpe
def  [debut,...,fin]
Divide and conquer
*/
{
    int millieu = (debut+fin)/2:
    lien racine = creernoeud(t[millieu]);
    
}