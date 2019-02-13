/**/
#include <stdio.h>
#define N 9
typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}nodo_t;
int val; /*Variabile globale: non è di nessuno, per cui è di tutti*/
/*Tutti possono leggerla e scriverla*/
/*Potrebbe avere senso utilizzare una variabile globale per la testa di un'unica lista*/

int p(int, int *);
int main(){
	
	return 0;
}

void p(int n, int * ris){
	/*in questo sottoprogramma n è locale e ris è visibile dal chiamante*/
}

/*In questo caso, se esiste la variabile testa NON VA BENE qeusto sottoprogramma perché modifica la posizione della testa*/
int lenlist(nodo_t * h){
	int n;
	for(n=0; h; h=h->next)
		n++;
	return n;
}

/*Questo va bene solo se esiste una sola lista globale; se ci sono più liste diventa un casino perché devo duplicare un sacco di codice*/
int lenlist(){
	nodo_t * ptr;
	int n;
	for(n=0, ptr=testa; ptr; ptr= ptr->next)
		n++;
	return n;
}

