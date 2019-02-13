/*Esercizio 1:
* esempio di tema d'esame
* questo prtrenbe capitarci
* primo problema: ordinare un array in ordine crescente
* la specifica 
* BUBBLE SORT
* 1) scambiare iterativamente gli elementi a coppie: se i due elementi sono decrescnti, allora li scambia
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 10

void swap(int *, int *);
void trueBubbleSort(int[], int);

int main(int argc, char * argv[]){
	int macello[DIM], i;
	for(i=0; i<DIM; i++)
		scanf("%d", &macello[i]);
	trueBubbleSort(macello, DIM);
	for(i=0; i<DIM; i++)
		printf("%d ", macello[i]);
	printf("\n");
	return 0;
}
/*Soluzione del prof*/
void swap(int * xp, int * yp){
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
	return ;
}

void trueBubbleSort(int arr[], int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=0; j<n-i-1; j++)
			if(arr[j]>arr[j+1])
				swap(&arr[j], &arr[j+1]);
	return ;
}
/*Fine soluzione del prof*/
