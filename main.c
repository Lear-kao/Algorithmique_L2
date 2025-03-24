#include "headers/headrs_fils.h"
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
    char * t = malloc(sizeof(char)*10);
    t = "++a*bc+bd";
    int i = 0;
    arbre_bin *p = parse(i,t);
}