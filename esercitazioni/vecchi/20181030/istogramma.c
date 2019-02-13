#include <stdio.h>
#define MAX 10
#define CAR '='
int main(int argc, char *argv[]){
	int arr[MAX], i, j, val;
	
	do
		scanf("%d", &val);
	while((val>=MAX) || (val>0));
	for(i=0; i<val; i++){
		scanf("%d", &arr[i];
	}
	for(i=0; i<val; i++){
		for(j=0; j<arr[i]; j++)
			printf("%c", CAR);
		printf("\n");
	}
	return 0;
}
