//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "../include/main.h"
#include "../include/dtd.h"
#include "../include/xml.h"
#include "../include/menu.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


doctypeDef dtd; 

int main(int argc, char* argv[]){
    (void)argc ; (void)argv;

    // initGlobals();
    initDtd();

    char* fileDTD = "test/dtds/test2.dtd";
    // char* fileXML = "test/XML/test.xml";

    readDTD(fileDTD);
    
    // readXML(fileXML);

    freeDtd();
    return 0;

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
