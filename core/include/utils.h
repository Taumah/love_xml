#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*  s'assure du succes de l'allocation dynamique, 
    stop le programme sinon*/
void checkMalloc(void* pointer);


/*  s'assure du succes de l'ouverture du fichier, 
    stop le programme sinon*/
void checkfOpen(void* pointer);

/*  decoupe une chaîne de caractère en fonction
    de delimiter. affecte nombre de tokens générés
    à splitSize et renvoie un tableau de string*/
char** splitStr(char* str , char delim , int *splitSize);


/*  libère la mémoire d'un tableau de chaînes de
    caractères*/
void doubleFree(char** array , int size);