#include "../include/main.h"

//<to>[[:ascii:]]*<\/to>[\n\ \r]*<from>[[:ascii:]]*<\/from>
// regex example to check following elements

doctypeDef dtd; 

extern size_t gap;

int main(int argc, char* argv[]){
    
    (void)argc ; (void)argv;
    // initDtd();

    // char* fileDTD = "test/dtds/test.dtd";
    // char* fileXML = "test/XML/test.xml";


    // readDTD(fileDTD);
    

    // // printDtd();
    
    

    // char* xmlBuffer = NULL;
    // int readXmlErrors = readXML(fileXML , &xmlBuffer);

    // if(readXmlErrors != EXIT_FAILURE){
    //     if(checkXML(xmlBuffer)){
    //         printf("\nxml valide");
    //     }else
    //     {
    //         printf("\nxml invalidé");
    //     }
        
    // }
    
    // free(xmlBuffer);
    // freeDtd();

    menu();
    return 0;

}
