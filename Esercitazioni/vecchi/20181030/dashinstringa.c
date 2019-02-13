#include <stdio.h>
#define MAX 40
#define DASH '-'
/* Input: stringa e carattere. Sostituire alla stringa il carattere per ogni occorreza con un dash (-). Ouput: numero di occorrenze */
int main(int argc, char * argv[]){
	char car, sin[MAX+1];
	int i, counter;
	counter = 0;
	scanf("%s %c", &sin[0], &car);
	
	for(i=0; sin[i]!='\0'; i++)
		if(sin[i]==car){
			sin[i]=DASH;
			counter++;
		}
	printf("%s %d\n", sin, counter);
	return 0;
}
