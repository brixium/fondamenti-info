#include <stdio.h>
#define DIM 6
/*
Scrivere un sottoprogramma viewArrayBack che ricevuto in ingresso un array di valori interi e qualsiasi altro parametro ritenuto strettamente necessario visualizzi il contenuto dell'array a partire dall'ultimo elemento fino al primo.
*/
void viewArrayBack(int [], int);
int main(int argc, char * argv[]){
	int i, values[DIM];
	for(i=0; i<DIM; i++)
		values[i]=i;
	viewArrayBack(values, DIM);
	return 0;
}

void viewArrayBack(int val[], int dim){
	int i;
	for(i=dim-1; i>=0; i--)
		printf("%d ", val[i]);
	printf("\n");
	return ;
}
