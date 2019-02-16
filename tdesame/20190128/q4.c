/*
Scrivere un sottoprogramma che riceve in ingresso un riferimento ad un file (già aperto) e legge un valore intero (se c’è ...) e restituisce la cifra del
valore letto che in esso compare più di frequente. Nel caso in cui non ci sia un valore, restituisce -1. Nel caso ci siano più cifre che compaiono lo
stesso numero di volte, restituisce quella più alta. Se per esempio legge il valore 217319 restituisce 1, se legge il valore 1002932 restituisce 2.
*/

#include <stdio.h>

#define BASE 10
#define STOP -1

int cifraFrequente(FILE *);

int main(int argc, char * argv[]){
	FILE * fp;
	char * nome;
	int ris;

	nome = argv[1];
	if((fp = fopen(nome, "r"))){
		ris = cifraFrequente(fp);
		while(ris != STOP){
			printf("%d\n", ris);
			ris = cifraFrequente(fp);
		}
		fclose(fp);
	}else
		printf("File non trovato!\n");
	return 0;
}

int cifraFrequente(FILE * fp){
	int val, cont[BASE], i, max;

	for(i=0; i<BASE; i++)
		cont[i] = 0;
	
	fscanf(fp, "%d", &val);
	if(!feof(fp)){
		while(val > 0){
			cont[val%BASE]++;
			val = val / BASE;
		}
		max = BASE-1;
		for(i=BASE-2; i>=0; i--)
			if(cont[i] > cont[max])
				max = i;
	}else
		max = -1;
	return max;
}
