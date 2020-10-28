#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct s_fileAsArray{
    char** array;
    int length;
}fileAsArray;



typedef struct s_element{
    char* name;  // nom de l'element

    char* category; // peut être vide ; 
    struct element *children; // elements enfants autorisés

    //à noter: il n'est pas possible que category et children soient rempli, l'un des deux est forcément  NULL

    char occurrences; // correspond au nombre de fois que l'element peut apparaitre dans son parent , peut-être l'un de ces caractères : '' , '+' , '*' , '?'  

}element;

typedef struct s_attribute{

    char* element_name; // nom de l'element dans lequel l'attribut est autorisé 
    char* name;  // nom de l'attribut
    char* type;  // type de l'attribut 
    char* value;  // value de l'attribut

}attribute;

typedef struct s_entity{

    char* name; // nom de l'entité
    char* shortcut; // raccourci à écrire pour obtenir son contenu
    char* result; // contenu du raccourci
}entity;


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


void getNextElement();
void getChildElement();

void getNumberElements();
void getNumberElements(int test);