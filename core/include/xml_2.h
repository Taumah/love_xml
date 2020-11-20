#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <regex.h>
#include <glib.h>

#include "dtd.h"
#include "main.h"

/*  readXML reçoit une string en parametre
    et rempli un buffer de la taille du 
    fichier XML fourni. Renvoie 0 en cas de
    succès de lecture, une erreur sinons*/
int readXML(char* fileName , char** buffer);


/*  renvoi un pointeur vers l'adresse du 
    début de l'extension de la chaine de 
    caractère passé en paramètres*/
const char *getFilenameExt(const char *filename);

/*  renvoie 0 si l'extension du fichier est
    correcte , 1 sinon*/
int isExtensionValid(char* fileName , char* extension);


/*  appelle toutes les fonctions de 
    validation des balises, renvoie
    1 en cas d'échec, 0 sinon*/ 
int checkXML(char* buffer);


/* compare la 1ere balise du fichier
    avec l'élement rootElement de la 
    structure dtd*/
int isRootElementValid(char* buffer);

/*  augmente la valeur de la globale 
    gap, seulement en cas de succès.
    renvoie une erreur sinon*/
int getFirstBlock(char *buffer);


int getClosingTag(char* marker , char* buffer , char* highest  );
