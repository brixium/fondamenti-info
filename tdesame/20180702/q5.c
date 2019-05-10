/*DISCLAIMER: QUESTO PROGRAMMA NON È STATO NÉ COMPILATO NÉ TESTATO E PERTANTO POTREBBE NON FUNZIONARE, ANCHE PERCHÉ MANCA IL CODICE DELLA FUNZIONE INSERTUP CHE INSERISCE L'ELEMENTO IN ORDINE CRESCENTE IN UNA LISTA*/

/*
Scrivere un sottoprogramma in C selectitems che ricevuta in ingresso una lista per la gestione di valori interi e due interi min e max crea una nuova lista contente tutti e soli i valori presenti nella lista di ingresso strettamente compresi tra min e max, ordinati in modo crescente e la restituisce al chiamante. La lista di partenza non deve essere modificata. Si considerino dati i sottoprogrammi i cui prototipi sono riportati nel seguito.
*/

#include <stdio.h>
#include <stdlib.h>

#define MIN 3
#define MAX 17

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * selectitems(nodo_t *, int, int);
nodo_t * insertup(nodo_t *, int);
nodo_t * push(nodo_t *, int);
void printlist(nodo_t *);

int main(int argc, char * argv[]){
	nodo_t * lista = NULL;
	int n, i;
	for(i=0; i<7; i++){
		scanf("%d", &n);
		lista = push(lista, n);
	}
	printlist(lista);
	lista = selectitems(lista, MIN, MAX);
	printlist(lista);
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

nodo_t * insertup(nodo_t * h, int num){
	nodo_t * e;
	nodo_t * cur, *last;

	if((e=malloc(sizeof(nodo_t)))){
		e->val = num;
		e->next = NULL;
		if(!h)
			return e;
		for(last = NULL, cur = h; cur; last = cur, cur = cur->next){
			if(cur->val > num){
				if(last){
					last->next = e;
					e->next = cur;
					return h;
				}else{
					e->next = cur;
					return e;
				}
			}
		}
		last->next = e;
	}else
		printf("No memory\n");
	return h;
}

nodo_t * push(nodo_t * h, int num){
	nodo_t * ptr = NULL;
	
	if((ptr = malloc(sizeof(nodo_t)))){
		ptr->val = num;
		ptr->next = h;
		return ptr;
	}
	printf("No memory\n");
	return h;
}

void printlist(nodo_t * h){
	nodo_t * ptr;
	for(ptr = h; ptr; ptr = ptr->next)
		printf("%d ", ptr->val);
	printf("\n");
	return;
}
