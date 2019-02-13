/*
* Esercizio 4
ricevuti in ingresso due array bidimensionali e un valore k ecc..., copia nel secondo array in posizione identica tutti i valori 0 e tutti i valori positivi che sono divisibili per k.
*/
#include <stdio.h>
#define NCOL 10
#define NPO 7
int main(int argc, char * argv[]){
	int start[NPO][NCOL], finish[NPO][NCOL];
	int sel, i, j;
	
	for(i=0; i<NPO; i++)
		
	return 0;
}

void modArrayB(int src[][NCOL], int dst[][NCOL], int nr, int nc, int k){
	int i, j;

	for(i=0; i<nr; i++)
		for(j=0; j<nc; j++)
			if(src[i][j] == 0 || (src[i][j] > 0 && ((k && src[i][j] % k == 0) || k % src[i][j] == 0))) /*Se k può essere 0 abbiamo aggiunto k && alla colonna 45*/
				dst[i][j] = src[i][j];
}
