#include <stdio.h>
#include <stdlib.h>

/* ecrire une fonction pour créer un BST parfaitement équilibré.

INPUT :
      0  1  2  3  4  5  6  7  8  9  10 11 12
t = | 7| 3| 1| 5| 2|10| 9| 8|12| 4|13|14|15|

OUTPUT :
    Un BST de hauteur (log_2(13)) avec 13 le nombre de noeuds

ALGO :
    Trier t avec quicksort de compléxité O(nlog(n)) en moyenne

t_ordonne = | 1| 2| 3| 4| 5| 7| 8| 9|10|12|13|14|15|

devide and conquere

m = (0+12)/2 = 6

*/


typedef struct Noeud {
    int info;
    struct Noeud *g, *d;
} Noeud;

typedef Noeud * lien;

lien creerNoeud(int info){
    lien temp = (lien)malloc(sizeof(Noeud));
    temp->info = info;
    temp->g = temp->d = NULL;
    return temp;
}

lien bstPE(int t[], int debut, int fin){
    //construire un bstPE de t[debut ... fin]
    //divide and conquere
    if(debut>fin){
        return NULL;
    }

    int milieu = (debut+fin)/2;
    lien racine = creerNoeud(t[milieu]);  


    racine->g = bstPE(t,debut,milieu-1);
    racine->d = bstPE(t,milieu+1,fin);
    return racine;
}

//qsort(t,taille_de_t,sizeof(int),compare#fonction de comparaison)

//écrivons la fonction de compare
int compare(int *a, int *b){
    return *a-*b;
}


void imprimer_arbre(lien r, int niveau){
    //Imprimer l'arbre avec indentation niveau
    if(r != NULL){
        imprimer_arbre(r->d, niveau+1);
        for(int i=0; i<niveau; ++i){
            printf("   ");
        }
        printf("%d\n",r->info);
        imprimer_arbre(r->g, niveau+1);
    }
}

int main(){
    int n; // le nombre d'élements du tab t
    printf("Entrer stp un entier pour");
    scanf("%d",&n);
    int t[n];

    //saisie du tab;
    for(int i=0; i<n; i++){
        printf("Enter stp l'entier numero %d",i+1);
        scanf("%d",&t[i]);
    }
    qsort(t,n,sizeof(int),compare);

    lien racine = bstPE(t,0,n-1);
    imprimer_arbre(racine,0);
    return 0;
}

