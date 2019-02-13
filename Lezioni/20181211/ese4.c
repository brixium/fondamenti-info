/*
* E4: Nomi di file
* Sviluppare il sottoprogramma splitFileName, che ha il prototipo seguente (in cui compaiono i nomi dei parametri formali):

void splitFileName(char srcFileName[], char percorso[], char nome[], char e);

che preso in ingresso il nome di un file completo di percorso ed estensione, trasmette al chiamante il percorso del file, il suo nome e la sua estensione, ed il numero di caratteri in esso contenuto. Scrivere poi un programma che, utilizzando il sottoprogramma fornito, ciclicamente chieda all’utente l’indicazione completa del nome del file e poi visualizza, per ogni file i dati estratti. Il programma termina quando l’utente inserisce la stringa "fine".

*/
#include <stdio.h>
#include <string.h>

#define SEPU '/'
#define SEPW '\\'
#define SEPTEXT '.'
#define STOP "fine"
#define MAX 100
void splitFileName(char [], char [], char [], char [], int *);

int main(int argc, char * argv[]){
	char full[MAX+1], name[MAX+1], path[MAX+1], ext[MAX+1];
	int n;

	gets(full);
	while(strcmp(full, STOP)){
		splitFileName(full, path, name, ext, &n);
		printf("> %s\t| %s\t| %s\t| %d\n", path, name, ext, n);
		gets(full);
	}
	return 0;
}

void splitFileName(char srcFileName[], char percorso[], char nome[], char est[], int * ncar){
	FILE * fp;
	char car;
	int i, len;
	int iext, iname;

	len = strlen(srcFileName);
	i = len - 1;
	iext = len;
	iname = 0;
	while(i >=0 && srcFileName[i] != SEPTEXT && (srcFileName[i] != SEPU && srcFileName[i] != SEPW))
		i--;
	if(i== -1)
		i++;
	if(srcFileName[i] == SEPTEXT)
		iext = i+1;
	while(i>=0 && (srcFileName[i] != SEPU && srcFileName[i] != SEPW))
		i--;
	if(i == -1)
		i++;
	if(srcFileName[i] == SEPU || srcFileName[i] == SEPW)
		iname = i+1;
	
	/*printf("%d %d\n", iname, iext);*/
	if(iext - iname > 1){
		strcpy(est, &srcFileName[iext]);
		strncpy(nome, &srcFileName[iname], iext-iname);
		if(iext == len)
			nome[iext-iname] = '\0';
		else
			nome[iext-1-iname] = '\0';
	}else if(iext ==1){
		est[0] = '\0';
		iname = iext-1;
		strcpy(nome, &srcFileName[iname]);
	}else{
		est[0] = '\0';
		strcpy(nome, &srcFileName[iname]);
	}

	if(iname >0)
		strncpy(percorso, srcFileName, iname);
	percorso[iname] = '\0';

	if(fp = fopen(srcFileName, "r")){
		*ncar = 0;
		fscanf(fp, "%c", &car);
		while(!feof(fp)){
			(*ncar)++;
			fscanf(fp, "%c", &car);
		}
		fclose(fp);
	} else{
		*ncar = -1;
		printf("Impossibile accedere al file %s\n", srcFileName);
	}
	return ;
}

