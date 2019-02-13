#define BASE 10
#include <stdio.h>
/*
Scrivere un programma in C che acquisito un valore intero calcola e visualizza il valore ottenuto invertendo l'ordine delle cifre che lo compongono. Ad esempio, se il programma acquisisce il valore 251, il programma visualizza 152. Si ipotizzi (non si devono far veriche in merito) che il valore acquisito non dia problemi di overflow e sia senz'altro strettamente positivo. Se l'utente inserisce il valore 1000, il programma visualizza 1 (questo perchè CALCOLA e poi visualizza). Se l'utente inserisce 9001 il programma visualizza 1009.
*/
int main(int argc, char * argv[]){
	int val, aux, vfin, i;
	scanf("%d", &val);
	vfin = 0;
	i = 1;
	aux = val;
	while(aux>0){
		aux = aux / BASE;
		i = i * BASE;
	}
	while(val>0){
		i = i / BASE;
		vfin = vfin + ((val%BASE)*i);
		val = val / BASE;
	}
	printf("%d\n", vfin);
	return 0;
}
