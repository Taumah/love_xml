#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILE_AS_ARRAY_DEFAULT_LENGTH    40
#define FILE_AS_ARRAY_LINE_LENGTH       200

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