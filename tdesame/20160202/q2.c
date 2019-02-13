/*Scrivere un sottoprogramma che ricevute in ingresso due stringhe restituisce 1 se sono una l’anagramma dell’altra, 0 altrimenti. Il sottoprogramma non deve modificare le stringhe ricevute in ingresso.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MD 100

int anag(char[], char[]);

int main(int argc, char * argv[]){
	char s1[MD], s2[MD];

	scanf("%s", &s1[0]);
	scanf("%s", &s2[0]);

	printf("%d\n", anag(s1, s2));
	return 0;
}

int anag(char s1[], char s2[]){
	int dim1, dim2, i, j, k;
	char *  s2c;

	k = 0;
	dim1 = strlen(s1);
	dim2 = strlen(s2);
	if((s2c = (char *) malloc(sizeof(char) * dim2))){
		for(i=0; i<dim2; i++)
			*(s2c+i) = s2[i];
		*(s2c+i) = '\0';
		for(i=0; i<dim1; i++){
			for(j=0; j<dim2; j++){
				if(s1[i] == s2c[j]){
					s2c[j] = ' ';
					k++;
				}
			}
		}
		if(k == dim1 && k == dim2)
			return 1;
		return 0;
	}else
		printf("Sei ghei\n");
	return 0;
}
