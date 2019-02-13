#include <stdio.h>
#define N 20
#define USED 1
#define UNUSED 0
int main(int argc, char * argv []){
	char v1[N+1], v2[N+2];
	int used[N], i, j; /*Array di supporto, indici*/
	int found;
	
	scanf("%s%s", v1, v2);
	for(i=0; i < N; i++)
		used[i] = 0; /*Array di supporto con tutti 0*/
		/*diocanee codice incustodito :-P :-* */
	found = 1;
	for(i=0; v1[i]!='\0' && found; i++){
		found=0;
		for(j=0; v2[j] != '\0'&& !found; j++)
			if(v1[i] == v2[j] && used[j] == UNUSED){
				used[j]=USED;
				found = 1;
			}
	}
	for(i=0; v2[i] != '\0' && found; i++)
		if(used[i] == UNUSED)
			found = 0;
	printf("%d\n", found);
	return 0;
}