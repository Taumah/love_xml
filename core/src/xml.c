#include "../include/xml.h"

extern doctypeDef dtd;

size_t gap = 0;

int readXML(char* fileName , char** buffer){
	*buffer = NULL;
	size_t fileSize = 0;

	if( !isExtensionValid(fileName , "xml") ){ //check l'extension du fichier si elle n'est pas bonne renvoie une erreur
		return false ;
	}

	if( getFileSize(fileName , &fileSize) == false){ // check la taille du fichier et du nom. Renvoie une erreur si probleme	
		return false;
	}



	FILE* fXML = fopen(fileName , "rw");

	if( fXML == NULL){
		printf("erreur à l'ouverture");
		return false;
	}

	*buffer = malloc(sizeof(char) * fileSize);
	checkMalloc(*buffer);

	if (fread(*buffer, sizeof(char), fileSize, fXML) != fileSize)
	{
		return false;
	}

	fclose(fXML);
  	return true;
}

const char *getFilenameExt(const char *filename) {
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}

int isExtensionValid(char* fileName , char* extension){

	if( strcmp( extension , getFilenameExt(fileName) )  != 0  ){ //compare l'extension passée en paramètres et l'Extension du fichier 
		printf("ceci n'est pas un fichier %s\n" , extension);
		return false;
	}else
	{
		printf("extension valide \n");
		return true;
	}
}

int checkXML(char* buffer){
	
	if( !getFirstBlock(buffer+gap)){ //apelle de fonction permettant d'augmenter la valeur de gap 
		return false;
	}
	printf("\nEntête XML correcte");
	
	if(!isRootElementValid(buffer+gap)){ // appelle de la fonction qui vérifie la 1 er balise des fochiers XML et DTD 	
		return false;
	}
	return true;
}

int isRootElementValid(char* buffer){

	int valid = true;
	
	valid &= getTag(dtd.rootElement , buffer , buffer+strlen(buffer) , OPENING_ELEMENT);
	
	valid &= getTag(dtd.rootElement , buffer , buffer+strlen(buffer) , CLOSING_ELEMENT);

	valid &= generateRegexForElement(dtd.rootElement , buffer , buffer+strlen(buffer));

	return valid;
}

int getFirstBlock(char *buffer){
	
	GRegex *regex;
	GMatchInfo *match_info;

	char *strRegex = "<\?[[:ascii:]]*\?>"; // création d'un pattern qui prend tous les ASCII 

	regex = g_regex_new(strRegex, 0, 0, NULL); // cette fonction permet de créer une expresiion régulieres en utilisant un pattern 	

	g_regex_match (regex, buffer, 0, &match_info); 
	// Cherche une correspondance dans la chaine entre les 2 premiers paramétres. 	
	// Les informations sont stockés dans match info
	
	if(g_match_info_matches (match_info)) // Renvoie oui si l'opération de correspondance précédente a réussi.
	{
		char *word = g_match_info_fetch (match_info, 0); // recupere le texte de match_info et le stocker dans word

		gap += strlen(word)-1;
		// printf("\n\n%s , %d" , word , (int)strlen(word));
		g_free (word); // permets de libérer le regex 
		g_match_info_free (match_info); // Va rechercher la correspondance suivante de match info 
		g_regex_unref (regex); 

		return true;

	}
	g_match_info_free (match_info); // libère la mémoire de la structure	
	g_regex_unref (regex); // il est maintenant possible de reutiliser g_regex_match

	return false;
}


int getTag(char* marker , char* buffer , char* highest , int isClosing  ){

	char* copy = malloc(sizeof(char) * strlen(marker)+2 + isClosing);
	checkMalloc(copy);

	*(copy+isClosing) 	= '/';
	*(copy)		= '<';
	strcpy( copy + 1 + isClosing , marker); 
	
	char* found = strstr(buffer , copy);

	if(found == NULL || found > highest){
		// printf("\n [%s] not found" , copy);
		return false;
	}

	char* endingMarker = strchr(found , '>');
	if( endingMarker == NULL || endingMarker >= highest  ){
		// printf("\n [%s] not found" , copy);
		return false;
	}
	// printf("\n [%s] found" , copy);
	free(copy);

	// if(isClosing == OPENING_ELEMENT && checkAttributes(marker , found , endingMarker) != true){
		
	// 	return false;
	// }
	return true;
}

