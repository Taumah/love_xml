#include "../../include/objects/Entity.h"

void freeEntity(entity enty){

    if(enty.name != NULL){
        free(enty.name);    
    }

    if(enty.shortcut != NULL){
        free(enty.shortcut);
    }

}