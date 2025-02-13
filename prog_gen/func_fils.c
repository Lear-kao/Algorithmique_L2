#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"


File* enfiler(File *f,int i)
{
    File *tmp;
    if(f==NULL)
    {
        f=(File*)malloc(sizeof(File));
        f->info=i;
        f->next=NULL;
    }
    else{
        tmp=f;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=(File*)malloc(sizeof(File));
        tmp->next->info=i;
    }
    return f;
}

noeud* defiler(File *f ,int *r)
{ // *r est un pointeur vers une variable pour stocker la valeur defiler
    *r=f->info;
    File *tmp=f;
    tmp=tmp->next;
    free(f);
    return tmp;
}

int file_vide(noeud *f)
{
    if(f==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}


/*creer noeud avec l'info donné*/
enfant* creer_noeud(int info)
{
enfant *temp = (enfant*)malloc(sizeof(enfant));
temp -> val = info;
temp -> suiv = NULL;
return temp;
}

void saisie_dEnfant( void )
{
    enfant  *temp;
    int ne;

    /*initialisation de tab*/
    for  (int i = 0; i < n; i++)fils[i] = NULL;

    //saisie des enfants de chaque noeuds
    for(int i = 0;i < n; i++)
    {
        printf("nombre d'enfant stp\n");
        scanf("%d", &ne);
        for( int j = 0; j < ne; j++)
        {
            printf("entrer val");
            int e;
            scanf("%d",&e);
            //on stocke e
            temp = creer_noeud(e);
            //attacher les  enfants à temp et temp à la tête
            temp->suiv = fils[i];
            fils[i] = temp;
        
        }
    }
}

void imprimmer__enfant( void )
{
    enfant *temp;
    for( int i = 0; i < n; i++)
    {
        temp = fils[i];
        if ( fils[i] = NULL ) return;
        else 
        {
            for( ; temp !=  NULL; temp = temp->suiv ) printf("%d,", temp->val );
            printf("\n");
        } 
    }
}