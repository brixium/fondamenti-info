#include <stdio.h>

/* 
Scrivere un sottoprogramma _ricorsivo_ che ricevuti in ingresso due interi "n" e "k" con n≥k≥0 senz’altro, calcola e restituisce al chiamante il coefficiente binomiale

(n)      n!   
( ) = ________  (n>=k)
(k)   k!(n-k)! 

(n) (n-1)   (n-1)
( )=(   ) + (   )
(k) ( k )   (k-1)

*/
/*Prototipo della funzione coeffBinRec che è quella chiesta e poi della mia implementazione iterativa*/
int coeffBinRec(int, int);
int coeffBinIter(int, int);

int main(int argc, char * argv[]){
	printf("%d\n", coeffBinIter(9, 5));
	return 0;
}

int coeffBinRec(int n, int k){
	if(n == 1) /*Quindi n == k*/
		return 1;
	if(k == 1)
		return n;
	return n*coeffBinRec(n-1, k) / (coeffBinRec(n, k-1) * coeffBinRec()); /* <-NON FUNZONA*/
	
}
/*Quello iterativo funziona*/
int coeffBinIter(int n, int k){
	int num, denL, denR, i;

	if(n<0 || k<0 || n > 9 || k > 9)
		return -1;

	num = 1;
	for(i=0; i < n; i++)
		num = num * (i+1);
	denL = 1;
	for(i=0; i < k; i++)
		denL = denL * (i+1);
	denR = 1;
	for(i=0; i < n-k; i++)
		denR = denR * (i+1);

	return num/(denL*denR);
}
