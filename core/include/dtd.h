#ifndef DTD_H
#define DTD_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "../include/main.h"
#include "../include/utils.h"

#include "../include/objects/Element.h"
#include "../include/objects/Attribute.h"
#include "../include/objects/Entity.h"


#define DTD_FIELDS_DEFAULT_LENGTH    10

typedef struct s_doctypeDef{
    char* rootElement;

    element* elements;
    short cursorElements;
    short sizeElements;

    attribute* attributes;
    short cursorAttributes;
    short sizeAttributes;
    
    entity* entities;
    short cursorEntities;
    short sizeEntities;

}doctypeDef;

typedef enum e_doctypeDefFields{
    FIELD_ELEMENTS,
    FIELD_ATTRIBUTES,
    FIELD_ENTITIES,
}doctypeDefField; 


void initDtd(void);
void freeDtd(void);

/*  getFileSize renvoie sous la forme d'un long int
    la taille nette du fichier.*/
off_t getFileSize(char* fileName);


/*  readDTD reçoit une chaîne de caractères en
    parametre et rempli la structure DoctypeDef*/
void readDTD(char* filename);



/*  la chaîne de caractère envoyée est traitée puis 
    découpée en 3 parties pour renvoyer une structure 
    adéquate */
void splitDtdLine(char* line);


/*  reçoit le contenu du fichier sous 
    la forme d'un tableau, puis rempli
    les différents champs de la structure 
    doctypeDef. Renvoie 1 si une erreur
    s'est produite, 0 sinon*/
int fillDoctypeDef(char *buffer);


/*  reçoit une balise de la dtd
    et en renvoie le premier mot
    (l'attribut 'name' de l'objet)
    */
char* getFirstWord(char *line);


/*  reçoit une balise de la dtd
    et renvoie la derniere partie
    de cette balise*/
char* getEndOfBlock(char *block, int decay);


/*  double la taille du champ (de la dtd) 
    selectionné via le parametre field*/
void doubleDtdField(doctypeDefField field);


/*  renvoie la valeur par défaut d'un
    ATTLIST , ou sa caractéristique le
    cas échant*/
char* getDefaultVal(char*);


/*  */
char *getTheNWord(char* block , int N);


#endif
