#include <stdio.h>
#define MAX 50
/*Scrivere programma che data una stringa di 50 max conta e restituisce il numero di vocaboli contenti doppie. Ingresso: stringa tutta minuscola in italiano, output n intero + a capo*/
int main(int argc, char * argv[]){
	char in[MAX+1], prev;
	int num, endword, i;
	/*Init values*/
	num=0;
	endword=1;
	prev='\0';
	gets(&in[0]);
	/*Cose*/
	for(i=0; in[i]!='\0'; i++){
		if(prev==in[i] && endword){
			num++;
			endword=0;
		}
		if(in[i]==' ')
			endword = 1;
		prev = in[i];
	}
	/*printf("%d\n", i);*/
	/*result*/
	printf("%d\n", num);
	return 0;
}