char* checkAttributes(char *marker){

	char *strRegex = malloc(1000 * sizeof(char));
	checkMalloc(strRegex);

	char *strRegexCopy = strRegex;

	sprintf(strRegex , "<%s +", marker );

	// char* theElementWeWantToAnalyse = malloc(sizeof(char) * (endBloc-startBloc)+1);
	// checkMalloc(theElementWeWantToAnalyse);

	char flags = 0;

	// strncpy(theElementWeWantToAnalyse , startBloc , endBloc-startBloc +1);

	// *(theElementWeWantToAnalyse+(endBloc-startBloc)+1) = '\0';

	char* attributeQuantifier = malloc(sizeof(char) * 4) ;
	char* defaultAttrValue = malloc(sizeof(char) * 25);
	for (int i = 0; i < dtd.cursorAttributes; i+=1)
	{

		if(strcmp(dtd.attributes[i].elementName , marker) != 0){
			continue;	
		}
		flags = 0;
			
		//TODO read the attribute selected and adapt pre-built regex <3333
		
		flags += strncmp(dtd.attributes[i].defaultVal , "#IMPLIED " , 8) == 0;
		flags <<= 1;

		flags += strncmp(dtd.attributes[i].defaultVal, "#REQUIRED " , 10) == 0;
		flags <<= 1;
	
		flags += strncmp(dtd.attributes[i].defaultVal, "#FIXED " , 7) == 0;

		switch (flags){
			case 4: // IMPLIED
				strcpy(attributeQuantifier , "?");
				strcpy(defaultAttrValue,  "[[:print:]]+");
				break;
			case 2: //REQUIRED
				strcpy(attributeQuantifier , "{1}");
				strcpy(defaultAttrValue,  "[[:print:]]+");
				break;
			case 1: // FIXED
				strcpy(attributeQuantifier , "{1}");
				free(defaultAttrValue);
				defaultAttrValue = getDefaultValueWhenFixed(dtd.attributes[i].defaultVal);
				break;
			case 0: //NONE
				//TODO check if it is an enum. if so, create new variable to match the check
				
				break;
			
			default: // WHAT?
				fprintf(stderr , "\nWHAT? , please try again...\n");
				break;
		}


		sprintf(strRegex , "%s(%s=\"%s\")%s *" , strRegexCopy ,dtd.attributes[i].name , defaultAttrValue ,attributeQuantifier );
	}

	strcat(strRegex , ">");
	
	// int returned = checkRegex(strRegex , theElementWeWantToAnalyse);
	

	// printf("regex |%s| \nstring|%s|" , strRegex , theElementWeWantToAnalyse);

	// free(theElementWeWantToAnalyse);
	free(attributeQuantifier);
	free(defaultAttrValue);

	return strRegex;
}


int checkRegex(char* strRegex , char* haystack){
	GRegex *regex;
	GMatchInfo *match_info;

	regex = g_regex_new(strRegex, 0, 0, NULL);
	if(regex == NULL){
		return false;
	}
	g_regex_match (regex, haystack, 0, &match_info);


	int returned = false;
	if(g_match_info_matches (match_info))
	{
		returned = true;
	}
	g_match_info_free (match_info);
	g_regex_unref (regex);

	free(haystack);


	return returned;

}


int generateRegexForElement(char* elementName , char* buffer , char*  endBuffer){
	
	//TODO transform it into a char* instead of char* begin and char* end
	int elementIndex = -1;

	char* newBuffer = malloc(sizeof(char) * (endBuffer - buffer)+1);
	checkMalloc(newBuffer);
	
	strncpy(newBuffer , buffer , endBuffer - buffer );


	elementIndex = getElementIndexFromName(elementName);

	if(elementIndex == -1){
		return false;
	}

	// printf("\n[%s]\n" , dtd.elements[elementIndex].content);

	if(strcmp(dtd.elements[elementIndex].content , "EMPTY") == 0){
		return regexEmpty(dtd.elements[elementIndex].name , newBuffer);
		// printf("\n!!!!!!!!EMPTY and %dand [%s]" ,isValid , buffer );
	}
	else if( strcmp(dtd.elements[elementIndex].content , "#PCDATA" ) == 0){
		// printf("\n!!!!!!!!PCDATA ");
		return regexPCDATA(dtd.elements[elementIndex].name , newBuffer);
	}
	else if( strcmp(dtd.elements[elementIndex].content , "ANY") == 0){
		return regexANY(dtd.elements[elementIndex].name , buffer);
		// printf("\n!!!!!!!!ANY ");
	}else{
		return regexChildren(dtd.elements[elementIndex].name , newBuffer);
	}
}


