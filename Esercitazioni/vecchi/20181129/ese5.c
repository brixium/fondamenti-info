/*
Scrivere un sottoprrogramma che date in ingresso due stringhe senz'altro della stessa dimensione, restituisce 1 se sono una l'anagramma dell'altra, zero altrimenti.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 30
int anagramma(char * s1, char * s2);
int main(int argc, char * argv[]){
	char str1[MAXLEN+1], str2[MAXLEN+1];
	scanf("%s", str1);
	do
		scanf("%s", str2);
	while(strlen(str1)!=strlen(str2));
	printf("%d\n", anagramma(str1, str2));
	return 0;
}
int anagramma(char * s1, char * s2){
	int n, i, j, found;
	int * tmp;
	int count;
	
	n = strlen(s1);
	if(tmp = (int *)malloc(n*sizeof(int))){
		for(i=0; i<n; i++){
			tmp[i]=0;
		}
		count = 0;
		for(i = 0; i<n; i++){
			found = 0;
			for(j=0; j<n && found==0; j++){
				if(tmp[j]==0 && s1[i]==s2[j]){
					found++;
					tmp[j] = 1;
					count++;
				}
				if(found == 0){
					free(tmp);
					return 0;
				}
			}
		}
		free(tmp);
		if(count == n)
			return 1;
	}else
		printf("Errore in anagramma!");
	return -1;
}
