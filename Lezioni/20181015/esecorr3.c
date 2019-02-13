#include <stdio.h>
/*
Scrivere un programma in C che acquisisca una sequenza str di 20 caratteri. Per ogni carattere car contenuto nella stringa str, a partire dall'ultimo fino ad arrivare al primo, il programma visualizza (senza lasciare spazi) il carattere car, seguito dal numero di volte in cui compare consecutivamente in quel punto della stringa. Per esempio, se l'utente inserisce aabbbddbbbbhhhhhzzzz il programma visualizza z4h5b4d2b3a2.
*/
#define N 20
int main(int argc, char * argv []){
	char str[N], car;
	int i, count;
	
	for(i=0; i<N; i++)
		scanf("%c", &str[i]);	
	i--;
	
	car = str[i];
	count = 1;
	for(i--; i>=0; i--){
		if(str[i] == car)
			count++;
		else{
			printf("%c%d", car, count);
			count = 1;
			car = str[i];
		}
	}
	printf("%c%d\n", car, count);
	return 0;
}
