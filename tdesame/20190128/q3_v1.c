/* 
6pt: Scrivere un sottoprogramma che visualizza tutti i numeri binari rappresentati da una stringa costituita dai valori '0','1' e 'x', dove le 'x' possono assumere valore sia 0, sia 1. Quindi, se il sottoprogramma riceve in ingresso la stringa 1x0 visualizza 100 e 110 (l’ordine non è importante). Scrivere un sottoprogramma genera che riceve in ingresso una stringa costituita esclusivamente di 0,1 e x (è senz’altro così) e visualizza tutti i numeri binari rappresentabili.
1pt: versione ricorsiva del sottoprogramma genera (è possibile aggiungere un eventuale parametro).
1pt: Scrivere un programma che acquisisce da riga di comando una stringa e chiama il sottoprogramma genera.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BASE 2
#define JOLLY 'x'

void genera(char[]);
void binario(int, char[], int);
int compatibile(char[], char[]);

int main(int argc, char * argv[]){
	char * mask;
	
	mask = argv[1];
	genera(mask);
	return 0;
}

void genera(char mask[]){
	int len, nmax, i;
	char * cod;

	len = strlen(mask);
	nmax = pow(BASE, len);
	if((cod = (char *)malloc(sizeof(char)*(len+1)))){
		for(i=0; i<nmax; i++){
			binario(i, cod, len+1);
			if(compatibile(cod, mask))
				printf("%s\n", cod);
		}
		free(cod);
	}else
		printf("Errore nell'allocazione di memoria");
	return;
}

void binario(int n, char bin[], int dim){
	int i;
	bin[dim-1] = '\0';
	for(i=dim-2; i>=0; i--){
		bin[i] = n % BASE + '0'; /*from int to char*/
		n = n / BASE;
	}
	return ;
}

int compatibile(char bin[], char mask[]){
	int i;

	for(i=0; bin[i] != '\0'; i++)
		if(mask[i] != JOLLY && mask[i] != bin[i])
			return 0;
	return 1;
}
