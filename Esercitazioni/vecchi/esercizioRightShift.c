#include <stdio.h>
#define N 10
int main(int argc, char * argv []){
	char last, seq[N], sec[N];
	int i;
	for(i=0; i<N; i++){
		scanf("%c", &seq[i]);
		sec[i] = seq[i];
	}
	last = seq[N-1];
	for(i=0; i<N-1; i++){
		sec[i+1] = seq[i];
	}
	sec[0]=last;
	for(i=0; i<N; i++){
		printf("%c", sec[i]);
	}
	printf("\n");
	return 0;
}
