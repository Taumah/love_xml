#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*  représente un fichier avec chaque ligne du
    fichier comme une chaîne de caractères , 
    tous manipulables de la même manière */
typedef struct fileAsArray{
    char** array;
    int length;
}fileAsArray;

/*  sert à libérer la mémoire de notre tableau de 
    chaines de caractères pour les fichiers*/
void freeFileAsArray(fileAsArray fas);



/* prérempli les variables globales du programme */
void initGlobals(void);