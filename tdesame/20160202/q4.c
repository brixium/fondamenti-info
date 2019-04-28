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
/*Prototipo della funzione coeffBinRec che è quella chiesta. Non richieste le implementazioni iterative, ma svolte lo stesso*/
int coeffBinRec(int, int);
int coeffBinIter(int, int);
int coeffBinImproved(int, int);

int main(int argc, char * argv[]){
	int n, k;
	n = 16;
	k = 7;
	printf("N: %d; K: %d\n", n, k);
	printf("V. iterativa: %d\nV. iter. improved: %d\nV. ricorsiva: %d\n", coeffBinIter(n, k), coeffBinImproved(n,k), coeffBinRec(n,k));
	return 0;
}

int coeffBinRec(int n, int k){
	if(n == k)
		return 1;
	return coeffBinRec(n, k+1) * (k+1) / (n-k);
}

int coeffBinIter(int n, int k){
	int num, denL, denR, i;
	/*Condizioni di overflow*/
	if(n<0 || k<0 || n > 12 || k > 12)
		return -1;
	/*Condizioni speciali*/
	if((n-k == 1 && n>k) || (k==1) )
		return n;
	/*Condizioni normali*/
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

int coeffBinImproved(int n, int k){
	int diff, num, den, i;
	
	diff = n-k;
	if(diff < 0 || k<0 || n<0 || n>15)
		return -1;
	if(diff == 0)
		return 1;
	if(diff == 1 || k == 1)
		return n;
	den = 1;
	num = n;
	if(n/k <= 2){
		for(i=2; i <= diff; i++){
			den = den * i;
			num = num * (n-i+1);
		}
	}else{
		for(i=k; i >= 2; i--){
			num = num * (n-i+1);
			den = den * i;
		}
	}
	return num/den;
}
