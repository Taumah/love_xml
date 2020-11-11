#include "../include/xml.h"
#include "../include/main.h"


void readXML(char* fileName){

    if(verifExtension(fileName) == false){
        return;
    }
    printf("yo?");

    FILE* XML = fopen(fileName , "rw");

    if( XML == NULL){
        printf("erreur à l'ouverture");
        exit(1);
    }
    fclose(XML);    

}


const char *getFilenameExt(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int verifExtension(char* fileXML){

    if(   strcmp("xml" , getFilenameExt(fileXML) )  != 0  ){
        printf("ceci n'est pas un fichier XML\n");
        return false;
    }else
    {
        printf("extension valide \n");
        return true;
    }
}

