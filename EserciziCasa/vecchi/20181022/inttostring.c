#include <stdio.h>
#define MAX 9
#define BASE 10
#define OFFSET 48
int main(int argc, char * argv[]){
	int input, aux, i, j, cond, last;
	char output[MAX+1];
	cond = 1;
	scanf("%d", &input);
	aux = input;
	for(j=0; aux!=0; j++)
		aux = aux / BASE;
	last = j;
	for(i=0, j--; i<MAX && cond; i++, j--){
		output[j] = OFFSET + input % BASE; /* Offset serve per allineare i numeri interi alla tabella ascii*/
		input = input / BASE;
		if(input==0){
			cond = 0;
			output[last]='\0';
		}
	}
	printf("%s\n", output);
	return 0;
}