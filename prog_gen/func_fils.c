#include <stdio.h>
#include <stdlib.h>
#include "../headers/headrs_fils.h"


link enfiler(link *head, link *tail,int i)
{
    link tmp = (link)malloc(sizeof(noeud));
    t->info = i;
    t->next = NULL;
    if(f==NULL)
    {
        if (head == NULL)
        {
            *head = t;
            *tail = t;
        }
    }
    else
    {
        tail->next = t;
        tail = t;
    }
    return f;
}

int defiler(link noeud ,link r)
/* 
*r est un pointeur vers une variable pour stocker le pointeur
*/
{ 
    if (head !=  NULL)
    {
        int 
    }
    int temp = noeud->info;
    r = noeud->next;
    free(noeud);
    return temp;
}

int file_vide(link f)
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
link creer_noeud(int info)
{
    enfant *temp = (enfant*)malloc(sizeof(enfant));
    temp -> info = info;
    temp -> next = NULL;
    return temp;
}

void saisie_dEnfant( int n,  link *fils )
{
    link temp;
    int ne;

    /*initialisation de tab*/
    for  (int i = 0; i < n; i++) fils[i] = NULL;

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
            temp->next = fils[i];
            fils[i] = temp;
        
        }
    }
}

void imprimmer__enfant( int n,  link *fils )
{
    link temp;
    for( int i = 0; i < n; i++)
    {
        temp = fils[i];
        if ( fils[i] == NULL ) return;
        else 
        {
            for( ; temp !=  NULL; temp = temp->next ) printf("%d,", temp->info );
            printf("\n");
        } 
    }
}

int max( int *list, int n)
{
    int max = list[0];
    for( int i = 1; i < n; i++)
    {
        if (max < list[i])
        {
            max = list[i];
        }
    }
    return max;
}


