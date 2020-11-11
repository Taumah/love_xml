#include "../include/dtd.h"
#include "../include/main.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

extern doctypeDef dtd;

off_t getFileSize(char* fileName){
    struct stat stats ; 

    if( stat(fileName, &stats) != 0 ){
        printf("Erreur lecture info fichiers\n");
        exit(EXIT_FAILURE);
    } 

    return stats.st_size;
}

void readDTD(char* fileName){

    unsigned long long fileSize = getFileSize(fileName);

    char* buffer = malloc(sizeof(char) * fileSize+1);
    checkMalloc(buffer);


    FILE* f = fopen(fileName , "r");
    checkfOpen(f);
    fread(buffer , fileSize , sizeof(char) , f);
    fclose(f);


    fillDoctypeDef(buffer);

    
}

void initDtd(){
    dtd.elements    = malloc(sizeof(element)    * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.elements);
    dtd.attributes  = malloc(sizeof(attribute)  * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.attributes);
    dtd.entities    = malloc(sizeof(entity)     * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.entities);

  
}

void freeDtd(){
    free(dtd.elements);
    free(dtd.attributes);
    free(dtd.entities);
}

void splitDtdLine(char* line){
    switch ( *(line+1) )
    {
    case 'L': // eLement
        addElement(line);
        break;
    
    case 'T': // aTtlist
        addAttribute(line);
        break;
        
    case 'N': // eNtity
        addEntity(line);
        break;
    default:
        printf("NULL\n");
        break;
    }

    // printf("%d eheh \n", strncmp(left , "ELEMENT" , right - left) );

}

int fillDoctypeDef(char* buffer){
    
    char* defDebut = strchr(buffer , '[');
    
    char* defFin = strrchr(buffer , ']');
    
    char* left = strchr(defDebut , '!');

    char* right=strchr(defDebut , '>');

    char* tmp = malloc(500);
    checkMalloc(tmp);

    while( right < defFin ){
        strncpy(tmp , left+1 , right-left); // +1 to ommit the extra "!" at the beginning of the string
        tmp[right-left] = '\0';
        // printf("|%s|\n\n" , tmp);
        
        splitDtdLine(tmp);
        
        
        left = strchr(right , '!');
        if(left == NULL){
            break;
        }
        right = strchr(left , '>');

    }

    free(tmp);
    free(buffer);
    
    return 0;
}


void addElement(char *line){
    printf("adding element\n");
    (void)line;
}


void addAttribute(char *line){
    printf("adding attribute\n");
    (void)line;
    
}


void addEntity(char *line){
    printf("adding entity\n");
    (void)line;
    
}