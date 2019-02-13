/*
* E3: sostituisci sottosequenze
* Definire un tipo di dato opportuno clist_t per realizzare una lista dinamica che gestisce caratteri (ogni elemento un carattere). Si definisce sottosequenza una sequenza di caratteri compresa tra una parentesi tonda iniziale ( e una finale ). Le sottosequenze possono anche essere vuote (parentesi aperta e poi chiusa senza altri caratteri intermedi). Scrivere un sottoprogramma riceve in ingresso una lista che costituisce una sequenza e la restituisce dopo aver sostituito le sottosequenze con il carattere #. La sequenza dei caratteri in ingresso e' ben formata, ossia: i) per ogni parentesi tonda che si apre, c’e' una parentesi tonda che si chiude, ii) non ci sono intersezioni tra coppie di parentesi. Per esempio, ab(acg)be()a(xx)f e' una sequenza ben formata, ab(a(c)g)b e aba(c)g)b non lo sono.
* Se il sottoprogramma riceve in ingresso la sequenza ab(acg)be()a(xx)f(a), restituisce la sequenza ab(#)be(#)a(#)f(#).
sono dati i sottoprogrammi append, pop, delete e exists
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START '('
#define SUB '#'
typedef struct clist_s{
	char c;
	struct clist_s * next;
}clist_t;

int main(int argc, char * argv[]){
	
	return 0;
}

clist_t * replacesubs(clist_t * h){
	clist_t * tmp, * beg, * end;
	
	tmp = h;
	while(tmp){
		if(tmp->c == START){
			beg = tmp;
			tmp = tmp->next;
			while(tmp->c != STOP){
				beg->next = pop(tmp);
				tmp = beg->next;
			}
			end = tmp;
			beg->next = push(end, SUB);
		}
		tmp = end->next;
	}
	return h;
}

clist_t * pop(clist_t * h){ /*inserisci in testa*/
	clist_t * sec;

	if(h){
		sec = h->next;
		free(h);
		h = sec;
	}
	return h;
}

clist_t * push(clist_t * h, char c){
	clist * n;
	
	if(n = (clist_t *) malloc())
	
	else
		printf();
	return h;
}
