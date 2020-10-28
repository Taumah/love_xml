//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "../include/Partie1.h"

fileAsArray dtd , xml ;
element *found_elements;

int main(int argc, char* argv[]){
    (void)argc ; (void)argv;

    initGlobals();

    char* fileDTD = "test/dtds/test1.dtd";
    char* fileXML = "test/XML/test.xml";

    

    readDTD(fileDTD);
    readXML(fileXML);


    printf("%s\n" , dtd.array[2]);
    printf("\n");

    char* pos = strpbrk(dtd.array[2] , "!") ;

    // dtd.array[strlen(dtd.array[2])] = 

    while(  pos != NULL  ){
        
        *pos = '\0';

        printf( "%s \n" , dtd.array[2]);

        strcpy(dtd.array[2] ,  pos+1);

        pos = strpbrk(dtd.array[2] , " >");

    }

    // for (int i = 0; i < xml.length; i+=1)
    // {
    //     printf("%s",  xml.array[i]);
    // }
    // printf("\n");
    // printf("\n");
    
    // for (int i = 0; i < dtd.length; i+=1)
    // {
    //     printf("%s",  dtd.array[i]);
    // }

    printf("\n");

    

    freefileAsArray(dtd);
    freefileAsArray(xml);
    return 0;

}

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
        printf("extension valide \n");
        return 0;
    }
}


void readXML(char* fileName){

    if(verifExtension(fileName) == 1){
        return;
    }

    FILE* XML = fopen(fileName , "rw");

    if( XML == NULL){
        printf("erreur à l'ouverture");
        exit(1);
    }
    
    int line_number = 0;
      

    while (  fgets( xml.array[line_number]  , 200 , XML) != NULL ){
        line_number+= 1;    
    }

    xml.length = line_number;

    fclose(XML);    

}

void initGlobals(){
    dtd.length = 40;
    xml.length = 40;

    dtd.array = malloc(sizeof(char*) * dtd.length );
    xml.array = malloc(sizeof(char*) * xml.length );

    if(dtd.array == NULL || xml.array == NULL){
        printf("manque d'espace");
        exit(1);
    }

    for(int i = 0 ; i < 40 ; i+=1){
        dtd.array[i] = malloc(sizeof(char*) * 200);
        xml.array[i] = malloc(sizeof(char*) * 200);
        
        if(dtd.array[i] == NULL || xml.array[i] == NULL){
            printf("manque d'espace");
            exit(1);
        }

    }
  
}


void freefileAsArray(fileAsArray fas){

    for (int i = 0; i < fas.length ; i+=1)
    {
        free(fas.array[i]);
    }  
    free(fas.array);
}








