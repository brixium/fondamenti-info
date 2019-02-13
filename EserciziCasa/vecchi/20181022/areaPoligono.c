#include <stdio.h>
#define MAX 10
#define MIN 3
typedef struct vertex_s{
	int x; /*Coordinata x*/
	int y;	/*Coordinata y*/
} vertex_t;
int main(int argc, char * argv []){
	/*Dichiarazione var*/
	int numvertici, i, part;
	float area;
	vertex_t coord[MAX]; /*Poligono*/
	part = 0;
	/*Input valori*/
	do
		scanf("%d", &numvertici); /*N vertici*/
	while(!(numvertici >= MIN && numvertici <= MAX));

	for(i=0; i<numvertici; i++)
		scanf("%d %d", &coord[i].x, &coord[i].y ); /*Ins coord x & y*/
	
	/*Calcolo con formula di Gauss */
	for(i=0; i<numvertici; i++)
		part = part + (coord[i].x * (coord[(i+1)%numvertici].y) - (coord[(i+1)%numvertici].x * coord[i].y) ); /*inefficiente*/
	/*In questi casi fare 1 istruzione a parte*/
	/*
	for(i=1; i<num; i++){
		//istruzioni
	}
	
	*/
	if(part<0) /*Modulo*/
		part = part * -1; /*part = -part*/
	area = part / 2.0;
	printf("%f\n", area);

	return 0;
}

