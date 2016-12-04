#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> /*Permet d'activer des fonctions permettant
		    de parcourir des fichiers*/
#include <sys/types.h> /*VOIR FICHIER 'sauvegarde.c'*/

int main(int argc, char* argv[]){

	struct dirent *contenuRepertoire; /**/
	DIR *repertoire; /*permet de simuler le répertoire que l'on
			 a ouvert*/

	if(repertoire == NULL){
		printf("Erreur lors de l'ouverture du répertoire");
		return -1;
	}
	while((contenuRepertoire = readdir(repertoire)) != NULL){
		printf("nom:%s | ", contenuRepertoire->d_name);
		printf("ID:%d \n", contenuRepertoire->d_ino);
	}
	closedir(repertoire);
	return 0;

}
