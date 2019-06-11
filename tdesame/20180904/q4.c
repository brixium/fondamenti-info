/*
Scrivere un sottoprogramma che ricevuta in ingresso una matrice di valori interi e qualsiasi altro parametro ritenuto strettamente necessario, calcola e restituisce l’indice della riga in cui la massima differenza ottenuta tra due suoi elementi, sia massima.
Si ipotizzi che il numero di colonne della matrice sia definito tramite una direttiva define con il simbolo NCOL.
*/
#include <stdio.h>
#include <stdlib.h>

#define NROW 5
#define NCOL 5

int maxDiffRow(int[][NCOL], int, int);

int main(int argc, char * argv[]){
	int x, i, j, mat[NROW][NCOL];

	for(i=0; i<NROW; i++){
		for(j=0; j<NCOL; j++)
			scanf("%d", &mat[i][j]);
	}

	x = maxDiffRow(mat, NROW, NCOL);
	printf("%d\n", x);
	return 0;
}

int maxDiffRow(int val[][NCOL], int nr, int nc){
	int a, r, c, mdiff, d, rr;

	mdiff = 0;
	rr = 0;

	for(r=0; r<nr; r++){
		for(a=0; a<nc; a++){
			for(c=0; c<nc; c++){
				d = abs(val[r][a] - val[r][c]);
				if(mdiff < d){
					mdiff = d;
					rr = r;
				}
			}
		}
	}
	return rr;
}
