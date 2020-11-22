#include "../include/xml_2.h"

extern doctypeDef dtd;

size_t gap = 0;

int readXML(char* fileName , char** buffer){
	*buffer = NULL;
	size_t fileSize = 0;

	if( !isExtensionValid(fileName , "xml") ){ // check l'extension du fichier si elle n'est pas bonne renvoie une erreur 
		return EXIT_FAILURE ;
	}

	if( getFileSize(fileName , &fileSize) == EXIT_FAILURE){ // check la taille du fichier et du nom. Renvoie une erreur si probleme
		return EXIT_FAILURE;
	}

	FILE* fXML = fopen(fileName , "rw");

	if( fXML == NULL){
		printf("erreur à l'ouverture");
		return EXIT_FAILURE;
	}

	*buffer = malloc(sizeof(char) * fileSize);
	checkMalloc(*buffer);

	if (fread(*buffer, sizeof(char), fileSize, fXML) != fileSize)
	{
		return EXIT_FAILURE;
	}

	fclose(fXML);
  return EXIT_SUCCESS;
}

const char *getFilenameExt(const char *filename) {
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}

int isExtensionValid(char* fileName , char* extension){ 

	if( strcmp( extension , getFilenameExt(fileName) )  != 0  ){ // compare l'extension passée en paramètres et l'Extension du fichier 
		printf("ceci n'est pas un fichier %s\n" , extension);
		return false;
	}else
	{
		printf("extension valide \n");
		return true;
	}
}

int checkXML(char* buffer){
	
	if( getFirstBlock(buffer)){ //apelle de fonction permettant d'augmenter la valeur de gap 
		return true;
	}
	
	if(!isRootElementValid(buffer)){ // appelle de la fonction qui vérifie la 1 er balise des fochiers XML et DTD 
		return true;
	}

	return false; // renvoie false si y'a une erreur. 
}

int isRootElementValid(char* buffer){  // J'ai rien compris

	int errors = true;
	
	errors &= getTag(dtd.rootElement , buffer , buffer+strlen(buffer) , OPENING_ELEMENT);
	
	errors &= getTag(dtd.rootElement , buffer , buffer+strlen(buffer) , CLOSING_ELEMENT);


	return errors;
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
		g_match_info_next (match_info, NULL); // Va rechercher la correspondance suivante de match info 
		return false;
	}
	g_match_info_free (match_info); // Si match_info n'est pas NULL, appelle g_match_info_unref ()
	g_regex_unref (regex); 

	return true;
}




int getTag(char* marker , char* buffer , char* highest , int isClosing  ){

	char* copy = malloc(sizeof(char) * strlen(marker)+2 + isClosing);
	checkMalloc(copy);

	*(copy+isClosing) 	= '/';
	*(copy)		= '<';
	strcpy( copy + 1 + isClosing , marker); 
	
	char* found = strstr(buffer+gap , copy);

	if(found == NULL || found > highest){
		printf("\n [%s] not found" , copy);
		return true;
	}

	char* endingMarker = strchr(found , '>');
	if( endingMarker == NULL || endingMarker >= highest  ){
		printf("\n [%s] not found" , copy);
		return true;
	}
	printf("\n [%s] found" , copy);
	free(copy);

	if(isClosing == OPENING_ELEMENT && checkAttributes(marker , found , endingMarker) != true){
		
		return true;
	}
	return false;
}

int checkAttributes(char *marker , char *startBloc , char* endBloc){

	char strRegex[1000] = "";
	char *strRegexCopy = strRegex;

	sprintf(strRegex , "<%s +", marker );

	char* theElementWeWantToAnalyse = malloc(sizeof(char) * (endBloc-startBloc)+1);
	checkMalloc(theElementWeWantToAnalyse);

	char flags = 0;

	strncpy(theElementWeWantToAnalyse , startBloc , endBloc-startBloc +1);

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

		printf("|%s|test \n" ,defaultAttrValue);

		sprintf(strRegex , "%s(%s=\"%s\")%s *" , strRegexCopy ,dtd.attributes[i].name , defaultAttrValue ,attributeQuantifier );
	}

	strcat(strRegex , ">");
	
	printf("\nregex [%s]" , strRegex);

	free(theElementWeWantToAnalyse);
	free(attributeQuantifier);
	free(defaultAttrValue);
	return true;

}