/*Acquisire i dati di due insiemi di numeri interi, ciascuno di 25 elementi (insiemi propri*/
/*Il programma calcola l'insieme unione e l'intersezione e li visualizza*/
#include <stdio.h>
#define DIM 25
int main(int argc, char * argv[]){
	int ins1[DIM], ins2[DIM], uni[DIM*2], inte[DIM], i, j, indU, indI, check;
	/*Scan*/
	indU = 0;
	indI = 0;
	check= 1;
	for(i=0; i<DIM; i++)
		scanf("%d", &ins1[i]);
	for(i=0; i<DIM; i++)
		scanf("%d", &ins2[i]);
	/*Intersezione*/
	for(i=0; i<DIM; i++)
		for(j=0; j<DIM; j++)
			if(ins1[i]==ins2[j]){
				inte[indI]=ins1[i];
				indI++;
			}
	/*Unione*/
	for(i=0; i<DIM; i++){
		uni[i]=ins1[i];
		indU++;
	}
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM && check; j++){
			if(ins2[i] == uni[j])
				check = 0;
		}
		if(check){
			uni[indU] = ins2[i];
			indU++;
		}
		check=1;	
	}
	/*View*/
	for(i=0; i<indU; i++)
		printf("%d ", uni[i]);
	printf("\n");
	
	for(i=0; i<indI; i++)
		printf("%d ", inte[i]);
	printf("\n");
	return 0;
}

