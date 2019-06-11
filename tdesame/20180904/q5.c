#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Scrivere un programma che chiede all’utente il nome di tre file di testo ASCII (ognuno di al più 80 caratteri, comprensivi di percorso ed estensione): i primi due file sono i file sorgente, il terzo quello destinazione ed un intero.
Il programma crea il terzo file concatenando il contenuto dei due file in ingresso: se l’intero fornito vale 0, il programma concatena il contenuto del secondo file al primo, se l’intero fornito vale 1, il programma concatena il contenuto del primo al secondo.
Nel caso in cui l’intero valga un valore diverso da 0 e da 1, il programma non fa nulla.
*/
#define NFL 80
#define MAXROWLEN 1024

int main(int argc, char * argv[]){
	FILE *f1, *f2, *f3;
	char nf1[NFL+1], nf2[NFL+1], nf3[NFL+1], s[MAXROWLEN];
	int n;
	
	printf("Inserisci i nomi dei 2 file in ingresso e del file in uscita ed un intero: ");
	scanf("%s %s %s %d", &nf1[0], &nf2[0], &nf3[0], &n);
	if((f1 = fopen(nf1, "r"))){
		if((f2 = fopen(nf2, "r"))){
			if((f3 = fopen(nf3, "w"))){
				
				if(!n){
					fscanf(f2, "%s", &s[0]);
					while(!feof(f2)){
						fprintf(f3, "%s", &s[0]);
						fscanf(f2, "%s", &s[0]);
					}
					fscanf(f1, "%s", &s[0]);
					while(!feof(f1)){
						fprintf(f3, "%s", &s[0]);
						fscanf(f1, "%s", &s[0]);
					}

				}else if(n==1){
					fscanf(f1, "%s", &s[0]);
					while(!feof(f1)){
						fprintf(f3, "%s", &s[0]);
						fscanf(f1, "%s", &s[0]);
					}
					fscanf(f2, "%s", &s[0]);
					while(!feof(f2)){
						fprintf(f3, "%s", &s[0]);
						fscanf(f2, "%s", &s[0]);
					}

				}

				fclose(f3);
			}else
				printf("Errore apertura file %s\n", nf3);
			fclose(f2);
		}else
			printf("Errore apertura file %s\n", nf2);
		fclose(f1);
	}else
		printf("Errore apertura file %s\n", nf1);
	return 0;
}
