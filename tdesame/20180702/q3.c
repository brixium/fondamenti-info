/*
Scrivere un sottoprogramma che ricevuto in ingresso un intero positivo conta e restituisce al chiamante il numero di cifre che compongono il numero in ingresso e ne sono divisori.
*/

#include <stdio.h>

#define BASE 10

int opera(int);

int main(int argc, char * argv[]){
	int val;
	scanf("%d", &val);
	printf("%d\n", opera(val));
	return 0;
}

int opera(int num){
	int ret, aux;
	if(num<0)
		return -1;
	ret = 0;
	aux = num;
	while(aux>0){
		if(aux%BASE != 0 && num%(aux%BASE) == 0)
			ret++;
		aux /=BASE;
	}
	return ret;
}
