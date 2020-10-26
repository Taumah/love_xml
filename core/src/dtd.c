#include "../include/dtd.h"
#include "../include/main.h"

extern fileAsArray dtd;

void readDTD(char* fileName){

    FILE* dtd_f = fopen(fileName , "rw");

    if( dtd_f == NULL){
        printf("erreur à l'ouverture");
        return;
    }
    
    int line_number = 0;    

    while (  fgets( dtd.array[line_number]  , 200 , dtd_f) != NULL ){
        line_number+= 1;    
    }


    //**************************************************
    //*
    //*        gérer le saut de line de fin
    //*
    //*
    //***************************************************

    fclose(dtd_f);
}


void splitDtdLine(char* line){

    char* left = strchr(line , '!')+1;
    char* right = NULL;

    if(left == NULL){
        exit(1);
    }

    while(  (right = strpbrk(left , " >") ) != NULL  ){
        
        *right = '\0';

        printf( "%s \n" , left);

        strcpy(left ,  right+1);
    
    }
}