/* scrivere un sottoprogramma cifra che riceve in ingresso due valori interi, num e k il sottoprogramma calcola e restituisce al chiamante la k-esima cifra da destra presente in num. Se questa cifra non esiste, restituire -1. Il numero num in ingresso è senz'altro positivo. */
#include <stdio.h>
#define BASE 10
int cifra(int, int);

int main(int argc, char * argv[]){
	int num, k, ris;
	do
		scanf("%d", &num);
	while(num<1);
	do
		scanf("%d", &k);
	while(k<1);
	ris = cifra(num, k);
	printf("%d\n", ris);
	return 0;
}

int cifra(int num, int k){
	int i, ret, check;
	i = 1;
	ret = num;
	check = 1;
	while(i<k && check){
		ret = ret / BASE;
		if(ret<=0)
			check = 0;
		i++;
	}
	if(check)
		ret = ret % BASE;
	else
		ret = -1;
	return ret;
}

