/*Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione di informazioni strutturate (il cui tipo è riportato di seguito) visualizza per ogni diverso valore del campo ufficio presente nella lista, quanti elementi compaiono nella lista.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem_s {
	int ufficio;
	char * timpestamp;
	int valore;
	struct elem_s * next;
} elem_t;

int nel(elem_t *);
int conta(elem_t *, int);
elem_t * delete(elem_t *, int);
elem_t * push(elem_t * , int);

int main(int argc, char * argv[]){
	int i;
	elem_t * sdroga;
	if((sdroga = (elem_t *)malloc(sizeof(elem_t) *10) )){
		for(i=0; i<10; i++)
			sdroga = push((sdroga+i), i);
		nel(sdroga);
	}else{
		printf("Avete tutti la mamma\n");
	}
	return 0;
}

int nel(elem_t * h){
	int r;
	elem_t * ptr = NULL;
	r = 0;
	for(ptr = h; ptr!=NULL; ptr = ptr->next)
		printf("%d %d\n", ptr->ufficio , conta(h, ptr->ufficio));
	return r;
}

int conta(elem_t * h, int num){
	int c;
	elem_t * ptr = NULL;
	c = 0;
	for(ptr = h; ptr !=NULL; ptr = ptr->next)
		if(ptr->ufficio == num){
			c++;
			delete(h, num);
		}
	return c;
}

elem_t * delete(elem_t * h, int num){
	elem_t *cur, *prev;

	for(cur = h, prev = NULL; cur!= NULL && cur->ufficio != num; prev = cur, cur = cur->next)
		;
	if(cur == NULL)
		return h;
	if(prev == NULL)
		h = h->next;
	else
		prev->next = cur->next;
	/*free(cur);*/
	return h;
}

elem_t * push(elem_t * h, int num){
	elem_t * ptr = NULL;
	if((ptr = (elem_t *)malloc(sizeof(elem_t)))){
		ptr->ufficio = num;
		ptr->next = h;
	}
	return ptr;
}
/*
data_t * pop(data_t ** h){
	nodo_t * hlocal, *ptr;
	hlocal = *h;
	if(!hlocal)
		return NULL;
	ptr = hlocal;
	*h = hlocal->next;
	return ptr;
}
*/

