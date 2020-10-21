#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*  readDTD reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne de la DTD fournie*/
char** readDTD(char* filename);

/*  sert à libérer la mémoire de notre tableau de 
    chaines de caractères pour le fichier DTD*/
void freeDTD(char** lines , int nbr_of_lines);



/*  readXML reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne du fichier XML fourni*/
char** readXML(char* filename);

/*  sert à libérer la mémoire de notre tableau de 
    chaines de caractères pour le fichier XML*/
void freeXML(char** lines , int nbr_of_lines);


/*  renvoi un pointeur vers l'adresse du début de l'extension
    de la chaine de caractère passé en paramètres*/
const char *getFilenameExt(const char *filename);

/*  renvoie 0 si l'extension du fichier est correcte , 1 sinon*/
int verifExtension(char* fileXML);