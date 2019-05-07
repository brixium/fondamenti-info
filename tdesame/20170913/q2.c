#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define DIM 5

/*Si scriva un sottoprogramma che ricevuto in ingresso un array x di valori interi ed un valore intero n e qualsiasi parametro ritenuto strettamente necessario trasmette al chiamante l'array di valori che costituiscono la varianza x calcolata su n campioni. L'elemento i-esimo della varianza viene calcolato come varianza degli n valori del vettore in ingresso che precedono ed includono l'elemento i. Se l'elemento i è preceduto da meno di n-1 valori, la varianza si calcola su quelli.*/

/*varianza riceve: array di valori interi, dimensione finestra n (intero), dimensione array (int), riferimento in memoria a varianza (1 array di float)*/
void varianza(int[], int, int, float ** v);

int main(int argc, char * argv[]){
	int val[DIM], n, dimx;
	float * verza;
	
	int i;
	verza = malloc(sizeof(float)*DIM);
	val[0] = 7;
	val[1] = 5;
	val[2] = 8;
	val[3] = 4;
	val[4] = 6;
	n = 3;
	dimx = DIM;
	
	varianza(val, n, dimx, &verza);

	for(i=0; i<DIM; i++)
		printf("%f; ", *(verza+i));
	printf("\n");
	return 0;
}

void varianza(int x[], int n, int dimx, float ** varia){
	int i, j, startpt;
	float media, somma;
	
	for(i=0; i<dimx; i++){
		/*Qui decido il punto di partenza del ciclo per la somma delle medie*/
		if(i+1-n > 0)
			startpt = i+1-n;
		else
			startpt = 0;
		/*Calcolo delle medie*/
		media = 0;
		for(j=startpt; j<=i; j++)
			media = media+x[j];
		media = media / (j-startpt);
		/*qua si calcola la varianza*/
		somma = 0;
		for(j=startpt; j<=i; j++)
			somma = somma + pow(x[j]-media, 2);
		somma = somma / (j-startpt);
		*(*varia+i) = somma;
	}
}
