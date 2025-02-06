#include <stdio.h>
#include <stdlib.h> //pour qsort
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

lien creerNoeud(int info)
{
    lien temp = (lien)malloc(sizeof(noeud));
    temp->info = info;
    temp->left = temp->right = NULL;
    return temp;
}

lien bstPE( int t[], int debut, int fin)
/*
Construire unr bstpe
def  [debut,...,fin]
Divide and conquer
*/
{
    if (debut > fin) return NULL;
    int millieu = (debut+fin)/2;
    lien racine = creerNoeud(t[millieu]);
    racine->left = bstPE(t,debut,millieu+1);
    racine->right = bstPE(t,millieu+1,fin);
    return racine;
}

//qsort(t, taille_t,sizeof(int),compare)
//ecrivons la fonction compare
int compare(int *a, int *b)
{
    return  *a - *b;
}


void printTree( lien r, int niveau)
{
    if( r!= NULL )
    {
    printTree( r->right, niveau+1);
    for(int i = 0; i < niveau; i++) printf("   ");
    printf("%d\n", r->info);
    printTree(r->left, niveau + 1);
    }
}

int main( void )
{
    int n; //le nombre d'entier du tableau
    printf("entrer stp un entier du tableau");
    scanf("%d", &n);
    int t[n];
    //saisie  tableau
    for(int i = 0; i < n; i++)
    {
        printf("entrer un entier stp");
        scanf("%d", &t[i]);
    }
    qsort(t,n,sizeof(int),compare);
    lien racine = bstPE(t,0,n-1);
    printTree(racine,0);
    return 0;
}
