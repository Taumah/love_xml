#include "../include/dtd.h"
#include "../include/main.h"

extern fileAsArray f_dtd;

void readDTD(char* fileName){

    FILE* dtd_f = fopen(fileName , "rw");

    if( dtd_f == NULL){
        printf("erreur à l'ouverture");
        return;
    }
    
    int line_number = 0;    

    while (  fgets( f_dtd.array[line_number]  , FILE_AS_ARRAY_LINE_LENGTH , dtd_f) != NULL ){
        line_number+= 1; 

        if(line_number == f_dtd.length){
            printf("ouip");
            doubleDtdSize();
        }
    }

    //**************************************************
    //*
    //*        gérer le saut de line de fin
    //*
    //*
    //***************************************************

    fclose(dtd_f);
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



void splitDtdLine(char* line){

    char* left = strchr(line , '!')+1;
    char* right = NULL;

    if(left == NULL){
        exit(1);
    }

    right = strchr(left , ' ');
    // *right = '\0';
    printf("%d eheh , %d ahah , %d hihi \n", strncmp(left , "ELEMENT" , right - left), strncmp(left , "ATTLIST" , right - left) , strcmp(left , "ENTITY") ) ;

    while(  (right = strpbrk(left , " >") ) != NULL  ){
        
        *right = '\0';

        printf( "%s \n" , left);

        strcpy(left ,  right+1);
    
    }
}


