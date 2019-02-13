/**
E2: stringa moltiplicata
* Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un intero n (senz’altro non negativo). Il sottoprogramma restituisce una nuova stringa ottenuta concatenando n copie di s. Ad esempio, se il sottoprogramma riceve in ingresso “esempio” e 3 restituisce la nuova stringa
* “esempioesempioesempio”, se riceve “esempio” e 0 restituisce una stringa vuota.
non utilizzare sottoprogrammi di libreria string.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strmult(char [], int);
int main(int argc, char * argv[]){
	char * single;
	int times;
	
	single = argv[1];
	times = atoi(argv[2]);
	printf("%s x %d --> %s\n", single, times, strmult(single, times));
	return 0;
}

char * strmult(char s[], int n){
	char * r;
	int len;
	int i, j, k;

	len = strlen(s); /*legittimo*/
	if(r = (char *) malloc(sizeof(char)*(n*len+1))){
		j=0;
		for(i=0; i < n; i++)
			for(k=0; s[k] !='\0'; k++, j++)
				*(r+j) = s[k];
		*(r+j) = '\0';
	}else
		printf("Memory error for %d replicas of %s\n", n, s);
	return r;
}

