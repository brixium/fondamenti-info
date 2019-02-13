#include <stdio.h>

int main(int argc, char * argv[]){
	int a, b;
	int mcm, mcd;
	int min, max;
	scanf("%d%d", &a, &b);
	if(a>=b){
		min = b;
		max = a;
	}else{
		min=a;
		max=b;
	}
	/*MCD*/
	mcd=1;
	while(min>mcd){
		if(a%min==0 && b%min == 0)
			mcd = min;
		min--;
	}
	/*mcm*/
	mcm = a*b/mcd;
	printf("%d\n%d\n", mcd, mcm);
	return 0;
}
