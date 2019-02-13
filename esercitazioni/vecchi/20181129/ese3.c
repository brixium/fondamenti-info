#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/*
	Scrivere sottoprogramma che dato in ingresso un array di numeri con dei duplicati restituisce un array senza duplicati.
*/
int * set(int [], int, int *);
int esiste(int [], int, int);

int main(int argc, char * argv[]){
	int v[DIM];
	int * ris;
	int len;
	/*init fatta da me, ma funzionante
	int i;
	for(i=0; i<DIM; i++)
		v[i] = 876%(i+2);
	Fine init*/	
	ris=set(v, DIM, &len);
	return 0;
}

int * set(int v[], int num, int * dim){
	int * tmp;
	int * ris;
	int ndiff, i;
	
	ndiff= 0;
	ris = NULL;

	if(tmp = (int *) malloc(num * sizeof(int))){
		for(i = 0; i<num; i++)
			if(!esiste(tmp, ndiff, v[i])){
				*(tmp + ndiff) = v[i];
				ndiff++;
			}
		if(ris = (int *) malloc(ndiff * sizeof(int)))
			for(i = 0; i<ndiff; i++)
				*(ris+i) =* (tmp+i);	/*Copio nel vettore ris di dim corretta le cose*/
		else
			printf("Errore in set in allocazione %d elementi", ndiff);
		free(tmp);
	}else
		printf("Errore su allocazione di %d elementi", num);
	* dim = ndiff;
	return ris;
}
int esiste(int v[], int size, int val){
	int i;
	for(i=0; i<size; i++)
		if(v[i]==val)
			return 1;
	return 0;
}
