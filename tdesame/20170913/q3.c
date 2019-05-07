/*
Scrivere un programma in C che acquisisca una stringa str (priva di spazi e lunga al più 500 caratteri). La stringa str contiene una sequenza di caratteri numerici non necessariamente tutti distinti (può cioè contenere delle ripetizioni). Per ogni carattere n contenuto nella stringa str, a partire dall’ultimo fino ad arrivare al primo, il programma visualizza (senza lasciare spazi) il carattere n, seguito dal numero di volte che questo compare in str.
Per esempio, data la stringa 3333666221117777444444444444444440999 il programma visualizza 93014177413226334.
*/
#include <stdio.h>
#include <string.h>

#define MAXLEN 500
#define BASE 10

int main(int argc, char * argv[]){
	char str[MAXLEN];
	int i, dim, pos, rip[BASE];
		
	scanf("%s", &str[0]);
	for(i=0; i<BASE; i++)
		rip[i] = 0;
	dim = strlen(str);
	for(i=0; i<dim; i++){
		pos = str[i]-'0';
		rip[pos]++;
	}
	for(i=dim-1; i>=0; i--){
		pos = str[i] - '0';
		if(rip[pos]!=0){
			printf("%c%d", str[i], rip[pos]);
			rip[pos] = 0;
		}
	}
	printf("\n");
	return 0;
}
