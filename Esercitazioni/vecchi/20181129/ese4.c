#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/*	Esercizio 4, allocazione dinamica
*	sottoprogramma che, dati in ingresso due vettori interi e ne restituisce l'intersezione
*
*	MI VA IN SEGFAULT, CONTROLLARE CODICE
*/
int * intersezione(int set1[], int n1, int set2[], int n2, int * dimint);
int main(int argc, char * argv[]){
	int v1[DIM], v2[DIM];
	int res;
	int set_size;
	int i;
	for(i=0; i<DIM; i++)
		scanf("%d", &v1[i]);
	/*Leggo v2*/
	for(i=0; i<DIM; i++)
		scanf("%d", &v2[i]);
	res = intersezione(v1, DIM, v2, DIM, &set_size);
	return 0;
}

int * intersezione(int set1[], int n1, int set2[], int n2, int * dimint){
	int * inter;
	int count;
	int i, j, found;
	count = 0;
	for(i=0; i<n1; i++){
		found = 0;
		for(j=0; j<n2 && found; j++)
			if(set1[i]==set2[j]){
				found = 1;
				count++;
			}
	}
	* dimint = count;
	if(inter = (int *) malloc(count * sizeof(int))){
		count = 0;
		for(i=0; i<n1; i++){
			found = 0;
			for(j=0; j<n1; i++)
				if(set1[i]==set2[j]){
					*(inter+count) = set1[i];
					count++;
				}
		}
	}else
		printf("Errore");

	return inter;
}
