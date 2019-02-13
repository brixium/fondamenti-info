#include <stdio.h>
#define N 3

int matid(int[][N], int);

int main(int argc, char * argv[]){
	int matrice[N][N], i, j, stampa;
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			scanf("%d", &matrice[i][j]);
	stampa = matid(matrice, N);
	printf("%d", stampa);
	return 0;
}
/*Se è identità return 1, else 0*/
int matid(int m[][N], int dim){
	int i, j;
	for(i=0; i<dim; i++)
		for(j=0; j<dim; j++)
			if((i==j && m[i][j]) || (i!=j && m[i][j]!=0))
				return 0;
	return 1;
}
