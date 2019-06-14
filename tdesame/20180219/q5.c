/*
Si consideri una lista per la gestione di valori interi e si definisca un tipo opportuno list_t. Si scrivano due sottoprogrammi kcon e knocon che ricevuta in ingresso una lista del tipo definito ed un intero k, si comportino come specificato di seguito:
• kcon: restituisce 1 se la lista contiene almeno due occorrenze consecutive di k, 0 altrimenti, e
• knocon: restituisce 1 se la lista contiene almeno due occorrenze non consecutive di k, 0 altrimenti.
Un punto extra per ogni programma realizzato in modo ricorsivo.
*/
#include <stdlib.h>
#include <stdio.h>

#define NOCC 2

typedef struct list_s{
	int val;
	struct list_s * next;
}list_t;

int kcon(list_t *, int);
int knocon(list_t *, int);
list_t * push(list_t *, int);

int main(int argc, char * argv[]){
	list_t * lista = NULL;

	lista = push(lista, 5);
	lista = push(lista, 1);
	lista = push(lista, 5);

	printf("Cons: %d\tNon cons: %d\n", kcon(lista, 5), knocon(lista, 5) );
	return 0;
}

int kcon(list_t * h, int k){
	int conto;
	list_t * ptr = NULL;

	conto = 0;

	for(ptr = h; ptr; ptr=ptr->next){
		if(ptr->val == k)
			conto++;
		else if(conto>0)
			conto--;
		if(conto == NOCC)
			return 1;
	}
	return 0;
}

int knocon(list_t * h, int k){
	int conto;
	list_t * ptr = NULL;
	
	conto = 0;
	for(ptr = h; ptr; ptr = ptr->next)
		if(ptr->val == k)
			conto++;
	if(conto >= NOCC)
		return 1;
	return 0;
}

list_t * push(list_t * h, int num){
	list_t * ptr = NULL;
	list_t * scroll = NULL;
	if((ptr = malloc(sizeof(struct list_s)))){
		ptr->val = num;
		ptr->next = NULL;
	}
	if(!h)
		h = ptr;
	else{
		for(scroll = h; scroll->next; scroll=scroll->next)
			;
		scroll->next = ptr;
	}
	return h;
}
