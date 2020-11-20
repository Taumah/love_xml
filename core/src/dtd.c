#include "../include/dtd.h"


extern doctypeDef dtd;

int getFileSize(char* fileName , size_t *fileSize){
    struct stat stats ; 

    if( stat(fileName, &stats) != 0 ){
        printf("Erreur lecture info fichiers\n");
        return EXIT_FAILURE;
    } 

    *fileSize = stats.st_size;
    return EXIT_SUCCESS;
}


void printDtd(){
    for (short i = 0; i < dtd.cursorElements; i+=1)
    {
        printElem(dtd.elements[i]);
    }
    for (short i = 0; i < dtd.cursorAttributes; i+=1)
    {
        printAttr(dtd.attributes[i]);
    }
    for (short i = 0; i < dtd.cursorEntities; i+=1)
    {
        printEnti(dtd.entities[i]);
    }
}

void readDTD(char* fileName){

    size_t fileSize;

    if(getFileSize(fileName , &fileSize) == EXIT_FAILURE){
        return;
    }
    

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

    free(dtd.rootElement);

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
        printf("This is not a valid DTD block..\n");
        break;
    }

}

int fillDoctypeDef(char* buffer){
    
    char* defDebut = strchr(buffer , '[');
    char* defFin = strrchr(buffer , ']');
    
    char* left = strchr(defDebut , '!');
    char* right=strchr(defDebut , '>');

    dtd.rootElement = getFirstWord(buffer);

    char* block = malloc(500);
    checkMalloc(block);

    while( right < defFin ){
        strncpy(block , left+1 , right-left); // +1 to ommit the extra "!" at the beginning of the string
        block[right-left] = '\0';
        
        splitDtdLine(block);
        
        
        left = strchr(right , '!');
        if(left == NULL){
            break;
        }
        right = strchr(left , '>');

    }

    free(block);    
    return 0;
}


void addElement(char *line){

    
    dtd.elements[dtd.cursorElements].name = getFirstWord(line);
    // printf("|%s|\n" , dtd.elements[dtd.cursorElements].name);

    dtd.elements[dtd.cursorElements].content = getEndOfBlock(line , 8);// 8 for e l e m e n t and trailing space
    // printf("|%s|%s|\n" ,dtd.elements[dtd.cursorElements].name, dtd.elements[dtd.cursorElements].content);

    dtd.cursorElements += 1;

    if (dtd.cursorElements == dtd.sizeElements)
    {
        doubleDtdField(FIELD_ELEMENTS);
    }
    

}

void addAttribute(char *line){
    
    dtd.attributes[dtd.cursorAttributes].elementName = getFirstWord(line);

    
    dtd.attributes[dtd.cursorAttributes].defaultVal = getDefaultVal(line);

    dtd.attributes[dtd.cursorAttributes].name = getTheNWord(line , 2);

    dtd.attributes[dtd.cursorAttributes].type = getTheNWord(line , 3);
    
    // printf("|%s|%s|%s|%s|\n" ,  dtd.attributes[dtd.cursorAttributes].elementName    , 
    //                             dtd.attributes[dtd.cursorAttributes].defaultVal     ,
    //                             dtd.attributes[dtd.cursorAttributes].name           ,
    //                             dtd.attributes[dtd.cursorAttributes].type);
    
    
    
    dtd.cursorAttributes += 1;

    
    if (dtd.cursorAttributes == dtd.sizeAttributes)
    {
        doubleDtdField(FIELD_ATTRIBUTES);
    }

}

void addAttributeWithGivenElementName(char *line , char* defaultElementName){
    (void)line;(void)defaultElementName;
}

void addEntity(char *line){
    
    dtd.entities[dtd.cursorEntities].name = getFirstWord(line);
    

    dtd.entities[dtd.cursorEntities].shortcut = getEndOfBlock(line , 7); // 7= 6 for e n t i t y and trailing space
    // printf("|%s|%s|\n",dtd.entities[dtd.cursorEntities].name, dtd.entities[dtd.cursorEntities].shortcut);
    
    dtd.cursorEntities += 1;

    
    if (dtd.cursorEntities == dtd.sizeEntities)
    {
        doubleDtdField(FIELD_ENTITIES);
    }
}

