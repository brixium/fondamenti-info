#define SPACE ' '
#define CAR '='
#define SEP '|'
int main(int argc, char argv[]){
	int arr[MAX];
	int i,j;
	int val, min;

	do
		scanf("%d", &val);
	while
/*Considerazione: c'e almeno un numero positivo*/
	min = 0;

	for(i=0; i<val; i++){
		scanf("%d", &arr[i];
		if(arr[i]<min)
			min=arr[i];
	}
	for(i=0; i<val; i++){
		if(arr[i]>0){
			for(j=min; j<0; j++)
				printf("%c", SPACE);
			printf("%c", SEP);
			for(j=0; j< arr[i]; j++)
				printf("%c", CAR);
		}else{
			for(j=min - arr[i]; j<0; j++)
				printf("%c", SPACE);
			for(j=arr[i]; j<0; j++)
				printf("%c", CAR);
			printf("%c", SEP);
		}
		printf('\n');
	}
	return 0;
}
