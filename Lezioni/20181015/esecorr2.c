#include <stdio.h>
#define N 10
/* Si scriva un programma in C che acquisiti 100 valori interi ed un valore intero n calcola e visualizza l'array di valori che costituiscono la media mobile dei dati in ingresso di finestra n. L'elemento i-esimo della media mobile viene calcolato come media degli n valori del vettore in ingresso che precedono e includono l'elemento n. Se l'elemento n e preceduto da meno di n-1 valori, la media si calcola su quelli. */
int main(int argc, char * argv[]){
	int v[N], n;
	int i, j, tot;
	float m[N];
	
	for(i = 0; i<N; i++)
		scanf("%d", &v[i]);
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0, tot = 0; j<=i; j++)
			tot = tot + v[i];
		m[i] = (float) tot / j;
	}
	
	for(; i<N; i++){
		for(j=0, tot=0; j<n; j++)
			tot = tot+ v[i-j];
		m[i] = (float) tot / n;
	}
	for(i=0; i<N; i++)
		printf("%f", m[i]);
	printf("\n");
	return 0;
}
