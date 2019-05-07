/*
Scrivere un sottoprogramma scomponi che ricevuto in ingresso un numero intero senz’altro strettamente positivo n lo scompone e restituisce al chiamante i fattori. Realizzare un’opportuna struttura dati. Ad esempio, per n = 60 il programma trasmette i valori 2 2 3 5.
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
nodo_t * scomponi(int);
nodo_t * append(nodo_t *, int);

int main(int argc, char * argv[]){
	nodo_t * finale = NULL;
	finale = scomponi(60);
	stampa(finale);
	return 0;
}

nodo_t * scomponi(int n){
	int i, num;
	nodo_t * fattori = NULL;
	i=2;
	num = n;

	while(i<=n/2){
		if(num%i==0){
			fattori = append(fattori, i);
			num = num / i;
		}else
			i++;
	}
	return fattori;
}
/*Sottoprogrammi di utilità*/

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
nodo_t * append(nodo_t * h, int num){
	nodo_t * ptr;
	nodo_t * e;
	if((e = malloc(sizeof(nodo_t)))){
		e->val = num;
		e->next = NULL;
		if(!h)
			return e;
		for(ptr=h; ptr->next; ptr = ptr->next)
			;
		ptr->next = e;
	}else
		printf("No memory\n");
	return h;
}
