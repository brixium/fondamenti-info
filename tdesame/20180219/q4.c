/*
(5 punti) Scrivere un sottoprogramma rep che riceve in ingresso una stringa s e un intero n (senz’altro non negativo).
Il sottoprogramma restituisce una nuova stringa ottenuta concatenando n copie di s.
Ad esempio, se il sottoprogramma riceve in ingresso “esempio” e 3 restituisce la nuova “esempioesempioesempio”, se riceve “esempio” e 0 restituisce una stringa vuota.
Non è consentito l’uso dei sottoprogrammi di libreria quali strcat(), strcpy() e simili.
(1 punto) Scrivere il programma che acquisisce da riga di comando la stringa s e l’intero n –utilizzando il sottoprogramma rep – visualizza la nuova
stringa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * rep(char*, int);

int main(int argc, char * argv[]){
	if(argc > 2){
		printf("%s\n", rep(argv[1], atoi(argv[2])));
	}else
		printf("Argomenti insufficienti\n");
	return 0;
}

char * rep(char *s, int n){
	int i, j, slen;
	char * ret;

	if(n <=0)
		return "";
	slen = strlen(s);
	if((ret =(char *) malloc(sizeof(char)*slen*n))){
		for(j=0; j<n; j++){
			for(i=0; i<slen; i++)
				*(ret+i+(j*slen)) = *(s+i);
		}
	}else{
		printf("Memory error\n");
		return "";
	}
	return ret;
}
