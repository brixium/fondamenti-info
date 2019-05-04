/*
Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione di numeri interi, restituisce la lista in modo tale che tutti gli elementi adiacenti uguali siano ridotti ad un solo elemento. Scrivere anche la definizione del tipo opportuno.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * collapse(nodo_t *);
/*Prototipi non richiesti*/
nodo_t * append(nodo_t *, int);
nodo_t * push(nodo_t *, int);
void freelist(nodo_t *);
void printlist(nodo_t *);

int main(int argc, char * argv[]){
	int n;
	nodo_t * lista = NULL;
	printf("Inserisci i numeri nella lista. (con 0 termini l'inserimento)\n");
	n = 1;
	while(n){
		scanf("%d", &n);
		lista = append(lista, n);
	}
	printf("Lista inserita:\n");
	printlist(lista);
	printf("Lista finale:\n");
	lista = collapse(lista);
	printlist(lista);
	return 0;
}

nodo_t * collapse(nodo_t * h){
	nodo_t * succ;
	nodo_t * now;
	nodo_t * e;
	for(now = h, succ = h->next; succ; now = now->next, succ = succ->next){
		if(now->val == succ->val){
			/*NON FUNZIONA QUELLO CHE HO SCRITTO QUI DENTRO*/
			e = succ->next;
			free(succ);
			now->next = e;
		}
	}
	return now;
}





/*metodi non richiesti*/
nodo_t * push(nodo_t * h, int v){
	nodo_t * ptr = NULL;
	if((ptr = (nodo_t *)malloc(sizeof(nodo_t)))){
		ptr->val = v;
		ptr->next = h;
	}else
		printf("No memoria\n");
	return ptr;
}

void freelist(nodo_t * h){
	nodo_t * ptr = NULL;
	while(h!=NULL){
		ptr = h;
		h = h->next;
		free(ptr);
	}
	return;
}

nodo_t * append(nodo_t * h, int v){
	nodo_t * ptr = NULL;
	nodo_t * e = NULL;
	if((e = (nodo_t *) malloc(sizeof(nodo_t)))){
		e->val = v;
		e->next = NULL;
		if(!h)
			h = e;
		else{
			for(ptr = h; ptr->next != NULL; ptr = ptr->next)
				;
			ptr->next = e;
		}
	}else
		printf("No memory\n");
	return h;
}

void printlist(nodo_t * h){
	nodo_t * ptr;
	for(ptr = h; ptr; ptr = ptr->next){
		printf("%d ", ptr->val);
	}
	printf("\n");
	return;
}
