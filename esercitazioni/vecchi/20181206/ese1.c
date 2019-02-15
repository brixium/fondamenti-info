/*
* Esercizio 1: Scriviamo un sottoprogramam che ricevuta in ingresso una lista e qualsiasi altro parametro ritenuto str. necessario (lista di interi) trasmette al chiamante valore min, max, medio e n elementi presenti nella lista.

* Esercizio 2: sottoprogramma delete che ricevuta in ingresso una lista, elimina il primo elemento della lista (liberando la memoria corrispondente). Restituisce la lista modificata (testa di lista)modificata.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

void infoList(nodo_t *, int *, int *, float *, int *);
int main(int argc, char * argv[]){
	float media;
	int vmin, vmax, len;
	nodo_t * testa = NULL;
	testa = fillist(); /*Non esiste di libreria*/
	listval(testa, &vmin, &vmax, &media, &len);
	
	return 0;
}
/* trasmetti: passaggio per indirizzo */
void infoList(nodo_t * h, int * min, int * max, float * avg, int * num){
	nodo_t * ptr;
	int tot;
	/*Se non ci sono elementi num è zero*/
	* num = 0;
	if(h){ /* controllo lista vuota */
		* min = h->val;
		* max = h->val;
		tot = h->val;
		
		for(ptr = h->next; ptr; ptr = ptr->next){
			if(* min < ptr->val)
				* min = ptr->val;
			else if(* max < ptr->val) /*else obbligatorio*/
				* max = ptr->val;
			tot = tot + ptr->val;
			(* num)++;
		}
		* avg = (float)tot/(*num);
	}
	return;
}

nodo_t * delete(nodo_t * h){
	nodo_t * ptr;
	if(!h)
		return h;
	ptr = h;
	h = h->next;
	free(ptr);
	/*oppure
	ptr = h->next;
	free(h);
	return(ptr);
	*/
	return h;
}

nodo_t * pop(nodo_t * * h){ /*Posso modificare un indirizzo*/
	nodo_t * hlocal, * ptr;
	hlocal = * h;
	if(!hlocal)
		return NULL;
	ptr = hlocal;
	* h = hlocal->next;
	return ptr;
}
/*
* Si può fare anche:
nodo_t * pop(nodo_t * * h){
	nodo_t * ptr;
	if(!(*h))
		return NULL;
	ptr = * h;
	* h = * h -> next;
	return ptr;
}
*/

/*
void pusha(nodo_t * * head, int val){
	
}
*/
/*
	CODICE MIO inutile :/
	int i, min, max, med, num_el;
	med = 0;
	num_el = 0;
	for(i=0; i<dim; i++){
		med = med + h->val;
		num_el = num_el + 1;
		if(i)

		else
	}

	int min_l, max_l, num_l;
	int avg_l;
	float media;
	num_l = 0;
	avg_l = 0;
	for(;h->next; h=h->next){
		
		avg_l = avg_l + h->val;
		if(num_l==0){
			min_l = h->val;
			max_l = h->val;
		}else{
			if(h->val < min_l)
				min_l = h->val;
			if(h->val > max_l)
				max_l = h->val;
		}
		num_l ++;
	}
	media = (float)avg_l / num_l;
	min = min_l;
	max = max_l;
	avg = media;
	num = num_l;

*/


