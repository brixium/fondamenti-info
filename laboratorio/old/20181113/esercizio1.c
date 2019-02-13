/*
1)Numero dei fattori - input: n>0; output: numero di fattori primi che lo compongono
2)Tabella numero di fattori - in: n>0; out: 
3)Indice massimo di un array - in: array di interi, dim; out: index max value
4)Numero magico - in: integer array; out: last digit del numero dei divisori propri del prodotto dell'array in input
5)Numeri perfetti
6)Campionato di calcio
*/
#include <stdio.h>
#define DIM 10
#define MAT_DIM 5
/*PROTOTIPI*/
int numeroFattori(int);
void tabellaNumeroFattori(int);
int imaxArray(int[], int);
int magicNumber(int[], int);

int main(int argc, char * argv[]){
	int i, num, array[DIM], choice;
	do{
		printf("[0] ESCI\n[1] Numero fattori\n[2] Tabella Numero fattori\n[3] Max index array\n[4] Magic Number\n");
		scanf("%d", &choice);
		if(choice==1){
			scanf("%d", &num);
			printf("%d\n", numeroFattori(num));
		}else if(choice==2){
			scanf("%d", &num);
			tabellaNumeroFattori(num);
		}else if(choice==3){
			for(i=0; i<DIM; i++)
				scanf("%d", &array[i]);
			printf("%d\n", imaxArray(array, DIM));
		}else if(choice==4){
			for(i=0; i<DIM; i++)
				scanf("%d", &array[i]);
			printf("%d\n", magicNumber(array, DIM));
		}else
			choice = 0;
	}while(choice!=0);
	
	/*
	printf("%d\n", numeroFattori(num));
	tabellaNumeroFattori(num);
	
	printf("%d\n", imaxArray(array, DIM));
	printf("%d\n", magicNumber(array, DIM));
	
	perfectNumbers(MAT_DIM);
	*/
	return 0;
}
/*E1*/
int numeroFattori(int num){
	int nfattori, div;
	nfattori=0;
	div = 2;
	while(num>1){
		if(num%div==0){
			num = num / div;
			nfattori++;
		}
		else{
			div++;
		}
	}
	return nfattori;
}
/*E2*/
void tabellaNumeroFattori(int n){
	int current;
	current = 1;
	while(current<=n){
		printf("%d %d\n", current, numeroFattori(current));
		current++;
	}
}
/*E3*/
int imaxArray(int num[], int dim){
	int imax, i;
	imax = 0;
	for(i=0; i<dim; i++)
		if(num[i]>num[imax])
			imax = i;
	return imax;
}
/*E4*/
int magicNumber(int num[], int dim){
	int ret, i, prodotto;
	ret = 1;
	i=0;
	prodotto = 1;
	for(i=0; i<dim; i++)
		prodotto = prodotto * num[i];
	if(prodotto<0)
		prodotto =  -prodotto;
	i=2;
	while((prodotto/2)>=i){
		if(prodotto%i==0)
			ret++;
		i++;
	}
	return ret%10;
}
/*E5*/
/*E6*/
/*Svolgo gli es.5 e 6 su due file diversi*/
