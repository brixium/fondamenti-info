#include <stdio.h>
/*
*	Esercizio 2: 
*	i numeri di Catalan sono una successione 
*	C0= 1; Cn è la sommatoria da i=0 a n-1 di Ci*C(n-i-1)
*	Scrivere il programma che dato n, restituisce i primi x+1 valori. catN(); . Richiedere anche x che è quelli che devo stampare.
*	
*/
int catN(int);
int main(int argc, char * argv[]){
	int i,n;
	do
		scanf("%d", &n);
	while(n<0);
	for(i=0; i<n; i++)
		printf("%d\t", catN(i));
	printf("\n");
	return 0;
}

int catN(int n){
	int i, sum;
	if(n==0)
		return 1;
	for(sum = 0, i = 0; i<n; i++)
		sum += catN(i)*catN(n-1-i);
	return sum;
	
}
