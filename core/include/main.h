#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DTD_FIELDS_DEFAULT_LENGTH    40

#define false 0
#define true 1

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



/*  prérempli les variables globales du programme */
void initGlobals(void);


/*  s'assure du succes de l'allocation dynamique, 
    stop le programme sinon*/
void checkMalloc(void* pointer);


/*  s'assure du succes de l'ouverture du fichier, 
    stop le programme sinon*/
void checkfOpen(void* pointer);
