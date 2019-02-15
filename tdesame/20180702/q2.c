/*
Scrivere un sottoprogramma che ricevuta in ingresso una stringa la modifica in modo tale che la stringa finale sia quella iniziale, fatta scorrere a
sinistra di una posizione, con il carattere riportato in coda. Se per esempio la stringa iniziale è Esempio, la stringa finale sarà sempioE.
*/
#include <stdio.h>
#include <string.h>

#define DIM 10

void cambioPosto(char *);

int main(int argc, char * argv[]){
	char val[DIM+1];
	scanf("%s", &val[0]);
	cambioPosto(val);

	printf("%s\n", val);
	return 0;
}

void cambioPosto(char * val){
	int i, slen;
	char swap;

	slen = strlen(val);
	swap = *(val);
	for(i=1; i<slen; i++)
		*(val+i-1) = *(val+i);
	*(val+i-1) = swap;

	return ;
}
