//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "../include/main.h"
#include "../include/dtd.h"
#include "../include/xml.h"
#include "../include/menu.h"

// on récupère les variables globales des autres fichiers
fileAsArray f_dtd , f_xml ;

doctypeDef dtd; 

int main(int argc, char* argv[]){
    (void)argc ; (void)argv;

    initGlobals();


    char* fileDTD = "test/dtds/test1.dtd";
    char* fileXML = "test/XML/test.xml";

    //readDTD(fileDTD);
    
    //readXML(fileXML);

    //splitDtd();
    //splitDtdLine(f_dtd.array[10]);

    menu();

    freeFileAsArray(f_dtd);
    freeFileAsArray(f_xml);
    return 0;

}


void initGlobals(){
    f_dtd.length = FILE_AS_ARRAY_DEFAULT_LENGTH;
    f_xml.length = FILE_AS_ARRAY_DEFAULT_LENGTH;

    f_dtd.array = malloc(sizeof(char*) * f_dtd.length );
    f_xml.array = malloc(sizeof(char*) * f_xml.length );

    checkMalloc(f_dtd.array);
    checkMalloc(f_xml.array);

    for(int i = 0 ; i < FILE_AS_ARRAY_DEFAULT_LENGTH ; i+=1){
        f_dtd.array[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        f_xml.array[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        
        checkMalloc(f_dtd.array[i]);
        checkMalloc(f_xml.array[i]);

    }
  
}


void freeFileAsArray(fileAsArray fas){

    for (int i = 0; i < fas.length ; i+=1)
    {
        free(fas.array[i]);
    }  
    free(fas.array);
}

void printFileAsArray(fileAsArray fas){
    for (int i = 0; i < fas.length; i+=1)
    {
        printf("%s",  fas.array[i]);
    }
    printf("\n");
    
}

void checkMalloc(void* pointer){
    if(pointer == NULL){
        printf("manque d'espace");
        exit(1);
    }

}

void checkfOpen(void* pointer){
    if(pointer == NULL){
        printf("fichier Non ouvert");
        exit(1);
    }
    
}
