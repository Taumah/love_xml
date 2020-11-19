#include "../../include/objects/Element.h"

void freeElement(element elem){

    if(elem.content != NULL){
        free(elem.content);
    }

    if(elem.name != NULL){
        free(elem.name);
    }

}


void printElem(element elem){
    printf("|%s|%s|\n" , elem.name , elem.content);
}