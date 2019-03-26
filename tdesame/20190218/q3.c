/*
Scrivere un sottoprogramma che riceve in ingresso un array bidimensionale di interi mat, un intero val e qualsiasi parametro ritenuto strettamente
necessario e trasmette al chiamate gli indici di riga e colonna che identificano la posizione del primo elemento (scandendo l’array per righe) che,
sommato a tutti i suoi precedenti, dia come risultato un valore > val. Nel caso in cui tal elemento non esista, si trasmettono i valori -1, -1. Esiste
una direttiva #define NCOL 10
*/
#include <stdio.h>
#include <stdlib.h>

#define NROW 7 /*SOLO PER IL MAIN, NON USARE QUESTA INFORMAZIONE*/
#define NCOL 10

void indexOfVal(int[][NCOL], int, int, int, int *, int*);

int main(int argc, char * argv[]){
	int inva[NROW][NCOL], nr, nc, i ,j, *xcoor, *ycoor, valore;

	xcoor = NULL;
	ycoor = NULL;
	nr = NROW;
	nc = NCOL;
	valore = 9999;
	
	if((xcoor = (int *) malloc(sizeof(int))) && (ycoor = (int *) malloc(sizeof(int))) ){
		for(i=0; i<nr; i++)
			for(j=0; j<nc; j++)
				inva[i][j] = i+j;
		indexOfVal(inva, valore, nr, nc, xcoor, ycoor);
		printf("X: %d\nY: %d\n", *(xcoor), *(ycoor));

		free(ycoor);
		free(xcoor);
	}else
		printf("Troppa poca memoria libera sul dispositivo\n");
	return 0;
}

/*Parametri: matrice di interi, intero "valore", numero righe, numero colonne, indice posizione x, indice posizione y*/
void indexOfVal(int mat[][NCOL], int val, int nrow, int ncol, int * xindex, int * yindex){
	/*indice righe (i), colonne (j) e somma parziale dei valori della matrice*/
	int i, j, part;
	/*Somma parziale inizializzata a 0*/
	part = 0;
	/*Scorrimento dell'array*/
	for(i=0; i<nrow; i++)
		for(j=0; j<ncol; j++){
			/*Sommo i valori della matrice*/
			part = part + mat[i][j];
			/*Se il parziale della sommatoria supera il valore dato, allora trasmetto i valori degli indici ed esco dal sottoprogramma*/
			if(val<part){
				*xindex = i;
				*yindex = j;
				return ;
			}
		}
	/*Se non ho trovato nessun valore, trasmetto -1 e -1*/
	*xindex = -1;
	*yindex = -1;
	return ;
}
