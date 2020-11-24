#include "../include/menu.h"

extern char nameXml[20][40], nameDtd[20][40];
extern char filePathXml[20][200], filePathDtd[20][200];
extern char clear[20];

int increment;

int existingFile(char *filePath){
  int lenght = strlen(filePath);

  filePath[lenght-1] = '\0';

  // printf("%s\n %d\n",filePath2, lenght); vérifier si la taille est bonne 
  // ./test/XML/coucouLesAmisBijour.xml
  // ./test/dtds/grossTDdeMort.dtd

  FILE *fichier;
  fichier = fopen(filePath,"r+");
  if(fichier==NULL){
    printf("Impossible d'ouvrir le fichier ! \n");
    return 0;
  }
  return 1;
}

void menu(){
  	int choice;
  	do{
    printf(	"--------Menu-------- \n"	\
    		"1: Effectuer un enregistrement \n"				\
    		"2: Voir les enregistrements \n"				\
			"3. Quitter \n"				\
			"Entre ton choix! "
			);

	int emptyStream = 0;
	errno = 0;
	scanf("%d",&choice);
    while((emptyStream = getchar()) != '\n' && emptyStream != EOF);

    

    switch(choice){
      	case 1:
        	insertFile(); // apelle de la methode une permettant de prendre un fichier dtd et un xml 
        	break;
      	case 2: 
        	afficheEnregistrement(); 
        	break;
      	case 3: 
        	printf("Au revoir \n");
        	break;
      	default: 
        	printf("Demande non reconnue, entrez une nouvelle valeur\n"); 
        	break;
    }
    
    
  	}while (choice !=3);
}



void insertFile(){
	/*
	Partie XML
	*/

	//Partie PathXml
  	do{
    	printf("Donne moi le chemin complet du fichier XML: ");
    	fgets(filePathXml[increment],sizeof(filePathXml[increment]),stdin);
  	}
  	while(! (existingFile(filePathXml[increment]) && isExtensionValid(filePathXml[increment] , "xml") )  );


	//Partie NomXML
	printf("Donne moi un nom pour ton fichier XML: ");
	fgets(nameXml[increment],sizeof(nameXml[increment]),stdin);
	nameXml[increment][strlen(nameXml[increment]) -1 ] = '\0'; // Permets de prendre le dernier caractère et le remplacer par un \0  
	/* 
	Partie DTD 
	*/

	//Partie PathDTD
	do{
		printf("Donne moi le chemin complet de la DTD: ");
		fgets(filePathDtd[increment],sizeof(filePathDtd[increment]),stdin);

	}
	while(! (existingFile(filePathDtd[increment]) && isExtensionValid(filePathDtd[increment] , "dtd") )  );


	//Partie NomDTD
	printf("Donnes moi un nom pour la DTD: ");
	fgets(nameDtd[increment],sizeof(nameDtd[increment]),stdin);
	nameDtd[increment][strlen(nameDtd[increment]) -1 ] = '\0'; // Permets de prendre le dernier caractère et le remplacer par un \0  
	
	increment++; // on l'increment car on as un nouvelle enregistrement

	//mettre un if si pas bien enregistrer 

	// Affichage des fichiers et noms
	//printf("%s%s",filePathXml,nameXml);
	//printf("%s%s",filePathDtd,nameDtd);
	// putc('\n',stdin);
	// putc('\0',stdin);
	printf("\n\n");
}

void afficheEnregistrement(){
  printf("Voici les enregistrement: \n");
  int valide = 1;

  char numberToExecute[1000];
  int intToExecute;

  for(int i=0;i<increment;i++){ // Parcours les enregistrements si aucun enregistrement alors on vérifie le if 
    if(strlen(nameXml[i])>0 && strlen(nameDtd[i])>0){ // si la taille du tableau>0 alors il existe un enregistrement
      valide=0; //valide = 0 car on est rentré dans le if et pas besoin d'afficher aucun enregistrement
      
      printf("%d) %s-%s\n",i+1,nameXml[i],nameDtd[i]); // Affichage des enregistrements sur la même ligne grace au remplacement du \0
    }
  }
  
  if(valide==1){ // si aucun enregistrement on affiche : 
    printf("Aucun enregistrement veuillez en faire un \n"); 
    return;
  }

  
  do{
    valide= 0;
    printf("Quel enregistrement voulez-vous lancer? R pour retour\n");
    fgets(numberToExecute , sizeof(numberToExecute),stdin );


    if( *numberToExecute == 'R' || *numberToExecute == 'r'){
		  // putc(' ',stdin);
      return;
    }

    intToExecute = atoi(numberToExecute);

    if(intToExecute > increment || intToExecute <= 0){
      printf("Nombre invalide\n");
    }else
    {
      valide = 1;
    }

    
  }while( !valide);

  verify(intToExecute);

}

int verify(int intToExecute  ){
	int returned = true;
	initDtd();

	readDTD(filePathDtd[intToExecute-1]); // -1 because we added +1 at display

	printDtd();

	char* xmlBuffer = NULL;
	int readXmlErrors = readXML(filePathXml[intToExecute-1] , &xmlBuffer);

	if(readXmlErrors == true){
		if(checkXML(xmlBuffer) == true){
			printf("\nxml valide");
			returned = true;
		}else
		{
			printf("\nxml invalidé");
			returned = false;
		}
		
	}else{
    printf("Erreur lors de la lecture des fichiers");
  }

	free(xmlBuffer);
	freeDtd();

	printf("\n");

	return returned;
}

