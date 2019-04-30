#include <stdio.h>

int sommatoriaSemplice(int);
int coefficienteBinomiale(int, int);
int fibonacci(int);
int potenza(int, int);

int main(int argc, char * argv[]){
	printf("%d\n", sommatoriaSemplice(37));
	printf("%d\n", coefficienteBinomiale(8, 4));
	printf("%d\n", fibonacci(139));
	printf("%d\n", potenza(2, 25));
	return 0;
}

int sommatoriaSemplice(int fine){
	return (fine+1)*fine/2;
}

int coefficienteBinomiale(int n, int k){
	if(n==k)
		return 1;
	return coefficienteBinomiale(n, k+1) * (k+1) / (n-k);
}

int fibonacci(int fin){
	int prev, cur, aux;
	cur = 1;
	prev = 0;
	while(cur < fin){
		printf("%d ",cur);
		aux = cur;
		cur = prev + cur;
		prev = aux;
	}
	return cur;
}

int potenza(int base, int exp){
	if(exp == 0)
		return 1;
	return potenza(base, exp-1) * base;
}

