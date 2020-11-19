#include "../include/main.h"


doctypeDef dtd; 
int main(int argc, char* argv[]){
    (void)argc ; (void)argv;
    initDtd();

    // char* fileDTD = "test/dtds/test1.dtd";
    char* fileXML = "test/XML/test.xml";


    // readDTD(fileDTD);
    

    // printDtd();
    
    
    // freeDtd();
    // menu();

    
    printf("%s",readXML(fileXML));

    //existingFile(fileXML);
    printf("\n");

    printf("%s",recoverValue(fileXML));
    
    printf("\n");

    return 0;

}
