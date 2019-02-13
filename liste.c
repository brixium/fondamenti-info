/*Voglio fare dei sottoprogrammi che lavorano con le liste*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * push2(nodo_t *, int);
nodo_t * pushInTesta(nodo_t *, int);
nodo_t * append(nodo_t *, int);
void stampa(nodo_t *);
nodo_t * pop(nodo_t **);

int main(int argc, char * argv[]){
	nodo_t * testa=NULL;
	int numins, i;
	numins=20;
	
	for(i=0; i<numins; i++)
		testa = append(testa, i);
	pop(&testa);
	stampa(testa);
	return 0;
}
/*void stampa FUNZIONA*/
void stampa(nodo_t * h){
	nodo_t * ptr = NULL;
	for(ptr = h; ptr; ptr= ptr->next)
		printf("%d ", ptr->val);
	printf("\n");
	return ;
}

nodo_t * push2(nodo_t * h, int num){
	nodo_t * ptr;
	int addr;
	addr = &h;
	/*printf("%d", addr);*/
	for(ptr=h; ptr; ptr=ptr->next)
		;
	if((ptr = (nodo_t *) malloc(sizeof(nodo_t)))){
		ptr->val = num;
		ptr->next = NULL;
	}
	return ptr;
}

/*pushInTesta: FUNZIONA*/
nodo_t * pushInTesta(nodo_t * h, int num){
	nodo_t * ptr = NULL;
	if((ptr = (nodo_t *) malloc(sizeof(nodo_t)))){
		ptr->val = num;
		ptr->next = h;
	}
	return ptr;
}
/*Append*/
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

nodo_t * pop(nodo_t **  h){
	nodo_t * ptr = NULL;
	if(!(h))
		return NULL;
	ptr = * h;
	* h = (*h)->next;
	return ptr;
}
/*
nodo_t * append(nodo_t * h, int num){
	nodo_t * temp=NULL;
	temp->val = num;
	temp->next = NULL;
	if((temp = (nodo_t *) malloc(sizeof(nodo_t)))){
		if(!h){
			h = temp;
			h->next = NULL;
		}else{
			nodo_t * ptr = h;
			while(ptr->next!= NULL)
				ptr = ptr->next;
			(ptr->next) = temp;
			temp->next = NULL;
		}
	}else{
		printf("Errore in allocazione della memoria\n");
	}
}
*/
