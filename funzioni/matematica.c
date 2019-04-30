#include <stdio.h>

int sommatoriaSemplice(int);
int coefficienteBinomiale(int, int);
int fibonacci(int);
int potenza(int, int);
float media(float[], int);
float mediana(float[], int);

int main(int argc, char * argv[]){
	float v[6];

	v[0] = 25;
	v[1] = 7;
	v[2] = 11;
	v[3] = 17;
	v[4] = 19;
	v[5] = 31;

	printf("%d\n", sommatoriaSemplice(37));
	printf("%d\n", coefficienteBinomiale(8, 4));
	printf("%d\n", fibonacci(139));
	printf("%d\n", potenza(2, 25));
	printf("%f\n", media(v, 6));
	printf("%f\n", mediana(v, 6));
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

float media(float values[], int len){
	int i;
	float p;
	for(i=0, p=0; i<len; i++)
		p+=values[i];
	p/=len;
	return p;
}

float mediana(float v[], int len){
	if(len == 1)
		return v[0];
	if(len%2)
		return v[len/2];
	return (v[len/2] + v[len/2-1]) / 2;
}
