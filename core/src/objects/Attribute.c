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

    if(attr.value != NULL){
        free(attr.value);
    }
}