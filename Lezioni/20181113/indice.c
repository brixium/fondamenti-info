/*scrivere sottoprogramma che ricevuto in ingresso un array di interi e qualsiasi parametro ritenuto strettamente necessario restituisce al chiamante l'indice dell'elemento con valore massimo.*/
#include <stdio.h>
#define DIM 10
int indexmax(int, int);

int main(int argc, char * argv[]){
	int i, val[DIM];
	for(i=0; i<DIM; i++)
		scanf("%d", &val[i]);
	indexmax(val, DIM);
}

int indexmax(int values[], int dim){
	int imax, i;
	imax = 0;
	for(i=1; i<dim; i++)
		if(values[i]>values[imax]){
			imax = i;
	return imax;
}
