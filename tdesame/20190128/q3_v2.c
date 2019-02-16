/*Versione 2 (iterativa)*/
#include <stdio.h>
#include <math.h>

#define JOLLY 'x'
#define BASE 2

void genera(char[]);

int main(int argc, char * argv[]){
	char * mask;

	mask = argv[1];
	genera(mask);
	return 0;
}

void genera(char mask[]){
	int i, j, num, conf, k;

	for(num=0, i=0; mask[i]!='\0'; i++)
		if(mask[i] == JOLLY)
			num++;
	
	conf = pow(BASE, num);

	for(j=0; j<conf; j++){
		for(i=0, k=j; mask[i] != '\0'; i++)
			if(mask[i] == JOLLY){
				printf("%d", k%2);
				k = k/2;
			}else
				printf("%c", mask[i]);
		printf("\n");
	}
}
