#include <stdio.h>
#define DIM 5
typedef struct p {
    int x, y;
} punto_t;
/*
Si scriva un sottoprogramma che ricevuto in ingresso un array di tipo punto_t e qualsiasi altro parametro ritenuto strettamente necessario calcoli e restituisca al chiamante l'area del poligono i cui veritici sono i dati dell'array d'ingresso. Utilizzare la formula di Gauss per il calcolo dell'area.
*/
float areaPoligono(punto_t * pt[], int);
int main(int argc, char * argv[]){
	int i;
	punto_t arr[DIM];
	for(i=0; i<DIM; i++){
		scanf("%d", &arr[i].x);
		scanf("%d", &arr[i].y);
	}
	printf("%f", areaPoligono(&arr, DIM));	
	return 0;
}

float areaPoligono(punto_t *  pt[], int dim){
	float area;
	int i, somma;
	somma = 0;
	for(i=0; i<dim-1; i++)
		somma = somma + ((pt[i]->x) * (pt[i+1]->y));
	i++;
	somma = somma + ((pt[i]->x) * (pt[0]->y));
	for(; i>0; i--)
		somma = somma - ((pt[i+1]->x) * (pt[i]->y));
	i--;
	somma = somma - ((pt [0]->x) * (pt[i]->y));
	area = (float) somma / 2;
	return area;
}
