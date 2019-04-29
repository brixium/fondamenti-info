/*Realizzare un programma che calcola il coefficiente binomiale in modo ricorsivo di due numeri n>=k>=0 per forza così*/
#include <stdio.h>
int coeffBinRec(int, int);
int main(int argc, char * argv[]){
	int n, k;
	printf("Inserisci N e K in quest'ordine: ");
	scanf("%d %d", &n, &k);
	printf("%d\n", coeffBinRec(n,k));
	return 0;
}
int coeffBinRec(int n, int k){
	if(n == k)
		return 1;
	return coeffBinRec(n, k+1) * (k+1)/(n-k);
}
