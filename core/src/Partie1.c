//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "core/include/Partie1.h"

int main(int argc, char* argv[]){
    (void)argc ; (void)argv;



    char* fileDTD = "test/dtds/test1.dtd";
    char* fileXML = "test/XML/test.xml";

    

    char** linesDTD = readDTD(fileDTD);
    char** linesXML = readXML(fileXML);

    for (int i = 0; i < 40; i+=1)
    {
        printf("%s",  linesDTD[i]);
    }
    printf("\n");
    printf("\n");
    
    for (int i = 0; i < 40; i+=1)
    {
        printf("%s",  linesXML[i]);
    }

    printf("\n");

    

    freeDTD(linesDTD, 40);
    freeXML(linesXML , 40);

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

    fclose(dtd);

    return lines;
    
}


void freeDTD(char** lines , int nbr_of_lines){

    for (int i = 0; i < nbr_of_lines; i+=1)
    {
        free(lines[i]);
    }
    
    free(lines);

}

void freeXML(char** lines , int nbr_of_lines){

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

int verifExtension(char* fileXML){

    if(   strcmp("xml" , getFilenameExt(fileXML) )  != 0  ){
        printf("ceci n'est pas un fichier XML\n");
        return 1;
    }else
    {
        printf("extention valide \n");
        return 0;
    }
}


char** readXML(char* fileName){

    if(verifExtension(fileName) == 1){
        return NULL;
    }

    FILE* XML = fopen(fileName , "rw");

    if( XML == NULL){
        printf("erreur à l'ouverture");
        return NULL;
    }
    
    int nbr_of_lines = 40; // attention , à adapter au fichier lu 
    int line_number = 0;
    char** lines = malloc(sizeof(char*) * nbr_of_lines);

    for (int i = 0; i < nbr_of_lines; i+=1)
    {
        lines[i] = malloc(sizeof(char) * 200);
    }
      

    while (  fgets( lines[line_number]  , 200 , XML) != NULL ){
        line_number+= 1;    
    }

    printf("%s",  lines[2]);

    printf("\n");

    fclose(XML);
    return lines;
    

}

