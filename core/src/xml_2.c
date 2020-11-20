#include "../include/xml_2.h"

extern doctypeDef dtd;

size_t gap = 0;

int readXML(char* fileName , char** buffer){
	*buffer = NULL;
	size_t fileSize = 0;

	if( !isExtensionValid(fileName , "xml") ){
		return EXIT_FAILURE ;
	}

	if( getFileSize(fileName , &fileSize) == EXIT_FAILURE){
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

	if( strcmp( extension , getFilenameExt(fileName) )  != 0  ){
		printf("ceci n'est pas un fichier %s\n" , extension);
		return false;
	}else
	{
		printf("extension valide \n");
		return true;
	}
}

int checkXML(char* buffer){
	
	if( getFirstBlock(buffer)){
		return true;
	}
	
	return !isRootElementValid(buffer);
}

int isRootElementValid(char* buffer){

	

	return true;
}

int getFirstBlock(char *buffer){
	
	GRegex *regex;
	GMatchInfo *match_info;

	char *strRegex = "<\?[[:ascii:]]*\?>";

	regex = g_regex_new(strRegex, 0, 0, NULL);

	g_regex_match (regex, buffer, 0, &match_info);

	if(g_match_info_matches (match_info))
	{
		char *word = g_match_info_fetch (match_info, 0);

		gap += strlen(word);
		printf("\n\n%s , %d" , word , (int)strlen(word));
		g_free (word);
		g_match_info_next (match_info, NULL);
		return false;
	}
	g_match_info_free (match_info);
	g_regex_unref (regex);

	return true;
}


int getClosingTag(char* marker , char* buffer , char* highest  ){

	char* copy = malloc(sizeof(char) * strlen(marker)+3);
	checkMalloc(copy);

	*(copy)		= '<';
	*(copy+1) 	= '/';
	strcpy( copy+2 , marker); 
	
	char* found = strstr(buffer+gap , copy);

	free(copy);
	if(found == NULL || found > highest){
		printf("\nunfortunately;...");
		return true;
	}

	char* endingMaker = strchr(found , '>');
	if( endingMaker == NULL || endingMaker >= highest  ){
		printf("\nunfortunately 2 !!...");
		return true;
	}
	printf("\nwazaaaaaaaaaaa;...");

	return false;

}