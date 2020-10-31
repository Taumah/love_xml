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

