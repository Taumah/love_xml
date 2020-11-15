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
    fileXml = malloc(sizeof(char) * str_size+1);

    // permet de lire tout lezz fichier en une seule fois
    read_size = fread(fileXml, sizeof(char), str_size, XML);

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
  int i=0;
  char tab[256];

  if(buffer == 1){
    return;
  }

  while(buffer[i] !='\0'){
      if(buffer[i]=='<'){
        tab[i] = buffer[i];
        i++;
    }
    else if(buffer[i] =='>'){
      tab[i] = buffer[i];
      i++;
    }
    i++;
  }
  return tab;
}