int regexEmpty(char* elementName , char* buffer){

	char strRegex[1000];
	char *subRegex = checkAttributes(elementName);
	strcpy(strRegex , subRegex);
	free(subRegex);

	strRegex[strlen(strRegex)] = '\0';
	strRegex[strlen(strRegex)-1] = '>';
	strRegex[strlen(strRegex)-2] = '/';



	return checkRegex(strRegex , buffer);
}

int regexPCDATA(char* elementName , char* buffer){
	char strRegex[1000];
	char* subRegex = checkAttributes(elementName);

	sprintf(strRegex , "%s[^<>]*</%s *>" , subRegex , elementName);
	free(subRegex);
	// printf("my regex : [%s]" , strRegex);
	return checkRegex(strRegex , buffer);
}

int regexANY(char* elementName , char* buffer){
	char strRegex[1000];

	char* subRegex = checkAttributes(elementName);

	int isEmpty = regexEmpty(elementName , buffer);

	sprintf(strRegex , "%s[[:ascii:]]*</%s *>)" , subRegex , elementName);
	int isOther = checkRegex(strRegex , buffer);
	// printf("my regex : [%s]" , strRegex);
	return isEmpty || isOther;
}

int regexChildren(char* elementName , char* buffer){
	int i;

	i = getElementIndexFromName(elementName);
	if( i == -1){
		printf("hay un problemo");
		return 0;
	}

	char **contentSplit = NULL ;
	// char **contentPipeSplit = NULL;
	int splitSize ;
	// int splitPipeSize;
	
	contentSplit = splitStr(dtd.elements[i].content , ',' , &splitSize );

	char strRegex[1000] = "";
	char* subRegex;

	// printf("\nil y a %d token(s)\n" , splitSize);
	if(splitSize == 0){ // 1 seul élement dans .content
		// printf("\n[%s]", dtd.elements[i].content);
		subRegex = regexOneToken(dtd.elements[i].content);

		char *subRegexMarker = checkAttributes(dtd.elements[i].name);

		// dtd.elements[i].content[strlen(dtd.elements[i].content)-1] = '\0';

		sprintf(strRegex 	,"%s[[:blank:]\\n]*%s</%s *>" ,
							subRegexMarker , subRegex , elementName);
		
		printf("\nregex used : %s" ,  strRegex);
		free(subRegex);
		free(subRegexMarker);
		
	}
	else{
		char* strRegexMarker = checkAttributes(elementName );
		sprintf(strRegex, "%s[[:blank:]\\n]*",
							strRegexMarker);
		free(strRegexMarker);
		char* strRegexCpy = strRegex;
		for (int j = 0; j < splitSize; j+=1)
		{
			
			subRegex = regexOneToken(contentSplit[j]);
			strcat(strRegex , subRegex );

			// if(strchr(contentSplit[j] , '|')){
				// 	contentSplit = removeParentheses(contentSplit);
				// 	contentPipeSplit = splitStr(contentSplit[j] , '|' , &splitPipeSize); 
				// 	for (int k = 0; k < splitPipeSize; k+=1)
				// 	{
				// 		printf("\nIntra content : [%s]\n" , contentPipeSplit[k]);
				// 	}
			// }

			free(subRegex);
		}
		sprintf(strRegex, "%s</%s *>",
						   strRegexCpy , elementName);
		printf("\nregex used : %s" ,  strRegex);

	}
	
	doubleFree(contentSplit , splitSize);
	// doubleFree(contentPipeSplit , splitPipeSize);

	// printf(" regex used:|%s|" , strRegex);
	return checkRegex(strRegex , buffer);
}

//sprintf permet d'envoyer la sortie formatée à une chaîne pointée, par str.
// utilisation des regex par ce que c'est bien plus simple que de chercher dans tout le code une balise < et >. 

char* regexOneToken(char* token){

	char* subRegex = malloc(sizeof(char) * 150);
	char* quantifier;


	char* copy = malloc(sizeof(char)* strlen(token)+1);
	strcpy(copy , token);
	char strQuantifier[4];
	if( (quantifier = strpbrk(  copy ,  "?+*") ) != NULL){
		strncpy(strQuantifier , quantifier , 1);
		strQuantifier[1]= '\0';
		
		copy[strlen(copy)-1] = '\0'; // remove quantifier from token
	}else
	{
		strcpy(strQuantifier , "{1}");
	}

	char* subRegexMarker = checkAttributes(copy);

	sprintf(subRegex 	, "(%s[[:ascii:]]*</%s *>[[:blank:]\\n]*)%s"
						, subRegexMarker , copy , strQuantifier );

	free(subRegexMarker);
	free(copy);
	return subRegex;
}
	