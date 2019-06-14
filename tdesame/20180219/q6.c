/*PROBLEMA: non riesce a sostituire più di una parentesi*/
/*
Definire un tipo di dato opportuno clist_t per realizzare una lista dinamica che gestisce caratteri (ogni elemento un carattere) e serve per gestire sequenze di caratteri.
Si definisce sottosequenza una sequenza di caratteri compresa tra una parentesi tonda iniziale ( e una finale ).
Le sottosequenze possono anche essere vuote (parentesi aperta e poi chiusa senza altri caratteri intermedi).
Scrivere un sottoprogramma riceve in ingresso una lista che costituisce una sequenza e la restituisce dopo aver sostituito le sottosequenze con il carattere #. La sequenza dei caratteri in ingresso è ben formata, ossia: i) per ogni parentesi tonda che si apre, c’è una parentesi tonda che si chiude, ii) non ci sono intersezioni tra coppie di parentesi. Per esempio, ab(acg)be()a(xx)f è una sequenza ben formata, ab(a(c)g)b e aba(c)g)b non lo sono.
Se il sottoprogramma riceve in ingresso la sequenza ab(acg)be()a(xx)f(a), restituisce la sequenza ab(#)be(#)a(#)f(#).
Si considerino già disponibili e non da sviluppare i sottoprogrammi seguenti:
*/
#include <stdlib.h>
#include <stdio.h>

#define SOS '#'

typedef struct clist_s{
	char val;
	struct clist_s * next;
}clist_t;

clist_t * push(clist_t *, char);
clist_t * append(clist_t *, char);
clist_t * pop(clist_t *);
clist_t * delete(clist_t *, char);
clist_t * exists(clist_t *, char);
int length(clist_t *);
clist_t * sos(clist_t *);
void printlist(clist_t *);

int main(int argc, char * argv[]){
	clist_t * testa = NULL;
	testa = append(testa, 'c');
	testa = append(testa, '(');
	testa = append(testa, 'c');
	testa = append(testa, 'c');
	testa = append(testa, 'c');
	testa = append(testa, 'c');
	testa = append(testa, ')');
	testa = append(testa, 'c');
	testa = append(testa, 'c');
	testa = append(testa, '(');
	testa = append(testa, ')');

	testa = sos(testa);
	printlist(testa);
	return 0;
}

clist_t * sos(clist_t * h){
	clist_t * e = NULL;
	clist_t * ptr, *prev;
	clist_t * ini = NULL, *fin = NULL;
	int status; /*1: non fa nulla; 0: distrugge tutto*/

	if((e = (clist_t *)malloc(sizeof(clist_t)))){
		e->val = SOS;
		status = 1;
		for(ptr=h, prev=NULL; ptr; prev=ptr, ptr=ptr->next){
			if(prev && prev->val == '('){
				ini = prev;
				status = 0;
			}
			if(ptr->val == ')'){
				fin = ptr;
				status = 1;
			}
			if(!status){
				ptr = pop(ptr);
				prev->next = ptr;
			}
			if(ini && fin){
				ini->next = e;
				e->next = fin;
				ini = NULL;
				fin = NULL;
			}
		}
	}else
		printf("No memoria\n");
	return h;
}

clist_t * pop(clist_t * h){
	clist_t * r;

	r = h;
	h = h->next;
	free(r);
	return h;
}

clist_t * append(clist_t * h, char n){
	clist_t * ptr;
	clist_t * e;
	if((e = (clist_t *)malloc(sizeof(clist_t)))){
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

void printlist(clist_t * h){
	clist_t * ptr;
	for(ptr = h; ptr; ptr=ptr->next)
		printf("%c", ptr->val);
	printf("\n");
	return ;
}
