/**/
#include <stdio.h>

int main(int argc, char argv[]){
	teoria();

	e1();
	return 0;
}

void teoria(){
	/*malloc : allocazione in memoria*/
	int * p1;	/*Indirizzo per la memoria*/
	int num;	/*Numero di elementi variabile*/
	num = 5;
	p1 = (int *) malloc(num * sizeof(int)); /* cast esplicito, non obbligatorio */
	/*free : libera memoria*/


}

/*Scrivere un programma che chiede all'utente quanti valori interi intenda fornire,
* quindi li acquisice e li visualizza in ordine inverso
*/

void e1(){
	int n;
	int * dati;
	int i;
	scanf("%d", &n);
	dati = (int *) malloc(n * sizeof(int));
	if(dati){
		for(i=0; i<n; i++)
			scanf("%d", dati+i); /*dati è un indirizzo, poi si somma i*/
			/*Teoricamente sarebbe stato il contenuto all'indirizzo dati +i &*(d+i) ma si annulano a vicenda*/
		for(i--; i>=0; i--)
			printf("%d ", *(dati+i)); /*L'asterisco indica il contenuto dell'indirizzo */
		free(dati); /*Libero la memoria all'indirizzo dati*/
	}else
		printf("Errore allocazione %d interi", n);
}
/*	Scrivere un sottoprogramma che, ricevuta in ingresso una stringa, ne crea una nuova di zecca
*	della dimensione strettamente necessaria a contenere la stringa ricevuta in ingresso
*	ci copia il contenuto e la restituisce al chiamante
*/	
char * duploStringa(char s[]){ /*Restituisco un indirizzo di stringa*/
	char * ns;
	int dim;
	int i;
	dim = strlen(s);
	ns = (char *) malloc((dim+1) * sizeof(char));
	if(ns){
		for(i=0; i<(dim+1); i++)
			*(ns+i) = s[i]; /*così ci abbiamo messo anche il terminatore*/
	}else{
		printf("Errore allocazione %d caratteri", dim+1);
	}
	return ns; /* ns è di tipo char * (indirizzo variabile con nome ns)*/
}/*Chi chiama sto sottoprogramma deve fare la free*/

