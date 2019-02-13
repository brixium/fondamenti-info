#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 5
/*
* Si sviluppi un sottoprogramma che, ricevuto in ingresso una stringa ed un array di valori booleani (1/0) (di dimensione senz'altro pari alla stringa), restituisca una nuova stringa contenente solo caratteri corrispondenti agli 1 del vettore. Si sviluppi anche il programma chiamante.
*/
char * filtro(char *, int *);
int main(int argc, char * argv[]){
	char inutili[DIM+1];
	char * risultato;
	int i, schifo[DIM+1];
	risultato = NULL;
	scanf("%s", &inutili[0]);
	for(i=0; i<DIM; i++)
		do
			scanf("%d", &schifo[i]);
		while(!(schifo[i]==0 || schifo[i]==1));
	risultato = filtro(inutili, schifo);
	printf("%s\n", risultato);
	free(risultato);
	return 0;
}

char * filtro(char in[], int boolean[]){
	char * fin;
	int i, dim, j;
	j=0;
	dim = strlen(in);
	if(fin = (char *) malloc(dim * sizeof(char))){
		for(i=0; i<dim; i++)
			if(boolean[i]==1){
				* (fin + j) = in[i];
				j++;
			}
		* (fin + j) = '\0';
	}else
		printf("PC: Errore! Fai schifo e suicidati\nTu: occhei X-D <--questo è un omino morto\n");
	return fin;
}

