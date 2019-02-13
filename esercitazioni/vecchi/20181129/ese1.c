#include <stdio.h>
#define N 30
/*	Giovedì 29 novembre 2018
*	Esercizi su ricorsione e allocazione dinamica.
*	chiede all'utente numero n di stringhe al più 30 caratteri, stamparle in ordine inverso.
*/
void stampai(int);
int main(int argc, char * argv[]){
	int n;
	do
		scanf("%d", &n);
	while(n<0);
	stampai(n);
	return 0;
}
void stampai(int num){
	char s[N+1];
	if(num<=0)
		return;
	scanf("%s", s);
	stampai(num-1);
	printf("%s\n", s);
	return;
}

/*
QUESTO É IL MIO CODICE CHE NON FUNZIONA
void stringhe(int, char s[], int i);
int main(int argc, char * argv[]){
	int n, i; num stringhe
	char s[N];
	i=0;
	scanf("%d", &n);
	stringhe(n, s, i);
	return 0;
}

void stringhe(int numS, char s[], int i){
	if(numS==1){
		printf(s[numS]);
		return ;
	}
	else{
		scanf("%s", &s[numS-1]);
		numS--;
		i++;
		stringhe(numS, s[i], i);
	}
}
*/

