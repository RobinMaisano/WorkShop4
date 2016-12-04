#include <stdio.h>  	/*"Standard Input/Outpu Header" Permet la déclaration
			de macros, de constantes et la definition de fonctions*/
#include <stdlib.h> 	/*Permet l'allocation dynamique, la conversion de
			valeurs, les randoms*/
#include <fcntl.h>	/*"File Control Options" défini les arguments pour les
			fonctions fcntl() et open()*/
#include <sys/types.h>	/*Definie de nouveaux types*/
#include <unistd.h>	/*Définition de types et constantes et permet
			l'utilisation de pointeurs*/
#define BUF_SIZE 512
int main(int argc, char* argv[]){ /*argv[] est un tableau de pointeur, pointant
				  sur des chaînes de caractères.
				  argc indique le nombre de chaîne sur
				  lesquelles pointe argv[]*/

int idFichierLu, idFichierEcrit;
int byteLu, byteEcrit;
char buffer[BUF_SIZE];
char nomFichier[255];

if(argc == 2){
	idFichierLu = open(argv[1], O_RDONLY);
	if (idFichierLu == -1){
		printf("Erreur de lecture");
		return -1;
	}else{
		sprintf(nomFichier, "/home/exia/save/%s", argv[1]);
		idFichierEcrit = open(nomFichier, O_WRONLY | O_CREAT, 0777);
		if(idFichierEcrit == -1){
			printf("Erreur d'ecriture");
			return -2;
		}else{
			while((byteLu = read(idFichierLu, &buffer, BUF_SIZE)) > 0){
				byteEcrit = write(idFichierEcrit, &buffer, byteLu);
				if(byteEcrit != byteLu){
					printf("Erreur d'ecriture dans le fichier");
					return -3;
				}else{
					printf("%d byte lus, %d byte ecrit\n", byteLu, byteEcrit);
				}
			}
		}
		close (idFichierLu);
		close (idFichierEcrit);
	}
}else{
	printf("Nombre de parametre incorrect");
}

}
