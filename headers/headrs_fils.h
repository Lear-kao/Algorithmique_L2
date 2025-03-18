#ifndef _test_h_
#define _test_h_


//const
#define N 25

//structure
typedef struct noeud
{
    struct noeud *next;
    int info;
}enfant;

typedef enfant *link;


typedef struct ar_b
{
    struct ar_b *left, *right;
    int info;
} arbre_bin;

typedef struct pile
{
    int top;
    arbre_bin *t[N];

}pile;

typedef struct QueueNode
{
    arbre_bin *ptr;
    struct QueueNode *next;
} Qnode;

typedef struct Queue
{
    Qnode *front, *rear;
}Queue;

//fonction générale tab enfant
link enfiler(link *head, link *tail,int i);
int defiler(link *head, link *tail);
int file_vide(link f);
link creerNoeudArbreQuelquonque(int info);
void saisie_dEnfant( int n,  link *fils );
void imprimmer__enfant( int n, link *fils);
int max(int *list, int n);

//fonction generale arbre binaire
arbre_bin *creerNoeudArbreBinaire(int info);
void imprimer_arbre( arbre_bin *r, int niveau);
arbre_bin *insertion( arbre_bin *racine, int info);

//TD2
void bfs( int i, link *fils, int n );
arbre_bin *search_it(arbre_bin *root, int data);
arbre_bin *search(arbre_bin *root, int data);
void prefixeIte( arbre_bin *a);
void  infixeIte(arbre_bin *a);
void postfixeIte( arbre_bin *a);
int testTheta(int* tab, int n);
void descendre_tas(int *t,int n, int i);
void tri_par_tas(int *t, int n);
void bfs_arb_bin( arbre_bin *a);

//main
int main( void  );

#endif // _test_h_