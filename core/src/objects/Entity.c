#include "../../include/objects/Entity.h"
#include <unistd.h>

void freeEntity(entity enty){

    if(enty.name != NULL){
        free(enty.name);    
    }

    if(enty.shortcut != NULL){
        free(enty.shortcut);
    }

}