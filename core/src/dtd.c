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
    // TODO find DEBUT AND END OF LINE
    // then copy it to f_dtd.array[line_number]


    while (  fgets( f_dtd.array[line_number]  , FILE_AS_ARRAY_LINE_LENGTH , dtd_f) != NULL ){
        line_number+= 1; 

        if(line_number == f_dtd.length){
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


