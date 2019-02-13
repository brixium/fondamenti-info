/*
Scrivere un sottoprogramma che ricevuto in ingresso un array di interi e lo stretto indispensabile. In output TRASMETTE al chiamante l'indice del valore max e l'indice dell'elemnto con valore minimo.
*/
#include <stdio.h>
#define DIM 10
void maxminarray(int[], int, int *, int *);

int main(int argc, char * argv[]){
	int v[DIM], i;
	int posmax, posmin;
	for(i=0; i<DIM; i++)
		scanf("%d", &v[i]);
	maxminarray(v, DIM, &posmax, &posmin);/*&val modifica il valore*/
	printf("%d %d\n", posmax, posmin);
	return 0;
}

void maxminarray(int v[], int dim, int * pmax, int * pmin){ 
	/* int * indica l'indirizzo dell'intero */
	int i, imax, imin;
	imax = 0;
	imin = 0;
	for(i=0; i<dim; i++)
		if(v[i]<v[imin])
			imin = i;
		else if(v[i] > v[imax])
			imax = i;
	/*Trasmissione al chiamante*/
	*pmax = imax;
	*pmin = imin;
}
/*Cosa si fa in questi casi?
1) Faccio due sottoprogrammi? NO
2) Predisporre lo spazio in cui scrivere. Passare al chiamante la posizione di dove scrivere il valore. Strategia: farsi passare gli indirizzi. Non posso restituirne solo uno con la return.
La scanf fa questa cosa: si fa dire dove mettere il risultato

*/
