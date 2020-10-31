#include "../include/dtd.h"
#include "../include/main.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

extern fileAsArray f_dtd;

off_t getFileSize(char* fileName){
    struct stat stats ; 
    
    if( stat(fileName, &stats) == false ){
        printf("Erreur lecture info fichiers");
        exit(EXIT_FAILURE);
    } 
    
    printf("File size:                %lld bytes\n",
            (long long) stats.st_size);

    return stats.st_size;
}

void readDTD(char* fileName){

    unsigned long long fileSize = getFileSize(fileName);

    char* buffer = malloc(sizeof(char) * fileSize);
    checkMalloc(buffer);

    FILE* f = fopen(fileName , "r");

    fread(buffer , fileSize , sizeof(char) , f);

    // printf("%s" , buffer);

    free(buffer);

    fclose(f);



}

void doubleDtdSize(){
    int originalSize = f_dtd.length;
    int endSize = f_dtd.length*2;

    char** newArray = malloc(sizeof(char*)* endSize);
    checkMalloc(newArray);

    int i =0;
    for (; i < originalSize; i+=1){

        newArray[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        checkMalloc(newArray[i]);

        strcpy(newArray[i] , f_dtd.array[i]);        
    }

    for (; i < endSize; i+=1){

        newArray[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        checkMalloc(newArray[i]);
    }

    f_dtd.array = newArray;
    f_dtd.length = endSize;

}



void splitDtd(){
    for(int i = 0 ; i < f_dtd.length ; i+=1){
        printf("%s" , f_dtd.array[i]);
        // splitDtdLine(f_dtd.array[i]);
    }
}

void splitDtdLine(char* line){
    
    char* left = strchr(line , '!');
    char* right = NULL;

    if(left == NULL){ // means no "!" found.
        printf("ligne vide\n");
        return;
    }

    left +=1;

    right = strchr(left , ' ');
    
    
    *right = '\0';
    // if(right < left ){
    //     return;
    // }
    // printf("%d eheh \n", strncmp(left , "ELEMENT" , right - left) );

    while(  (right = strpbrk(left , " >") ) != NULL  ){
        
        *right = '\0';

        printf( "%s \n" , left);

        strcpy(left ,  right+1);
    
    }
}


