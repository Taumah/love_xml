#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct element{
    char* name;  // nom de l'element
    char* category; // peut être vide ; 
    
    struct element *children; 

    char occurrences; // correspond au nombre de fois que l'element peut apparaitre dans son parent , peut-être l'un de ces caractères : '' , '+' , '*' , '?'  

}element;

typedef struct attribute{

    char* elementName;
    char* name;
    char* type;
    char* value;

}attribute;



/*  readDTD reçoit une string en parametre
    renvoi un tableau de chaines de caractères 
    correspondant à chaque ligne de la DTD fournie*/
void readDTD(char* filename);

/*  la chaîne de caractère envoyée est traitée puis 
    découpée en 3 parties pour renvoyer une structure 
    adéquate */
void splitDtdLine(char* line);
