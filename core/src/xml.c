#include "../include/xml.h"
#include "../include/main.h"

extern fileAsArray f_xml;

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
    
    int line_number = 0;
      

    while (  fgets( f_xml.array[line_number]  , 200 , XML) != NULL ){
        line_number+= 1;  
    }

    f_xml.length = line_number;

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

