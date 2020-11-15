#include <stdlib.h>
#include <stdio.h>

typedef struct s_entity{
    char* name; // mot clé de l'entité
    char* shortcut; // resultat du mot clé 
}entity;

/*  ajoute un élement de type ENTITY
    à la strucutre DoctypeDef*/
void addEntity(char *line);


void freeEntity(entity);