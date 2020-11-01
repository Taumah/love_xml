#include "../include/menu.h"


void menu(){
  int choice;
  do{
    printf(	"--------Menu-------- \n"	\
    		"1: blblbl \n"				\
    		"2: blblbl \n"				\
			"3. Exit \n"				\
			"Entre ton choix! "
			);
			
    scanf(" %d",&choice);

    switch(choice){
      case 1: 
        printf("je suis une fleur \n\n "); // apelle de la methode une permettant de prendre un fichier dtd et un xml 
        break;
      case 2: 
        printf("je suis une fleur blouge \n\n"); 
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
  
  //Partie XML

  //Partie PathXml
  printf("Donnes moi le chemin complet de ton fichier XML: ");
  fgets(filePathXml,sizeof(filePathXml),stdin);
  fflush(stdin);

  /*
  ATTENTION
  Faire une detection du fichier inexistant
  */

  //Partie NomXML
  printf("Donnes moi un nom pour ton fichier XML: ");
  fgets(nameXml[increment],sizeof(nameXml),stdin);
  fflush(stdin); 

 
  // Partie DTD 

  //Partie PathDTD
  printf("Donne moi le chemin complet de ta DTD: ");
  fgets(filePathDtd,sizeof(filePathDtd),stdin);
  fflush(stdin);

  /*
  ATTENTION
  Faire une detection du fichier inexistant
  */

  //Partie NomDTD
  printf("Donnes moi un nom pour ta DTD: ");
  fgets(nameDtd[increment],sizeof(nameDtd),stdin);
  fflush(stdin);

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

