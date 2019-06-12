/*
Scrivere un sottoprogramma in C listebuffe che riceve in ingresso una lista per la gestione di singoli caratteri (dichiarare il tipo) e restituisce un intero che vale 1 se i caratteri della lista corrispondono ad una stringa buffa, 0 altrimenti.
Per determinare se i caratteri di una lista corrispondono ad una stringa buffa, si proceda nel seguente modo. Si crei una lista contenente gli elementi della lista di partenza, in ordine opposto (se la lista iniziale ha i caratteri a→b→c→d→⊥ la seconda lista ha gli elementi d→c→b→a→⊥). Si calcolano le differenze in valore assoluto tra i caratteri di due elementi adiacenti (per la prima stringa, la differenza tra a e b, tra b e c ...). Se la sequenza delle differenze in valore assoluto è la stessa per entrambe le liste, la lista corrisponde ad un stringa buffa.
Per esempio, la lista a->c->x->z->⊥ corrisponde ad una stringa buffa, la lista i->v->v->k->x->⊥ no.
È possibile utilizzare (senza doverli sviluppare) i sottoprogrammi i cui prototipi sono riportati di seguito.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMERR "Errore: memoria insufficiente\n"
#define SLM 10
typedef struct elem_s{
	char c;
	struct elem_s * next;
}elem;

/*inserisce l’elemento specificato in coda*/
elem* append(elem*, char);
/*inserisce l’elemento specificato in testa*/
elem* push(elem*, char);
/*inserisce l’elemento specificato in ordine crescente*/
elem* insertup(elem*, char);
/*inserisce l’elemento specificato in ordine decrescente*/
elem* insertdown(elem*, char);
/*rimuove la prima occorrenza dell’elemento specificato*/
elem* delete(elem*, char);
/*visualizza la lista*/
void view(elem*);
/*distrugge la lista*/
elem* destroy(elem*);
/*restituisce 1 se l’elemento e’ presente nella lista, altrimenti 0*/
int exists(elem*, char);

int listebuffe(elem *);

int main(int argc, char * argv[]){
	char l1[SLM+1], l2[SLM+1];
	elem * h = NULL;
	int i, s1l, s2l;
	
	strcpy(l1, "axcz\0");
	strcpy(l2, "ivvkx\0");
	s1l = strlen(l1);
	s2l = strlen(l2);
	for(i=0; i<s1l; i++)
		h = append(h, l1[i]);

	if(listebuffe(h))
		printf("%s è buffa\n", l1);
	else
		printf("%s non è buffa\n", l1);
	
	h = destroy(h);

	for(i=0; i<s2l; i++)
		h = append(h, l2[i]);

	if(listebuffe(h))
		printf("%s è buffa\n", l2);
	else
		printf("%s non è buffa\n", l2);
	return 0;
}

int listebuffe(elem * h){
	elem *ptr=NULL, *riocontra=NULL;
	int i, *dif1, *dif2, max, cel;
	
	cel=0;
	for(ptr = h; ptr; ptr = ptr->next)
		cel++;

	if((dif1 = (int *)malloc(sizeof(int) * cel))){
		for(ptr = h, i=0; ptr; ptr=ptr->next, i++){
			riocontra = push(riocontra, ptr->c);
			if(ptr->next)
				*(dif1+i) = abs(ptr->c - ptr->next->c);
		}
		if((dif2 = (int *)malloc(sizeof(int) * cel))){
			for(ptr = riocontra, i=0; ptr; ptr = ptr->next, i++){
				if(ptr->next)
					*(dif2+i) = abs(ptr->c - ptr->next->c);
			}
			
			max = i;
			/*confornto valori arr int*/
			for(i=0; i<max; i++)
				if(*(dif1+i) != *(dif2+i))
					return 0;
			return 1;
		}else
			printf(MEMERR);
	}else
		printf(MEMERR);
	return -1;
}

/*Metodi fighi*/
elem* push(elem * h, char num){
	elem * ptr = NULL;
	if((ptr = (elem *)malloc(sizeof(elem)))){
		ptr->c = num;
		ptr->next = h;
	}
	return ptr;
}

elem * append(elem * h, char n){
	elem * ptr;
	elem * e;
	if((e = (elem *)malloc(sizeof(elem)))){
		e->c = n;
		e->next = NULL;
		if(!h)
			h = e;
		else{
			for(ptr = h; ptr->next!=NULL; ptr = ptr->next)
				;
			ptr->next = e;
		}
	}else
		printf("Memory allocation error in append\n");
	return h;
}

elem * destroy(elem * h){
	elem * tmp;

	while(h != NULL){
		tmp = h;
		h = h->next;
		free(tmp);
	}
	return NULL;
}
