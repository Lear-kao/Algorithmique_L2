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
        for(int i = 0; i < niveau; i++)
            printf("   ");
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


/* 
Exercice:
Ecrire une fonction non récursive permettant d'afficher
les noeuds d'un arbre binaire dans l'ordre préfixe, infixe, postfixe.
*/
//version récursive
void prefixe( arbre_bin *racine)
{
    if (racine != NULL)
    {
        printf("%d ",racine->info);
        prefixe(racine->left);
        prefixe(racine->right);
    }
}

/*
Algo:
push la racine
Entrer dans la boucle
tant que la  pile != vide
    pop(la  pile)
    et écrire la valeur retournée
    push(enfant droit)
    push( enfant  gauche )

Pile:
On va utiliser une pile pour afficher les  element un par un dès la première rencontre
*/

arbre_bin *pop(pile *p)
{
    if(p->top == 0) return NULL;
    return p->t[p->top--];
}
void push( pile *p, arbre_bin* ptr)
{
    if(p->top==N-1)
    {
        printf("pile pleine\n");
        return;
    }
    p->t[++p->top] = ptr;
}

void prefixeIte( arbre_bin *a)
{
    arbre_bin *courant;
    pile p;
    p.top = 0;
    courant = a;
    if (courant != NULL)
    {
        push(&p,courant);
    }
    while( p.top !=  0)
    {
        courant = pop(&p);
        printf("%d-",courant->info);
        if (courant->right != NULL)
        {
            push(&p,courant->right);
        }
        if (courant->left != NULL)
        {
            push(&p,courant->left);
        }
    }
}

void infixe( arbre_bin *racine)
{
    if (racine != NULL)
    {
        prefixe(racine->left);
        printf("%d ",racine->info);
        prefixe(racine->right);
    }
}

void  infixeIte(arbre_bin *a)
{
    arbre_bin *courant = a;
    pile p;
    p.top = 0;
    while (courant != NULL || p.top != 0 )
    {
        while( courant != NULL){
            push(&p,courant);
            courant = courant->left;
        }
        courant = pop(&p);
        printf("%d-",courant->info);
        courant = courant->right;
    }

}

void postfixeIte( arbre_bin *a)
{
    pile *p1 = malloc(sizeof(pile));
    pile *p2 = malloc(sizeof(pile));
    arbre_bin *courant = a;
    p1->top = 0;
    p2->top = 0;
    push(p1,courant);
    while( p1->top != 0 )
    {
        courant = pop(p1);
        push(p2,courant);
        if( courant->left != NULL) push(p1,courant->left);
        if( courant->right != NULL) push(p1,courant->right);
    }
    while(p2->top != 0)
    {
        arbre_bin *temp = pop(p2);
        printf("%d - ",temp->info);
    }
}

int testEstTas(int* tab, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        if(tab[i] < tab[i*2] || tab[i] < tab[2*i+1]) return 0;
    }
    return 1;    
}


void monter_tas(int *t,int n, int i,int valeur)
/* 
t[i...n-1]un tas
on augmente  t[i] = t[i]+val
restructurer le tas
le papa de l'indice i-i/2
*/
{
    t[i] = t[i] + valeur;
    while( i>0 && !testEstTas(t,n) )
    {
        int temp = t[i];
        t[i] = t[i-i/2];
        t[i-i/2] = temp;
        i = i-i/2;
    }
}

void descendre_tas(int *t,int n, int i)
/* 
Input: un tableau d'entier
Output: un tableau trié
FCT TRIS PAR TAS
*/
{
    int x = t[i];
    int j = i*2;
    while (j < n)
    {
        if(j+1 < n)
        {
            if( t[j+1] > t[j] ) j = j+1;
        }
        if ( x >= t[j] ) break;
        t[i] = t[j];
        i = j;
        j = 2*i;
    }
    t[i] = x;
    
}

void tri_par_tas(int *t, int n)
{
    int temp, k = n-1;
    for(int i =  n-1;i >= 1; i--)
    {
        temp = t[i];
        t[i] = t[1];
        t[1] = temp;
        descendre_tas(t,k,1);
        k = k-1;
    }
}

/* 
Algo: BFS pour un arbre binaire 
*/

Queue *creer()
{
    Queue *t = (Queue*)malloc(sizeof(Qnode));
    t->front = t->rear = NULL;
}

int isempty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, arbre_bin *tptr)
{
    Qnode *t =  (Qnode*)malloc(sizeof(Qnode));
    t->ptr = tptr;
    t->next = NULL;
    if(isempty(q))
    {
        q->front = q->rear  = t;
        return;
    }
    q->rear->next = t;
    q->rear = t;
}

arbre_bin* dequeue(Queue *q)
{
    if(isempty(q))
    {
        exit(10);
    }
    Qnode *t = q->front;
    arbre_bin *p = t->ptr;
    q->front = q->front->next;
    if( isempty(q) )
    {
        q->rear = NULL;
    }
    free(t);
    return p;
}


void bfs_arb_bin( arbre_bin *a)
{
    arbre_bin *courant;
    Queue *p = creer();
    enqueue(p,a);
    while( !isempty(p))
    {
        courant = dequeue(p);
        printf("%d-",courant->info);
        if (courant->left != NULL)
        {
            enqueue(p,courant->left);
        }
        if (courant->right != NULL)
        {
            enqueue(p,courant->right);
        }
    }
}