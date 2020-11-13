#include "../../include/objects/Entity.h"
#include <unistd.h>

void freeEntity(entity enty){
    printf("passes");
    for (size_t i = 0; i < 10; i++)
    {
        printf("passes");

        sleep(1);
    }

    if(enty.name != NULL){
        free(enty.name);    
    }

    if(enty.shortcut != NULL){
        free(enty.shortcut);
    }

   

}