#include "../../include/objects/Element.h"

void freeElement(element elem){

    if(elem.content != NULL){
        free(elem.content);
    }

    if(elem.name != NULL){
        free(elem.name);
    }

}