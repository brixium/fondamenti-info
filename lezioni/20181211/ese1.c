/*E1: Array ruotati
* Scrivere un programma che acquisisce i dati per popolare due array monodimensionali di 10 interi ciascuno. Il programma verifica quindi se, pur di fare uno scorrimento circolare del secondo array, i due array siano identici. Nello scorrimento circolare, la cifra che si trova in ultima posizione diventa quella in prima posizione dopo lo scorrimento. In caso affermativo il programma visualizza di quante posizioni deve essere fatto scorrere il secondo array verso destra. In caso negativo, visualizza -1. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10
int areEqual(int [], int [], int, int);

int main(int argc, char * argv[]){
	int v1[LEN], v2[LEN];
	int i;
	int rot;

	for(i=0; i<LEN; i++)
		scanf("%d", &v1[i]);
	
	for(i=0; i<LEN; i++)
		scanf("%d", &v2[i]);
	
	rot = -1;
	for(i=0; i<LEN && rot == -1; i++)
		if(areEqual(v1, v2, LEN, i))
			rot = i;
	printf("%d\n", rot);
	return 0;
}

int areEqual(int a1[], int a2[], int dim, int shift){
	int i;

	for(i=0; i<dim; i++)
		if(a1[(i+shift)%dim] != a2[i])
			return 0;
	return 1;
}

