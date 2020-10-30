//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "../include/main.h"
#include "../include/dtd.h"
#include "../include/xml.h"

// on récupère les variables globales des autres fichiers
fileAsArray dtd , xml ;

int main(int argc, char* argv[]){
    (void)argc ; (void)argv;

    initGlobals();

    char* fileDTD = "test/dtds/test1.dtd";
    char* fileXML = "test/XML/test.xml";

    readDTD(fileDTD);
    
    readXML(fileXML);


    // printf("%s\n" , dtd.array[2]);
    // printf("\n");

   splitDtdLine(dtd.array[3]);

    printf("\n");

    

    freeFileAsArray(dtd);
    freeFileAsArray(xml);
    return 0;

}


void initGlobals(){
    dtd.length = FILE_AS_ARRAY_DEFAULT_LENGTH;
    xml.length = FILE_AS_ARRAY_DEFAULT_LENGTH;

    dtd.array = malloc(sizeof(char*) * dtd.length );
    xml.array = malloc(sizeof(char*) * xml.length );

    if(dtd.array == NULL || xml.array == NULL){
        printf("manque d'espace");
        exit(1);
    }

    for(int i = 0 ; i < FILE_AS_ARRAY_DEFAULT_LENGTH ; i+=1){
        dtd.array[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        xml.array[i] = malloc(sizeof(char*) * FILE_AS_ARRAY_LINE_LENGTH);
        
        if(dtd.array[i] == NULL || xml.array[i] == NULL){
            printf("manque d'espace");
            exit(1);
        }

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
    printf("\n");
    
}