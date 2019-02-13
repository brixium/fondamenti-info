#include <stdio.h>
#define DIM 20
int main(int argc, char * argv []){
	char s1[DIM+1], s2[DIM+1];
	int i, j, t, check;
	scanf("%s %s", &s1[0], &s2[0]);
	t=0, j=0, check = 1;
	for(i=0; s1[i]!='\0'; i++){
		for(j=0; s2[j]!='\0' && check; j++)
			if(s1[i]==s2[j]){
				s2[j]='|';
				t++;
				check = 0;
			}
		check=1;
	}
	for(j=0; s2[j]!='\0';j++)
		;
	/*printf("%d %d %d",  i, j, t);*/
	if(i==j&&i==t)
		printf("1");
	else
		printf("0");
	printf("\n");
	return 0;
}

