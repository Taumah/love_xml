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



/*  readDTD reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne de la DTD fournie*/
void readDTD(char* filename);

/*  parcours la structure fileAsArray dtd , 
    et appelle splitDtdLine*/
void splitDtd(void);


/*  la chaîne de caractère envoyée est traitée puis 
    découpée en 3 parties pour renvoyer une structure 
    adéquate */
void splitDtdLine(char* line);

/*  double la taille du tableau de chaine de caractère
    de la structure fileAsArray pour permettre de 
    continuer la lecture du fichier */
void doubleDtdSize();