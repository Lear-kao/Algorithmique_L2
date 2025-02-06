#include <stdio.h>
#include <stdlib.h>

/*
Exercice 8:
    Construire un BST en lisant les entiers un par un depuis le clavier; 
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

lien insertion(  lien racine, int info)
/*
inserer une feuille dans un bst
*/
{
    if (racine == NULL) racine = creerNoeud(info);
    else
    {
        if(info < racine-> info) racine->left = insertion( racine->left, info);
        else if (info > racine->info)) racine -> right = inserton(racine->right, info);
    }
    return racine;
}

int main( void )
{
    int x;
    scanf("%d",&x);
    for( int i = 0; i < x; i++)
    {
        scanf("%d")
    }
}