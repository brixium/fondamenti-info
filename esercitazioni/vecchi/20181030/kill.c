/*
	Data in input una matrice dimensione 10x10. Ogni valore è compreso tra 1 e 10
	Stampare la frequenza di ogni valore e stampare quello che compare più volte.

*/
#include <stdio.h>
#define DIM 10

int main(int argc, char * argv[]){
	int max, i, j, m[DIM][DIM], num[DIM];
	for(i=0; i<DIM; i++)
		num[i] = 0;
	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++){
			do
				scanf("%d", &m[i][j]);
			while(m[i][j]<1 || m[i][j]>10);
			num[m[i][j]-1]++;
		}
	max=num[0];
	for(i=0; i<DIM; i++){
		printf("%d : %d\n", i+1, num[i]);
		if(max<num[i])
			max = i+1;
	}
	printf("%d\n", max);
	return 0;
}
