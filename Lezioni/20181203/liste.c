#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STOP 0
typedef struct nodo_s{
	int val;	 /*Elemento della lista*/
	struct nodo_s * next; /*Next è un indirizzo di una struttura nodo_s*/
}nodo_t;
/*
* Lunedì 3 dicembre 2018 
* lista dinamica
* Utente inserisce numeri (terminatore 0) e li stampa in reverse.
* Per le liste fare sempre una struct
* Nel main ci va sempre una testa di lista, ovvero il riferimento al primo elemento della lista., ovvero il riferimento al primo elemento della lista.
* All'inizio non esiste, per cui lo inizializziamo a NULL.
*/
nodo_t * push(nodo_t *, int);
nodo_t * append(nodo_t *, int);
int main(int argc, char * argv[]){
	nodo_t * head = NULL; /*È obbligatorio fare questa inizializzazione*/
	int n;
	nodo_t * elem;
	scanf("%d", &n);
		/* Piazzare elementi nella lista
		*  Lo scopo dell'esercizio è stampare gli elementi dall'ultimo al primo (LIFO)
		*  Quindi inserisco gli elementi in testa.
		*/
	while(n!=STOP){
		head = push(head, n);
		/* push		= inserisci in testa (di una lista)
		*  append	= inserisci in coda
		* 
		* TUTTE LE INTERFACCE DELLA LISTA CHE FACCIAMO ADESSO RICHIEDONO IN INGRESSO LA TESTA DELLA LISTA E LA RESTITUISCONO NELL'OUTPUT.
		*
		*/
		scanf("%d", &n);
	}
	elem = head;
	/*Punto al primo elemento*/
	while(elem!=NULL){
		/*printf("%d\t", *elem.val);*/
		/*Sta cosa si può anche scrivere come*/
		printf("%d\t", elem->val);
		/*elem = *elem.next;*/
		elem = elem->next;
	}
	/*
	* potevamo usare un for(elem=head; elem!=STOP; elem = elem->head)
		printf();
	*/
	freelist(head);
	/*Rilasciare la memoria*/
	return 0;
}

/* FUNZIONE per l'inserimento in testa: PUSH*/
nodo_t * push(nodo_t * h, int n){
	/*h è head*/
	nodo_t * e;
	/*Passo 0: creazione del nodo*/
	if(e=(nodo_t *) malloc(sizeof(nodo_t))){
		e->val = n;
		/*Passo 1: e guarda dove sta guardando h in questo istante*/
		e->next = h;
		/*Passo 2: la nuova testa è e*/
		h = e;
	}else
		printf("push: errore allocazione di %d\n", n);
	return h;
}
/*INSERIMENTO IN CODA: restituisce la testa della lista perché i*/
nodo_t * append(nodo_t * h, int n){
	nodo_t * e;
	nodo_t * ptr;
	if(e=(nodo_t *) malloc(sizeof(nodo_t))){
		e->val = n;
		e->next = NULL;
		if(!h)	/*oppure if(h==NULL)*/
			h = e;
		else{
			/*Passo 2)*/for(ptr=h; ptr->next!=NULL ;ptr=ptr->next)
				/*Passo 2: ciclare fino all'ultimo elemento buono*/
				;
			ptr->next = e;/* Passo 3: l'ultimo elemento è appeso all'ultimo esistente*/
		}
	}else
		printf("non va un cazzo, impiccati %d volte\n", n);
	return h;
}
