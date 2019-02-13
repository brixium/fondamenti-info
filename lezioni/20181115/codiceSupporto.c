#include <stdio.h>
#define NR 2
#define NC 3
#define N 10
typedef struct p{
	int x, y;
}punto_t;
/**/

int main(int argc, char * argv[]){
	int m[NR][NC];
	punto_t elem;
	punto_t vettore[N];
	elem.x=0;
	elem.y=9;
	for(i=0; i<N; i++){
		vettore[i].x = 0;
		vettore[i].y = 1;
	}

	return 0;
}

int f(int v[], int dim, int * ns){
	int ret;
	
	return ret;
}

int fbid(int m, int nrighe, int ncolonne){

	return 0;
}

int prova(punto_t v[], int dim){
	int i;
	for(i=0; i<dim; i++){
		v[i].x = 0;
		v[i].y = 1;
	}
	return 0;
}

int foo(punto_t * var){
	* var.x = 0;
	* var.y = 1;
	/*Questa cosa si può anche scrivere come*/
	var -> x = 0;
	var -> y = 1;

}
/**
