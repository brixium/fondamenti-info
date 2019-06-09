/*
Scrivere un sottoprogramma in C selectitems che ricevuta in ingresso una lista per la gestione di valori interi e due interi min e max crea una nuova lista contente tutti e soli i valori presenti nella lista di ingresso strettamente non compresi tra min e max, ordinati in modo decrescente, e la restituisce al chiamante.
La lista di partenza non deve essere modificata.
Si considerino come dati i sottoprogrammi i cui prototipi sono riportati nel seguito. Scrivere la dichiarazione del tipo della lista.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem_s{
	int val;
	struct elem_s * next;
}elem;

/*inserisce l’elemento specificato in coda*/
elem* append(elem*, int);
/*inserisce l’elemento specificato in testa*/
elem* push(elem*, int);
/*inserisce l’elemento specificato in ordine crescente*/
elem* insertup(elem*, int);
/*inserisce l’elemento specificato in ordine decrescente*/
elem* insertdown(elem*, int);
/*rimuove la prima occorrenza dell’elemento specificato*/
elem* delete(elem*, int);
/*visualizza la lista*/
void view(elem*);
/*distrugge la lista*/
elem* destroy(elem*);
/*restituisce 1 se l’elemento e’ presente nella lista, altrimenti 0*/
int exists(elem*, int);

elem * selectitem(elem * h, int min, int max){
	elem * lista = NULL;
	elem * ptr;
	
	for(ptr=h; ptr; ptr=ptr->next){
		if(ptr->val < min || ptr->val > max){
			lista = insertdown(lista, ptr->val);
		}
	}
	return lista;
}
