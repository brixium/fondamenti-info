/*
	Mo'provo a fare qualcosa con le liste
	 - push
	 - pop
	 - delete
	 - [...]
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s{
	int val;
	struct nodo_s *next;
}nodo_t;

nodo_t * push(nodo_t * , int);
nodo_t * deleteByPos(nodo_t *, int);
void stampa(nodo_t *);
nodo_t * search(nodo_t *, int);
nodo_t * delete(nodo_t *, int);
nodo_t * append(nodo_t *, int);

int main(int argc, char * argv[]){
	int i;
	nodo_t * lista = NULL;

	for(i=0; i<20; i++)
		lista = push(lista, i);
	stampa(lista);
	printf("%d\n", search(lista, 5)->val);
	lista = delete(lista, 3);
	stampa(lista);
	return 0;
}

nodo_t * push(nodo_t * h, int num){
	nodo_t * ptr = NULL;
	if((ptr = (nodo_t *)malloc(sizeof(nodo_t)))){
		ptr->val = num;
		ptr->next = h;
	}
	return ptr;
}

void stampa(nodo_t * h){
	nodo_t * ptr = NULL;
	for(ptr = h; ptr; ptr = ptr->next)
		printf("%d ", ptr->val);
	printf("\n");
	return ;
}

nodo_t * search(nodo_t * h, int num){
	nodo_t * ptr = NULL;
	for(ptr = h; ptr !=NULL; ptr = ptr->next)
		if(ptr->val == num)
			return ptr;
	return NULL;
}

nodo_t * delete(nodo_t * h, int num){
	nodo_t *cur, *prev;
	
	for(cur = h, prev = NULL; cur!= NULL && cur->val != num; prev = cur, cur = cur->next)
		;
	if(cur == NULL)
		return h;
	if(prev == NULL)
		h = h->next;
	else
		prev->next = cur->next;
	free(cur);
	return h;
}

nodo_t * append(nodo_t * h, int n){
	nodo_t * ptr;
	nodo_t * e;
	if((e = (nodo_t *)malloc(sizeof(nodo_t)))){
		e->val = n;
		e->next = NULL;
		if(!h)
			h = e;
		else{
			for(ptr = h; ptr->next!=NULL; ptr = ptr->next)
				;
			ptr->next = e;
		}
	}else
		printf("Errore allocazione memoria in append");
	return h;
}

/*
nodo_t * deleteByPos(nodo_t * h, int num){
	nodo_t * ptr = NULL;
	int stop, i;
	stop = 0;
	for(ptr = h, i=0; ptr->next && !stop; ptr = ptr->next, i++)
		if(i==num){
			TODO: sostituire posizioni senza eliminare il percorso

			stop = 1;
		}
	return 0xCAFEBABE; anche qui non so cosa restituire
}
*/