char* getFirstWord(char *block){
    char* wordDbt = strpbrk(block , " \n");

    char* wordEnd = strpbrk(wordDbt+1 , " \n");

    char* word = malloc(sizeof(char) * abs(wordEnd-wordDbt)  + 1);
    checkMalloc(word);

    strncpy(word , wordDbt+1 , wordEnd-wordDbt);

    *(word+ (wordEnd-wordDbt)-1 ) = '\0'; 

    return word;
}

char* getEndOfBlock(char *block, int decay){

    char* blockDbt = strpbrk(block+decay , " \n\r\0");
    
    char* blockEnd = strchr(blockDbt+1 , '>');

    char* word = malloc(sizeof(char) * (blockEnd-blockDbt)  + 1); // extra '\0' at the end 
    checkMalloc(word);

    strncpy(word , blockDbt+1 , blockEnd-blockDbt);

    *(word+ (blockEnd-blockDbt)-1 ) = '\0'; 

    return word;

}

void doubleDtdField(doctypeDefField field){
    
    switch (field)
    {
    case FIELD_ELEMENTS:
        dtd.sizeElements *= 2;
        dtd.elements = realloc(dtd.elements , sizeof(element) * dtd.sizeElements);
        checkMalloc(dtd.elements);
        break;

    case FIELD_ATTRIBUTES:
        dtd.sizeAttributes *= 2;

        dtd.attributes = realloc(dtd.attributes , sizeof(attribute) * dtd.sizeAttributes);
        checkMalloc(dtd.attributes);
        break;
    
    case FIELD_ENTITIES:
        dtd.sizeEntities *= 2;

        dtd.entities = realloc(dtd.entities , sizeof(entity) * dtd.sizeEntities);
        checkMalloc(dtd.entities);
        break;
    
    default:
        //WHUT ?
        return;
    }



}

void doubleDtdElements(void){
    dtd.sizeElements *= 2;

    element *newElements = malloc(sizeof(element) * dtd.sizeElements);

    for (int i = 0; i < dtd.cursorElements; i+=1)
    {
        newElements[i].name = malloc(sizeof(char) * strlen(dtd.elements[i].name));

        strcpy(newElements[i].name, dtd.elements[i].name);

        newElements[i].content = malloc(sizeof(char) * strlen(dtd.elements[i].content));
        strcpy(newElements[i].content ,  dtd.elements[i].content);

        freeElement(dtd.elements[i]);
    }
    
    free(dtd.elements);

    dtd.elements = newElements;

}


char* getDefaultVal(char* line){
    

    char *wordDbt , *wordEnd;
    
    wordDbt = strchr(line , '#');
    if(  wordDbt != NULL){
        wordEnd = strrchr(line , '>');
    }else
    {
        wordEnd = strrchr(line , '"'); 
        wordDbt = strchr(line  , '"')+1; // exclude the " at the beginning
    }

    char *word = malloc(sizeof(char) * (wordEnd-wordDbt) +1);

    strncpy(word , wordDbt , wordEnd-wordDbt);

    *(word+ (wordEnd-wordDbt) ) = '\0'; 

    return word;

    
}



char *getTheNWord(char* block , int N){
    char* leftOfWord = strpbrk(block , " \n\r") ;
    char *rightOfWord = NULL;
    char *word = NULL;
    int Nword = 1;
    int strlen = 0;

    while ( (leftOfWord = strpbrk(leftOfWord+1 , " \n\r>")+1) != NULL )
    {
        

        Nword += 1;
        if(Nword == N){
            break;
        }

    }

    rightOfWord = strpbrk(leftOfWord , " \n\r>");


    strlen = rightOfWord -leftOfWord;

    word = malloc(sizeof(char) * strlen  + 1);

    strncpy(word , leftOfWord , strlen );

    *(word + strlen ) = '\0';

    return word;

}