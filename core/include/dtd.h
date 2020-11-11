#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct s_element{
    //pour plus d'infos... => https://www.w3schools.com/xml/xml_dtd_elements.asp

    char* name;  // nom de l'element


    /*  peut être soit un mot clé (EMPTY , ANY....) ou un type 
        de contenu sous forme de tableau : 
            -(balise1,balise2,balise3... baliseN) 
        chaque balise est suivi d'un caractère précisant son 
        nombre d'occurence (si aucun , considérer que c'est 1 occurence forcée)     
    */
    char* content; 

}element;

typedef struct s_attribute{
    //pour plus d'infos... => https://www.w3schools.com/xml/xml_dtd_attributes.asp

    char* elementName;
    char* name;
    char* type;
    char* value;

}attribute;

typedef struct s_entity{
    char* name; // mot clé de l'entité
    char* shortcut; // resultat du mot clé 
}entity;


typedef struct s_doctypeDef{
    element* elements;
    attribute* attributes;
    entity* entities;
}doctypeDef;

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

/*  double la taille du tableau de chaine de caractère
    de la structure fileAsArray pour permettre de 
    continuer la lecture du fichier */
void doubleDtdSize();


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



/*  ajoute un élement de type ENTITY
    à la strucutre DoctypeDef*/
void addEntity(char *line);
