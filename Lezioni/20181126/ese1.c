#include <stdio.h>

int main(int argc, char argv[]){

	return 0;
}

/*Fare il fattoriale in maniera iterativa, per ogni n>=0*/
int fattorialeIterativo(int n){
	int f;
	f=1;
	for(; n>1; n--)	/*Qui si può pasticciare la var perché non è visibile all'esterno*/
		f= f*n;
	return f;
}
/*Fattoriale ricorsivo per n>=0*/
int fattorialeRicorsivo(int n){
	if(n==0)	/*Se n==0, la risposta si ha immediatamente (PASSO BASE)*/
		return 1;	/*Il fattoriale di n è 1*/
	/*Niente else se no muoro X-( :dead: */
	return n*fattorialeRicorsivo(n-1);
	/*Il sottoprogramma chiama se stesso e il contributo del metodo è aggiungere n* fatt(n-1)*/
}
/*
*	Stack e visibilità delle variabili
*	Si crea una struttura a nodi
__________	 ___________  __________  __________
|  3     |	 |   2     |  |   1    |  |   0    |
|--------|-->|---------|->|--------|->|--------|
|3*f(n-1)|	 |2*f(n-1) |  |1*f(n-1)|  |return 1|
|________|   |_________|  |________|  |________|
        ^      |      ^     |     ^           |
        |----<-|      |___<-|     |---------<-|
*   	
*   eccetera
*	poi alla fine si arriva a 0 che restituisce 1 
*
*	Si possono fare anche dei miglioramenti al codice: in if mettiamo come condizione
*	if((n==0)||(n==1))
*/

/*Scrivere un sottoprogramma che ricevuto in ingresso una stringa restituisce la sua lunghezza (ricorsivamente)*/

int strLength(char s[]){
	if(s[0]=='\0')	/*Se arrivo al terminatore, la lunghezza è 0*/
		return 0;	
	return 1+strLength(&s[1]); /*s[0] è una caso già coperto (passo base)*/
}
/*chiamata(array); == chiamata(&array[0]);*/
/*Sottoprogramma che ricevuto in ingresso str e char e restituisce quante volte quel char compare nella stringa*/
/*Questo l'ho fatto io con le mie manine*/
int chinstrR(char s[], char c){
	if(s[0] == '\0')
		return 0;
	if(s[0] == c)
		return 1+chinstrR(&s[1], c);
	return chinstr(&s[1], c);
}
/*1ma domanda: quando smetto? Quando la str è vuota
* non ci piace avere 2mila return, per cui return limitate
*/
int chinstrR(char s[], char c){	/*Soluzione della proffa*/
int cont;
	if(s[0] == '\0')
		return 0;
	if(s[0] == c)
		cont = 1;
	else
		cont = 0;
	return cont + chinstr(&s[1], c);
}

void testStatic(){
	static int cont = 0; /*Queste si dichiarano sempre all'inizializzazione*/
	int num = 0;
	cont++;
	num++;
	printf("%d\t%d\n", cont, num);
	return;
}
/*Se questa cosa la chiamo dal main 5 volte, l'output sarà questo:
*	1	1
*	2	1
*	3	1
*	4	1
*	5	1
*/
/*Il valore static non è salvato nello stack. In tutte le successive chiamate sarà sempre lì*/
/*
	se faccio printf("%p", &cont); posso notare che lo spazio di memoria della variabile cont è sempre quello.
* 
*/
void testR(int n){
	static int cont = 0;
	int num = 0;
	if(n==0)
		return;
	cont++;
	num++;
	printf("%d %d\t%p %d\n", &cont, cont, &num, num); /*Mi aspetto di vedere num nel valore dello stack(variabile) e cont in un indirizzo fissato*/
	testR(n-1);
	return;
}

