#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct fileAsArray{
    char** array;
    int length;
}fileAsArray;



typedef struct element{
    char* name;  // nom de l'element
    char* category; // peut être vide ; 
    
    struct element *children; 

    char occurrences; // correspond au nombre de fois que l'element peut apparaitre dans son parent , peut-être l'un de ces caractères : '' , '+' , '*' , '?'  

}element;

typedef struct attribute{

    char* element_name;
    char* name;
    char* type;
    char* value;

}attribute;


/*  readDTD reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne de la DTD fournie*/
void readDTD(char* filename);



/*  readXML reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne du fichier XML fourni*/
void readXML(char* filename);

/*  sert à libérer la mémoire de notre tableau de 
    chaines de caractères pour les fichiers*/
void freefileAsArray(fileAsArray fas);


/*  renvoi un pointeur vers l'adresse du début de l'extension
    de la chaine de caractère passé en paramètres*/
const char *getFilenameExt(const char *filename);

/*  renvoie 0 si l'extension du fichier est correcte , 1 sinon*/
int verifExtension(char* fileXML);


/* prérempli les variables globales du programme */
void initGlobals(void);