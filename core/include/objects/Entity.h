#include <stdlib.h>
#include <stdio.h>

typedef struct s_entity{
    char* name; // mot clé de l'entité
    char* shortcut; // resultat du mot clé 
}entity;

void freeEntity(entity);