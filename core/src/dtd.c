#include "../include/dtd.h"


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
    free(buffer);


    
}

void initDtd(){
    
    dtd.cursorAttributes = dtd.cursorElements   = dtd.cursorEntities    = 0;
    dtd.sizeAttributes   = dtd.sizeElements     = dtd.sizeEntities      = DTD_FIELDS_DEFAULT_LENGTH;

    dtd.elements    = malloc(sizeof(element)    * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.elements);
    dtd.attributes  = malloc(sizeof(attribute)  * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.attributes);
    dtd.entities    = malloc(sizeof(entity)     * DTD_FIELDS_DEFAULT_LENGTH);
    checkMalloc(dtd.entities);

    
}

void freeDtd(){

    for (int i = 0; i < dtd.cursorElements; i+=1)
    {
        freeElement(dtd.elements[i]);
    }
    for (int i = 0; i < dtd.cursorAttributes; i+=1)
    {
        freeAttribute(dtd.attributes[i]);
    }
    for (int i = 0; i < dtd.cursorEntities; i+=1)
    {
        freeEntity(dtd.entities[i]);
    }
    free(dtd.elements);
    free(dtd.attributes);
    free(dtd.entities);
}
//TODO : create doubleDtdField someWhere ahah
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
        
        splitDtdLine(tmp);
        
        
        left = strchr(right , '!');
        if(left == NULL){
            break;
        }
        right = strchr(left , '>');

    }

    free(tmp);    
    return 0;
}


void addElement(char *line){

    
    dtd.elements[dtd.cursorElements].name = getFirstWord(line);
    printf("|%s|\n",dtd.elements[dtd.cursorElements].name);
    dtd.cursorElements += 1;

}

void addAttribute(char *line){
    
    dtd.attributes[dtd.cursorAttributes].name = getFirstWord(line);
    printf("|%s|\n",dtd.attributes[dtd.cursorAttributes].name);

    dtd.cursorAttributes += 1;

}


void addEntity(char *line){
    
    dtd.entities[dtd.cursorEntities].name = getFirstWord(line);
    printf("|%s|\n",dtd.entities[dtd.cursorEntities].name);

    dtd.cursorEntities += 1;
}

char* getFirstWord(char *line){
    char* wordDbt = strpbrk(line , " \n");

    char* wordEnd = strpbrk(wordDbt+1 , " \n");

    char* word = malloc(sizeof(char) * (wordEnd-wordDbt)  + 1);

    strncpy(word , wordDbt+1 , wordEnd-wordDbt);

    *(word+ (wordEnd-wordDbt)-1 ) = '\0'; 

    return word;
} 