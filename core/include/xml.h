#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*  readXML reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne du fichier XML fourni*/
char *readXML(char* filename);


/*  renvoi un pointeur vers l'adresse du début de l'extension
    de la chaine de caractère passé en paramètres*/
const char *getFilenameExt(const char *filename);

/*  renvoie 0 si l'extension du fichier est correcte , 1 sinon*/
int verifExtension(char* fileXML);

/* récupere les balises */ 
char *recoverValue(char* fileName);

