/* Premessa:
	Un numero perfetto è pari alla somma dei divisori (es. 28 = 1+2+4+7+14)
	dati due numeri, questi sono amicali se 

	Dato un sottoprogramma dato in ingresso un numero intero restituisce 
		quali sono i divisori del primo e del secondo numero. (nn la somma, ma creando una struttura dati che contenga questi dati).

	scrivere poi un ulteriore sottoprogramma amicali che restituisce 1 o 0 a seconda se lo sono oppure no.
	Dichiarare la append perché la uso
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;

nodo_t * divisori(int);
int amicali(int, int);
nodo_t * append(nodo_t *, int);

int main(int argc, char * argv[]){
	
	return 0;
}

nodo_t * divisori(int x){
	nodo_t * l;
	int i;
	l = NULL;
	for(i=1; i<x; i++)
		if((x%i)==0)
			l=append(l, i);
	return l;
}

int amicali(int m, int n){
	int sm, sn;
	nodo_t * divm, *divn, *tmp;
	divm = divisori(m);
	divn = divisori(n);
	for(tmp = divm, sm = 0; tmp; tmp=tmp->next)
		sm = sm + tmp->val;
	if(n==sm){
		for(tmp=divn, sn = 0; tmp; tmp=tmp->next)
			sn = sn + tmp->val;
		if(m==sn)
			return 1;
	}
	/*Bisogna fare una free della memoria da qualche parte prima del return*/
	/*Non basta eliminare il primo elelemento: bisnogna scorrere tutta la lista ed eliminare tutti gli elementi*/
	return 0;
}

nodo_t * append(nodo_t * head, int valore){
	nodo_t * np, *tmp;
	if(np = (nodo_t *) malloc(sizeof(nodo_t))){
		np->val = valore;
		np->next = NULL;
		if(head){
			for(tmp=head; tmp->next; tmp = tmp->next)
				;
			tmp->next = np;
		}else
			head = np;
	}else
		printf("Errore in allocazione memoria\n");
	return head;
}
