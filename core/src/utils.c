#include "../include/utils.h"


void checkMalloc(void* pointer){
    if(pointer == NULL){
        printf("manque d'espace");
        exit(1);
    }

}

void checkfOpen(void* pointer){
    if(pointer == NULL){
        printf("fichier Non ouvert");
        exit(1);
    }
    
}
