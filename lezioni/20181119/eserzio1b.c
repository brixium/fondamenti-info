#include <stdio.h>
/*Esercizio 1*/
#define STOP 1000
fillArray(int v[], int n){
	int i, val;
	i=0;
	scanf("%d", &val);
	while(val != STOP && i<n){
		v[i] = val;
		i++;
		scanf("%d", &val);
	}
	return i;
}
/*ES1: Altra sintassi*/
int fillArray(int * v, int n){
	int i, val;
	i=0;
	scanf("%d", &val);
	while(val!=STOP && i<n){
		*(v+i) = val;
	}
	return i;
}
/*
 * Esercizio1b
 */
void viewArrayBack(int v[], int num){
	int i;
	for(i = num-1; i>=0; i--)
		printf("%d ", v[i];
	return ;
}
/*
#define N 10

int fillArray(int [], int);
void viewArrayBack(int [], int);
int main(int argc, char * argv[]){
	int dati[N], dim;

	dim = fillArray(dati, N);
	viewArray(dati, dim);

	return 0;
}
*/


