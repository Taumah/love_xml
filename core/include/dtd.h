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


#define DTD_FIELDS_DEFAULT_LENGTH    40

typedef struct s_doctypeDef{
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

void initDtd(void);
void freeDtd(void);

typedef enum e_attributeType{
    CDATA,
    MULTIPLE,
    ID,
    IDREF,
    IDREFS,
    NMTOKEN,
    NMTOKENS,
    ENTITY,
    ENTITIES,
    NOTATION,
    XML,
}attributeType;

typedef enum e_attributeValue{
    DEFAULT,
    REQUIRED,
    IMPLIED,
    FIXED,
}attributeValue;

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

/*  ajoute un élement de type ELEMENT
    à la strucutre DoctypeDef*/
void addElement(char *line);


/*  ajoute un élement de type ATTLIST
    à la strucutre DoctypeDef*/
void addAttribute(char *line);

/*  similaire à addAttribute, seulement est
    utilisé lorsque l'element auquel est
    rataché l'attribut contient plusieurs
    attributs, et donc la déclaration se fait 
    sur plusieurs lignes dans le fichiers,
    tous possédant le même élement rataché*/
void addAttributeWithGivenElementName(char *line , char* defaultElementName);


/*  ajoute un élement de type ENTITY
    à la strucutre DoctypeDef*/
void addEntity(char *line);

/*  reçoit une balise de la dtd
    et en renvoie le premier mot
    (l'attribut 'name' de l'objet)
    */
char* getFirstWord(char *line);


/*  reçoit une balise de la dtd
    et renvoie la derniere partie
    de cette balise*/
char* getEndOfBlock(char *block, int decay);





#endif
