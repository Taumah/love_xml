#include <stdlib.h>
#include <stdio.h>

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


void freeElement(element);
