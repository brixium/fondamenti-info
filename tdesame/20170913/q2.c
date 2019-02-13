#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define DIM 5
/*SI scriva un sottoprogrmma che ricevuto in ingresso un array x di valori interi ed un valore intero n e qualsiasi parametro ritenuto strettamente necessario trasmette al chiamante l'array di valori che costituiscono la varianza x calcolata su n campioni. L'elemento i-esimo della varianza viene calcolato come varianza degli n valori del vettore in ingresso che precedono ed includono l'elemento i. Se l'elemento i è preceduto da meno di n-1 valori, la varianza si calcola su quelli.*/

float * varianza(int [], int, int);
float * varianza3(int [], int, int);

int main(int argc, char * argv[]){
	int val[DIM], gap, i;
	float * risultato;
	gap = 3;
	
	/*init*/
	val[0] = 10;
	val[1] = 2;
	val[2] = 3;
	val[3] = 13;
	val[4] = 101;
	/*richiamo varianza*/
	risultato = varianza3(val, gap, DIM);
	/*stampa del ris*/
	for(i=0; i<DIM; i++)
		printf("%f ", *(risultato+i));
	printf("\n");
	return 0;
}

float * varianza3(int x[], int n, int dimx){
	/*Dichiarazione variabili*/
	float * varianza = NULL;
	float media, parz;
	int i, j, k;

	/*Ciclare per tutti i valori dell'array*/
	for(j=0; j<dimx; j++){
		/*Ciclare per una finestra di n numeri max*/
		media = 0;
		parz = 0;
		for(i=0; i<n; i++){
			/*Calcolo della media*/
			if(j<n){
				for(k=0; k<=j; k++)
					media = media + x[i];
				media = media / k;
				printf("Media: %f\n", media);
				/*Calcolo varianza per elemento j-esimo*/
				if((varianza = (float *)malloc(sizeof(float)))){
					for(k=0; k<j; k++){
						parz = parz + ((x[k] - media)*(x[k] - media));
					}
					parz = parz / k;
					*(varianza+k) = parz;
				}else
					printf("Errore allocazione memoria\n");
			}else{
				for(k=j-n; k<n; k++)
					media = media + x[i];
				media = media / n;
			}
			
		}
	}
	return varianza;
}
/*
float * varianza2(int x[], int n, int dimx){
	float * ret = NULL;
	int i, j, mpar;

	mpar = 0;
	for(j=0; j<dimx; j++){
		for(i=0; i<=n && i<=j; i++){
			if(n<j)
				div = n;
			else
				div = j;
			for(k=i; k<div; k++)
				mpar = mpar + x[k];
			ret[j] = ret[j] + (x[i] - (mpar/div) * (x[i] - (mpar/div) );
			
		}
		ret[j] = ret[j] / n;
	}
	return ret;
}/

float * varianza(int x[], int n, int dimx){
	int i, j, dim;
	float *ris, media, part;

	dim = dimx;
	media = x[0];
	part = 0;
	if((ris = (float *)malloc(sizeof(float)*dimx))){

		for(i=0; i<dim; i++){
			for(j=0; j<=i && j<n;j++){
				part = part + pow(x[j] - media, 2);
				printf("part: %f, i: %d, j: %d\n", part, i, j);
				if(i<3)
					media = part / (i+1);
				else
					media = part / n;
			}
			*(ris+i) = sqrt(part / (dim-1));
			part = 0.0;
			media = 0.0;
		}
		return ris;
	}else
		printf("Errore nell'allocazione di spazio heap");
	return NULL;
}
*/
