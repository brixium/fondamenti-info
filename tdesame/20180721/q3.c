#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 1024
/*
Scrivere un sottoprogramma rot che ricevuta in ingresso una stringa voc ed un numero intero senz’altro positivo n, la modifica in modo tale che la stringa finale sia quella iniziale, fatta scorrere a destra di n posizioni, con gli ultimi n caratteri riportati in testa.
Se per esempio la stringa iniziale è Esempio ed n è 1, la stringa finale sarà oEsempi. Data la stringa iniziale Fondamenti e il valore 4, la stringa finale è entiFondam.
*/

void rot(char *, int);

int main(int argc, char * argv[]){
	char * s;
	int n;
	if(argc > 2){
		s = argv[1];
		n = atoi(argv[2]);
	}else if((s = (char *)malloc(sizeof(char)*MAXSTRLEN))){
		printf("Inserisci una stringa e un numero: ");
		scanf("%s %d", &s[0], &n);
	}

	rot(s, n);
	return 0;
}

void rot(char * voc, int n){
	int voclen, i, j;
	char *copia;
	
	voclen = strlen(voc);
	if(n<0 || n>voclen)
		return;
	if((copia = (char *)malloc(sizeof(char)*voclen))){
		strcpy(copia, voc);
		for(i=0; i<voclen-n; i++)
			*(voc+i+n) = *(copia+i);
		for(j=0; i<voclen; i++, j++)
			*(voc+j) = *(copia+i);
		printf("\n%s\n", &voc[0]);
	}
	return ;
}

