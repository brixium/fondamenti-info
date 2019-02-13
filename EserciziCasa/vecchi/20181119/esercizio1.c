#include <stdio.h>
#define MAX 33
/*
Scrivere un sottoprogramma fillArray che popoli un array di interi leggendo da console una sequenza di al più n interi terminata dall'inserimento del valore sentinella 1000 (non fa parte dei dati). Il sottoprogramma restituisce al chiamante il numero totale di elementi inseriti.
*/
int fillArray();

int main(int argc, char * argv[]){
	printf("%d\n", fillArray());
	return 0;
}

int fillArray(){
	int i, val[MAX], alert;
	alert = 1000;
	for(i=0; i<MAX; i++){
		scanf("%d", &val[i]);
		if(val[i]==alert)
			return i;
	}
	return i;
}
