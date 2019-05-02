/*
Scrivere un sottoprogramma che riceve in ingresso un riferimento ad un file (già aperto) e legge un valore intero (se c’è ...) e restituisce la cifra del
valore letto che in esso compare più di frequente. Nel caso in cui non ci sia un valore, restituisce -1. Nel caso ci siano più cifre che compaiono lo
stesso numero di volte, restituisce quella più alta. Se per esempio legge il valore 217319 restituisce 1, se legge il valore 1002932 restituisce 2.
*/

#include <stdio.h>

#define BASE 10
#define STOP -1

int cifraFrequente(FILE *);

int main(int argc, char * argv[]){
	FILE * fp;
	char * nome;
	int ris;

	/*Lettura nome dagli argomenti del terminale*/
	nome = argv[1];

	/*Provo a leggere in lettura il file letto in precedenza*/
	if((fp = fopen(nome, "r"))){
		/*Chiamo il sottoprogramma cifraFrequente e gli passo il file aperto come parametro*/
		ris = cifraFrequente(fp);
		/*
		Qui può succedere che ris sia: 
			- un valore compreso tra 0 e 9 (il file ha almeno un numero al suo interno)
			- -1 (il file non ha neppure un numero al suo interno)
		Se ris fosse -1, la condizione del ciclo while non è soddisfatta e il file viene chiuso,
		altrimenti si entra nel ciclo e per potere uscire occorre che il file sia finito (non ci siano più numeri al suo interno)
		*/
		while(ris != STOP){
			/*Stampo a video una riga alla volta la cifra con occorrenza più alta*/
			printf("%d\n", ris);
			/*Leggo un'altra volta il file*/
			ris = cifraFrequente(fp);
		}
		/*Chiusura file*/
		fclose(fp);
	}else
		printf("File non trovato!\n");
	return 0;
}

/*Riceve in ingresso un file già aperto e restituisce la cifra che ha l'occorrenza più alta*/
int cifraFrequente(FILE * fp){a
	/*Vars: Numero con più cifre letto, array contatore per ciascuna cifra lungo 10 (0-9), i, cifra con + ripetizioni*/
	int val, cont[BASE], i, max;
	/*Inizializzazione a 0 dell'array che associa ciascuna cifra al numero di ripetizioni */
	for(i=0; i<BASE; i++)
		cont[i] = 0;
	/*Unica lettura del primo valore numerico intero*/
	fscanf(fp, "%d", &val);
	/*Controllo che il file non sia vuoto*/
	if(!feof(fp)){
		/*Controllo che il numero sia maggiore di zero, nel ciclo leggo l'ultima cifra del numero e la riporto all'interno dell'array cont nella posizione relativa alla cifra*/	
		while(val > 0){
			cont[val%BASE]++;
			val = val / BASE;
		}
		/*Presuppongo che la cifra con la massima ripetizione sia il 9*/
		max = BASE-1;
		/*Verifico se dall'8 allo 0 c'è qualche cifra con più ripetizioni rispetto al 9 in ordine decrescente e se così fosse la indico come max*/
		for(i=BASE-2; i>=0; i--)
			if(cont[i] > cont[max])
				max = i;
	/*Se il file non contenesse nulla, restituisco -1*/
	}else
		max = -1;
	/*Valore di ritorno: cifra con più ripetizioni*/
	return max;
}
