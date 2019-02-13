#include <stdio.h>
#include <string.h>

#define MAX 500

/*THIS GETS A 0*/
/*UCCIDETEMI*/
int main(int argc, char * argv[]){
	int i, count;
	char str[MAX], num;

	count = 0;
	scanf("%s", &str[0]);
	i = strlen(str);
	/*i--;*/
	num = str[i];
	for(; i>0; i--){
		if(str[i-1] == num)
			count++;
		else{
			printf("%c%d", num, count+1);
			count = 0;
		}
	}
	if(count>0)
		printf("%c%d\n", num, count+1);
	else
		printf("\n");
	return 0;
}
