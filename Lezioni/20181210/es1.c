/*Oggi argc, argv e getopt*/
#include <stdio.h>

int main(int argc, char * argv[]){
	int i;

	for(i=0; i<argc; i++)
		printf("arg %d: %s\n", i, argv[i]);
	printf("Totale: %d elementi\n", i);
	return 0;
}
