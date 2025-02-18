#ifndef _test_h_
#define _test_h_

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



//fonction générale tab enfant
link enfiler(link *head, link *tail,int i);
int defiler(link *head, link *tail);
int file_vide(link f);
link creer_noeud(int info);
void saisie_dEnfant( int n,  link *fils );
void imprimmer__enfant( int n, link *fils);
int max(int *list, int n);

//fonction generale arbre binaire
arbre_bin *creerNoeud(int info);
void imprimer_arbre( arbre_bin *r, int niveau);
arbre_bin *insertion( arbre_bin *racine, int info);



//TD2
void bfs( int i, link *fils, int n );



//main
int main( void  );

#endif // _test_h_