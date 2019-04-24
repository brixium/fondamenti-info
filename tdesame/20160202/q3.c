/*Scrivere un sottoprogramma che ricevuta in ingresso una lista per la gestione di informazioni strutturate (il cui tipo è riportato di seguito) visualizza per ogni diverso valore del campo ufficio presente nella lista, quanti elementi compaiono nella lista.*/

/*
Esempio:
Ufficio:	126 		123		 	124 		126			121			124			126
Timestamp:	1453714266->1453714266->1453714266->1453714617->1453714617->1453714737->1453714737->NULL
valore:		20.5		19.6		20.0		20.5		19.0		20.0		21.0

uscita: 126 3 123 1 121 1 124 2
*/
#include <stdio.h>
#include <stdlib.h>
/*il typedef è dato dal testo*/
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
	elem_t * archivio;
	if((archivio = (elem_t *)malloc(sizeof(elem_t) *10) )){
		for(i=0; i<10; i++)
			archivio = push((archivio+i), i);
		nel(archivio);
	}else
		printf("Memoria insufficiente\n");
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

