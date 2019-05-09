/*
Scrivere un programma che acquisisce da riga di comando una stringa e visualizza 1 se la stringa è buffa, 0 altrimenti. Per determinare se una stringa sia buffa, si proceda nel seguente modo. Si calcoli la stringa opposta (ovvero se la stringa inziale è abc si calcola cba). Si procede poi per ciascuna stringa, calcolando le differenze in valore assoluto tra due caratteri adiacenti (ovvero per la prima stringa la differenza tra a e b, la differenza tra b e c e in modo analogo per la seconda). Se la sequenza delle differenze in valore assoluto è la stessa per entrambe le stringhe la stringa è buffa. Per esempio, la stringa acxz è buffa, la stringa ivvkx non lo è.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calcolaDiff(char, char);

int main(int argc, char * argv[]){
	int len, i, j, flag, * diff1, * diff2;
	char * str, * reverse;

	if(!argv[1]){
		printf("Aggiungi una stringa come argomento\n");
		return 1;
	}

	len = strlen(argv[1]);
	str = argv[1];
	strcpy(str, argv[1]);
	/*printf("%c\n", str[0]);*/
	if((reverse = (char *)malloc(sizeof(char)*len))){
		for(i=0, j=len-1; i<len; i++, j--)
			*(reverse+i) = *(str+j);
		if((diff1 = (int *)malloc(sizeof(int)*len)) && (diff2 = (int *)malloc(sizeof(int)*len))){
			flag = 1;
			for(i=0; i<len-1 && flag; i++){
				*(diff1+i) = calcolaDiff(*(str+i), *(str+i+1));
				*(diff2+i) = calcolaDiff(*(reverse+i), *(reverse+i+1));
				if(*(diff1+i) != *(diff2+i))
					flag = 0;
			}
			printf("%d\n", flag);
			free(diff1);
			free(diff2);
		}else
			printf("Errore allocazione memoria arr int");

		free(reverse);
	}else
		printf("Err. alloc. mem. 2nda str.");
	return 0;
}

int calcolaDiff(char a, char b){
	int x;
	x = a - b;
	if(x<0)
		return -x;
	return x;
}
