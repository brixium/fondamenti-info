#include <stdio.h>
#include <stdlib.h>

int cat(int);

int main(int argc, char * argv[]){
	int x,i;
	
	do{
		scanf("%d", &x);
	}while(x<0);
	for(i=0; i<=x; i++)
		printf("%d", cat(x));
	printf("\n");
	return 0;
}

int cat(int n){
	int i;
	/*int part;
	part = 0;*/
	if(n==0)
		return 1;
	for(i=0; i<=n; i++)
		return cat(i)*cat(n-i-1);
	return -1;
}
