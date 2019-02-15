/* Si scriva un programma in C che acquisiti 100 valori interi ed un valore intero n calcola e visualizza l'array di valori che costituiscono la media mobile dei dati in ingresso di finestra n. L'elemento i-esimo della media mobile viene calcolato come media degli n valori del vettore in ingresso che precedono e includono l'elemento n. Se l'elemento n e preceduto da meno di n-1 valori, la media si calcola su quelli. */
#define DIMENSIONE 100

#include <stdio.h>
int main(int argc, char * argv[]){
	int vettore [DIMENSIONE];
    	float media[DIMENSIONE];
	int n, i, j;
    	for(i=0; i<DIMENSIONE; i++){ /* inizializzazione vettore */
        	vettore[i]=i;
        	media[i]=0;
    	}
	vettore[0] = 2;
	vettore[1] = 5;
	vettore[2] = -7;
	vettore[3] = 4;
	vettore[4] = 0;

	scanf("%d", &n);    /* acquisizione n */
	
	media[0] = 0;
	
	for(i=0; i<n; i++){ /* calcolo media */
        	for(j=0; j<=i; j++)
      			media[i] = media[i] + vettore[j];
        	media[i] = media [i] / (i+1);
	}
    	for(i=0;i<n; i++)   /* stampa media */
        	printf("%f\n", media[i]);
    	return 0;
}
