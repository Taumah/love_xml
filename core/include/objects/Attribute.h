#include <stdlib.h>
#include <stdio.h>

typedef struct s_attribute{
    //pour plus d'infos... => https://www.w3schools.com/xml/xml_dtd_attributes.asp

    char* elementName;
    char* name;
    char* type;
    char* value;

}attribute;


void freeAttribute(attribute);