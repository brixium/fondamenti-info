#include <stdio.h>
#define DIM 3
/*Sono riuscito a fuckuppare anche questa cosa che controlla se la matrice e un quadrato magico*/
int main(int argc, char * argv[]){
	int m[DIM][DIM], i, j, sum, ism, tot;
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM; j++)
			scanf("%d", &m[i][j]);
	}
	ism = 1;
	sum = 0;

	for(i=0; i<DIM; i++){
		sum = m[i][i];
	}
	for(i=0, tot=0; ism && i<DIM; i++)
		tot=m[i][DIM-1-i];
	if(tot!=sum)
		ism = 0;
	for(i=0; ism && i<DIM; i++){
		for(j=0, tot=0; j<DIM; j++)
			tot+=m[i][j];
		if(tot!=sum)
			ism = 0;
	}
	for(i=0; ism && i<DIM; i++){
		for(j=0, tot=0; j<DIM; j++)
			tot+=m[j][i];
		if(tot!=sum)
			ism=0;
	}
	printf("%d", ism);
	if(ism)
		printf("%d", sum);
	printf("\n");
	return 0;
}
