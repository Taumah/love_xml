#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "xml.h"
#include "dtd.h"

/* affiche le menu */
void menu();

/*
Cette fonction va demander à l'utilisateur d'entrer un nom, un chemin pour la DTD et le fichier XML.
*/ 
void insertFile();

/* 
Cette fonction sert à afficher les enregistrements.
Si aucun n'enregistrement est précent alors on n'affiche rien 
*/ 
void afficheEnregistrement();

/*
Cette fonction retourne si un fichier existe ou non. Si le chemin n'est pas bien rentré il vous demandera de retaper le chemin.
*/
int existingFile(char *filePath);