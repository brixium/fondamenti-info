#include <stdio.h>

int sommaSemplice(int);
int coefficienteBinomiale(int, int);

int main(int argc, char * argv[]){
	printf("%d\n", sommaSemplice(37));
	printf("%d\n", coefficienteBinomiale(8, 4));
	return 0;
}

int sommaSemplice(int fine){
	return (fine+1)*fine/2;
}

int coefficienteBinomiale(int n, int k){
	if(n==k)
		return 1;
	return coefficienteBinomiale(n, k+1) * (k+1) / (n-k);
}
