/* Esercizio 2:
 * tanti algoritmi di sorting, vedili un po'
 * Scrivere un sottoprogramam che ricevuta in ingresso una lista per la gestione di numeri interi
 * retstituisce tutti i numeri adiacenti uguali che hanno lo stesso valore vengono ridotti
	DEFINIZIONE DI TIPO
	possiamo utilizzare le funzioni push, pop, delete, ecc... a patto che ce le scriviamo dentro noi a manina perché non sono incluse nel testo

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * compatta(nodo_t *);

int main(int argc, char * argv[]){
	
	return 0;
}

nodo_t * compatta(nodo_t * h){
	nodo_t * tmp, *tbd;
	if(!h){
		for(tmp = h, tbd = tmp->next; tbd != NULL; tbd = tmp->next)
		if(tmp->val ==tbd->val){
			tmp->next = tbd->next;
			free(tbd);
		}else
			tmp = tmp->next;
	}
	return h;
}
