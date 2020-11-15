#include "../../include/objects/Entity.h"

void freeEntity(entity enty){

    if(enty.name != NULL){
        free(enty.name);    
    }

    if(enty.shortcut != NULL){
        free(enty.shortcut);
    }

}

void printEnti(entity enti){
    printf("|%s|%s|\n" , enti.name , enti.shortcut);
}