#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** readDTD(char* filename);
void freeDTD(char** lines , int nbr_of_lines);

const char *getFilenameExt(const char *filename);
int verifExtention(char* fileXML);



int main(int argc, char* argv[]){
    (void)argc ; (void)argv;



    char* fileName = "test/dtds/test1.dtd";

    

    char** lines = readDTD(fileName);

    for (int i = 0; i < 40; i+=1)
    {
        printf("%s",  lines[i]);
    }
    

    freeDTD(lines, 40);

    return 0;

}



char** readDTD(char* fileName){

    FILE* dtd = fopen(fileName , "rw");

    if( dtd == NULL){
        printf("erreur à l'ouverture");
        return NULL;
    }
    

    int nbr_of_lines = 40;
    int line_number = 0;
    char** lines = malloc(sizeof(char*) * nbr_of_lines);

    


    for (int i = 0; i < nbr_of_lines; i+=1)
    {
        lines[i] = malloc(sizeof(char) * 200);
    }
    

    

    while (  fgets( lines[line_number]  , 200 , dtd) != NULL ){
        line_number+= 1;    
    }


    //**************************************************
    //*
    //*        gérer le saut de line de fin
    //*
    //*
    //***************************************************

    printf("%s",  lines[2]);



    printf("\n");
    return lines;
    
}


void freeDTD(char** lines , int nbr_of_lines){

    for (int i = 0; i < nbr_of_lines; i+=1)
    {
        free(lines[i]);
    }
    
    free(lines);

}


const char *getFilenameExt(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}


int verifExtention(char* fileXML){

    if(   strcmp("xml" , getFilenameExt(fileXML) )  != 0  ){
        printf("ceci n'est pas un fichier XML\n");
        return 1;
    }else
    {
        printf("extention valide \n");
        return 0;
    }
}