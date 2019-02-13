#include <stdio.h>
#define CAR '*'
#define MAX 10
#define SPACE ' '
#define SEP '-'
/*Fare istogramma verticale*/
int main(int argc, char * argv[]){
	int min, max, val, i, j, arr[MAX];
	/*Lecito*/
	min = 0;
	max = 0;
	do 
		scanf("%d", &val);/*Numero valori*/
	while(!(val>0 && val<=MAX));
	
	for(i=0; i<val; i++){
		scanf("%d", &arr[i]);
		if(arr[i]<min)
			min=arr[i];
		if(arr[i]>max)
			max = arr[i];
	}
	
	for(i=MAX; i>0; i--){
		printf("%d", i);
		for(j=0; j<val; j++){
			if(arr[j]>=i)
				printf("%c", CAR);
			else
				printf("%c", SPACE);
		}
		printf("\n");
	}

	printf("0");
	for(j=0; j<val; j++)
		printf("%c", SEP);
	printf("\n");
	
	for(i=-1; i>=min; i--){
		printf("%d", i);
		for(j=0; j<val; j++){
			if(arr[j]<=i)
				printf("%c", CAR);
			else
				printf("%c", SPACE);
		}
		printf("\n");

	}
	return 0;
}
