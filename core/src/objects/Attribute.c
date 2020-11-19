#include "../../include/objects/Attribute.h"

void freeAttribute(attribute attr){

    if(attr.elementName != NULL){
        free(attr.elementName);
    }

    if(attr.name != NULL){
        free(attr.name);
    }

    if(attr.type != NULL){
        free(attr.type);
    }

    if(attr.defaultVal != NULL){
        free(attr.defaultVal);
    }
}

void printAttr(attribute attr){
    printf("|%s|%s|%s|%s|\n" , attr.elementName , attr.name , attr.type , attr.defaultVal);
}