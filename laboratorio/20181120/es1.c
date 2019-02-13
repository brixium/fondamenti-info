/*Lorenzo Asolan*/
typedef struct punto_s{
	int x;
	int y;
}punto_t;
#include <stdio.h>
#define COORD 2
#define MAX 10
int main(int arc, char * argv[]){
	
}
/*Argomenti: matrice di gioco, posizionamento alberi, dimensione campo*/
int checkRiga(int mat[][MAX], int alberi[][COORD], int dim){
	int treeinrow; /*Indica quanti alberi per riga ci dovrebbero essere*/
	int occ[MAX]; /*conta le occorrenze degli alberi per ciascuna riga */
	int i; /*Iteratore*/
	/*INIT*/
	if(dim<=5)
		treeinrow = 1; /*se le righe sono <=5, 1 albero per riga in teoria*/
	else
		treeinrow = 2; /*viceversa 2 se gli alberi sono >5*/

	for(i=0; i<dim; i++)
		occ[i] = 0;
	/*TODO*/
	for(i=0; i<dim; i++)
		occ[alberi[i][0]]++; /*Ad ogni occorrenza aumento di 1 il contatore di righe corrispondente*/
	for(i=0; i<dim; i++)
		if(occ[i]!=treeinrow) /*Se il numero di occorrenze sulla stessa riga è diverso da quello che ci si aspetta, restituisco 0*/
			return 0;
	return 1;
}

