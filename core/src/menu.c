#include "../include/menu.h"

char nameXml[20][20], nameDtd[20][20];
char filePathXml[80], filePathDtd[80];
char clear[20];

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
    		"1: Effectuez un enregistrement \n"				\
    		"2: Voir les enregistrements \n"				\
			"3. Exit \n"				\
			"Entre ton choix! "
			);
			
    scanf(" %d",&choice);
    

    switch(choice){
      case 1:
        insertFile(); // apelle de la methode une permettant de prendre un fichier dtd et un xml 
        break;
      case 2: 
        afficheEnregistrement(); 
        break;
      case 3: 
        printf("Casse toi petit merde \n");
        break;
      default: 
        printf("Wrong Choice. Enter again\n"); 
        break;
    }

  }while (choice !=3);
}



void insertFile(){
  fgets(clear,sizeof(clear),stdin);

  /*
  Partie XML
  */

  //Partie PathXml
  do{
    printf("Donnes moi le chemin complet de ton fichier XML: ");
    fgets(filePathXml,sizeof(filePathXml),stdin);
  }
  while(!existingFile(filePathXml));


  //Partie NomXML
  printf("Donnes moi un nom pour ton fichier XML: ");
  fgets(nameXml[increment],sizeof(nameXml),stdin);
 
  /* 
  Partie DTD 
  */

  //Partie PathDTD
  do{
     printf("Donne moi le chemin complet de ta DTD: ");
    fgets(filePathDtd,sizeof(filePathDtd),stdin);
  }
  while(!existingFile(filePathDtd));


  //Partie NomDTD
  printf("Donnes moi un nom pour ta DTD: ");
  fgets(nameDtd[increment],sizeof(nameDtd),stdin);
  

  increment++; // on l'increment car on as un nouvelle enregistrement

  //mettre un if si pas bien enregistrer 

  // Affichage des fichiers et noms
  //printf("%s%s",filePathXml,nameXml);
  //printf("%s%s",filePathDtd,nameDtd);

  printf("\n");
}

void afficheEnregistrement(){
  printf("Voici les enregistrement: \n");
  int valide = 1;
  for(int i=0;i<increment;i++){ // Parcours les enregistrements si aucun enregistrement alors on vérifie le if 
    if(strlen(nameXml[i])>0 && strlen(nameDtd[i])>0){ // si la taille du tableau>0 alors il existe un enregistrement
      valide=0; //valide = 0 car on est rentré dans le if et pas besoin d'afficher aucun enregistrement
      nameXml[i][strlen(nameXml[i]) -1] = '\0'; // Permets de prendre le dernier caractère et le remplacer par un \0  
      printf("%s-%s",nameXml[i],nameDtd[i]); // Affichage des enregistrements sur la même ligne grace au remplacement du \0
    }
  }
  if(valide==1){ // si aucun enregistrement on affiche : 
    printf("Aucun enregistrement veuillez en faire un "); 
  }
  printf("\n");
}

