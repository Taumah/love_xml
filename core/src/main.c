//Authors     Quentin Pierson  / Thomas Tresgots
//
//Date : 21/10/2020
//

#include "../include/main.h"

doctypeDef dtd; 
int main(/*int argc, char* argv[]*/){
    // (void)argc ; (void)argv;
    initDtd();

    char* fileDTD = "test/dtds/test1.dtd";
    // char* fileXML = "test/XML/test.xml";


    readDTD(fileDTD);
    
    freeDtd();
    // menu();

    //existingFile(fileXML);
    printf("\n");
    return 0;

}
