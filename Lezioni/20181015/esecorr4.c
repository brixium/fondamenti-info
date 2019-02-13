/* 
Scrivere un programma in C che chiede all’utente di inserire una sequenza di numeri interi terminata dallo 0 (lo 0 non fa parte della sequenza). Il programma ignora i valori negativi e valuta e stampa a video le coppie di numeri consecutivi che soddisfano tutte le condizioni che seguono:

    sono diversi tra di loro,
    sono entrambi numeri pari,
    il loro prodotto è un quadrato perfetto.
*/
#include <stdio.h>
#define STOP 0

int main(int argc, char * argv[]){
	int prec, last;
	int prod;
	int i, isq;
	
	do
		scanf("%d", &prec);
	while(prec <0);

	if(prec>0){
		scanf("%d", &last);
		while(last != STOP){
			if(last!=prec){
				if(last%2 == 0 && prec %2 == 0){
					prod = last * prec;
					i=2;
					isq = i*i;
					while(isq < prod){
						i++;
						isq = i*i;
					}
					if(isq == prod){
						printf("%d %d\n", prec, last);
					}
				}
			}
			prec = last;
			scanf("%d", &last);
		}		
	}
	return 0;
}
