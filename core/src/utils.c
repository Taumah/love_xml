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

char** splitStr(char* str , char delim , int *splitSize){

    char** array = NULL;

    int counter = 1 ;
    int i = 0;
    char* token=NULL;
    while( *(str+i) != '\0')
    {
        if(str[i] == delim){
            counter+=1;
        }
        i +=1;
    }
    if(counter == 1){
        return 0;
    }
    array = malloc(sizeof(char*) * counter);
    checkMalloc(array);

    token = strtok(str, &delim);
    i =0;
    while (token != NULL){

        array[i] = malloc(sizeof(char) * strlen(token));
        strcpy(array[i] , token);
        token = strtok(NULL, &delim);
        i +=1;
    }
    *(splitSize) = counter;
    return array ;
    

}