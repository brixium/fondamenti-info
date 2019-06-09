/*
Scrivere un programma che chiede all’utente il nome di tre file di testo (ognuno di al più 80 caratteri, comprensivi di percorso ed estensione): i primi due file sono i file sorgente, il terzo quello destinazione ed un intero. Il programma crea il terzo file concatenando i contenuti dei due file in ingresso: se l’intero fornito vale 0, il programma concatena il secondo file al primo, se l’intero fornito vale 1, il programma concatena il primo al secondo.
Nel caso in cui l’intero valga un valore diverso da 0 e da 1, il programma non fa nulla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFNL 80
#define STRLEN 1024

int main(int argc, char * argv[]){
	char nf1[MAXFNL+1], nf2[MAXFNL+1], nf3[MAXFNL+1];
	char s1[STRLEN];
	int num;
	FILE *f1, *f2, *f3;
		
	printf("Inserisci i nomi + percorso dei 2 file sorgente e di quello di destinazione: ");
	scanf("%s %s %s %d", nf1, nf2, nf3, &num);
	if((f1 = fopen(nf1, "r"))){
		if((f2 = fopen(nf2, "r"))){
			if((f3 = fopen(nf3, "w"))){
				
				if(!num){
					fscanf(f1, "%s", &s1[0]);
					while(!feof(f1)){
						fprintf(f3, "%s", &s1[0]);
						fscanf(f1, "%s", &s1[0]);
					}
					fscanf(f2, "%s", &s1[0]);
					while(!feof(f2)){
						fprintf(f3, "%s", &s1[0]);
						fscanf(f2, "%s", &s1[0]);
					}
				}else if(num==1){
					fscanf(f2, "%s", &s1[0]);
					while(!feof(f2)){
						fprintf(f3, "%s", &s1[0]);
						fscanf(f2, "%s", &s1[0]);
					}
					fscanf(f1, "%s", &s1[0]);
					while(!feof(f1)){
						fprintf(f3, "%s", &s1[0]);
						fscanf(f1, "%s", &s1[0]);
					}
				}
				fclose(f3);
			}else
				printf("Errore apertura f3\n");
			fclose(f2);
		}else
			printf("Errore apertura file f2\n");
		fclose(f1);
	}else
		printf("Errore nell'apertura f1\n");
	return 0;
}
