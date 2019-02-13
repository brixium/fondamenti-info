#include <stdio.h>
#define NUM 10

typedef struct punto_s{
	int x, y;
}punto_t;

void acquisisci(punto_t[], int);
void readp(punto_t *);
/*Sottoprogramam che acquisice i dati di NUM punti */

int main(int argc, char * argv[]){
	

	return 0;
}

void acquisisci(punto_t v[], int num, int dim){
	int i;
	for(i=0; i<dim; i++)
		scanf("%d,%d", &v[i].x, &v[i].y);
	return ;
}
void readp(punto_t * pt){
	do
		scanf("%d", &(*pt.x));
	while(*pt.x<0);
	do
		scanf("%d", &pt->y);
	while(pt->y<0);
}
/* readp(&v[i]) */
