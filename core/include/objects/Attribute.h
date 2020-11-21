#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_attribute{
    //pour plus d'infos... => https://www.w3schools.com/xml/xml_dtd_attributes.asp

    char* elementName;
    char* name;
    char* type;
    char* defaultVal;

}attribute;


typedef enum e_attributeTypes{
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

typedef enum e_attributeValues{
    DEFAULT,
    REQUIRED,
    IMPLIED,
    FIXED,
}attributeValue;

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


void freeAttribute(attribute);


/*  affiche les différents champs de 
    l'attribut envoyé sur une ligne*/
void printAttr(attribute attr);


/*  renvoie la partie "FIXED value"
    d'un attribute "FIXED"*/
char* getDefaultValueWhenFixed(char* str);



#endif