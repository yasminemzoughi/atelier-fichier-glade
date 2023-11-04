#include <string.h>
#include "ajouter.h"
#include <stdio.h>
#include <stdlib.h>

void ajouter(char nom[], char prenom[], char username[], char password[], int
role){

FILE *f;

f=fopen("utilisateur.txt","a+");
	if(f != NULL){

		fprintf(f,"%s %s %s %s %d \n",nom,prenom,username,password,role);

fclose(f);
	}else printf("impossible d'ouvrir le fichier");

}
