/*Versione ricorsiva (3)*/
#include <stdio.h>

#define JOLLY 'x'

void genera(char[]);
void stampa(char[], int);

int main(int argc, char * argv[]){
	char * mask;

	mask = argv[1];
	genera(mask);
	return 0;
}

void genera(char mask[]){
	stampa(mask, 0);
	return;
}

void stampa(char mask[], int pos){
	if(mask[pos] == '\0')
		printf("%s\n", mask);
	else
		if(mask[pos] == JOLLY){
			mask[pos] = '0';
			stampa(mask, pos);
			mask[pos] = '1';
			stampa(mask, pos);
			mask[pos] = JOLLY;
		}else
			stampa(mask, pos+1);
	return;
}
