#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NROW 3
#define NCOL 2
/*
Scrivere un sottoprogramma che ricevuta in ingresso una matrice di valori interi e qualsiasi altro parametro ritenuto strettamente necessario, calcola e restituisce l’indice della colonna in cui la massima differenza ottenuta tra due suoi elementi, sia massima.
Si ipotizzi che il numero di colonne della matrice sia definito tramite una direttiva define con il simbolo NCOL.
*/
int colIndex(int [][NCOL], int, int);

int main(int argc, char * argv[]){
	int num[NROW][NCOL] = {{5, 4}, {7, 13}, {2, 11}};
	int x = colIndex(num, NROW, NCOL);
	printf("%d\n", x);
	return 0;
}

int colIndex(int mat[][NCOL], int nrow, int ncol){
	int ind, i, j, k;
	int el1, el2, maxd;
	
	maxd = 0;
	ind = 0;
	for(i=0; i<ncol; i++){
		for(k=1; k<nrow; k++){
			el1 = mat[k-1][i];
			for(j=0; j<nrow; j++){
				el2 = mat[j][i];
				if(maxd < abs(el1-el2)){
					maxd = abs(el1-el2);
					ind = j;
				}
			}
		}
	}
	/*printf("%d ", maxd);*/
	return ind;
}

