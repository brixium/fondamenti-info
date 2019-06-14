/*
Scrivere un programma che acquisisce i dati di un array di 25 valori interi. Una volta terminata l’acquisizione, il programma calcola e visualizza il massimo del prodotto di tre valori presenti nell’array. L’array, una volta acquisito, non deve essere modificato.
*/

#include <stdio.h>

#define DIMARR 25
#define NP 3
int main(int argc, char * argv[]){
	int val[DIMARR], i, j, low;
	int pr[NP];

	for(i=0; i<25; i++){
		scanf("%d", &val[i]);
		if(i<NP){
			pr[i] = val[i];
			if(!i)
				low = i;
			else if(val[i]<pr[low])
				low = i;
		}else{
			for(j=0; j<NP; j++)
				if(pr[j] < pr[low])
					low = j;
			if(pr[low] < val[i])
				pr[low] = val[i];
		}
	}
	/*
	printf("Array: ");
	for(i=0; i<DIMARR; i++)
		printf("%d ", val[i]);
	printf("\n");
	for(i=0; i<NP; i++)
		printf("%d ", pr[i]);
	printf("\n");*/
	j=1;
	for(i=0; i<NP; i++)
		j=j*pr[i];
	printf("%d\n", j);
	return 0;
}
