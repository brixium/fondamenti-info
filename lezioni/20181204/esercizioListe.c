/*
* Scrivere un sottoprogramma che ricevuta in ingresso una lista (si intende la testa) restituisce la lista in cui gli elementi sono in ordine inverso.
*/
#include <stdio.h>
#include <stdlib.h>
#define STOP 0
typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * revList(nodo_t *);
nodo_t * push(nodo_t *, int);
nodo_t * append(nodo_t *, int);
nodo_t * pushnoalloc(nodo_t *, nodo_t *);
nodo_t * invertiLista(nodo_t *);
nodo_t * belowArray(int v[], int);
nodo_t * intersezione(nodo_t *, nodo_t *);
nodo_t * exist(nodo_t *, int);
int sublist(nodo_t *, nodo_t *);

int main(int argc, char * argv[]){
	nodo_t * head = NULL;
	int n;
	nodo_t * elem;
	scanf("%d", &n);
	while(n!=STOP){
		head = push(head, n);
		scanf("%d", &n);
	}
	elem = head;
	while(elem!=NULL){
		printf("%d\t", elem->val);
		elem = elem->next;
	}
	freelist(head);
	return 0;
}

nodo_t * push(nodo_t * h, int n){
	nodo_t * e;
	if(e=(nodo_t *) malloc(sizeof(nodo_t))){
		e->val = n;
		e->next = h;
		h = e;
	}else
		printf("push: errore allocazione di %d\n", n);
	return h;
}

nodo_t * append(nodo_t * h, int n){
	nodo_t * e;
	nodo_t * ptr;
	if(e=(nodo_t *) malloc(sizeof(nodo_t))){
		e->val = n;
		e->next = NULL;
		if(!h)
			h = e;
		else{
			for(ptr=h; ptr->next!=NULL ;ptr=ptr->next)
				;
			ptr->next = e;
		}
	}else
		printf("non va un cazzo, impiccati %d volte\n", n);
	return h;
}
/*Per ogni elemento della lista originale faccio un inserimento in testa in una nuova lista*/
nodo_t * revList(nodo_t * h){
	nodo_t * hnuova = NULL;
	nodo_t * ptr; /*Var per scandire la lista*/
	for(ptr=h; ptr ;ptr=ptr->next)
		hnuova = push(hnuova, ptr->val);
	freelist(h);
	return hnuova;
}
/*Facciamo una push senza allocazione di memoria: bisogna solo sistemare i riferimenti*/
nodo_t * pushnoalloc(nodo_t * h, nodo_t * e){
	e->next = h;
	
	return e;
}
nodo_t * invertiLista(nodo_t * h){
	nodo_t * hnuova = NULL;
	nodo_t * ptr;
	
	ptr = h;
	while(ptr){
		h = h->next; /*1*/
		hnuova = pushnoalloc(hnuova, ptr);
		ptr = h;
	}
	/*
	* Si può anche scrivere con un for quanto scritto 7 righe prima + il while

	for(ptr=h; ptr; ptr=h){
		h=h->next;
		hnuova = pushnoalloc(hnuova, ptr);
	}
	* è un po'più efficiente
	*/
	return hnuova;
}
nodo_t * invertiLista2b(nodo_t * h){
	nodo_t * hnuova=NULL;
	nodo_t * ptr;
	ptr=h;
	while(ptr){
		h=h->next;
		ptr->next = hnuova;
		hnuova = ptr;
		ptr = h;
	}
	return hnuova;
	/*
	* Più efficiente ma più rischiosa.
	* Ai fini dell'esame, non rischiare.
	*/
}
nodo_t * unione(nodo_t * h1, nodo_t * h2){
	nodo_t * unione=NULL;
	nodo_t * ptr;
	for(ptr = h1; ptr; ptr=ptr->next)
		unione = append(unione, ptr->val);
	/*per ogni elemento di s2 se non esisite in s1 quellelemento lo aggiungo in s unione*/
	for(ptr = h2; ptr; ptr = ptr->next)
		if(!exist(h1, ptr->val))
			push(unione, ptr);
	return unione;
}

nodo_t * exist(nodo_t * h, int val){
	nodo_t * ptr;
	for(ptr = h; ptr; ptr = ptr->next)
		if(ptr->val == num)
			return ptr;
	return NULL;
	/*
	* verisione 2
	while(h){
		if(h->val==num)
			return h;
		h=h->next;
	}
	return NULL;
	*/
}
/*SOTTOMARCA*/
/*
* ESERCIZIO PROPOSTO: fare sottoprogramma che restituisce l'insieme intersezione
*/
nodo_t * intersezione(nodo_t * h1, nodo_t * h2){
	nodo_t * inter = NULL;
	nodo_t * ptr;
	
	return inter;
}
/* Scrivere un sottoprogramma che riceve in ingresso un array di valori interi e qualsiasi altro parametro ritenuto strettamente necessario e restituisce tutti e soli i valori dell'array che sono minori o uguali alla media dei valori contenuti nell'array stesso. (Utilizzare la lista).*/
nodo_t * belowArray(int v[], int dim){
	nodo_t * h = NULL;
	int tot, i;
	float avg;
	tot = 0;
	for(i=0; i<dim; i++)
		tot = tot + v[i];
	if(dim>0)
		avg = (float)tot/dim;
	for(i=0; i<dim; i++)
		if(i[i]<=avg)
			h = append(h, v[i]);
	return h;
}

/*
* Scrivere il programma sublist che richiede in ingresso due liste di n interi, restituisce 1 se una delle due liste è contenuta nell'altra, 0 altrimenti. Se una lista è vuota, senz'altro restutisce 1.
* Stessi elementi e stesso ordine
*/
int sublist(nodo_t * s1, nodo_t * s2){
	int l1, l2, diff, found;
	nodo_t * ptrs, ptrl;
	nodo_t * llong, *lshort;
	nodo_t * start;

	if(!h1||!h2)
		return 1;
	l1 = listlen(h1); /*Non esiste il sottoprogramma ma ce lo inventeremo*/
	l2 = listlen(h2);
	if(l1>l2){
		llong = h1;
		lshort = h2;
		diff = l1 - l2;
	}else{
		llong = h2;
		lshort = h1;
		diff = l1 - l1;
	}
	start = llong;
	found = 0;
	while(llong){
		ptrl = llong;
		ptrs = lshort;
		while(ptrl && ptrl->val != ptrs->val)
			ptrl = ptrl->next;
		start = ptr->next;
		while(ptrl && ptrs && ptrl->val == ptrs->val){
			ptrl = ptrl->next;
			ptrs = ptrs->next;
		}
		/*But I still haven't found what I'm looking for*/
		if(!((ptrs && ptrl && ptrs->val != ptrl->val) || (ptrs && !ptrl)))
			return 1;
		ptrs = lshort;
	}
	return 0;
}
