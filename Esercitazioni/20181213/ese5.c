/*Scrivere un programma che acquisito un valore val non negativo visualizza tutti i valori nell'intervallo 0-val per cui vale la seguente relazione:

n-1             n-1
---             ---
\           k   \    3
/    a  * 10  = /   a
---   k         ---  k
K=0             k=0

dove ak = qualcosa
E obligatorio un sottoprogramma duecifre che ricevuto un valore x in ingresso trasmette un array di interi restituisce le singole cifre che compongono x
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

int * num2cifre(int, int *);

int main(int argc, char * argv[]){
	int n, val, *cifre, i, p10;
	int ndig, left, right;
	scanf("%d", &val);
	for(n=0; n<=val; n++){
		cifre = num2cifre(n, &ndig);
		for(i=ndig-1, left = 0, right = 0, p10 = 1; i>=0; i--, p10 = p10*10){
			left += cifre[i] * p10;
			right += pow(cifre[i], 3);
		}
		if(left == right)
			printf("%d\n" , n);
		free(cifre);/*memoria riempita di numeri*/
	}
	return 0;
}

int * num2cifre(int val, int * dim){
	int i, tmp, *v;
	
	tmp = val;
	for(i=0; tmp>0; i++)
		tmp = tmp/10;
	*dim = i;
	if(v = (int *) malloc(sizeof(int)*(*dim))){
		for(i=0; val>0; i++){
			*(v+i) = val%10;
			val = val/10;
		}
		for(i=0; i<(*dim)/2; i++){
			tmp = *(v+i);
			*(v+i) = *(v+ *dim-i-1);
			*(v+ *dim -i-1) = tmp;
		}
	}else
		printf("Errore nell'allocazione della memoria");
	return v;
}
