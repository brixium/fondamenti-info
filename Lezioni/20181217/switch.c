/*Sottoprogramma che riceve in ingresso stringa restituisce il numero di vocali in esso presenti*/
#include <stdio.h>
#include <string.h>
#define N 30
int main(int argc, char * argv){
	char cac[N+1];
	scanf("%s", &cac[0]);
	numvocali(cac);
	return 0;
}

int numvocali(char val[]){
	int i;
	int n;
	int lungh;
	n=0;
	lungh = strlen(val);
	for(i=0; i<lungh; i++)
		if(val[i]=='a' || val[i]=='e' || val[i]=='i'||val[i]=='o'||val[i]=='u')
			n++;
	return n;
}
/*Se dobbiamo ripetere delle cose così c'è qualquadra che non cosa;
Introduciamo lo SWITCH(), che controlla una espressione di un valore intero
interessa con var con valori puntuali e interi in un insieme di possibilità
Si può usare su caratteri ed interi; per float nope, perché non ha senso

sintassi:*/
int nvocswitch(char val[]){
	int i;
	int n, lenn;
	lenn = strlen(val);
	n=0;
	for(i=0; i<lenn; i++)
		switch(val[i]){
			case 'a':	n++;
						/*altre istruzioni allineate qui*/
						/*Esempio di blocco: alla fine termino così:*/
						break;
			case 'A':	n++;
						break;
			case 'e':	n++;
						break;
			case 'E':	n++;
						break;
			case 'i':	n++;
						break;
			case 'I':	n++;
						break;
			case 'o':	n++;
						break;
			case 'O':	n++;
						break;
			case 'u':	n++;
						break;
			case 'U':	n++;
						break;

/*			default :	
						break;*/
			/*Default non è obbligatorio*/
		}
}
/*Non si deve delimitare un blocco case con le parentesi*/
/*Lo switch funziona così: appena trova un caso con condizione verificata, esegue tutte le istruzioni successive, anche dei casi successivi.
Per evitare ciò bisogna usare l'istruzione break, che permette di uscire dalla condizione*/

/*Se faccio così è un po'tedioso, però se sfrutto la proprietà fondamentale, lo faccio così*/
int vocalioconsonanti(char val[]){
	int i, lungh, nv, nc;
	nv=0;
	nc=0;
	lungh = strlen(val);
	for(i=0; i<lungh; i++)
		switch(val[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':	nv++; /*Num vocali++*/
						break;
			default:	nc++; /*Num consonanti*/
		}
}

/*COntare quanti giorni sono passati dall'inizio dell'anno, opure quanti giorni ci sono in un mese lo switch ci serve, elencando tutti i numeri dei mesi con relativi numeri dei giorni.
Oppure contare vocali e delle consonanti
*/

int quantiGiorniSonoPassatiDallInizioDellAno(){
	int mese, day; /*day contiene il giorno attuale (n/365 oppure /366)*/
/*	scanf("%d", &mese);*/
	switch(mese){
		case 1:	giorno = day;
				break;
		case 2: giorno=day+31;
				break;
		case 3: giorno = day+31+bisestile(anno)+28; /*Sto metodo non esiste, */
				break;
		/*eccetera, ma così è una sbatta: farli al contrario (dal 12 all'1), ma subentrano delle complicazioni nella logica*/
	}
}

