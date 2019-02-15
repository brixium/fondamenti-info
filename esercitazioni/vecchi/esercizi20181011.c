#define STOP 23
#define NUM 5
#define MAX 10
#define BASE 2
#include <stdio.h>
int main(int argc, char * argv []){
	/* mantissa(num); */
	/* opposto(); */
	/* array(); */
	intbase2();
	return 0;		
}

void foo(){
	printf("Ciao\n");
}
void mantissa(){
	double n;
	int print, i;
	scanf("%lf",&n);
	n = n - (int) n;
	for(i=0; i<STOP; i++){
		print = (int)n;
		printf("%i", print);
		if(n>0)
			n = (int)n;
		n = n * 2;
	}
	printf("\n");
}
void opposto(){
	int a,b,c,d,e;
	scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
	printf("%d %d %d %d %d\n", e,d,c,b,a);
	
}
void array(){
	int v [NUM];
	int i;
	i=0;
	while(i<NUM){
		scanf("%d", &v[i]);
		i++;
	}
/* i vale 5, diminuisco di uno per poter leggere l'ultimo numero*/
	i--;
	while(i>=0){
		printf("%d\n",v[i]);
		i--;
	}
}
/* Con questa funzione ho dimensione fissa 10 bit*/
void intbase2(){
	int input;
	int binario [MAX], i;
	scanf("%d",&input);
	i = MAX-1;
	while(i>=0){
		binario[i] = input % BASE;
		input = input / BASE;
		i--;
	}
	i=0;
	while(i<MAX){
		printf("%d",binario[i] );
		i++;
	}
	printf("\n");
}
