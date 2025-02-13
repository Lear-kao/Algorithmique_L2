#ifndef _test_h_
#define _test_h_

//structure
typedef struct noeud
{
    struct noeud *suiv;
    int val;
}enfant;

typedef noeud* link;

//fonction générale
noeud* enfiler(File *f,int i);
noeud* defiler(File *f ,int *r);
int file_vide(noeud *f);
enfant* creer_noeud(int info);
void saisie_dEnfant( void );
void imprimmer__enfant( void );


//TD2
void bfs( int i );



//main
int main( void  );

#endif // _test_h_