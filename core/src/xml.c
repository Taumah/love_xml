#include "../include/xml.h"
#include "../include/main.h"

extern fileAsArray xml;

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

