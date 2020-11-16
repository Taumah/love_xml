#include "../include/xml.h"
#include "../include/main.h"

extern fileAsArray f_xml;

char *readXML(char* fileName){
  char *fileXml = NULL;
  int str_size , read_size = 0;
  
  if(verifExtension(fileName) == 1){
    return;
  }
  
  FILE* XML = fopen(fileName , "rw");

  if( XML == NULL){
    printf("erreur à l'ouverture");
    exit(1);
  }

  if (XML) {
    // permet de se mettre a la fin du fichier
    fseek(XML,0,SEEK_END);
  
    // calculer la taille du fichier 
    str_size = ftell(XML);

    //retourner au debut du fichier
    //rewind(XML);
    fseek(XML,0,SEEK_SET);

    // creation d'un char dynamique de longeur du fichier+1
    fileXml = malloc(sizeof(char) * (str_size+1));

    // permet de lire tout le fichier en une seule fois
    read_size = fread(fileXml, sizeof(char), str_size, XML);

    // printf("taille du fichier : %d\n" , str_size );
    // printf("taille du fichier 2: %d\n" , read_size );

    //permet de transfromer fileXml en vrai chaine de caractre 
    fileXml[str_size] = '\0';

    
    if (str_size != read_size)
    {
      /*
        S'il y a eu une erreur alors on supprime tout.
      */
      free(fileXml);
      fileXml = NULL;
    }

    // A la fin on ferme le fichier pour eviter un probleme par la suite
    fclose(XML);
  }

  // On retourne notre fileXml pour pouvoir l'utiliser par la suite 

  return fileXml;
}

const char *getFilenameExt(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int verifExtension(char* fileXML){

    if(   strcmp("xml" , getFilenameExt(fileXML) )  != 0  ){
        printf("ceci n'est pas un fichier XML\n");
        return 1;
    }else
    {
        printf("extension valide \n");
        return 0;
    }
}



char *recoverValue(char* fileName){
  /*
  Cette fonction prend char par char et regarder si il tombe pas sur <
  si il le trouve on ajoute la suite jusqu'a qu'il trouve > dans un tableau et on le print 
  */
  
  char *buffer = readXML(fileName);
  
  //printf("je suis la 1\n|%s|\n" , buffer);

  int i=0;
  char *balise=NULL;
  char *baliseDbt = NULL, *baliseEnd = NULL;
  int strlen;
  char *tab[256];
  
  //printf("je suis la 2\n|%s|\n" , buffer); 
   
  if( buffer == NULL){
    return NULL;
  }
  //printf("je suis la 3\n|%s|\n" , buffer);
  //printf("1");
  
  baliseDbt = strchr( buffer , '<');
  baliseEnd = baliseDbt;
  while(buffer[i] !='\0'){
    

    baliseDbt = strchr( baliseEnd , '<');

    if(baliseDbt == NULL){
      break;
    }
    baliseEnd = strchr(baliseDbt , '>');
    
    if(baliseEnd == NULL){
      break;
    }
    strlen = baliseEnd - baliseDbt;
    
    balise = malloc( sizeof(char) *  strlen ); // baliseEnd - baliseDbt calcule nombre de char entre les deux
    
    strncpy(balise , baliseDbt+1 , strlen-1); 
    // copy dans balise 
    
    *(balise + strlen-1) = '\0';
  
    printf("%s\n", balise);

    i = (baliseEnd - buffer);
    
  }
  return NULL;
}
