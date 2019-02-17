/*DISCLAIMER: QUESTO PROGRAMMA NON È STATO NÉ COMPILATO NÉ TESTATO E PERTANTO POTREBBE NON FUNZIONARE, ANCHE PERCHÉ MANCA IL CODICE DELLA FUNZIONE INSERTUP CHE INSERISCE L'ELEMENTO IN ORDINE CRESCENTE IN UNA LISTA*/

/*
Scrivere un sottoprogramma in C selectitems che ricevuta in ingresso una lista per la gestione di valori interi e due interi min e max crea una nuova lista contente tutti e soli i valori presenti nella lista di ingresso strettamente compresi tra min e max, ordinati in modo crescente e la restituisce al chiamante. La lista di partenza non deve essere modificata. Si considerino dati i sottoprogrammi i cui prototipi sono riportati nel seguito.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * selectitems(nodo_t *, int, int);
nodo_t * insertup(nodo_t *, int);
int main(int argc, char * argv[]){
	
	return 0;
}

nodo_t * selectitems(nodo_t * h, int min, int max){
	nodo_t * ptr = NULL;
	nodo_t * fin = NULL;
	for(ptr = h; ptr; ptr = ptr->next)
		if(ptr->val < max && ptr->val > min)
			fin = insertup(fin, ptr->val);
	return fin;
}
